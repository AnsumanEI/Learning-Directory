from pydantic import BaseModel
#model_config tells pydantic it can read sql alchemy objects from attributes , else it cant read the objects directly as it only reads in dictonaries



class UserCreate(BaseModel):
    username :str
    password :str
    role :str

class UserLogin(BaseModel):
    username:str
    password:str
class UserResponse(BaseModel):
    model_config ={"from_attributes":True}
    id :int
    username :str
    role :str

class DeviceCreate(BaseModel):
    model_name:str
    model_no:str
    dev_status:str

class DeviceResponse(BaseModel):
    model_config ={"from_attributes":True}
    id:int
    model_name:str
    model_no:str
    dev_status:str