from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
from fastapi import Header
import sqlite3 
from fastapi.middleware.cors import CORSMiddleware
from fastapi.responses import JSONResponse
from fastapi import Request 
from jose import jwt , JWTError
from datetime import datetime , timedelta


app = FastAPI()

app.add_middleware(
    CORSMiddleware,
    allow_origins =["*"],
    allow_methods=["*"],
    allow_headers = ["*"],
)
@app.middleware("http")
async def logging_requests(request : Request , call_next):
    print(f"incoming: {request.method} -> {request.url}")
    response = await call_next(request)
    print(f"completed {response.status_code}")
    return response
@app.exception_handler(Exception)
async def global_exception_handler(request : Request , exc: Exception):
    return JSONResponse (
        status_code=500,
        content={"error" : "something went wrong" , "detail": str(exc)}
    )
class UserCreate(BaseModel):
    username : str
    password : str
    role : str

class UserLogin(BaseModel):
    username : str
    password : str

USERNAME = "user"
PASSWORD = "pwd"
SECRET_KEY ="123"
ALGORITHM = "HS256"
ACCESS_TOKEN_EXPIRE_MINUTES = 30

def create_access_token(data :dict):
    to_encode = data.copy()
    expire = datetime.utcnow() + timedelta(minutes=ACCESS_TOKEN_EXPIRE_MINUTES)
    to_encode.update({"exp":expire})
    encoded_jwt = jwt.encode(to_encode , SECRET_KEY , algorithm=ALGORITHM)
    return encoded_jwt

def verify_token(token : str):
    try:
        payload = jwt.decode(token , SECRET_KEY , algorithms = ALGORITHM)
        username : str = payload.get("sub")
        if username is None:
            raise HTTPException(status_code =401 , detail="invalid token with no username")
        return username
    except JWTError:
        raise HTTPException(status_code=401 , detail="Invalid token")

    

def setup_db():
    conn = sqlite3.connect("users.db")
    cursor = conn.cursor()
    cursor.execute("""
    CREATE TABLE IF NOT EXISTS users(
                   id INTEGER PRIMARY KEY AUTOINCREMENT,
                   username TEXT,
                   role TEXT,
                   password TEXT
                   )
""")
    conn.commit()
    conn.close()

setup_db()

@app.post("/users")
def create_user(user : UserCreate):
    conn = sqlite3.connect("users.db")
    cursor = conn.cursor()
    cursor.execute("""INSERT INTO users (username, role , password) VALUES (?,?,?)""" , (user.username ,user.role , user.password)
)
    conn.commit()
    conn.close()
    return {"message" : "User Created" , "user" : {"username": user.username , "role":user.role}}



@app.get("/users")
def fetch_users():
    conn = sqlite3.connect("users.db")
    cursor = conn.cursor()
    cursor.execute("SELECT * FROM users")
    users = cursor.fetchall()
    conn.close()
    return {"users" : users}

@app.post("/login")
def verify_user_cred(user : UserLogin):
    if(user.username != USERNAME or user.password != PASSWORD):
        raise HTTPException(status_code = 401 , detail = "Login username or pw invalid")
    
    return {"message": "Login SSFL" , "Accestoken": create_access_token(data ={"sub" : user.username}) }

API_KEY = "hello123"

@app.get("/hprotect")
def verify_api_key (x_api_key : str = Header()):
    if(x_api_key != API_KEY):
        raise HTTPException(status_code = 401, detail = "invalid API Key")
    return{"message" : "access granted"}

@app.get("/jwtprotect")
def protected_route(token :str):
    username = verify_token(token)
    return {"message" : f"hello {username} you have access"}