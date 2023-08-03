from datetime import datetime
import socket
now = datetime.now()
TCP_PORT = 5000
IP_ADDR = '127.0.0.1'
BUF_SIZE = 1024
k = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print("Server has created a port")
k.bind((IP_ADDR, TCP_PORT))
print("Server has bound successfully")
k.listen(1)
print("Server waiting for a connection")
con, addr = k.accept()
print('Connection address is: ',addr)
dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
msg = f"date and time={dt_string}".encode()
con.send(msg)
con.close()