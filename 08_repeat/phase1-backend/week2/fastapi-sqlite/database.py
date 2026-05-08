from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker , declarative_base
import os

DATABASE_URL = os.getenv("DATABASE_URL" ,"postgresql://ansuman966:tracker@localhost/db")
engine = create_engine(DATABASE_URL)
Base = declarative_base()
SessionLocal = sessionmaker(autocommit=False , autoflush = False ,bind=engine)

def create_tables():
    Base.metadata.create_all(bind=engine)

def get_db():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()


