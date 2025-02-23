## The Internet

- Have a broad understanding of what the internet is and how it works
- Understand the characteristics of the physical network, such as latency and bandwidth
- Have a basic understanding of how lower level protocols operate
- Know what an IP address is and what a port number is
- Have an understanding of how DNS works
- Understand the client-server model of web interactions, and the role of HTTP as a protocol within that model

## TCP & UDP

- Have a clear understanding of the TCP and UDP protocols, their similarities and differences
- Have a broad understanding of the three-way handshake and its purpose
- Have a broad understanding of flow control and congestion avoidance

## URLs

- Be able to identify the components of a URL, including query strings
- Be able to construct a valid URL
- Have an understanding of what URL encoding is and when it might be used

## HTTP and the Request/Response Cycle

- Be able to explain what HTTP requests and responses are, and identify the components of each
- Be able to describe the HTTP request/response cycle
- Be able to explain what status codes are, and provide examples of different status code types
- Understand what is meant by 'state' in the context of the web, and  be able to explain some techniques that are used to simulate state
- Explain the difference between `GET` and `POST`, and know when to choose each
- Have a basic understanding of the asynchronous nature of AJAX, and the kinds of features that it enables for web apps.

## Security

- Have an understanding of various security risks that can affect  HTTP, and be able to outline measures that can be used to mitigate  against these risks
- Be aware of the different services that TLS can provide, and have a broad understanding of each of those services

---

# Notes #

Things that immediately jump out to review:

* latency - elements of latency, references to this are scattered through the second half in relation to things like HOL blocking, evolution of network technology, etc
* TCP vs UDP similarities and differences
* understanding of how DNS works - not much detail on this as I can remember
* URL encoding
* components of HTTP requests and HTTP responses
* status codes
* Understand 'state' in the context of the web and be able to explain some techniques that are used to simulate state
* Explain differences between `GET` and `POST` and know when to choose each
* Basic understanding of the asynchronous nature of AJAX, and the kinds of features that it enables for web apps
* Security risks of HTTP and measures to mitigate against them
* TLS services (encryption, authentication, integrity)

* DNS - this is discussed in the HTTP book in the `Background` page. `6:4 Web Performance and HTTP Optimizations` has a section on DNS optimizations. `6:6 Peer to Peer Networking` mentions DNS in passing because peers do not have a fixed IP address which a DNS hostname can map to. The suggestion being that DNS maps to fixed, stable addresses, not to the transitory IP addresses of peers in a typical P2P network. So DNS is related to the server-based model of networking.

* How the internet works -- in the HTTP book, Background page

'The Internet consists of millions of interconnected networks that allow all sorts of computers and devices to communicate with each other. By convention, all devices that participate in a network are provided unique labels. The general term for this type of label is an IP Address (Internet Protocol Address). An IP address is like a computer's phone number on the Internet. Port numbers add more detail about how to communicate (think of company phone extensions). IP Addresses are represented as: `192.168.0.1`. When a port number is needed the address is specified as `192.168.0.1:1234` where the IP Adress is `192.168.0.1` and the port number is `1234`. An IP Address acts as the identifier for a device or server, which can contain hundreds or thousands of ports, each used for a different communication purpose to that device or server.

When it comes to the wider Internet, effective communication begins when each device has a public IP address provided by an Internet Service Provider. However, when we wish to connect to a resource like Google, we type in a URL, not an IP address. How does the computer map `www.google.com` to the appropriate IP address?' - goes on to talk about DNS under a new heading.

So this section follows on from A Brief Overview and History, which begins with the web browser and typing in a URL. Client-Server nature of HTTP. Webpages consist of HTML, CSS, JS, and media resources of various kinds. HTTP is introduced, brief history.

'This chapter covered an oversimplified interpretation of how the Internet works along with an explanation of a few key terms'

So it covered

* Web browser - client
* HTTP and history of HTTP
* Network of networks - one sentence stand-in for Physical and Link layers - What the Internet IS
* IP addresses
* TCP ports
* DNS (only description of this in LS170)
* Client and server (web server)
* Resources

Also mentions Statelessness but excludes this from 'how the internet works' topics

So the Internet here really means the internet connection between networks. Ethernet and physical medium are both taken for granted (although even out on the internet's routers, each hop still requires a new L2 header etc and obviously physical connections between routers)



So we essentially have two questions:

* What is the Internet - a network of networks that consists of both the network infrastructure (physical devices, wires, radio transmitters, etc) and the protocols that govern and facilitate internetwork communication (Ethernet, IP, TCP, etc)
* How does the internet work? - use HTTP as application layer example. Follow the request down through the layers including a DNS lookup. Then follow its deencapsulation at the other end.



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

