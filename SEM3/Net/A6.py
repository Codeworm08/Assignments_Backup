from scapy.all import *
import re
def getArpCache():
    try:
        with open("/proc/net/arp","r") as arp_file:
            arp_cache = arp_file.read()            
    except FileNotFoundError:
        print("Error: /proc/net/arp does not exist")
        return None
    return arp_cache
def detectArpPoisoning(packet):
    cache = getArpCache()
    if cache is None:
        return
    ipAddrs=re.findall(r"(\d+\.\d+\.\d+\.\d+)",cache)
    macAddrs=re.findall(r"([0-9a-f]+\:[0-9a-f]+\:[0-9a-f]+\:[0-9a-f]+\:[0-9a-f]+\:[0-9a-f]+)",cache)
    c={}
    for ip,mac in zip(ipAddrs,macAddrs):
        c[ip]=mac
    if packet[ARP].psrc in c.keys():
        if not packet[ARP].hwsrc==c[packet[ARP].psrc]:
            print(f"ARP poisoning detected.{packet[ARP].psrc} physical address: {packet[ARP].hwsrc} does not match system cache {c[packet[ARP].psrc]}")
    print(packet[ARP].hwsrc,packet[ARP].psrc)
    
sniff(filter="arp",prn=detectArpPoisoning)