from scapy.all import IP,TCP,ICMP, send, sr1
import ipaddress
ip = input("Enter IP address: ")
timeout = int(input("Timeout in seconds:"))
ports=[_ for _ in range(1024)]
for port in ports:
    res = sr1(IP(dst=ip)/TCP(dport=port, flags='S'),timeout=timeout,verbose=False)
    if res and res[TCP].flags == 'SA':
        print("Port ",port," is open")
