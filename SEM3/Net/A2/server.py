import socket
import threading
TCP_PORT = 5000
IP_ADDR = '127.0.0.1'
BUF_SIZE = 1024
def handle_client(con, addr):
    print("Connected with client: ",addr)
    while True:
        data = con.recv(BUF_SIZE)
        data = data.decode()
        if data.lower() == "quit":
            print(addr," disconnected")
            break
        print(f"Received from client {addr}: ",data)
        res="Received"
        con.send(res.encode())
    con.close()
k = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print("Server has created a port")
k.bind((IP_ADDR, TCP_PORT))
print("Server has bound successfully")
k.listen(5)
try:
    while True:
        con, addr = k.accept()
        cThread = threading.Thread(target=handle_client,args=(con, addr))
        cThread.start()
except Exception as e:
    print(f"Exception {e} occured.")
    print("Closing server.")
