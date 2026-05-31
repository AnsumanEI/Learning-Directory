from sqlalchemy import Column , Integer ,String , Float , DateTime , ForeignKey
from sqlalchemy.orm import relationship
from datetime import datetime 
from database import Base

class User(Base):
    __tablename__ ="users"
    id = Column(Integer , primary_key=True , index=True , autoincrement=True)
    name = Column(String , nullable= False)
    role = Column(String , nullable=False)

class UserAuth(Base):
    __tablename__= "auth_users"
    id = Column(Integer , primary_key= True , index = True)
    username = Column(String , unique = True , index = True, nullable=False)
    hashed_password = Column(String , nullable = False)

class Devices(Base):
    __tablename__ ="devices"
    id = Column(Integer , primary_key= True , index= True)
    model_name = Column(String , nullable=False )
    model_no =Column(String , index= True)
    dev_status = Column(String , nullable=False)
    readings = relationship("DeviceReading" , back_populates="device")

class DeviceReading(Base):
    __tablename__ = "device_readings"
    id = Column(Integer , primary_key= True , index=True)
    device_id = Column(Integer , ForeignKey("devices.id") , nullable=False)
    value = Column( Float , nullable=False)
    timestamp = Column ( DateTime , default= datetime.utcnow)
    device = relationship("Devices" , back_populates="readings")
