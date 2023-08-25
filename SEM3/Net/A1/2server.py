import socket

TCP_PORT = 5000
IP_ADDR = '127.0.0.1'
BUF_SIZE = 1024
k = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print("Server has created a port")
k.bind((IP_ADDR,TCP_PORT))
print("Server bound successfully")
k.listen(1)

while True:
	print("Server waiting for client")
	con, addr = k.accept()
	print("Connection address is ", addr)
	while True:
		data = con.recv(BUF_SIZE)
		print("Received expression: ",data.decode())
		if data.decode().lower() == "exit":
			msg="exit"
			con.send(msg.encode())#send exit back to client and break loop to wait for more clients
			break
		try:
			data=data.decode()
			if "{" in data or "}" in data or "[" in data or "]" in data: #since eval only works on python expressions, curly and square braces give improper result
				res="Only enter curved braces!" #send error message back to client
				con.send(res.encode())
			else:
				res = str(eval(data))
				res = "Result: "+res#send result back to client
				con.send(res.encode())
		except Exception as x:
			print(x)
			err = "Invalid integer expression: %s"%(x) #send exception back to client
			err=str(err)
			con.send(err.encode())
	print("Server closed!")
	con.close()
