import socket
def getAddr(name):
    with open("student.txt") as f:
        data = f.readlines()
        for line in data:
            sname, addr = line.split(":")#split the line in student file using : and unpack the name and address into separate variables
            if sname==name:
                return addr
    return "Address not found!"
IP_ADDR='127.0.0.1'
UDP_PORT=5000
BUF_SIZE=1024
k=socket.socket(family=socket.AF_INET,type=socket.SOCK_DGRAM)#create a udp socket using IPv4 addressing
k.bind((IP_ADDR,UDP_PORT))
print("Waiting for connection...")
try:
    while True:
        con, addr = k.recvfrom(BUF_SIZE)
        name = con.decode()
        print("Received from client: ",name)
        address=getAddr(name)
        k.sendto(address.encode(),addr)#send the address or not found message to client
except Exception as e:
    print(e)
    print("Server closed...")
    k.close()
