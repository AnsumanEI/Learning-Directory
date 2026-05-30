from database import get_db , SessionLocal
from passlib.context import CryptContext 
from models import Base , UserData , UserAuth , Device
from fastapi import FastAPI  ,Depends , HTTPException ,Header
from sqlalchemy.orm import sessionmaker  ,Session
from pydantic import BaseModel
from jose import JWTError ,jwt
from datetime import datetime , timedelta
from fastapi.security import OAuth2PasswordBearer
from typing import Optional
from fastapi.middleware.cors import CORSMiddleware
from fastapi.requests import Request
from fastapi.responses import JSONResponse
import redis ,json

r = redis.Redis(host="redis" , port=6379 , db=0 , decode_responses=True)

app = FastAPI()

EXPIRY_IN_MINUTES = 30
SECRET_KEY = "1234"
ALGORITHM = "HS256"
X_API_KEY = "realapi"

app.add_middleware(
    CORSMiddleware ,
    allow_origins =["*"] ,
    allow_headers =["*"] ,
    allow_methods =["*"] ,
)






@app.middleware("http")
async def log_request(request : Request , call_next):
    print(f"incoming {request.method} -> {request.url}")
    response = await call_next(request)
    print(f"completed {response.status_code}")
    return response

@app.exception_handler(Exception)
async def global_exception_handler(request : Request , exc : Exception):
    return JSONResponse(
        status_code=500 , 
    content= {"detail": str(exc) , "request" : f"{request.method}->>{request.url}" }
    )
    

class UserIn(BaseModel):
    name : str 
    role : str
class UserAuthClass(BaseModel):
    username : str
    password : str

class DeviceSchema(BaseModel):
    model_no : str
    model_name: str
    dev_status : str

pwd_context = CryptContext(schemes=["bcrypt"], deprecated = "auto")

oauth2_scheme = OAuth2PasswordBearer(tokenUrl="login")

def hash_password(password : str ):
    return pwd_context.hash(password)

def verify_xapi(x_api_key :str):
    if x_api_key != X_API_KEY:
        raise HTTPException(status_code=400 , detail="Invalid api key")

def verify_hash(plain : str , hashed :str):
    if pwd_context.verify(plain , hashed) is False:
        raise HTTPException(status_code=400 , detail="INVALID USERNAME/PASSWORD")

def create_token(data : dict):
    to_encode = data.copy()
    expiry = datetime.utcnow() + timedelta(minutes=EXPIRY_IN_MINUTES)
    to_encode.update({"exp":expiry})
    encoded_jwt = jwt.encode(to_encode , SECRET_KEY ,algorithm= ALGORITHM )
    return encoded_jwt

def verify_token(token : str = Depends(oauth2_scheme)):
    try:
      payload = jwt.decode(token , SECRET_KEY , algorithms=[ALGORITHM])
      username = payload.get("sub")
      if username is None :
          raise HTTPException(status_code=401 , detail= "Invalid Token Detected")
      return username
    except JWTError:
        raise HTTPException(status_code=401 , detail= "Invalid Token Detected")
        

@app.post("/register")
def register_user(user : UserAuthClass, db : Session=Depends(get_db)):
    if db.query(UserAuth).filter(UserAuth.username ==user.username).first() :
        raise HTTPException(status_code=400 , detail="Username already exists")
    hashed = hash_password(user.password)
    new_user = UserAuth(username = user.username , hashed_password = hashed )
    db.add(new_user)
    db.commit()
    db.refresh(new_user)
    return {"message" : f"The username {user.username} is successfylly registered"}

@app.post("/login")
def user_login(user : UserAuthClass , db : Session = Depends(get_db)):
    searched_user = db.query(UserAuth).filter(UserAuth.username==user.username ).first()
    if searched_user is None:
        raise HTTPException(status_code=400 , detail= "user does not exist")
    hashed_pw = str(searched_user.hashed_password )
    verify_hash(user.password ,  hashed_pw)
    return {"message" : f"{user.username} is Successfully logged in" , "Token" : create_token({"sub":user.username}) , "token_type" : "Bearer"}

@app.post("/users")
def create_users(user : UserIn , x_api_key : str = Header() , db : Session = Depends(get_db)):
    verify_xapi(x_api_key)
    if db.query(UserData).filter(UserData.name == user.name).first():
        raise HTTPException(status_code=400 , detail="User already exists")
    new_user = UserData(name = user.name , role = user.role)
    db.add(new_user)
    db.commit()
    db.refresh(new_user)
    return {"message": f"{user.name} has been added"} 

@app.get("/users")
def get_users(x_api_key : str = Header() ,db : Session = Depends(get_db)):
    verify_xapi(x_api_key)
    return db.query(UserData).all()

@app.get("/users/{id}")
def getdev_id(id : int , x_api_key : str =Header() , db : Session = Depends(get_db)):
    verify_xapi(x_api_key)
    user = db.query(UserData).filter(UserData.id == id).first()
    if user is None:
        raise HTTPException(status_code=404 , detail="This ID does not exist")
    return user

@app.post("/devices")
def create_device(device : DeviceSchema , token : str = Depends(oauth2_scheme) , db : Session = Depends(get_db) ):
    verify_token(token)

    if db.query(Device).filter(Device.model_name == device.model_name ,Device.model_no ==device.model_no).first():
        raise HTTPException(status_code=409, detail="Device Already Exists")
    new_device = Device(model_name = device.model_name , model_no = device.model_no , status = device.dev_status)
    db.add(new_device)
    db.commit()
    db.refresh(new_device)
    return {"Device" : device.model_name , "Model No." : device.model_no , "Status": device.dev_status , "message" : "is registered sucessfully"}

@app.get("/devices")
def get_all(page : int =1 ,limit :int = 10 ,status : Optional[str] =None , token : str = Depends(oauth2_scheme) , db : Session = Depends(get_db)):
    verify_token(token)
    skip = (page-1)*limit
    query  = db.query(Device)
    if status :
        query.filter(Device.status == status)
    devices = query.offset(skip).limit(limit).all()
    return devices 

@app.get("/devices/{id}")
def get_by_id(id : int ,token : str = Depends(oauth2_scheme), db : Session = Depends(get_db)):
    verify_token(token)
    cached = r.get(f"device:{id}")
    if cached:
        return json.loads(str(cached))
    device = db.query(Device).filter(Device.id == id).first()
    if device is None:
        raise HTTPException(status_code=404 , detail="This ID does not exist")
    device_dict = {"id" :device.id  , "mode_name": device.model_name , "model_no" :device.model_no , "dev_status" : device.dev_status}
    r.set(f"device:{id}" , json.dumps(device_dict) , ex = 60)
    return device_dict

@app.put("/devices/{id}")
def update_device(new_device : DeviceSchema ,id : int ,token : str = Depends(oauth2_scheme), db : Session = Depends(get_db)):
    verify_token(token)
    existing = db.query(Device).filter(Device.id == id).first()
    if existing is None:
        raise HTTPException(status_code=404 , detail="This ID does not exist")
    existing.model_name = new_device.model_name#type: ignore
    existing.model_no = new_device.model_no#type: ignore
    existing.status = new_device.status#type: ignore
    db.commit()
    db.refresh(existing)
    return existing
