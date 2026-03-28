from fastapi import FastAPI, HTTPException # type: ignore
from pydantic import BaseModel # type: ignore

class Device(BaseModel):
    name: str
    location: str
    temperature: float

app = FastAPI()

@app.get("/hello")
def hello():
    return {"message": "Hello from FastAPI"}

@app.post("/echo")
def echo(body :dict):
    return {"you_sent":body}

@app.get("/items/{item_id}")
def get_item(item_id: int):
    if item_id > 100:
        raise HTTPException(status_code=404 , detail ="item not found")
    return {"item_id": item_id, "name": f"Item {item_id}"}

@app.get("/items")
def get_items(limit: int = 10, category: str ="all"):
    return {"limit": limit, "category": category, "items": []}

@app.post("/devices")
def create_device(device: Device):
    return{"message": "Device created", "device": device}

users = [
    {"id": 1, "name": "Ansu", "role": "Backend-engineer"},
    {"id": 2, "name": "sudo", "role": "iot-engineer"},
]

@app.get("/users")
def get_users():
    return {"users": users}