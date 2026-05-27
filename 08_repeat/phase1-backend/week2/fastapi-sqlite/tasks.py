from celery_app import celery
import time

@celery.task #registers this function as a celery task that means it will workk in the background
def send_notification(username:str):
    print(f"sending notifications for device {username}...")
    time.sleep(2) #simulation twilio external call
    print(f"Notification send for the device {username}")
    return f"Done for device {username}"