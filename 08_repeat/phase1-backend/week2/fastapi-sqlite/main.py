from fastapi import FastAPI , Depends ,Header ,HTTPException ,Request
from fastapi.middleware.cors import CORSMiddleware 
from jose import jwt , JWTError 
from sqlalchemy.orm import Session ,sessionmaker
import os
from fastapi.responses import JSONResponse
from datetime import datetime , timedelta
from database import create_tables , get_db
from models import User
from pydantic import BaseModel

API_KEY = "realapi"
SECRET_KEY = "realsecret"
ALGORITHM = "HS256"
ACCESS_TOKEN_EXPIRE_MINUTES = 30
USERNAME = "admin"
PASSWORD = "admin"

class UserIn(BaseModel):
    username :str
    role :str

class Userlogin(BaseModel):
    username : str
    password : str

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


@app.post("/login")
def user_login(user : Userlogin):
    if(user.username!=USERNAME or user.password != PASSWORD):
        raise HTTPException(status_code=401 , detail="InvalidID/Password")
    return {"Login Sfl Toke": create_token({"sub":user.username}) }

@app.get("/protected")
def access_protected(token : str , x_api_key: str = Header()):
    verify_apikey(x_api_key)
    username = verify_token(token)
    return {"message" : f"Welcome to protected space {username}"}






