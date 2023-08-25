import socket
TCP_PORT = 5000
IP_ADDR = '127.0.0.1'
BUF_SIZE = 1024
k = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
k.connect((IP_ADDR,TCP_PORT))
while True:
    ch=str(input("Enter date:Get current date and time. quit:Close connection "))
    k.send(ch.encode())
    data = k.recv(BUF_SIZE)
    if data.decode() == "quit":
        break
    print(data.decode())
        
print("Client disconnected")

k.close()