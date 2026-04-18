from sqlalchemy import Column , Integer ,String
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

