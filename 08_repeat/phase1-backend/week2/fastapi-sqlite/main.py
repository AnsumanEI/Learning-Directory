from fastapi import FastAPI , Depends ,Header ,HTTPException ,Request
from fastapi.middleware.cors import CORSMiddleware 
from jose import jwt , JWTError 
from sqlalchemy.orm import Session ,sessionmaker
import os
from fastapi.responses import JSONResponse
from datetime import datetime , timedelta
from database import create_tables , get_db
from models import User , UserAuth , Devices
from pydantic import BaseModel
from fastapi.security import OAuth2PasswordBearer
from passlib.context import CryptContext # type: ignore
from dotenv import load_dotenv # to load from env file 
load_dotenv() #use getenc functions
from typing import Optional #for query parameters assign ed to None so either it can be string or none

API_KEY = os.getenv("API_KEY" , "")
SECRET_KEY = os.getenv("SECRET_KEY" ,"")#these values can not be wmpty in jwt encode and decode so a fallback value of "" is given
ALGORITHM = os.getenv("ALGORITHM","")
ACCESS_TOKEN_EXPIRE_MINUTES = int(os.getenv("ACCESS_TOKEN_EXPIRE_MINUTES" , "30"))
USERNAME = os.getenv("USERNAME")
PASSWORD = os.getenv("PASSWORD")

pwd_context  = CryptContext(schemes=["bcrypt"] , deprecated="auto")
oauth2_scheme = OAuth2PasswordBearer(tokenUrl= "login")

def hash_password(password: str):
    return pwd_context.hash(password)

def verify_hash(plain : str , hashed : str):
    return pwd_context.verify(plain , hashed)
class UserIn(BaseModel):
    username :str
    role :str

class Userlogin(BaseModel):
    username : str
    password : str

class DeviceSchema(BaseModel):

    model_no: str
    model_name :str
    dev_status :str



app = FastAPI()

app.add_middleware(

    CORSMiddleware,
    allow_origins=["*"], 
    allow_methods=["*"],
    allow_headers=["*"]

)


@app.on_event("startup")
def startup():
    create_tables()

@app.post("/register")
def register(user : Userlogin , db : Session = Depends(get_db)):
    if db.query(UserAuth).filter(UserAuth.username == user.username).first():
        raise HTTPException(status_code=400 , detail=f"User {user.username} already exists")
    hashed = hash_password(user.password)
    new_user = UserAuth(username = user.username , hashed_password = hashed)
    db.add(new_user)
    db.commit()
    return{"message" : f"User {user.username} is Registered Succesfully"}
        

@app.middleware("http")
async def log_requests(request : Request , call_next ):
    print(f"incoming : {request.method} -> {request.url}")
    response = await call_next(request)
    print(f"Completed : {response.status_code}")
    return response

def verify_apikey(x_api_key : str = Header()):
    if(x_api_key!=API_KEY):
        raise HTTPException(status_code=401 , detail="User not verified")

def create_token(data : dict):
    to_encode = data.copy()
    expire = datetime.utcnow() + timedelta(minutes=ACCESS_TOKEN_EXPIRE_MINUTES)
    to_encode.update({"exp" : expire})
    encoded_jwt = jwt.encode(to_encode , SECRET_KEY , algorithm=ALGORITHM)
    return encoded_jwt

def verify_token(token : str):
    try:
        payload = jwt.decode(token , SECRET_KEY , algorithms=[ALGORITHM])
        username = payload.get("sub")
        if username is None:
            raise HTTPException(status_code=401 , detail="InvalidAccesstoken")
        return username
    except JWTError:
        raise HTTPException(status_code=401 , detail="InvalidAccesstoken")

@app.post("/users")   
def create_users(user : UserIn , x_api_key : str = Header() ,db : Session = Depends(get_db)):
    verify_apikey(x_api_key)
    db_user = User(name = user.username , role= user.role)
    db.add(db_user)
    db.commit()
    db.refresh(db_user)
    return {"ID":db_user.id , "Name": db_user.name , "role": db_user.role}



@app.get("/users")
def get_users(x_api_key: str= Header() , db: Session = Depends(get_db)):
    users = db.query(User).all() #or . get(id)
    return users

@app.get("/devices")
def get_devices(page : int = 1 , limit : int = 10 , status : Optional[str] = None ,token : str =Depends(oauth2_scheme) , db : Session = Depends(get_db)):
    verify_token(token)
    skip = (page - 1) * limit
    if status == None:
        devices = db.query(Devices).offset(skip).limit(limit).all()
        return devices
    devices = db.query(Devices).filter(Devices.dev_status == status).offset(skip).limit(limit).all()
    return devices
    


@app.post("/login")
def user_login( user : Userlogin ,db : Session = Depends(get_db)):
    search = db.query(UserAuth).filter(UserAuth.username == user.username).first()
    if search is None:
        raise HTTPException(status_code=401 , detail=f" {user.username} not Found")
    hashpass  = str(search.hashed_password) #used str to silence the error
    if verify_hash(user.password , hashpass) is False:
        raise HTTPException(status_code=401 , detail=f" The Password for {user.username} is incorrect")
    return {"access_token" : create_token({"sub": user.username}) ,"token_type": "bearer"}

@app.post("/devices")
def post_device(device : DeviceSchema ,token : str = Depends(oauth2_scheme) ,db : Session = Depends(get_db) ):
    verify_token(token)
    new_device = Devices(model_name =device.model_name , model_no =device.model_no , dev_status =device.dev_status)
    if db.query(Devices).filter(Devices.model_name == device.model_name , Devices.model_no == device.model_no).first() :
        raise HTTPException(status_code=400 , detail="Device with same model no and model name already exists")
    db.add(new_device)
    db.commit()
    db.refresh(new_device)
    return {"Device": device.model_name , "Model No." : device.model_no , "Status": device.dev_status}

@app.get("/devices/{id}")
def get_devbyid(id : int  ,token : str = Depends(oauth2_scheme) ,db : Session = Depends(get_db)):
    verify_token(token)
    device = db.query(Devices).filter(Devices.id == id).first()
    if device is None:
        raise HTTPException(status_code=404 , detail = "Device not Found")
    return device

@app.put("/devices/{id}")
def update_dev(id :int ,device : DeviceSchema,token : str = Depends(oauth2_scheme) ,db : Session = Depends(get_db)):
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

@app.delete("/devices/{id}")
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


    
         
@app.get("/protected")
def access_protected(token : str = Depends(oauth2_scheme) , x_api_key: str = Header()):
    verify_apikey(x_api_key)
    username = verify_token(token)
    return {"message" : f"Welcome to protected space {username}"}






