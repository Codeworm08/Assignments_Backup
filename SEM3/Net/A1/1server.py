from datetime import datetime
import socket
now = datetime.now()
TCP_PORT = 5000
IP_ADDR = '127.0.0.1'
BUF_SIZE = 1024
k = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #create tcp socket which uses ipv4 addressing
print("Server has created a port")
k.bind((IP_ADDR, TCP_PORT))
print("Server has bound successfully")
k.listen(1)#Listen for incoming client connections

while True:
    con, addr = k.accept()
    print('Connection address is: ',addr)
    while True:
    
        data = con.recv(BUF_SIZE).decode()
        if data == "date":
            dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
            msg = f"date and time={dt_string}".encode() #send formatted date and time to client
            con.send(msg)
        if data == "quit":# to exit loop and wait for another client
            msg = "quit"
            con.send(msg.encode())
            break
