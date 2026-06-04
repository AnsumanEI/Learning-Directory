from fastapi import Depends , HTTPException
from sqlalchemy.orm import Session
from app.database import get_db
from app.models import Users
from jose import jwt , JWTError
from passlib.context import CryptContext 
from fastapi.security import OAuth2PasswordBearer
from datetime import datetime , timedelta
import os
from dotenv import load_dotenv
load_dotenv()


SECRET_KEY = os.getenv("SECRET_KEY","")
ALGORITHM = os.getenv("ALGORITHM","")
EXPIRY = os.getenv("ACCESS_TOKEN_EXPIRE_MINUTES","")


pwd_context  = CryptContext(schemes=["bcrypt"] , deprecated="auto")
oauth2_scheme = OAuth2PasswordBearer(tokenUrl= "users/login")

def hash_password(password: str):
    return pwd_context.hash(password)

def verify_hash(plain : str , hashed : str):
    return pwd_context.verify(plain , hashed)

def create_token(data :dict):
    to_encode = data.copy()
    expire = datetime.utcnow() + timedelta(minutes=int(EXPIRY))
    to_encode.update({"exp" : expire})
    encoded_jwt = jwt.encode(to_encode , str(SECRET_KEY) , algorithm=str(ALGORITHM))
    return encoded_jwt

def verify_token(token :str):
    try:
        payload = jwt.decode(token , SECRET_KEY , algorithms=[ALGORITHM])
        username = payload.get("sub")
        if username is None:
            raise HTTPException(status_code=401 , detail="Invalide Access Token")
        return username
    except JWTError:
        raise HTTPException(status_code=401 , detail="Invalid Access Token")
        

def get_current_user(token : str =Depends(oauth2_scheme) , db : Session =Depends(get_db)):
    try:
        payload = jwt.decode(token , SECRET_KEY , algorithms=[ALGORITHM])
        username = payload.get("sub")
        if username is None:
            raise HTTPException(status_code=401 , detail="Invalid Access Token")
        user = db.query(Users).filter(Users.username == username).first()
        if user is None :
            raise HTTPException(status_code=401 , detail= "User not found")
        return user
    except JWTError:
        raise HTTPException(status_code=401 , detail="Invalid Access Token")

    
