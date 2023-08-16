import socket

TCP_PORT = 5000
IP_ADDR = '127.0.0.1'
BUF_SIZE = 1024
k = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
k.connect((IP_ADDR,TCP_PORT))
try:
    while True:
        data = input("Enter data")
        k.send(data.encode())
        if data.lower() == "quit":
            break
        
except Exception as e:
    print(f"Exception {e} occured.\nClosing client")
k.close()