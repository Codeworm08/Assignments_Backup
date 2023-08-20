import socket
TCP_PORT = 5000
IP_ADDR = '127.0.0.1'
BUF_SIZE = 1024
k = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
k.connect((IP_ADDR,TCP_PORT))
print("Client sent connection request")
while True:
    exp = input("Enter integer arithmetic expression:")
    k.send(exp.encode())    
    res = k.recv(BUF_SIZE)
    if res.decode().lower()=="exit":#client closed if exit received from server
        break
    print(res.decode())
print("Client disconnected")
k.close()