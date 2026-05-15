from sqlalchemy.orm import declarative_base , sessionmaker
from sqlalchemy import create_engine
import os

DATABASE_URL = os.getenv("DATABASE_URL" , "postgresql://username:password@localhost/db")

engine = create_engine(DATABASE_URL)
SessionLocal = sessionmaker(bind = engine)
Base = declarative_base()

def create_table():
    Base.metadata.create_all(bind=engine)

def get_db ():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()
