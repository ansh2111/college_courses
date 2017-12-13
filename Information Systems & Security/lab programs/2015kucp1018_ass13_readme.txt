IP SPOOFING:
        I used 3 systems to check for spoofing of packets.
        IP_ADD1:172.16.25.204 (My IP)
        IP_ADD2:172.16.25.109 
        IP_ADD3:172.16.25.90
        nmap command was used to spoof my ip with source IP_ADD2 and Destination ip IP_ADD3.
        Type these comamnds in terminal of 1:
        -> nmap  172.16.25.110
           It checks if victim host is up or not.
        -> Syntax: nmap -e <interface> -S <spoof_ipaddr> <victim_ipaddr>
 
           sudo nmap -e eno1 -S 172.16.25.109 172.16.25.90
           
           >>Output on Terminal of 1:
                Starting Nmap 7.01 ( https://nmap.org ) at 2017-11-10 12:06 IST
                NSOCK ERROR [0.2800s] mksock_bind_addr(): Bind to 172.16.25.109:0 failed (IOD #1): Cannot assign requested address (99)
                Nmap scan report for 172.16.25.90
                Host is up (0.00027s latency).
                All 1000 scanned ports on 172.16.25.90 are closed
                MAC Address: 64:00:6A:66:8E:B8 (Dell)

                Nmap done: 1 IP address (1 host up) scanned in 14.57 seconds

           
           Output of sudo tcpdump -p -i eth0 -n on Terminal of 2:
           		00:01:55.612896 IP 172.16.25.109.46668 > 172.16.25.90.1025: Flags [S], seq 1280523889, win 1024, options [mss 1460], length 0
				00:01:55.612927 IP 172.16.25.90.1025 > 172.16.25.109.46668: Flags [R.], seq 0, ack 1280523890, win 0, length 0
				00:01:55.612937 IP 172.16.25.109.46668 > 172.16.25.90.445: Flags [S], seq 1280523889, win 1024, options [mss 1460], length 0
				00:01:55.612940 IP 172.16.25.90.445 > 172.16.25.109.46668: Flags [R.], seq 0, ack 1280523890, win 0, length 0
				00:01:55.612944 IP 172.16.25.109.46668 > 172.16.25.90.80: Flags [S], seq 1280523889, win 1024, options [mss 1460], length 0
				00:01:55.612947 IP 172.16.25.90.80 > 172.16.25.109.46668: Flags [R.], seq 0, ack 1280523890, win 0, length 0
				00:01:55.612951 IP 172.16.25.109.46668 > 172.16.25.90.110: Flags [S], seq 1280523889, win 1024, options [mss 1460], length 0
				00:01:56.714099 IP 172.16.25.109.46668 > 172.16.25.90.143: Flags [S], seq 1280523889, win 1024, options [mss 1460], length 0
				00:01:56.714129 IP 172.16.25.90.143 > 172.16.25.109.46668: Flags [R.], seq 0, ack 1280523890, win 0, length 0
				00:01:56.714137 IP 172.16.25.109.46668 > 172.16.25.90.53: Flags [S], seq 1280523889, win 1024, options [mss 1460], length 0
				00:01:56.714141 IP 172.16.25.90.53 > 172.16.25.109.46668: Flags [R.], seq 0, ack 1280523890, win 0, length 0
				00:01:56.714144 IP 172.16.25.109.46668 > 172.16.25.90.139: Flags [S], seq 1280523889, win 1024, options [mss 1460], length 0
	
			We see only packets coming from IP_ADD2 which were sent by IP_ADD1 so spoofing is successfull.   
           
DNS SPOOFING:
        This process was done using instructions from the site  https://null-byte.wonderhowto.com/how-to/tutorial-dns-spoofing-0167796/
        
        Listening on(interface):
        eno1 -> 60:6D:C7:59:2A:CF
	          172.16.25.204/255.255.255.0
	          fe80::6e3e:572c:507c:6e0b/64

        Ettercap might not work correctly. /proc/sys/net/ipv6/conf/all/use_tempaddr is not set to 0.
        Ettercap might not work correctly. /proc/sys/net/ipv6/conf/wlp6s0/use_tempaddr is not set to 0.
        Privileges dropped to EUID 65534 EGID 65534...

          33 plugins
          42 protocol dissectors
          57 ports monitored
        20388 mac vendor fingerprint
        1766 tcp OS fingerprint
        2182 known services
        Lua: no scripts were specified, not starting up!
        Starting Unified sniffing...

        Unified sniffing was stopped.
        Randomizing 255 hosts for scanning...
        Scanning the whole netmask for 255 hosts...
        99 hosts added to the hosts list...
        Host 172.16.25.204 added to TARGET1
        Host 172.16.25.1 added to TARGET2

        ARP poisoning victims:

         GROUP 1 : 172.16.25.204 4C:BB:58:D5:5C:A1

         GROUP 2 : 172.16.25.1 00:04:96:1D:E4:00
        Activating dns_spoof plugin...
                   
           

           
