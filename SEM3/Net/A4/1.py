from scapy.all import sniff
from scapy import packet


hostip = set()
sd = {}
pd = {}
def packet_analysis(pkt):
    # group tcp and udp packets according to their host and destination ip addresses
    host,dest=pkt["IP"].src,pkt["IP"].dst
    """
    if(host==None):
        print(pkt.show())
        """
    hostip.add(host) # to get the distinct host ip addresses
    if (host,dest) not in sd.keys():
        sd[(host,dest)] = {"TCP":[0,0],"UDP":[0,0]}
    if pkt.haslayer("TCP"):
        sd[(host,dest)]["TCP"][0] += 1
        # store sum of payload lengths. divide by number of payloads to get average length
        sd[(host,dest)]["TCP"][1] += len(pkt["TCP"].payload) 
    elif pkt.haslayer("UDP"):
        sd[(host,dest)]["UDP"][0] += 1
        sd[(host,dest)]["UDP"][1] += len(pkt["UDP"].payload)
    
def analysePort(pkt):
    # group tcp and udp packets according to their host, destination ip addresses alongwith their source and destination port numbers
    host,dest = pkt["IP"].src,pkt["IP"].dst
    if pkt.haslayer("TCP"):
        sport,dport = pkt["TCP"].sport,pkt["TCP"].dport
        if (host,dest,"TCP",sport,dport) not in pd.keys():
            pd[(host,dest,"TCP",sport,dport)] = [0,0]
        pd[(host,dest,"TCP",sport,dport)][0] += 1
        pd[(host,dest,"TCP",sport,dport)][1] += len(pkt["TCP"].payload)
    if pkt.haslayer("UDP"):
        sport,dport = pkt["UDP"].sport,pkt["UDP"].dport
        if (host,dest,"UDP",sport,dport) not in pd.keys():
                pd[(host,dest,"UDP",sport,dport)] = [0,0]
        pd[(host,dest,"UDP",sport,dport)][0] += 1
        pd[(host,dest,"UDP",sport,dport)][1] += len(pkt["UDP"].payload)
            
pkts = sniff(offline='packets.pcap',filter="tcp or udp",count=10000)#sniff 10000 packets from an offline save
for x in pkts:
    if not 'IP' in x:
        continue
    packet_analysis(x)
    analysePort(x)

print("Distinct Host IP addresses: ",len(hostip)," total")
for x in hostip:
    print(x)
print("\nSource IP|Destination IP|Protocol|Number Of Segments|Average Payload Length\n")
for k,v in sd.items():
    avgt = 0 if v['TCP'][0]==0 else v['TCP'][1]/v['TCP'][0]
    avgu = 0 if v['UDP'][0]==0 else v['UDP'][1]/v['UDP'][0]
    print(f"{k[0]:<34s}\t{k[1]:<34s}\tTCP\t{v['TCP'][0]:4d}\t{avgt:3.2f}")
    print(f"{k[0]:<34s}\t{k[1]:<34s}\tUDP\t{v['UDP'][0]:4d}\t{avgu:3.2f}")
print("\nSource IP|Destination IP|Protocol|Source Port|Destination Port|Number Of Segments|Average Payload Length\n")
for k,v in pd.items():
    avg = 0 if v[0]==0 else v[1]/v[0]
    print(f"{k[0]:<34s}\t{k[1]:<34s}\t{k[2]}\t{k[3]:10d}\t{k[4]:10d}\t{v[0]:4d}\t{avg:3.2f}")

