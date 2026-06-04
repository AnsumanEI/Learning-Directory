from fastapi import Depends , HTTPException , APIRouter
from app.auth import create_token , hash_password ,verify_hash
from app.models import Users
from sqlalchemy.orm import Session 
from app.database import get_db
from app.schemas import UserCreate , UserLogin

router = APIRouter()


@router.post("/register")
def register_user(user : UserCreate ,db : Session = Depends(get_db) ):
    if db.query(Users).filter(Users.username == user.username).first():
        raise HTTPException(status_code=401,detail="Username already exists")
    hashed_pwd = hash_password(user.password)
    new_user = Users(username = user.username , password =hashed_pwd, role = user.role)
    db.add(new_user)
    db.commit()
    db.refresh(new_user)
    return new_user



@router.post("/login")
def user_login(user : UserLogin , db : Session = Depends(get_db)):
    login_req = db.query(Users).filter(Users.username == user.username).first()
    if login_req is None:
        raise HTTPException(status_code=401 , detail=f" {user.username} not Found")
    hashed_pwd = str(login_req.password)
    if verify_hash(user.password , hashed_pwd) is False:
        raise HTTPException(status_code=401 , detail=f" The Username/Password for {user.username} is incorrect")
    return {"access_token" : create_token({"sub": user.username}) , "token_type": "bearer"}