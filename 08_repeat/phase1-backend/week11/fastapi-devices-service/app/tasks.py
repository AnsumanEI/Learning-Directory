from app.celery_app import celery_app
from app.redis_client import r
import json ,os 
import dotenv
from dotenv import load_dotenv
load_dotenv()
REDIS_EXPIRY = os.getenv("REDIS_EXPIRY","")

@celery_app.task
def cache_device(device_dict : dict , device_id :int):
    r.set(f"device:{device_id}" , json.dumps(device_dict) , ex=int(REDIS_EXPIRY))