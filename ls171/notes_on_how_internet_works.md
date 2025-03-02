# What is the Internet? How does the Internet work?





So:

* Web browser
* URLs and URL encoding
* HTTP Request
* DNS lookup needed to map host to IP address for the Network layer IP packet header, or DNS cache
* We could mention TLS for HTTPS, or we could not
* Data encapsulation and network layers
* HTTP Request encapsulated as TCP segment, given a randomized Source port, Destination Port is generally a known port: port 80 for unencrypted HTTP, or port 443 for HTTPS (encrypted with TLS).
* TCP segment encapsulated as IP packet, source IP is known to our browser from the OS, the OS usually acquiring its IP address through DHCP (which is outside the scope). The Destination IP is usually gleaned from DNS lookup (or DNS cache)
* At each hop, the TCP segment is encapsulated in an Ethernet frame with an appropriate header and trailer. Each network hop's Ethernet header will have a Source MAC address, as well as a Destination MAC address gleaned from the device's ARP cache or, if not there, via ARP request.
* The initial network hop will be from the device on which the client is running to the local router (the default gateway). A PC or laptop's local routing table typically records its own IP address and the IP address of the home router, which are gleaned from the nearest DHCP server, normally running on the home router itself. All traffic not addressed to the host itself is routed via the default gateway. Since our packet is intended for the wider internet, it will have to pass through the home router. This means that our initial Ethernet header's destination MAC address is the MAC address of the home router.
* A mapping between the home router's IP address and its MAC address will be stored in the local host's ARP cache. If it does not yet exist, an ARP request is sent out with an Ethernet Destination MAC Address of the Ethernet Broadcast Address
* The home router generally maintains a pool of private IP addresses which are assigned to devices on the home network as they are connected to its interfaces. The router itself receives its public IP address from the ISP's DHCP server.
* On the local network, the Ethernet frame is sent through the switch. The switch maintains a MAC Address table that maps the switch's ports to the MAC addresses of the devices connected to those ports. When an Ethernet frame passes into the switch, the switch learns the MAC address from the Source MAC address in the frame header. If the switch has the Destination MAC address in its MAC Address Table, it forwards the frame through the correct port only; if the Destination MAC is not in the table, the switch floods the frame out of all ports. When a switch floods, every connected device except the Source MAC device will receive a copy of the frame, but the devices whose MAC address is not the Destination MAC address will simply drop the frame.
* Whether forwarded or flooded, the Ethernet frame reaches the home router. The router checks the checksum of the Ethernet frame (Wait, does an Ethernet frame have a checksum???? is it used????)  and then de-encapsulates the IP packet, since the original Ethernet header/trailer have reached their destination: the end of the first hop. The router then calculates the packet's next hop based on its routing table and encapsulates the IP packet in a new Data Link Layer PDU and the packet continues to the next router.
* After a series of hops across the Internet, where at each intermediate node the IP packet is de-encapsulated and re-encapsulated within a new Data Link Layer PDU for the journey to the next hop, the packet arrives at the router of the destination network.
* The destination network router de-encapsulates the packet and encapsulates it as the data payload of an Ethernet frame whose destination MAC address is that of the destination host. The frame is sent through the switch to the destination host.
* The destination host strips the Ethernet header and trailer. The IP packet may be checked for errors, or this may be left to the Transport layer (is this only IPv6 that requires checksum from Transport layer for error-checking????)
* The server host then de-encapsulates the TCP segment and checks it for errors using the checksum in the header. The TCP segment is processed and checked for duplication, and an Acknowledgement is sent back to the source port/IP address. If an earlier segment in the same sequence is missing, there will be a delay in processing until the missing segment is re-sent.
* The HTTP request is then de-encapsulated and if it has been split over multiple segments, the data for the request is reassembled in the correct order.
* The Web server then processes the request, possibly forwarding the request to the Application server if the request requires content to be generated.
* The Web server then sends the HTTP response including the stored or Application-server generated response body.
* The HTTP response is encapsulated into TCP segment(s), then into IP packet(s), then into Ethernet frame(s) for the journey to the client host, and the process repeats. What were the destination port and IP address are now the source port and IP address, and vice versa.