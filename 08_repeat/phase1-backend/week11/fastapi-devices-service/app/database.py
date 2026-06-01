
from sqlalchemy import create_engine 
from sqlalchemy.orm import sessionmaker , declarative_base
from dotenv import load_dotenv
import os

load_dotenv()
DATABASE_URL = os.getenv("DATABASE_URL","")
engine = create_engine(DATABASE_URL)
Session_Local = sessionmaker(bind=engine)
Base = declarative_base()

def create_table():
    Base.metadata.create_all(engine)

def get_db():
    db = Session_Local()
    try:
        yield db
    finally:
        db.close()