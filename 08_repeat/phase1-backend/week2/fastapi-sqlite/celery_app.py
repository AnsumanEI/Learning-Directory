from celery import Celery

celery = Celery(
    "worker",#normal name
    broker="redis://redis:6379/0", #where celery sends the tasks redis
    backend="redis://redis:6379/0", # where it stores the tasks also redis
    include=["tasks"] # tell celery to add tasks / import tasks no reliable
    #/0 means the db redis has 16 db  we use 0 by default
)