#from scapy.all import Ether, IP, TCP
from scapy.all import IP, ICMP, send, sr1
import ipaddress
from time import sleep
networkAddress = input("Enter Network Address: ")
ipAd = ipaddress.ip_network(networkAddress, False) #Convert input address to ipaddress object to find all hosts
timeout = int(input("Time to wait for reply in seconds:")) #timeout for reply
hosts=[]
print("Sending ICMP packet to all hosts....")
for i in ipAd.hosts():    #iterate through all hosts
    d=str(i)    #since sr1 accepts string
    res=sr1(IP(dst=d)/ICMP()/"ABCD", verbose=False,timeout=timeout)
    if res: # if res is not none reply received before timeout
        hosts.append(i)
print("Received reply from:")
for h in hosts:
    print(h)