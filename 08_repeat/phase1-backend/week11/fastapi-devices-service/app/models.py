from sqlalchemy import String , Integer , Column
from database import Base 

class Users(Base):
    __tablename__ = "users"
    id = Column(Integer , primary_key=True )
    username = Column(String , index=True , unique=True , nullable=False)
    password = Column(String , nullable=False)
    role = Column(String , nullable=True)

class Devices(Base):
    __tablename__ ="devices"
    id = Column(Integer , primary_key= True , index= True)
    model_name = Column(String , nullable=False )
    model_no =Column(String , index= True)
    dev_status = Column(String , nullable=False)