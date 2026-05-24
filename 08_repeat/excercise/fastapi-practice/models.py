from sqlalchemy import String , Column ,Integer
from database import Base 


class UserData(Base):
    __tablename__ = "users"
    id = Column(Integer , index=True,primary_key=True ,nullable=False)
    name = Column(String ,nullable=False)
    role = Column(String , nullable=False)

class UserAuth(Base):
    __tablename__="auth_users"
    id = Column(Integer , primary_key=True , index=True )
    username = Column(String ,unique=True , index=True)
    hashed_password = Column(String , nullable=False)

class Device(Base):
    __tablename__ ="devices"
    id = Column(Integer , primary_key=True ,index=True)
    model_name = Column(String  , nullable=False)
    model_no = Column(String , index=True ,nullable=False)
    dev_status = Column(String , nullable=False)
