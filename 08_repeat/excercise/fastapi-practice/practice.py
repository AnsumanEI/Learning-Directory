from database import get_db , SessionLocal
from passlib.context import CryptContext 
from models import Base , UserData , UserAuth
from fastapi import FastAPI  ,Depends , HTTPException ,Header
from sqlalchemy.orm import sessionmaker  ,Session
from pydantic import BaseModel
from jose import JWTError ,jwt
from datetime import datetime , timedelta
from fastapi.security import OAuth2PasswordBearer

app = FastAPI()

EXPIRY_IN_MINUTES = 30
SECRET_KEY = "1234"
ALGORITHM = "HS256"
X_API_KEY = "realapi"
class UserIn(BaseModel):
    name : str 
    role : str
class UserAuthClass(BaseModel):
    username : str
    password : str

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
def get_by_id(id : int , x_api_key : str =Header() , db : Session = Depends(get_db)):
    verify_xapi(x_api_key)
    user = db.query(UserData).filter(UserData.id == id).first()
    if user is None:
        raise HTTPException(status_code=404 , detail="This ID does not exist")
    return user