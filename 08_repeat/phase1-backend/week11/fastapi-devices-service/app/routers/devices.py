from fastapi import APIRouter , Depends ,HTTPException 
from app.models import Devices
from app.schemas import DeviceCreate
from app.tasks import cache_device
from sqlalchemy.orm import Session
from app.database import get_db
from app.auth import oauth2_scheme , verify_token
from typing import Optional
from app.redis_client import r 
import json
import os
from dotenv import load_dotenv
load_dotenv()



router = APIRouter()
PAGE_START = os.getenv("PAGE_START","")
PAGE_LIMIT = os.getenv("PAGE_LIMIT","")
REDIS_EXPIRY = os.getenv("REDIS_EXPIRY","")

@router.get("/devices")
def get_devices(page : int = int(PAGE_START) ,
                 limit : int = int(PAGE_LIMIT), status : Optional[str] = None ,
                 token : str = Depends(oauth2_scheme) ,
                   db : Session = Depends(get_db)):
    verify_token(token)
    skip = (page - 1) * limit
    if status == None:
        devices = db.query(Devices).offset(skip).limit(limit).all()
        return devices
    devices = db.query(Devices).filter(Devices.dev_status == status).offset(skip).limit(limit).all()
    return devices
    

@router.post("/devices")
def post_device(device : DeviceCreate ,token : str = Depends(oauth2_scheme) ,db : Session = Depends(get_db) ):
    verify_token(token)
    if db.query(Devices).filter(Devices.model_name == device.model_name , Devices.model_no == device.model_no).first() :
        raise HTTPException(status_code=400 , detail="Device with same model no and model name already exists")
    new_device = Devices(model_name =device.model_name , model_no =device.model_no , dev_status =device.dev_status)
    db.add(new_device)
    db.commit()
    db.refresh(new_device)
    device_dict = {"id":new_device.id , "model_name":new_device.model_name , "model_no":new_device.model_no , "dev_status":new_device.dev_status}
    cache_device.delay(device_dict , new_device.id)
    return {"Device": device.model_name , "Model No." : device.model_no , "Status": device.dev_status}

@router.get("/devices/{id}")
def get_device(id : int  ,token : str = Depends(oauth2_scheme) ,db : Session = Depends(get_db)):
    verify_token(token)
    cached = r.get(f"device:{id}")
    if cached:
        return json.loads(str(cached))
    device = db.query(Devices).filter(Devices.id == id).first()
    if device is None:
        raise HTTPException(status_code=404 , detail = "Device not Found")
    device_dict = {"id":device.id , "model_name":device.model_name , "model_no" :device.model_no , "dev_status": device.dev_status}
    r.set(f"device:{id}" , json.dumps(device_dict) , ex=60)
    return device_dict

@router.put("/devices/{id}")
def update_dev(id :int ,device : DeviceCreate,token : str = Depends(oauth2_scheme) ,db : Session = Depends(get_db)):
    verify_token(token)
    existing = db.query(Devices).filter(Devices.id == id).first()
    if existing is None:
        raise HTTPException(status_code=404 ,detail="Device not Found")
    existing.model_name = device.model_name #type: ignore
    existing.model_no = device.model_no #type: ignore
    existing.dev_status = device.dev_status#type: ignore
    db.commit()
    db.refresh(existing)
    return existing

@router.delete("/devices/{id}")
def delete_dev(id : int , token :str = Depends(oauth2_scheme) , db : Session = Depends(get_db)):
    verify_token(token)
    device = db.query(Devices).filter(Devices.id == id ).first()
    if device is None:
        raise HTTPException(status_code=404 , detail="Device not Found")
    deleted_name = device.model_name
    deleted_no = device.model_no
    db.delete(device)
    db.commit()
    return {"message" : f"{deleted_name} with Model No. {deleted_no} is Deleted Succesfully"}
