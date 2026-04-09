from fastapi import FastAPI, HTTPException
from pydantic import BaseModel

app = FastAPI()

class UserLogin(BaseModel):
    username : str
    password : str

USERNAME = "user"
PASSWORD = "pwd"

def create_access_token(username : str):
    return f"fake at for {username}"


@app.post("/login")
def verify_user_cred(user : UserLogin):
    if(user.username != USERNAME or user.password != PASSWORD):
        raise HTTPException(status_code = 401 , detail = "Login username or pw invalid")
    
    return {"message": "Login SSFL" , "Accestoken": create_access_token(user.username) }