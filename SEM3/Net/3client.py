import socket
IP_ADDR='127.0.0.1'
UDP_PORT=5000
BUF_SIZE=1024
k=socket.socket(family=socket.AF_INET,type=socket.SOCK_DGRAM)
while True:
    name = input("Enter student name:")
    if name.lower() == "exit":
        k.sendto(name.encode(),(IP_ADDR,UDP_PORT))
        break
    k.sendto(name.encode(),(IP_ADDR,UDP_PORT))
    data,_ = k.recvfrom(BUF_SIZE)
    print(data.decode())
k.close()