import pika
connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()
channel.queue_declare('device_events')#not needed but what if we call consumer first so without the queue existing this will crash so better let it stay . it will be like a safety net
channel.queue_declare('new_device_event')
def callback(ch , method , properies ,body): #body is in bytes so decode
    print(f"Recieved: {body.decode()}")

#telling rabbitmq to call callback function 

#channel.basic_consume(queue='device_events' , on_message_callback=callback , auto_ack=True)

channel.basic_consume(queue='new_device_event' , on_message_callback=callback , auto_ack=True)
# auto ack means tell mq i got the message remove from queue

channel.start_consuming() #sits and waits for message like a loop