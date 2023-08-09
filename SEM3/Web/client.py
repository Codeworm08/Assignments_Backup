# Client code
import socket
import threading
def read_messages(c):
        while True:
            data = c.recv(1024)
            data = data.decode()
            if data == "[e]":
                 c.send(data.encode())
                 break
            print("Server says:", data)            
def write_messages(c):
    while True:
        mssg = input()
        c.send(mssg.encode())
        if mssg == "[e]":
            break

def main():

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(("127.0.0.1", 8000))
    read_thread = threading.Thread(target=read_messages, args=(client_socket,))
    write_thread = threading.Thread(target=write_messages, args=(client_socket,))
    
    read_thread.start()
    write_thread.start()

    read_thread.join()
    write_thread.join()
    client_socket.close()
if __name__=="__main__":
    main()
