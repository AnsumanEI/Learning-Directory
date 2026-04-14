import sqlite3
from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
from pydantic import BaseModel
from fastapi import Header , HTTPException , Request
from jose import JWTError # type: ignore # For handling JWT errors
from jose import jwt # type: ignore # For encoding and decoding JWTs
from datetime import datetime, timedelta # For handling token expiration
from fastapi.responses import JSONResponse

# Path to the SQLite database file on disk
# SQLite is just a file — no separate server needed
DB_PATH = "users.db"

app = FastAPI()

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_methods =["*"],
    allow_headers=["*"]
)

# def init_db():
#     # Open (or create) the database file
#     conn = sqlite3.connect(DB_PATH)
#     # Cursor is the object that runs SQL queries — like a pen
#     cursor = conn.cursor()
#     # Create the users table only if it doesn't already exist
#     # AUTOINCREMENT — SQLite auto-assigns id: 1, 2, 3... we never pass it manually
#     # NOT NULL — name and role cannot be empty
#     cursor.execute("""
#         CREATE TABLE IF NOT EXISTS users (
#             id INTEGER PRIMARY KEY AUTOINCREMENT,
#             name TEXT NOT NULL,
#             role TEXT NOT NULL
#         )
#     """)
#     # commit() saves changes permanently to disk
#     conn.commit()
#     # Always close the connection when done
#     conn.close()
# Pydantic model — defines what the client must send in POST body
# No id here — SQLite generates it automatically
class UserIn(BaseModel):
    name: str
    role: str


# Run init_db() once at server startup to ensure table exists
#init_db()

API_KEY = "secret123"# A simple API key for authentication (in production, use a more secure method!)
SECRET_KEY = "supersecetkey"# Secret key for signing JWTs (keep this safe in production!)
ALGORITHM = "HS256"# The algorithm used to sign the JWTs
ACCESS_TOKEN_EXPIRE_MINUTES = 30# Token expires after 30 minutes

@app.middleware("http")
async def log_requests(request : Request , call_next):
    print(f"incoming: {request.method} -> {request.url}")
    response = await call_next(request)
    print(f"completed: {response.status_code}")
    return response

def create_access_token(data: dict):# A helper function to create a JWT access token
    to_encode = data.copy()# Create a copy of the data to encode in the token
    expire = datetime.utcnow() + timedelta(minutes=ACCESS_TOKEN_EXPIRE_MINUTES)# Set the token to expire in 30 minutes
    to_encode.update({"exp": expire})# Add the expiration time to the token data
    encoded_jwt = jwt.encode(to_encode, SECRET_KEY, algorithm=ALGORITHM)# Encode the token using the secret key and algorithm
    return encoded_jwt

def verify_api_key(x_api_key: str = Header()):   # A helper function to check the API key in request headers
    if x_api_key != API_KEY:
        raise HTTPException(status_code=401, detail="Invalid API Key")
    

def verify_token(token:str):
    try:# Try to decode the token and extract the username
        payload = jwt.decode(token, SECRET_KEY, algorithms=[ALGORITHM])# Decode the token using the secret key and algorithm
        username = payload.get("sub")  # The "sub" (subject) field in the token should contain the username we set when creating the token
        if username is None:# If the username is missing, the token is invalid
            raise HTTPException(status_code=401, detail="Invalid token")
        return username
    except JWTError:# If there's an error decoding the token (e.g., expired, invalid signature), it's not valid
        raise HTTPException(status_code=401, detail="Invalid token")

@app.get("/protected")
def protected_route(token:str):
    username = verify_token(token)  # Check the token and get the username
    return {"message": f"Hello, {username}! You have access to this protected route."}# Return a personalized message if the token is valid

@app.post("/login")
def login(username: str, password: str):
    # In a real application, you would verify the username and password against a database
    if username == "admin" and password == "password":
        access_token = create_access_token(data={"sub": username})# Create a JWT token with the username as the subject
        return {"access_token": access_token, "token_type": "bearer"}# Return the token to the client
    else:
        raise HTTPException(status_code=401, detail="Invalid username or password")

@app.post("/users")
def create_user(user: UserIn  , x_api_key: str = Header()):
    verify_api_key(x_api_key)  # Check API key before creating a user
    conn = sqlite3.connect(DB_PATH)
    cursor = conn.cursor()
    # ? are placeholders — never put variables directly in SQL strings (SQL injection risk)
    # sqlite3 safely replaces ? with the actual values
    cursor.execute(
        "INSERT INTO users (name, role) VALUES (?, ?)",
        (user.name, user.role)
    )
    conn.commit()
    # lastrowid gives us the auto-generated id of the row just inserted
    new_id = cursor.lastrowid
    conn.close()
    # Return the full user object including the new id
    return {"id": new_id, "name": user.name, "role": user.role}

@app.get("/users")
def get_users(x_api_key: str = Header()):
    verify_api_key(x_api_key)  # Check API key before accessing the database
    conn = sqlite3.connect(DB_PATH)
    cursor = conn.cursor()
    cursor.execute("SELECT id, name, role FROM users")
    # fetchall() returns a list of tuples: [(1, 'Ansu', 'backend-engineer'), ...]
    rows = cursor.fetchall()
    conn.close()
    # Convert each tuple to a dict so FastAPI can return it as JSON
    # r[0]=id, r[1]=name, r[2]=role — order matches the SELECT columns
    return [{"id": r[0], "name": r[1], "role": r[2]} for r in rows]

@app.exception_handler(Exception)
async def global_exception_handler(request: Request , exc : Exception):
    return JSONResponse(
        status_code=500,
        content={"error": "something went wrong" , "detail" : str(exc)}
    )
