from celery_app import celery
import time

@celery.task #registers this function as a celery task that means it will workk in the background
def send_notification(device_id :int):
    print(f"sending notifications for device {device_id}...")
    time.sleep(2) #simulation twilio external call
    print(f"Notification send for the device {device_id}")
    return f"Done for device {device_id}"