import socket

TCP_PORT = 5000
IP_ADDR = '127.0.0.1'
BUF_SIZE = 1024
k = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print("Server has created a port")
k.bind((IP_ADDR,TCP_PORT))
print("Server bound successfully")
k.listen(1)
print("Server waiting for client")
con, addr = k.accept()
print("Connection address is ", addr)
data = con.recv(BUF_SIZE)
print("Received expression: ",data.decode())
try:
	res = str(eval(data))
	res = "Result: "+res
	con.send(res.encode())
except Exception as x:
	print(x)
	err = "Invalid integer expression: %s"%(x)
	err=str(err)
	con.send(err.encode())
finally:
	con.close()
