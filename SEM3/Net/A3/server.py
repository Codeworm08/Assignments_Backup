import socket

IP_ADDR = '127.0.0.1'
UDP_PORT = 8001
BUF_SIZE = 1024
k = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
print("Server created")
k.bind((IP_ADDR, UDP_PORT))

while True:
    con, addr = k.recvfrom(BUF_SIZE)
    print("Connected with: ",addr)
    print(con.decode())
    