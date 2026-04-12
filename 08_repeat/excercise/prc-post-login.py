from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
from fastapi import Header
import sqlite3 

app = FastAPI()

class UserCreate(BaseModel):
    username : str
    password : str
    role : str

class UserLogin(BaseModel):
    username : str
    password : str

USERNAME = "user"
PASSWORD = "pwd"

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
def create_access_token(username : str):
    return f"fake at for {username}"


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
    
    return {"message": "Login SSFL" , "Accestoken": create_access_token(user.username) }

API_KEY = "hello123"

@app.get("/protected")
def verify_api_key (x_api_key : str = Header()):
    if(x_api_key != API_KEY):
        raise HTTPException(status_code = 401, detail = "invalid API Key")
    return{"message" : "access granted"}