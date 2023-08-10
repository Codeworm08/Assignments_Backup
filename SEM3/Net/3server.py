import socket
def getAddr(name):
    with open("student.txt") as f:
        data = f.readlines()
        for line in data:
            sname, addr = line.split(":")
            if sname==name:
                return addr
    return "Address not found!"
IP_ADDR='127.0.0.1'
UDP_PORT=5000
BUF_SIZE=1024
k=socket.socket(family=socket.AF_INET,type=socket.SOCK_DGRAM)
k.bind((IP_ADDR,UDP_PORT))
print("Waiting for connection...")
try:
    while True:
        con, addr = k.recvfrom(BUF_SIZE)
        name = con.decode()
        print("Received from client: ",name)
        if name == "exit":
            break
        address=getAddr(name)
        k.sendto(address.encode(),addr)
except Exception as e:
    print(e)
finally:
    print("Server closed...")
    k.close()