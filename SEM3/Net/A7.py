from scapy.all import IP, ICMP, sr1
def traceroute():
    max_hops = int(input("Enter maximum number of hops: "))
    destip = input("Enter Destination IP Address")
    for i in range(1,max_hops+1):
        packet = IP(dst=destip,ttl=i)/ICMP()
        reply = sr1(packet, timeout=1, verbose=False)
        if reply is None:
            print("*")
        elif reply[ICMP].type==0: #Echo reply
            print(f"Destination Reached: {reply[IP].src}")
            break
        elif reply[ICMP].type==11: #Time Limit Exceeded
            print(f"Packet reached an intermediate router: {reply[IP].src}")
traceroute()