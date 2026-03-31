import sqlite3
from fastapi import FastAPI
from pydantic import BaseModel

# Path to the SQLite database file on disk
# SQLite is just a file — no separate server needed
DB_PATH = "users.db"

def init_db():
    # Open (or create) the database file
    conn = sqlite3.connect(DB_PATH)
    # Cursor is the object that runs SQL queries — like a pen
    cursor = conn.cursor()
    # Create the users table only if it doesn't already exist
    # AUTOINCREMENT — SQLite auto-assigns id: 1, 2, 3... we never pass it manually
    # NOT NULL — name and role cannot be empty
    cursor.execute("""
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            role TEXT NOT NULL
        )
    """)
    # commit() saves changes permanently to disk
    conn.commit()
    # Always close the connection when done
    conn.close()

# Pydantic model — defines what the client must send in POST body
# No id here — SQLite generates it automatically
class UserIn(BaseModel):
    name: str
    role: str

app = FastAPI()
# Run init_db() once at server startup to ensure table exists
init_db()

@app.post("/users")
def create_user(user: UserIn):
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
def get_users():
    conn = sqlite3.connect(DB_PATH)
    cursor = conn.cursor()
    cursor.execute("SELECT id, name, role FROM users")
    # fetchall() returns a list of tuples: [(1, 'Ansu', 'backend-engineer'), ...]
    rows = cursor.fetchall()
    conn.close()
    # Convert each tuple to a dict so FastAPI can return it as JSON
    # r[0]=id, r[1]=name, r[2]=role — order matches the SELECT columns
    return [{"id": r[0], "name": r[1], "role": r[2]} for r in rows]