To perform DOS and DDOS attacks on a system by CLI and by any tool.

DOS
In computing, a denial-of-service attack (DoS attack) is a cyber-attack where the perpetrator seeks to make a machine or network resource unavailable
to its intended users by temporarily or indefinitely disrupting services of a host connected to the Internet.

Command used for DOS attack:
	ping <Victim_IP_Address> -t -s 65530
	The potions –s  is used to specify the amount of data sent with each packet and –t is used to continue pinging until the host times out.

Tool Used:
	Tor's Hammer is a tool that uses the slow body attack to swamp Apache servers and cause a denial of service DoS. 
	It does this by sending a POST request with a large declared content-length (like 1000 MB), then performing the following,
	ad infinitum: send one letter through the open connection; take a nap.
	Tor's Hammer, in particular, provides a Python script that enables running the slow body attack through a web proxy like Tor, to provide anonymity. 
	It also implements other disguising elements like a slew of User Agent headers.


DDOS
A distributed denial-of-service (DDoS) is a cyber-attack where the perpetrator uses more than one unique IP address, often thousands of them. 
The incoming traffic flooding the victim originates from many different sources. 
This effectively makes it impossible to stop the attack simply by using ingress filtering. 
It also makes it very difficult to distinguish legitimate user traffic from attack traffic when spread across so many points of origin.
	
This attack was performed by me with Puneet and Tanmay in the lab:
Command:
	ping <Victim_IP_Address> -t -s 65530
Tool:
	Tor's Hammer--	If you are going to run it with Tor it assumes you are running Tor on 127.0.0.1:9050. 
	It kills most unprotected web servers running Apache and IIS via a single instance. 
	It kills Apache 1.X and older IIS with ~128 threads, newer IIS and Apache 2.X with ~256 threads.