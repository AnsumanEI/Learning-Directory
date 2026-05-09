from pydantic import BaseModel 
from fastapi import FastAPI , Header , Depends , HTTPException
from sqlalchemy.orm import Session
from database import get_db , create_tables 
from models import UserAuth
from fastapi.security import OAuth2PasswordBearer
from passlib.context import CryptContext
from dotenv import load_dotenv
load_dotenv()
import os
app= FastAPI()

class UserLog(BaseModel):
    username : str
    password :str

@app.on_event("startup")
def startup():
    create_tables()

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



    