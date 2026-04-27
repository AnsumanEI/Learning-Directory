from sqlalchemy.orm import declarative_base , sessionmaker
from sqlalchemy import create_engine 
import os

DATABASE_URL = os.getenv("DATABASE_URL" ,"postgresql://user:password@db/db")

engine = create_engine(DATABASE_URL)
SessionLocal = sessionmaker(autoflush=False , autoCommit =False ,bind=engine)
Base = declarative_base()

def get_db():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()

def create_tables():
    Base.metadata.create_all(bind=engine)