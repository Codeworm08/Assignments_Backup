import socket

IP_ADDR = '127.0.0.1'
UDP_PORT = 8001
BUF_SIZE = 1024
k = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
data = input("Enter data to send: ")
k.sendto(data.encode(), (IP_ADDR, UDP_PORT))
k.close()