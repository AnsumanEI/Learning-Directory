from pydantic import BaseModel 
from fastapi import FastAPI , Header , Depends , HTTPException, Request
from sqlalchemy.orm import Session
from database import get_db 
from models import UserAuth , Device
from fastapi.security import OAuth2PasswordBearer
from passlib.context import CryptContext
from dotenv import load_dotenv
from fastapi.middleware.cors import CORSMiddleware
from fastapi.responses import JSONResponse
from jose import jwt , JWTError

load_dotenv()
import os
app= FastAPI()

class TokenData(BaseModel):
    username:str

SECRET_KEY = "12345"
ALGORITHM = "HS256"


class UserLog(BaseModel):
    username : str
    password :str

app.add_middleware(
        CORSMiddleware,
        allow_origins=["*"],
        allow_methods=["*"],
        allow_headers=["*"],
)

@app.middleware("http")
async def log_req(request: Request , call_next):
    print(f"incoming {request.method} -> {request.url}")
    response = await call_next(request)
    print(f"Completed {response.status_code}")
    return response

@app.exception_handler(Exception)
async def global_handler(request : Request,exc : Exception):
    return JSONResponse(
        status_code=500 ,
        content={"detail" :str(exc),"request":f"{request.method}-> {request.url}"}
    )


X_API = os.getenv("API_KEY" , "")

def verify_api(api: str):
    if api!= X_API :
        raise HTTPException(status_code=401 , detail="Wrong Api code ,unauthorized")
    
oauth2_scheme = OAuth2PasswordBearer(tokenUrl="login")#forgot what is token url login
pwd_context = CryptContext(schemes=["bcrypt"] , deprecated ="auto")

def hash_pwd(password : str):
    return pwd_context.hash(password)

def verify_hash(plain : str , hashed :str):
    return pwd_context.verify(plain , hashed)

def verify_token(token : str):
    try:
      payload =  jwt.decode(token , SECRET_KEY , algorithms= [ALGORITHM] )
      username = payload.get("sub") 
      if username is None:
          raise HTTPException(status_code=401 , detail="Invalid token")
      return TokenData(username=username)
    except JWTError:
        raise HTTPException(status_code=401 , detail="Invalid Token")



@app.post("/register")
def register_user(user : UserLog ,x_api: str = Header(alias="x-api-key"), db : Session =Depends(get_db)):
    verify_api(x_api)
    if db.query(UserAuth).filter(UserAuth.username == user.username).first():
        raise HTTPException(status_code=400 , detail="user already exists")
    hashed = hash_pwd(user.password)
    new_user = UserAuth( username = user.username , hashed_password = hashed)
    db.add(new_user)
    db.commit()
    db.refresh(new_user)
    return {"user":f"{user.username}", "message" : f"Registered Succesfully"}

@app.get("/devices/{id}")
def getbyid(id : int  , token : str = Depends(oauth2_scheme) , db : Session= Depends(get_db)):
    verify_token(token)
    searched = db.query(Device).filter(Device.id == id ).first()
    if searched is None:
        raise HTTPException(status_code=404 , detail ="The device is not found")
    return searched
