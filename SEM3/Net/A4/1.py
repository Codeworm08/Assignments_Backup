from scapy.all import sniff
from scapy import packet

def capture():
    hostip = set()
    sd = {}
    pd = {}
    def packet_analysis(pkt):
        host,dest=pkt["IP"].src,pkt["IP"].dst
        if(host==None):
            print(pkt.show())
        hostip.add(host)
        if (host,dest) not in sd.keys():
            sd[(host,dest)] = {"TCP":[0,0],"UDP":[0,0]}
        if pkt.haslayer("TCP"):
            sd[(host,dest)]["TCP"][0] += 1
            sd[(host,dest)]["TCP"][1] += len(pkt["TCP"].payload)
        elif pkt.haslayer("UDP"):
            sd[(host,dest)]["UDP"][0] += 1
            sd[(host,dest)]["UDP"][1] += len(pkt["UDP"].payload)
    pkts = sniff(filter="tcp or udp",count=1000)
    def analysePort(pkt):
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
    for x in pkts:
        if not 'IP' in x:
            continue
        packet_analysis(x)
        analysePort(x)

    print("Distinct Host IP addresses: ",len(hostip)," total")
    for x in hostip:
        print(x)
    print("Source IP\tDestination IP\tProtocol\tNumber Of Segments\tAverage Payload Length")
    for k,v in sd.items():
        avgt = 0 if v['TCP'][0]==0 else v['TCP'][1]/v['TCP'][0]
        avgu = 0 if v['UDP'][0]==0 else v['UDP'][1]/v['UDP'][0]
        print(f"{k[0]}\t{k[1]}\tTCP\t{v['TCP'][0]}\t{avgt}")
        print(f"{k[0]}\t{k[1]}\tUDP\t{v['UDP'][0]}\t{avgu}")
    print("Source IP\tDestination IP\tProtocol\tSource Port\tDestination Port\tNumber Of Segments\tAverage Payload Length")
    for k,v in pd.items():
        avg = 0 if v[0]==0 else v[1]/v[0]
        print(f"{k[0]}\t{k[1]}\t{k[2]}\t{k[3]}\t{k[4]}\t{v[0]}\t{avg}")
capture()