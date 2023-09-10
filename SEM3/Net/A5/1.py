#from scapy.all import Ether, IP, TCP
from scapy.all import IP, ICMP, send, sr1
import ipaddress
from time import sleep
networkAddress = input("Enter Network Address: ")
ipAd = ipaddress.ip_network(networkAddress, False)
timeout = int(input("Time to wait for reply in seconds:"))
hosts=[]
print("Sending ICMP packet to all hosts....")
for i in ipAd.hosts():
    #print(i)
    d=str(i)
    #print("Sending ICMP packet to ",d,"...")
    res=sr1(IP(dst=d)/ICMP()/"ABCD", verbose=False,timeout=timeout)
    print(res,i)
    if res:
        hosts.append(i)
print("Received reply from:")
for h in hosts:
    print(h)