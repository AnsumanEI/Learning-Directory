from fastapi.security import OAuth2PasswordBearer 
from fastapi import HTTPException ,FastAPI ,Response ,Depends ,Request , Header
from database import create_tables ,get_db
from models import UserAuth , UserData
from passlib.context import CryptContext # type: ignore
from pydantic import BaseModel 
from fastapi.middleware.cors import CORSMiddleware
from jose import JWTError , jwt
from sqlalchemy.orm import Session , sessionmaker
from datetime import datetime , timedelta

app = FastAPI()

@app.on_event("startup")
def startup():
    create_tables()

class UserIn(BaseModel):
    user : str
    role : str

class UserLogin(BaseModel):
    username : str
    password : str

app.add_middleware(
    CORSMiddleware ,
    allow_origins =["*"],
    allow_methods = ["*"],
    allow_headers = ["*"]    
)


ALGORITHM= "HS256"
SECRET_KEY = "1234"
EXPIRE_TIME_MINUTES = 30
API_KEY = "APIKEY"

pwd_context = CryptContext(schemes=["bcrypt"] , deprecated = "auto")
oauth2_schemes = OAuth2PasswordBearer(tokenUrl="login")

@app.middleware("http")
async def log_requests(request : Request , call_next):
    print(f"incoming {request.method} -> {request.url}")
    response = await call_next(request)
    print(f"Completed : {response.status_code}")
    return response


def create_token(data : dict):
    to_encode = data.copy()
    expiry = datetime.utcnow() + timedelta(minutes=EXPIRE_TIME_MINUTES)
    to_encode.update({"exp":expiry})
    encoded_jwt = jwt.encode(to_encode , SECRET_KEY , algorithm= ALGORITHM)
    return encoded_jwt

def verify_token(token : str):
    try:
        payload = jwt.decode(token , SECRET_KEY , algorithms=[ALGORITHM])
        username = payload.get("sub")
        if username is None:
            raise HTTPException(status_code=400 , detail="Invalid Token")
        return username
    except  JWTError:
        raise HTTPException(status_code=401 , detail="Invalid Token Detected")
    
def hash_password(password : str):
    return pwd_context.hash(password)

def verify_hash(plain : str , hashed : str):
    return pwd_context.verify(plain , hashed)

def verify_apikey(x_api_key : str = Header()):
    if(x_api_key!=API_KEY):
        raise HTTPException(status_code=401 , detail="User not verified")

@app.post("/register")
def user_register(user: UserLogin , db : Session = Depends(get_db)):
    if db.query(UserAuth).filter(UserAuth.username == user.username).first() :
        raise HTTPException(status_code=401 , detail="the username already exists")
    hashed = hash_password(user.password)
    new_user = UserAuth(username = user.username , hashed_password = hashed)
    db.add(new_user)
    db.commit()
    return {"message" : f"{user.username} has registered succefully"}

@app.post("/login")
def user_login(user : UserLogin , db : Session = Depends(get_db)):
    sessionuser  = db.query(UserAuth).filter(UserAuth.username == user.username).first()
    if sessionuser is None:
        raise HTTPException(status_code=401 , detail=f"the username {sessionuser} not found")
    hashedpwd = str(sessionuser.hashed_password)
    if verify_hash(user.password , hashedpwd) is False:
        raise HTTPException(status_code=401 , detail="The password is incorrect")
    return {"message": "login successfull" , "token": create_token({"sub":user.username}) , "token_type":"bearer"}

@app.get("/protected")
def access_protected(token:str =Depends(oauth2_schemes) , x_api_key : str = Header()):
    verify_apikey(x_api_key)
    username = verify_token(token)
    return {"message":f"{username} successfully accessed the protected space"}
        
