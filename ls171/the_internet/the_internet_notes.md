## The Internet

- Have a broad understanding of what the internet is and how it works
- Understand the characteristics of the physical network, such as latency and bandwidth
- Have a basic understanding of how lower level protocols operate
- Know what an IP address is and what a port number is
- Have an understanding of how DNS works
- Understand the client-server model of web interactions, and the role of HTTP as a protocol within that model



## **<u>Have a broad understanding of what the internet is and how it works</u>**

1:1 - "As we progress through the course we will look to build a mental model of communication between networked applications as the interaction of multiple different protocols (systems of rules)."

"In the next assignment [actually 1:4 rather than 1:2], we'll learn a bit more about what the internet is and how it is structured"



<u>1:4: **What is the Internet?**</u>

"the internet as a 'network of networks'"

**What is a network?**

Two or more devices connected in such a way that they can communicate or exchange data.

**Local Area Network (LAN)**

Simplest network topology would be two computers connected via a LAN cable. Using a hub, we could connected several computers, albeit in an inefficient way.

In a typical office environment, multiple computers and other devices connected via cables to a network switch and this topography forms a LAN.

A home network follows the same principle, but the switch often permits wireless connection in addition to Ethernet cables. This implementation is known as WLAN, Wireless LAN.

* LAN: **"The key thing to understand here is that the scope of communication is limited to devices that are connected (either wired or wirelessly) to the network switch or hub, which imposes some geographic limitations. That's the 'local' in Local Area Network."**

**Inter-network Communication**

"In order to enable communication between networks, we need to add routers into the picture"

* Routers are network devices that can route network traffic to other networks
* Within a LAN, they act as gateways into and out of the network

**A Network of Networks**

"We can imagine the internet as a vast number of these networks connected together. In between all of the sub-networks are systems of routers that direct the network traffic"

"The actual network topology of the overall network is a bit more complex than that, but in terms of having a mental model on which to build more abstract networking concepts it should suffice"



<u>1:5 **Protocols**</u>

* Makes the point that protocols allow devices and software from a variety of vendors to communicate with each other in a standardized way
* A computer network protocol is a set of rules that govern the exchange or transmission of data
* Why are there so many protocols?
  1. Different protocols were developed to address different aspects of network communication
  2. Different protocols were developed to address the same aspect of network communication but differently for a specific use case
* TCP and UDP address the same fundamental aspect of network communication: the transfer of messages between applications. TCP and HTTP address different aspects of communication; TCP provides for the transfer of messages between applications, while HTTP defines the structure of those messages



1:6 **<u>A Layered System</u>**

"It can be useful to group protocols together in terms of the particular aspect of communication that they address. Furhtermore, we can think of those protocol groups as functioning within *layers* of an overall system of communication"

Discusses OSI and TCP/IP models, data encapsulation, PDUs, payload and metadata etc

**Lesson 1 Summary**

* The internet is a vast *network of networks*. It is comprised of both the *network infrastructure* itself (devices, routers, switches, cables, etc) and the *protocols* that enable that infrastructure to function.
* Protocols are *systems of rules*. Network protocols are systems of rules governing the exchange or transmission of data over a network.
* Different types of protocol are concerned with different aspects of network communication. It can be useful to think of these different protocols as operating at particular 'layers' of the network
* *Encapsulation* is a means by which protocols at different network layers can work together.
* Encapsulation is implemented through the use of *Protocol Data Units* (PDUs). The PDU of a protocol at one layer becomes the data payload of the PDU at a lower layer

 3:1 **<u>What to Focus On</u>**

* Develop a clear understanding of the role of HTTP -- try and build a picture of the functioning of the web as a combination of multiple different technologies, a combination within which HTTP has a specific role
  * HTTP, URLs, HTML -- the three big Web technologies that defined the Web at its inception
  * DNS needed (like a lot of internet services)
  * TLS (/SSL) -- introduced to add security as the Web expanded and commercialized
  * JavaScript and CSS -- added functionality and expanded style options
  * AJAX, Cookies, etc
* Break things down into individual components -- ensure clarity within your mental models by breaking concepts like HTTP and URLs into specific components, and understanding the purpose of each of those components
  * URL -- structure of URL, query parameters, host etc
  * HTTP -- less sure what this means
    * HTTP is a client-server protocol
    * HTTP is a request-response protocol
    * HTTP is a connectionless protocol
    * HTTP is a stateless protocol



3:2 **<u>The Application Layer</u>**

* The Application layer is not the application itself, but rather a set of protocols which provide communication services to applications
* The Application layer is the layer with which networked applications typically interact the most
  * Networked applications also interact with the Transport layer, though not typically with layers below Transport
* Lower level protocols are mainly concerned with the establishment and flow of communications, the rules around how messages get from one point to another
* Application layer protocols are concerned with the structure of a message and what data it should contain
  * Application layer protocols rely on the protocols at the layers below them to ensure that a message gets to where it is supposed to, and do not need to concern themselves with it
* We can think of Application layer protocols as the rules for how applications talk to each other at a syntactical level
  * Different types of applications have different requirements with regards to how they communicate at a syntactical level, and so as a result there are many different protocols which exist at the application layer
  * E.g., the rules for how an email client communicates with an email server will be different from the rules for how a web browser communicates with a web server, because emails and web pages are fundamentally different things serving different purposes



3:3 **<u>HTTP and the Web</u>**

* HTTP is the primary protocol used for communication on the Web
* The *Internet* is essentially a network of networks. It can be thought of as the infrastructure that enables inter-network communication, both in terms of the physical network and the lower-level protocols that control its use
* The World Wide Web is a **service** that can be accessed via the Internet
  * The Web is a vast information system comprised of **resources** which are navigable by means of a **URL** (Universal Resource Locator)
* HTTP is closely tied, both historically and functionally, to the web as we know it
  *  HTTP is the primary means by which applications interact with the resources which make up the web

**<u>A Brief History of the Web</u>**

* The Web was conceived at CERN in 1989 by Tim Berners-Lee, and later formalized as a proposal in 1990 by Berners-Lee and his colleague, Robert Cailliau
* The problem Berners-Lee identified at CERN was that CERN had information spread over many computer systems in many countries, and that accessing this information required different methods from system to system
* Berners-Lee's idea was to create a uniform system for accessing information resources over the internet, and these resources could be structured in a uniform way via Hypertext. The resources could all be connected to each other via hyperlinks in order to create a vast, world-wide 'web' of information.
* This system required uniformity
  * Uniformity in how the resources were structured so that they could all be correctly rendered for viewing (HTML)
  * Uniformity in how the resources were addressed so that they could simply and easily be located (URLs/URIs)
  * Uniformity in the way a request for a particular resource was made and in the way in which that request was responded to (HTTP)
* So the earliest incarnation of the Web was essentially a combination of three technologies: HTML, URIs, and HTTP
* Hypertext Markup Language (HTML) was the means by which the resources in this system should be uniformly structured
* A Uniform Resource Identifier (URI) is a string of characters which identifies a particular resource. It is part of a system by which resources should be uniformly **addressed** on the Web
* Hypertext Transfer Protocol (HTTP) is the set of rules which provide uniformity to the way resources on the web are transferred between applications



3:4 <u>**HTTP Book: Background**</u>

**<u>A Brief Overview & History</u>**

* When you type a URL into the address bar of your web browser, you expect to see the website displayed in your browser -- starting point of typical 'how does the internet work'/'what happens when you type a URL into the address bar of your browser' interview questions
  * When you click on a link, or submit a form, your browser may display the next page, or display errors in your form so you can correct them and submit again
* The browser is the interface or window, through which you interact with the world wide web
* A collection of files -- CSS, HTML, JavaScript, videos, images, etc -- makes displaying webpage possible
* All these files were sent from a **server** to the browser, the **client**, by an application protocol called HTTP (yes, this is why URLs in your browser, the **client**, via an application protocol called HTTP)
* HTTP, or Hypertext Transfer Protocol is a system of rules (a protocol) that serves as a link between applications and the transfer of hypertext documents
  * HTTP is an agreement, or message format, of how machines communicate with each other
  * HTTP follows a simple model where a client makes a **request** to a server and waits for a **response**. Hence, it's referred to as a **request-response protocol**
  * We can think of the request and the response as text messages, or strings, which follow a standard format that the other machine can understand (though it is important to understand that the body of responses can be binary since HTTP/1.0 at the latest, and since HTTP/2 the entire protocol is based on binary encoding even for text inputs like headers and html documents)
* The HTTP protocol has been through several changes from its inception
  * HTTP/0.9 (1991) -- the first documented version
  * HTTP/1.0 (1992) -- introduced the ability to transmit different types of documents in addition to HTML, such as CSS, videos, scripts and images
  * HTTP/1.1 (1995) -- introduced the ability to reuse established connections for subsequent requests, among a host of other features
  * HTTP/1.1 update (1999) -- defined the protocol that still dominates today
  * HTTP/2
  * HTTP/3

**<u>How the Internet Works</u>**

* The Internet consists of millions of interconnected networks that allow all sorts of computers and devices to communicate with each other
* All devices on this network of networks are provided an IP Address (Internet Protocol address)
* Port numbers add more detail about how to communicate
* We represent an IP address `192.168.0.1` and port number `1234` as `192.168.0.1:1234`, the IP address followed by a `:` followed by the port number
* An IP address acts as the identifier for a device or server, which can contain thousands of ports, each used for a different communication purpose

**<u>DNS</u>**

* DNS is a **distributed database** that translates domain names into IP addresses

* The responsibility of the Domain Name System is to map a domain name like `www.google.com` to an IP address like `197.251.230.45`

  * DNS servers provide this functionality to any internet service that needs it
  * The primary reason for the existence of DNS is to give a human-readable and memorable form to hosts on the internet, since IP numbers are difficult for people to meaningfully remember

  * When it comes to the Web, and browsers, it allows us to type `www.google.com` as part of a URL rather than `197.251.230.45`
  * We could if we liked type the IP address into the browser's bar rather than the domain name

* DNS databases are stored on computers called **DNS servers**

  * There is a very large world-wide network of hierarchically organized DNS servers
  * No single DNS server contains the complete database (hence, distributed database)
  * If a DNS server does not contain a requested domain name, the DNS server routes the request to another DNS server up the hierarchy, and eventually the address will be found in the DNS database on a particular DNS server, and the corresponding IP address will be used to receive the request
  * If a DNS record is cached as a temporary record on any server we traverse in the search, this speeds up the process
  * Otherwise the server hierarchy is structured:
    * Root servers -- highest level
    * Top-Level Domain servers -- servers covering the top-level domains, such as `com` and `org`, keeps records of authoritative servers under that domain
    * Authoritative Domain servers -- servers that actually house the original DNS record for a given second-level domain and its subdomains

Your typical interaction with the Internet starts with a web browser when you...

I don't think the DNS lookup is actually in the right place in the list that follows this. I think the DNS lookup is performed before the HTTP request is created so that a TCP/IP socket can be created for the request which is then constructed and sent through the socket. Every other source seems to insist that DNS search comes before the request is created.

**<u>Clients and Servers</u>**

* Web browsers are HTTP clients, responsible for issuing HTTP requests and processing the HTTP response in a user-freindly manner onto your screen
* Web browsers are not the only clients: many tools and applications also issue HTTP requests
* 'Server' as a term can refer both to computers that are configured with software that can respond to requests, and the software itself

**<u>Resources</u>**

* "Resource" is a generic term for things that you interact with on the internet via an URL
* Resources can be images, videos, web pages, and other files
* Resources are not limited to files; resources can also be applications

**<u>Statelessness</u>**

* A protocol is said to be **stateless** when it's designed in such a way that each request/reponse pair is completely independent of the previous one
* HTTP is a stateless protocol
* HTTP's stateless means the server does not need to hang on to information, or state, between requests
* As a consequence of HTTP's statelessness, when a request breaks en route to the server, no part of the system has to do any cleanup
* HTTP's statelessness makes the web resilient

  * When a request breaks or fails, the server does not need to perform any cleanup or maintain information about the broken connection; failures are isolated and don't cascade through the system
  * Servers don't need to maintain complex state tracking between requests, which simplifies server design and reduces memory requirements
  * If a server fails, requests can simply be redirected to another server, promoting fault tolerance
* HTTP's statelessness facilitates the distributed nature of the web

  * Requests can be routed to any server in a cluster without needing to synchronize session state between them
* HTTP's statelessness makes the web harder to control

  * Third-party enforcement of content restrictions or rate limiting are harder when there's no inherent relationship between requests
* Since HTTP is stateless, web developers have to work hard to simulate a stateful experience in web applications
  * For instance, on a social media website, developers need to 'simulate' statefulness so that we remain 'logged in' somehow
  * Otherwise, after validating our credentials, we would be immediately logged out again every time we clicked on a link on the page, since HTTP itself treats each request/response as independent of every other
  * There are various techniques for achieving this 'simulation' of statefulness, or building a stateful experience on top of a stateless communication protocol



3:4 **<u>HTTP Book: What is a URL?</u>**

* A URL is a string of characters that uniquely identifies a Web resource
* If we have the URL of a resource, we can visit the resource by typing the URL into a browser address bar
* We could see a URL as being to Web resources what a home address or telephone number is to an individual person



## **<u>Understand the characteristics of the physical network, such as latency and bandwidth</u>**

1:7 **<u>The Physical Network</u>**

"If we drill down through these layers of abstraction, underlying everything at the most basic level is a 'physical' network made of tangible pieces such as networked devices, cables, and wires. Even the radio waves used in wireless networks, though we can't touch or see them, exist in the physical realm and are bound by physical laws and rules"

"These laws and rules determine how data actually gets transported from one place to another in a physical sense. What happens at this level involves real-world limitations and boundaries, such as how fast an electrical signaal or light can travel, or the distance a radio wave can reach. These limitations determine the physical characteristics of a network, and these characteristics have an impact on how protocols function further up at the conceptual level. If we want to work with these protocols, it is therefore important to have at least a basic understanding of how a network works at this level."

**Bits and Signals**

Electricity - copper wire

Light - fibre optic

Radio waves - wifi

**<u>Characteristics of a Physical Network</u>**

"The two main characteristics in terms of the performance of a physical network are Latency and Bandwidth."

* "Latency is a measure of the *time* it takes for some data to get from one point in a network to another point in a network"
* "Bandwidth is the *amount* of data that can be sent in a particular unit of time (typically a second)"

"We can think of latency as a measure of delay. Data starts at one location at a certain point in time. At a later point in time it reaches another location. The difference between these two points in time is the delay."

**Latency**

Elements of latency (types of delay)

* Propagation delay - "the ratio between distance and speed". This delay is a consequence of the physical limitations of the medium (such as how fast electrical signal can travel on a copper wire)
* Transmission delay - "the amount of time it takes to push the data onto the link". This delay is a ratio of the length of the data and the bandwidth of the connection.
* Processing delay - at each node in the network, the data being sent needs to be processed in various ways. Processing delay is a measure of the time the data spends being processed.
* Queuing delay - network devices such as routers can only process a certain amount of data at one time. If there is more data than the device can handle, then it queues, or buffers, the data. the amount of time the data is waiting in the queue to be processed is the queuing delay

The total latency between two points is the sum of all these elements. The value is usually given in milliseconds (ms)

* Last-mile Latency: "relates to the delays involved in getting the network signal from your ISP's network to your home or office network. The 'hops' within the core par of the network are longer with less interruptions for transmission, processing, and queuing. At the network edge, there are more frequent and shorter hops as the data is directed down the network hierarchy to the appropriate sub-network"
* Round-trip Time (RTT) - a latency calculation often used in networking is Round-trip Time (RTT). This is the length of time for a signal to be sent, added to the length of time for an acknowledgement or response to be received

**Bandwidth**

"Bandwidth varies across the network, and isn't going to be at a constant level between the start point and the end point of our data's journey. For example, the capacity of the core network is going to be much higher than the part of the network infrastructure that ultimately connects to your home or office building"

"The bandwidth that a connection receives is the lowest amount at a particular point in the overall connection. A point at which bandwidth changes from relatively high to relatively is generally referred to as a bandwidth bottleneck"

"Low bandwidth can be an issue when dealing with large amounts of data. As we'll see... in many situations latency can be a much more serous limitation on the performance of a networked application"



<u>**Summary**</u>

* The *physical network* is the tangible infrastructure that transmits the electrical signals, light, and radio waves which carry network communications.
* *Latency is a measure of delay*. It indicates the amount of time it takes for data to travel from one point to another.
* *Bandwidth is a measure of capacity*. It indicates the amount of data that can be transmitted in a set period of time.





## **<u>Have a basic understanding of how lower level protocols operate</u>**

"The protocols that support network functionality are essentially logical sets of rules that have been designed and engineered to be the way they are. Viewing them as such makes them easier to break down and contextualize"

**<u>1:8 The Link/Data Link Layer</u>**

"One of the most important rules for transferring data from one place to another is identifying the device to which we want to send that data. The protocols operating at this layer are primarily concerned with the identification of devices on the physical network and moving data over the physical network between the devices that comprise it"

* Two of the most important aspects of Ethernet are **framing** and **addressing**

**<u>Framing</u>**

* Ethernet frames
  * Encapsulates data from the Internet/Network layer above
  * The Link/Data Link layer is the lowest layer at which data encapsulation takes place. 
    * At the physical layer, the data is essentially a stream of bits in one form or another without logical structure.
    * An Ethernet frame adds logical structure to this binary data.
    * The logical structure defines which bits are the data payload and which bits are metadata to be used in the process of transporting the frame
  * Source and Destination MAC Address headers
  * Frame Check Sequence (FCS) - a checksum generated by the sending device, calculated from the frame data using an algorithm such as a cyclic redundancy check. The receiving device can use the same algorithm to generate an FCS and compare it to the sent one. If the two don't match, the data is assumed to be corrupt and the frame is dropped. Ethernet does not offer retransmission of lost data, so it is the responsibility of higher-level protocols to manage retransmission of lost data if necessary
* The key components to remember are the Source and Destination MAC addresses and the Data Payload

Interframe Gap (IFG):

As well as using the Preamble and SFD to prepare a receiving device to process the frame data, Ethernet also specifies an interframe gap (IFG). This gap is a brief pause between the transmission of each frame, which permits the receiver to prepare to receive the next frame. The length of this gap varies according to the capability of the Ethernet connection.

This IFG contributes to Transmission Delay.

**<u>Addressing</u>**

MAC Addresses:

* If two computers are connected directly together to form a tiny network, an addressing scheme is not needed, since if either computer receives data it can be sure it is the intended recipient. In any larger topography, we need an addressing scheme
* Every network-enabled device, e.g. a Network Interface Card (NIC) that you would find in a PC or laptop, is assigned a MAC Address when it is manufactured
* In theory, MAC addresses should be unique. In practice, this is not always the case, though it rarely presents a problem
* This address is linked to the specific physical device and (usually) doesn't change, so it is often referred to as the *physical address* or *burned-in address*
* MAC Addresses are formatted as six pairs of hexadecimal digits, e.g. `00:40:96:9d:68:0a`
* Different ranges of addresses are assigned to different manufacturers



* A hub simply repeats each frame it receives through all ports. All devices on the network receive the frame. Each host checks the Destination MAC address and if it does not match its own MAC address it drops the frame. If the addresses match, then the host accepts the frame
* A switch forwards the frames it receives to the specific host the frame is addressed to. A switch keeps a MAC Address Table, which maps a MAC Address to the Ethernet port to which the device with that MAC Address is connected

Why MAC Addresses can only work for local networks

* The MAC Addressing system works well for local networks, where all the devices are connected to a switch that can keep a record of each device's address. In theory, we could conduct inter-network communication just using MAC addresses
* However, MAC Addressing does not scalable to inter-network communication because of two characteristics of MAC Addresses:
  * They are physical rather than logical. Each MAC Address is tied (burned in) to a specific physical device
  * They are flat rather than hierarchical. The entire address is a single sequence of values and can't be broken down into sub-divisions

**Summary**

* *Ethernet* is a set of standards and protocols that enables *communication between devices on a local network*.
* Ethernet uses a Protocol Data Unit called a Frame.
* Ethernet uses *MAC addressing* to identify devices connected to the local network.



## **<u>Know what an IP address is and what a port number is</u>**

**<u>1:9 The Internet/Network Layer</u>**

The primary features of IPv4 and IPv6 are the same:

* Routing capability via IP addressing
* Encapsulation of data into packets

**Data Packets**

* The PDU within the IP protocol is referred to as a packet
* IP packet
  * Header
    * Version: indicates version of the Internet Protocol, e.g. IPv4
    * ID, Flags, Fragment Offset: these fields are related to **fragmentation** of IP packets. If the Transport Layer PDU is too large to be sent as a single packet, it can be fragmented, sent as multiple packets, and then reassembled by the recipient
    * TTL: every packet has a Time To Live (TTL value). This is to ensure that any packets which don't reach their destination for some reason aren't left to endlessly bounce around the network. The TTL indicates the maximum number of network 'hops' a packet can take before being dropped. At each hop, the router which processes and forwards the packet will decrement the TTL value by one
    * Protocol: this indicates the protocol used for the Data Payload: e.g., TCP, UDP, etc
    * Checksum: this is an error checking value generated via an algorithm. The destination device generates a value using the same algorithm and if it doesn't match, it drops the packet. IP doesn't manage retransmission of dropped packets. This is left to the layers above to implement.
    * Source Address: the source IP address, 32-bit IP address of the sender
    * Destination Address: the 32-bit IP address of the intended recipient
* Data Payload: the PDU from the layer above, Transport. This is usually a TCP segment or a UDP datagram

**IP Addresses (IPv4)** - includes information on sub-netting and the hierarchical nature of IP routing

* Unlike MAC addresses, IP addresses are logical in nature
  * not tied to specific device
  * assigned as required to devices as they join a network
* The IP address that the device is assigned must fall within a range of addresses available to the local network that the device is connected to
* This range is defined by a network hierarchy, where an overall network is split into logical subnetworks, with each defined by the range of IP addresses available to it
* IPv4 Addresses are 32 bits in length and are divided into four sections (octets) of eight bits each. When converted from binary to decimal, each of those sections provides a range of numbers between `0` and `255` since `2` to the power of `32` is `256`
* Each subnet defines the address at the start of the range as the network address and the address at the end of the range as the broadcast address
* The network address is used to identify a specific subnet for routing purposes
* This means that a router that wants to forward a packet to any address in the entire range only needs to keep a record of which router on the network controls access to the segment with that network address
* This logic is what creates the hierarchical structure and makes the complexity of the system manageable by reducing the number of addresses that any given router needs to keep track of
* The splitting of a network into parts is called sub-netting. By dividing IP address ranges further, subnets can be split into smaller subnets to create even more tiers within the hierarchy

**Routing and Routing Tables**

* All routers on the network store a local routing table
* When an IP packet is received by a router, the router examines the destination IP address and matches it against a list of network addresses in its routing table
* These network addresses define a range of addresses within a particular subnet
* The router will look for the most specific network address (prefix) match for the destination IP address when determining the best route for the IP packet to travel

**<u>*IPv6*</u>**

* The structure of IPv4 means that there is a logical maximum of about 4.3 million addresses
* The popularity of the internet means that this space will eventually be depleted
* Since the 1990s, the IETF has been working on a new version called IPv6
* IPv6 uses 128-bit addresses, which increases the number of addresses to 340 undecillion
* IPv6 also has a different header structure and a lack of error checking (since both the Link layer and the Transport layer typically provide this)

* The Ethernet protocol provides communication between devices on the same local network, whereas the IP protocol enables communication between two networked devices anywhere in the world
* 

**Summary**

* The *Internet Protocol* (IP) is the predominant protocol used for *inter-network communication*.
* There are two versions of IP currently in use: IPv4 and IPv6.
* The *Internet Protocol* uses a system of addressing (IP Addressing) to *direct data between one device and another across networks*.
* IP uses a Protocol Data Unit called a Packet.



From Quiz 1:

* Subnetting is enabled by IP addressing. It is the hierarchical structure of IP Addresses that allows networks to be logically split into subnets

The Quiz says: "IP addresses are represented by 4 sets of numbers, each containing 8 bits of information. The first two sets of numbers usually references  the network and sub-network, respectively. The third is the host, and  the fourth part references a machine connected to that host. This choice represents the most widely used type of IP address used at the moment,  IPv4."

However, LSBot says "it's not always as clear-cut as the quiz suggests:  

•  The first set often represents the network
•  The second set often represents the subnetwork
•  The third set is typically for the host [????]
•  The fourth set usually identifies a specific device on that host [???]  However, this division can vary depending on the specific network configuration and subnetting."

* There is also a new standard for IP addresses  which is in the process of being adopted, IPv6. This representation of  an IP address is broken into 8 sets of hexadecimal characters, each  containing 16 bits of information. The first 4 sets are used to locate a specific network on the internet.  The last 4 sets are typically used to identify a particular interface or device within that network.

<u>2:2 **Communication Between Processes**</u>

**<u>Ports</u>**

* A port is an identifier for a specific process running on a host
* Each port is an integer in the range 0-65535
  * 0-1023 -- well known ports. These are assigned to processes that provide commonly used network services (server-side, normally). For example HTTP is port 80, FTP is port 20 and 21, SMTP is port 25, and so on.
  * 1024-49151 -- registered ports. They are assigned as requested by private entities. For example, companies like Microsoft, IBM, and Cisco have ports assigned that they use to provide specific services. On some operating systems, ports in this range are also used for allocation as *ephemeral ports* on the client side.
  * 49152-65535 -- dynamic ports (sometimes known as private prts). Ports in this range cannot be registered for a specific use. They can be used for customized services or for allocation as ephemeral ports. (This is the IANA-recommended range respected by Windows systems. On Unix-like systems, the range for ephemeral ports is likely to be 32768-60999 or 32768-65535 depending on the exact OS, and it also varies among Linux distributions. On Unix systems, the range for ephemeral ports used to be 1024-5000 but it has shifted and expanded to accommodate more simultaneous connections)
* Services running on servers will likely have a port in the well-known range assigned to them
  * We say that a server *listens* on a port.
* A service running on a client machine, for example in a browser running on your laptop, won't use one of these well-known ports, but instead have an *ephemeral* or temporary port assigned to it by the operating system
* Ports enable the multiplexing and demultiplexing of multiple process-to-process communication channels over the single host-to-host connection provided by IP addressing. The source and destination port numbers in the header of a TCP segment or UDP datagram identify specific processes running on a host. The Transport layer PDU including this header information is encapsulated as the data payload of an IP packet, sent across the single channel of the Network layer from host to host, and then used to separate a 'channel' of communication from other channels at the other end by delivering it to the correct process identified by the destination port
* The combination of IP addresses and port numbers enables end-to-end communication between two networked processes (usually running on different machines)
* The combination of an IP address and a port number defines a *communication end-point*, generally referred to as a *socket*

So the system of TCP and UDP ports offers multiplexing and demultiplexing; ports allows us to send multiple channels of data from distinct networked processes over a single channel (IP) of communication between network hosts, and have those channels be separated out again at the other end.



## Have an understanding of how DNS works

3:4 <u>**HTTP Book: Background**</u>

**<u>DNS</u>**

* DNS is a **distributed database** that translates domain names into IP addresses

* The responsibility of the Domain Name System is to map a domain name like `www.google.com` to an IP address like `197.251.230.45`

  * DNS servers provide this functionality to any internet service that needs it
  * The primary reason for the existence of DNS is to give a human-readable and memorable form to hosts on the internet, since IP numbers are difficult for people to meaningfully remember

  * When it comes to the Web, and browsers, it allows us to type `www.google.com` as part of a URL rather than `197.251.230.45`
  * We could if we liked type the IP address into the browser's bar rather than the domain name

* DNS databases are stored on computers called **DNS servers**

  * There is a very large world-wide network of hierarchically organized DNS servers
  * No single DNS server contains the complete database (hence, distributed database)
  * If a DNS server does not contain a requested domain name, the DNS server routes the request to another DNS server up the hierarchy, and eventually the address will be found in the DNS database on a particular DNS server, and the corresponding IP address will be used to receive the request
  * If a DNS record is cached as a temporary record on any server we traverse in the search, this speeds up the process
  * Otherwise the server hierarchy is structured:
    * Root servers -- highest level
    * Top-Level Domain servers -- servers covering the top-level domains, such as `com` and `org`, keeps records of authoritative servers under that domain
    * Authoritative Domain servers -- servers that actually house the original DNS record for a given second-level domain and its subdomains

Your typical interaction with the Internet starts with a web browser when you...

I don't think the DNS lookup is actually in the right place in the list that follows this. I think the DNS lookup is performed before the HTTP request is created so that a TCP/IP socket can be created for the request which is then constructed and sent through the socket. Every other source seems to insist that DNS search comes before the request is created.



## Understand the client-server model of web interactions, and the role of HTTP as a protocol within that model

3:4 <u>**HTTP Book: Background**</u>

**<u>Clients and Servers</u>**

* Web browsers are HTTP clients, responsible for issuing HTTP requests and processing the HTTP response in a user-freindly manner onto your screen
* Web browsers are not the only clients: many tools and applications also issue HTTP requests
* 'Server' as a term can refer both to computers that are configured with software that can respond to requests, and the software itself
