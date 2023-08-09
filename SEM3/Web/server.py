import socket
import threading

def read_messages(connection):
    while True:        
        data = connection.recv(1024)
        data = data.decode()
        if data == "[e]":
            connection.send(data.encode())
            break
        print("Received:", data)
        
def write_messages(connection):
        while True:
            message = input()
            connection.send(message.encode())
            if message == "[e]":
                break
def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(("127.0.0.1", 8000))
    server_socket.listen(1)        
    connection, address = server_socket.accept()
    print("Received connection from", address)
    read_thread = threading.Thread(target=read_messages, args=(connection,))
    write_thread = threading.Thread(target=write_messages, args=(connection,))

    read_thread.start()
    write_thread.start()

    read_thread.join()
    write_thread.join()
    server_socket.close()
if __name__=="__main__":
     main()
