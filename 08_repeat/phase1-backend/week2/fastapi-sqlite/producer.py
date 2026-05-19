import pika 
connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()
channel.queue_declare(queue='device_events')
channel.basic_publish(exchange='' ,routing_key='device_events' , body='Device Reading: temp=72' )
channel.basic_publish(exchange='' ,routing_key='device_events' , body='Second publish on the queue' )
connection.close()
print("Message Sent")