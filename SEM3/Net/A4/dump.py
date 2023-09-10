#save for offline capture
from scapy.all import sniff,wrpcap
capture = sniff(filter="", count=10000)
wrpcap("packets.pcap",capture)
