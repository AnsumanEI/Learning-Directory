from fastapi import FastAPI,Request 
from fastapi.responses import JSONResponse
from fastapi.middleware.cors import CORSMiddleware
from app.routers import devices , users
from app.database import create_table

app = FastAPI()
app.include_router(users.router)
app.include_router(devices.router)

@app.on_event("startup")
def startup_events():
    create_table()

@app.get("/health")
def health():
    return {"status":"ok"}

app.add_middleware(
    CORSMiddleware,
    allow_methods= ["*"],
    allow_headers= ["*"],
    allow_origins= ["*"],
)

@app.middleware("http")
async def log_requests(request : Request , call_next ):
    print(f"incoming->{request.method}->{request.url}")
    response = await call_next(request)
    print(f"Completed:{response.status_code}")
    return response

@app.exception_handler(Exception)
def global_exception_handler(request : Request ,exc: Exception):
    return JSONResponse(
        status_code=500 , content={"detail": str(exc) , "Request": f"{request.method}->{request.url}"}
    )

