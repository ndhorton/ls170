# The LS 170 list of practice questions to deeper your understanding

Course: LS170
Concepts: Networking fundamentals theory
Last Edited: June 6, 2022 3:56 PM

Disclaimer: The list of the following questions was made before I took the assessment. It is not by any means a list of questions that you will get on the assessment, nor is it a guide that you should be using to prepare for the assessment. Please refer to the official LS170 study guide for topics that will be covered in the assessment. Please treat those questions as a way to help better and deeper understand the topics that are covered in the JS170 and find some blind spots. Some of the questions may go much deeper than the assessment itself while other parts may not be covered at all. 

**What is a network?**

From LS: 

A network is a set of two or more devices connected together in such a way that they can communicate or exchange data.

Wikipedia:

A computer network is a set of computers sharing resources located on or provided by network nodes. Computers use common communication protocols over digital interconnections to communicate with each other. These interconnections are made up of telecommunications network technologies based on physically wired, optical, and wireless radio-frequency methods that may be arranged in a variety of network topologies. The nodes of a computer network can include personal computers, servers, networking hardware, or other specialized or general-purpose hosts. 

In networking, a node is either a redistribution point or a communication endpoint within a network. A physical network node is an electronic device that is attached to a network, and is capable of creating, receiving, or transmitting information over a communication channel. In data communication, a physical network node may either be data communication equipment (such as a modem, hub, bridge, or switch) or data terminal equipment (such as a digital telephone handset, a printer, or a host computer).

**What is the Internet?**

The Internet is a network of networks, and is comprised of both the physical infrastructure and the network protocols that facilitate inter-network communication. The Internet enables communication between networks via a system of routers.

**Is the Internet the same thing as a network?**

The Internet is a network of networks, so in a sense the Internet is a network. However, a network could simply be a local network that is not connected to any other network via a router (a host that can forward traffic to other networks), whereas the Internet is defined by inter-network communication between smaller networks.

**What is WEB (world wide web)**

The World Wide Web is a service that can be accessed via the Internet. The Web is a vast information system comprised of resources that can be accessed via URLs (Uniform Resource Locator). The primary means by which applications access Web resources is through the HTTP protocol.

**What is the difference between network, Internet, and WEB?**

A network, its simplest, could be two computers connected in such a way that they can exchange data. A network is often a group of computers connected via a switching device or devices. Such a network is called a Local Area Network. A LAN might be connected to the Internet via a router. The Internet is a global network of networks, and as such is defined by inter-network communication between smaller networks via routing. The Web is a service that is available through the Internet.

**What are LAN and WLAN?**

From LS:

A LAN is, generally, "multiple computers and other devices connected via a network bridging device such as a hub or, more likely, a switch. The computers are all connected to this device via network cables and this forms the network."

"Your home network follows the same principle, but the central device will likely be a wireless hub or switch so that the devices can connect wirelessly rather than being plugged in. This implementation is known as WLAN or Wireless LAN"

"The key thing to understand here is that the scope of communications is limited to devices that are connected (either wired or wirelessly) to the network switch or hub, which imposes some geographic limitations. That's the 'local' in Local Area Network."



**What is a protocol?**

A protocol is a set of rules. A network protocol is a set of rules that govern the exchange or transmission of data.

**What is the role of protocols?**

Protocols are essential sets of rules that govern the exchange or transmission of data. Protocols act as a standard for various aspects of communication and facilitate communication between devices and software created by a vast array of different vendors and developers.

Protocols establish a common language of rules and procedures with which devices can communicate, regardless of their hardware, software, or operating systems.

Without protocols, there would be no standardized way for all of these heterogeneous components to communicate in a mutually intelligible way.



**Why there are many different types of protocols?**

Networking protocols are layered with each layer addressing a single aspect of network communication. Through data encapsulation, each layer provides a service to the layer above. This layering is modeled through conceptual frameworks such as the OSI model and the TCP/IP model.

Various different protocols address different aspects of network communication within a layered networking system. For instance, Ethernet, at the Data Link layer, deals with host to host communication within a single network, whereas Internet Protocol, at the Network layer, deals with network to network communication.

In addition, there are various different protocols that address the same aspect of communication but with different use cases in view. For instance, both TCP and UDP, at the Transport layer, enable process to process communication, but TCP offers reliable but complex interprocess communication, while UDP offers unreliable but fast and flexible interprocess communication.

**What does it mean that a protocol is stateless?**

A stateless protocol is one in which every request/response cycle is independent of any that came before. This means that any request by a client should be intelligible to the server without the server needing to maintain connection state, or information about previous requests and responses.

**Explain briefly what are OSI and TCP/IP models? What is the purpose of having models like that?** 

Trying to understand every aspect of network communication as a single end-to-end process would be extremely difficult..

The OSI model and the TCP/IP model both offer a way to think about aspects of network communication in isolation from each other, and to understand how each layer, or aspect of communication depends, on a more basic aspect.

Though the ways in which they do this (as well as the precise purposes of their development) differ, the OSI and TCP/IP models both offer a way to modularize and structure the system of network communication into a layered system, so that we can zoom in on a particular layer to more clearly understand what is happening at that level of the system.

 The OSI model is structured as follows:

1. The Physical layer
2. The Data Link layer
3. The Network layer
4. The Transport layer
5. The Session layer
6. The Presentation layer
7. The Application layer

The TCP/IP model is structured as follows:

1. The Link layer
2. The Internet layer
3. The Transport layer
4. The Application layer

The Link layer of the TCP/IP model roughly corresponds to the Data Link layer of the OSI. The TCP/IP model does not concern itself with the Physical layer (except with minor overlap in the Link layer).

The Internet layer of the TCP/IP model roughly corresponds to the Network layer of the OSI model.

The Application layer of the TCP/IP model roughly includes the Session, Presentation, and Application layers of the OSI model.

The differences between these models is partly a result of the difference in approach each takes. The Internet Protocol Suite, or TCP/IP model, divides the layers in terms of the scope of communications within each layer (within a local network, between networks, between processes, etc). The OSI model divides the layers in terms of the functions that each layer provides (physical addressing, logical addressing and routing, encryption, compression, etc).

The purpose of these layered models is to simplify the understanding of complex networking systems. They allow us to modularize the complex process of communication into conceptually manageable components, letting us focus on specific aspects of communication at different layers.



**What is PDU? What is its role?**

A Protocol Data Unit, within layered network models like the OSI or TCP/IP models, is a general concept representing a unit or block of data transferred over a network. Different protocols, or protocol layers, refer to PDUs by different names.

The structure of a PDU is similar across different protocols. The PDU has a data payload, which is the encapsulated PDU of the layer above, and then a header section (and for some protocols, a trailer) which contains metadata that enables the successful transmission of the data payload across the network. The metadata contained in the header (and trailer) varies by protocol and protocol layer. For instance, an Internet Protocol PDU, called a packet, contains in its header the Source IP Address and Destination IP Address, permitting the data payload to be routed across the Internet. The Ethernet PDU, called a frame, contains in its header the Source MAC Address and Destination MAC Address permitting the data payload to be sent from device to device across a single network.



**What is Data Payload?** 

The data payload portion of a PDU is simply the data that we want to transport over the network using a specific protocol at a particular network layer.

The data payload is how network data encapsulation is implemented. The entire PDU from a protocol at the layer above is set as the data payload for the PDU at the layer below. This process continues down the network stack. For example, the data from an Application layer protocol such as HTTP becomes the data payload of a TCP Segment, which in turn becomes the data payload of an IP packet, which in turn becomes the data payload of an Ethernet frame.

A major benefit of this approach is the separation it creates between the protocols at different layers. This means that a protocol at one layer doesn't need to know anything about how a protocol at another layer is implemented in order for those protocols to interact. The protocol can complete its specific task without information from other layers. It creates a system whereby a lower layer effectively provides a 'service' to the layer above it.

This separation of layers through data encapsulation provides a certain level of abstraction, which allows us to use different protocols at a certain layer without having to worry about the layers below.



**What is the relationship between PDU and Data Payload?** 

The relationship between PDU and Data Payload is one of encapsulation.

The data payload of any PDU is data from a protocol in the layer above that is encapsulated within the PDU of the protocol at the layer below. Encapsulation in this context means that a protocol at the layer below is not concerned with the details of what its data payload actually is. A TCP Segment is not concerned with whether its payload is an HTTP Request or a SMTP command. It is only concerned with attaching a Transport layer header to successfully transmit the data payload from one networked process to another. In turn, at the layer below, an IP packet is not concerned with whether its data payload consists of a TCP Segment or a UDP Datagram.

This layered encapsulation allows each protocol to focus on its specific task while relying on the layers below for data delivery. Each protocol can concern itself with its own specific task without depending on the details of which protocols are used at the layers above or below. This allows a great deal of flexibility, whereby a protocol at one layer can be used in conjunction with a great variety of protocols at the layer above without any special considerations.



**Explain How lower-level protocols work in general?**

Network data encapsulation means that higher-level protocols such as HTTP can rely on lower-level protocols for actual data delivery without needing to know the precise details of which protocols will be used.

Below the Application layer, the Transport layer protocols, primarily TCP and UDP, are responsible for encapsulating data from the Application layer and ensuring its transmission from the source process (or Source Port) to the destination process (or Destination Port). The Transport layer PDU is then encapsulated as the data payload of the Network/Internet layer.

The primary protocol here is Internet Protocol (IP), which is concerned with IP Addressing and routing. It is the responsibility of IP to enable a host on one network to exchange data with a host on another network. The PDU of the Internet Protocol, the Packet, is then encapsulated as the data payload of a Link/Data Link protocol's PDU.

The Link layer's responsibility is to ensure transmission of the data payload from a from one host to another on the same network. A gateway router might use the Link layer Ethernet protocol to transmit  an IP packet received from the Internet to the target machine on a Local Area Network to which the router is connected. The IP packet is encapsulated as the data payload of an Ethernet frame, which concerns itself with the Source MAC Address (the router) and the Destination MAC Address (the target machine). The Ethernet frame is then sent across the Physical layer as a series of bits.

Lower-level protocols handles the fundamental spects of network communication, addressing, routing, and reliable delivery. They abstract away these complexities so that higher-level protocols like HTTP can focus on application-specific concerns rather than the mechanics of network data delivery.



**What is encapsulation in the context of networking?**

Encapsulation in the context of networking refers to the encapsulation of data from a network protocol layer above as the Data Payload of a Protocol Data Unit of a protocol at the layer below.

The data payload of a PDU is said to be encapsulated because the data contained in the data payload is unimportant to the protocol that encapsulates it within its PDU. For example, a TCP Segment does not need to know whether its data payload is an HTTP Request or a SMTP command; this detail is not relevant to the responsibilities of the TCP protocol. Likewise, an IP packet is not concerned with whether its data payload contains a TCP segment or a UDP datagram.



**Why do we need encapsulation?** 

In programming, encapsulation can refer to hiding the internal representation of an object and preventing it being accessed from outside the object. This separates the details of an object's representation from client code, preventing the client code from become dependent on these details.

Similarly, by designing protocols to encapsulate the data they are handed by a higher-level protocol, we create a separation between the protocols at different layers. A protocol at one layer doesn't need to know anything about how a protocol at another layer is implemented in order for those protocols to interact. 

This separation of layers through data encapsulation creates a useful level of abstraction. We ensure that higher level protocols can rely on the lower level protocols for network data delivery without needing to concern themselves with which protocols are being used or with their implementation details. Likewise, a lower level protocol can be used to transmit a huge variety of types of higher level application data without needing to know anything about these higher level protocols. Any new Application layer protocol can rely on an existing set of lower level protocols without there needing to be any changes to those protocols.



**What are the characteristics of a physical network?**

The physical network refers to the tangible infrastructure underlying the higher level protocols. This infrastructure includes devices, copper wire, optical cables, and radio transmitters, which transmit data in the form of electrical signals, light signals, and radio waves.

The two main characteristics of a physical network in terms of performance are latency and bandwidth.

Latency is a measure of time: how long a unit of data takes to travel from one point in the network to another.

Bandwidth measures network capacity in bitrate: how much data can be transmitted in a given unit of time, usually a second.

If a section of the network were a road, then latency might be a measure of the time it takes for a car traveling at the speed limit to drive the section of the road, while bandwidth might be the number of lanes along which cars could drive simultaneously.



**How can we as developers deals with the limitations of physical network?**

As developers, there is not a lot we can do about the limitations of the physical network itself (which include the physical limit of the speed of light, physical distances, and so on). If we want to improve the performance of the applications we build, then our influence is limited to the implementation of the application in terms of how we use the higher-level protocols with a view to mitigating the impact of the limitations of the physical network.

We need to understand two important things about the physical network and design our applications accordingly. We must understand that latency will always exist; no matter how the infrastructure is improved we are still dealing with physical distances and the properties of the materials used at the physical layer.

We must also recognize that bandwidth varies across the network, and the effective bandwidth a connection receives is the lowest amount of any point in the path across the network, known as a bandwidth bottleneck.

An understanding of these physical limitations can impact the way we think about those higher-level protocols, and therefore the decisions we make about how we use them within our applications.

We can optimize for latency by eliminating unnecessary roundtrips, reducing the number of resources to be fetched, and using CDNs (Content Delivery Networks) to place content closer to users. We can also reduce file sizes through compression and minification, implement caching strategies, and prioritize loading of critical resources.

It is important to recognize that for most modern applications, latency has a bigger performance impact than bandwidth limitations. This is because web applications, for the most part, need to send many small pieces of data rather than transferring large files. The brunt of the performance impact will therefore be the time it takes for each request/response cycle, requiring a request to travel from the client to the server, and then the response to travel back across the network to the client. Since the response data is relatively small, increased bandwidth would only marginally increase the performance; most of the performance impact is to do with the time it takes for the response to travel across the network, not the quantity of data that needs to be transmitted. As an analogy, if a single car needs to travel a section of road, increasing the number of lanes on the road does not necessarily reduce the time it takes.



**What is Latency?**

Latency is a measure of the time taken for a piece of data to travel from one point in the network to another point. We can think of latency as a measure of delay. Data starts at one location at a certain point in time. At a later point in time, the data has reached another location. The difference between those points in time is the delay.

There are different types of delay that make up latency: propagation delay, transmission delay, processing delay, and queuing delay.

Propagation delay is the amount of time data spends on the physical medium (traveling through cables and radio waves) between two points on the network. Propagation delay can be described as a ratio between distance and speed.

Transmission delay is the amount of time the data spends being pushed onto the physical medium. The path of data across the network will typically include passing through multiple intermediary devices such as routers. Each of these devices will be linked to the next (with cables or wireless technology). Transmission delay will accrue at every point in the network path where the data needs to be pushed onto a new physical link between network devices.

Processing delay is the time data spends being processed by network devices on its network path.

Queuing delay is the time data spends being held in buffers.

The total latency between two points, such as a client and a server, is the sum of these delays. Latency is usually measured in milliseconds (ms).



**What is** **Bandwidth?**

Bandwidth is the maximum rate of data that can be transmitted across a given path in a given time period. Bandwidth is measured by bitrate, the amount of bits that can be transferred in a given unit of time, usually a second.

Bandwidth is never even across the entire path taken by data between, say, client and server. The core Internet infrastructure will have a much greater bandwidth than the edges of the network, or an office or home LAN. The effective bandwidth of the path between a client and server will be the lowest bandwidth of any link or connection in the path across the network.



**What are** **Network 'Hops'?**

On the Internet, the path of data between source and destination hosts is never direct, but consists of several 'hops' between intermediate nodes on the network. Hops are the smaller journeys between network nodes that make up the overall network path. These intermediate nodes are routers and other network devices.



**What is the relationship between network 'Hops' and latency?** 

Data makes a series of hops between network nodes on the way to its destination host. These nodes are routers and other network devices. Each device the data passes through generally needs to do some processing; this often involves holding the data in buffers while other data is being processed. The device then needs to transmit the data onto the link to the next node. The time spent processing the data corresponds to processing delay, the time spent buffering the data to queuing delay, and the time it takes to transmit the data onto the link is transmission delay. These three elements of latency therefore accrue at each node, and so, generally, the more hops the data has to traverse en route to its destination, the more latency will be experienced.



**What is a switch and what is it used for?**

A switch is a network device used in a Local Area Network whose responsibility is to relay traffic between the devices on the local network.

Like a network hub, a switch is a central device to which the hosts on a local network are connected by cables or wifi. A network hub, a simpler device, relays traffic by flooding each frame it receives out through all of its ports. This means every host on the local network receives every frame, and a host discards frames unless it is the intended recipient. A switch is more sophisticated, and can forward frames only to the intended recipient.

In order to do this, the switch reads the Destination MAC addresses in the header of an incoming Ethernet frame. The switch then uses its internal MAC Address Table to map the MAC address to the port to which the host with that MAC address is connected. The switch then forwards the frame only through that port.

 A switch builds its MAC address table by continuously learning the Source MAC Address of the device connected to each port by reading the frame headers as the switch receives Ethernet frames through its ports.



**What is a hub and what is it used for?**

A hub is a network device that relays data frames between hosts on a local network. A hub is a multi-port repeater, to which the hosts on the local network are connected. Every time a host sends a frame out through its Network Interface Card, the frame reaches the hub. The hub then simply floods copies of the frame out through all of its ports, sending a frame to every connected host. Each host reads the Destination MAC Address field in the frame header and discards the frame unless that host is the intended recipient.



**What is a modem and what it is used for?**

A modem is a modulator/demodulator whose purpose is to translate digital signals to analogue signals for transmission over various types of communications infrastructure such as telephone or cable television lines. Today, modems are often a component of other devices rather than the discrete units prevalent in the early days of the mass Internet.



**What is a router and what is it used for?**

A router is a network device which contains interfaces to more than one network whose purpose is to direct traffic between networks based on its routing table. This is to say, routers are network devices that can route network traffic to other networks. Within a Local Area Network, a router acts as the gateway into and out of the network.





**What is the difference between a switch, hub, modem, and router?**

Hubs and switches relay traffic within a Local Area Network. The hosts on the local network are connected to a central hub or switch via cables or wifi.

Any frame received by a hub will simply be repeated out of all of its ports. This means that whenever a host on the local network sends a frame to another host on the same network, the frame is sent to the hub and the hub sends a copy of the frame to every host on the network. The hosts each have to check the Destination MAC Address in the frame header, and if the frame is not intended for a host, the host simply discards it.

This works but is inefficient. Switches offer a more sophisticated way to relay traffic between hosts on a Local Area Network. A Switch keeps an internal MAC Address Table which maps MAC addresses to the ports of the switch. When a host sends a frame to a host on the same Local Area Network, the frame is first received by the switch, which checks the frame header for the Destination MAC Address and then forwards the frame through the port to which the destination host is connected to the switch.

Switches and hubs both serve to relay or direct traffic within a Local Area Network, but the purpose of a router is to route data traffic between networks. Routing is what makes inter-network (and thus Internet) communication possible. Within a Local Area Network, a router serves as the gateway into and out of the local network.



**How does the Internet work?**

The Internet is a network of networks that comprises both the physical infrastructure (computers, network devices, cables, etc) and a layered system of communication protocols that enable the physical infrastructure to function.

These protocols can be grouped into layers according to the aspect of communication the protocols serve. Two models which group protocols in this way are the OSI model and the Internet Protocol Suite, or TCP/IP model.

At the highest level of both models is the Application layer. Application layer protocols such as HTTP or SMTP describe the structure that messages should have to be intelligible between networked applications using the protocol to communicate over the network (e.g. a web client and a web server).

The TCP/IP model's Application layer roughly includes the Presentation and Session layers from the OSI model. Below these is the Transport layer. Protocols at the Transport layer enable interprocess communication between networked processes (usually on different hosts). Below the Transport layer is the Network/Internet layer. The role of protocols at this layer (now almost always the Internet Protocol) is to enable inter-network communication. Below the Network/Internet layer is the Link/Data Link layer. This is the lowest layer of the TCP/IP model. The OSI model also formally includes a Physical layer below, referring to the physical infrastructure that makes up the network.

Each layer of protocols provides a service to the layer above and encapsulates data from the layer above as the data payload of a Protocol Data Unit. The Protocol Data Unit (PDU) adds metadata in the form of a header and sometimes a trailer to the data payload. For instance, the data payload of a Network layer PDU is generally the PDU of a Transport layer protocol; in turn, the PDU of the Network layer becomes the data payload of a Data Link layer PDU. The contents or structure of the data encapsulated thus are of no concern to the protocol providing the encapsulation. This encapsulation allows many different protocols at one layer to make use of a protocol at the layer below without any special considerations.

At the physical layer, data is transmitted as a stream of bits in the form of electrical signals, light signals, and radio waves. Protocols in the Data Link layer such as Ethernet give structure to data transmitted over the physical medium so that data sent over the physical network can be interpreted correctly. The role of protocols at the Data Link layer is to identify devices on the physical network and to move data over the physical network between the devices that comprise it.

The way that devices are identified, or addressed, at the Data Link layer is by MAC Address. Each device connected to a network has at least one Network Interface Card (NIC) which is assigned a number by its vendor called a MAC (Medium Access Control) Address. A MAC Address is sometimes called a physical address, or burned-in address, because it is generally fixed permanently at manufacture rather than assigned dynamically.

The smallest networks that comprise the network of networks that is the Internet are known as Local Area Networks. A simple Local Area Network (LAN) might be comprised of an office full of computers connected to a central network device called a switch. The geographic constraints imposed by the need to be connected wired or wirelessly to the central switch are what is 'local' about a Local Area Network.

For wired connections to a LAN, the most common Data Link protocol used is Ethernet. The PDU of the Ethernet protocol is called an Ethernet frame. The header of an Ethernet frame contains fields for the Source MAC Address and Destination MAC Address. When a host wishes to send some data to another host on the same LAN, the data is encapsulated as the data payload of an Ethernet frame and sent over the network via the host's NIC. The NIC is connected via Ethernet cable to the switch, which receives the frame and reads the frame header to determine which of its ports (its physical connections to hosts) should be used to forward the frame. To do this, it reads the Destination MAC Address and consults its internal MAC Address Table, which maps MAC Addresses to the switch's port numbers. The MAC Address Table is populated by reading the Source MAC Address in the headers of Ethernet frames as it receives them through its ports.

The role of the network switch is thus to direct traffic between all the hosts on the local network. However, if a host wishes to send data to a host on a different LAN, we need a router. A router is a network device that can direct traffic between different networks. For a LAN, the router acts as a gateway into and out of the network, and therefore acts as a gateway to the Internet. To do this, a router has interfaces to multiple networks between which it can route traffic using its internal Routing Table.

In order to send data between networks, we need a Network/Internet layer protocol, which is now almost always Internet Protocol (IP). IP offers inter-network addressing and routing, and encapsulation of data from the layers above into its PDU, called an IP packet. 

For the sake of simplicity, I will only discuss IP version 4. A new version, IPv6, has been in process of introduction in recent decades. IPv6's most notable improvement is a greatly expanded address space, since IPv4 addresses are limited by their 32-bit size to around 4.3 billion IP addresses and this limit already requires workarounds to serve the existing number of Internet-connected devices. An IPv4 address consists of four groups of 8 bits (octets). In the human-readable form of an IP address, each octet is represented as a number from 0 to 255 and the octets are separated by dots, e.g. `109.156.1.155`.

MAC Addresses are unsuitable as inter-network addresses because they are fixed and flat (unstructured). This works fine for LANs, since a network switch only needs to keep track of a relatively small number of directly connected hosts, each of which has a (for most practical purposes) unique MAC address. As hosts are connected and disconnected to the ports of the switch, the switch can simply update its MAC Address Table accordingly and continue. However, since routers need to be able to route a piece of data to any device on the entire Internet, the same form of addressing cannot be used. Since there is no hierarchy or structure to MAC addresses, each router would need to keep a record of the MAC Address of every networked machine on the planet in order to route the traffic to its destination. And since MAC addresses are permanently assigned, every router's impossibly vast routing table would need to be constantly updated as portable devices like laptops and phones were disconnected and reconnected on different networks at different locations.

Where MAC addresses are permanent and flat, IP addresses are logical and hierarchical. The IP address space is hierarchical in that large networks are split gradually into smaller and smaller subnetworks (via a structuring principal known as subnetting) and any given host's specific IP address reflects its position within the network as a whole. This means that a packet can easily be routed towards its destination LAN via a series of hops between routers, with each router only needing to maintain records of proximate routers in the IP network hierarchy rather than every device on the internet. IP addresses are logical in that they can be assigned and revoked as machines are connected and disconnected to different networks, with a machine's current IP address reflecting its current position within the IP network and not an immutable identity.

When a host wishes to send some data to a host on another network, the data is encapsulated as the data payload of an IP packet. The header of an IP packet includes fields for the Source IP Address, the IP address of the sender, and Destination IP address, the IP address of the host we are sending the data to. The IP packet is then encapsulated as the data payload of an Ethernet frame. The Ethernet header includes the Source MAC Address, the MAC address of the sender, and the Destination MAC Address, the MAC address of the router, or 'default gateway' out of the local network. The Ethernet frame is relayed to the local router by the switch. At this point the router strips the Ethernet header and footer, and thus de-encapsulates the IP packet. The router consults its internal Routing Table to determine the best path for the data to take for the next hop. The packet is encapsulated in another Data Link PDU and sent to the next router. This process continues, with the packet getting closer to the destination LAN with each hop across the core of the Internet, which can be thought of as a vast mesh of routers, though this is a simplification. When the packet arrives at the router that acts as gateway to the destination local network, this router then encapsulates the packet in an Ethernet frame with the MAC address of the destination host taken from its internal ARP cache. The purpose of ARP, or the Address Resolution Protocol, is to map IP addresses to MAC addresses. The frame is then relayed through the switch of the destination network and arrives at the destination host, which strips the Ethernet and IP headers and can now access the data.

Although the protocol layers of network communication covered so far allow us to get data from a host on one network to a host on another network, this doesn't account for how data gets to a delivered to a particular application running on that host. A single host may well be running many networked applications and services, and each of these processes needs to receive data from, and send data to, processes running on different hosts. IP addressing effectively provides a single channel for internet data into and out of a given host, but we need a way that multiple streams of data can be sent over this single channel and then reassembled and delivered to the correct process running on the host machine at the other end. In order for this interprocess communication between networked processes to be possible we need the Transport layer protocols, the most common of which are Transmission Control Protocol (TCP) and User Datagram Protocol. The PDU of TCP is known as a TCP Segment, while the PDU of UDP is known as a Datagram.

Both TCP and UDP offer multiplexing of multiple processes' data streams through the single channel of communication represented by the IP address of the host, as well as demultiplexing at the other end. This is achieved through a system of ports. A port is an identifier for a particular process running on a host. Both TCP segments and UDP datagrams include Source Port and Destination Port fields in their headers. When a host receives application data encapsulated in a Transport layer PDU, the host can check the port number in the Destination Port field and deliver the data to the process identified by that port. If the host needs to send data back to the process running on the other host, it can send the data to the port given in the Source Port header of the PDU it received. The combination of a Transport layer port number and a Network layer IP address forms what is known as a network socket, a communication end-point for interprocess communication between networked processes.

In addition to this multiplexing and demultiplexing, TCP offers reliable delivery of data. If we send a TCP segment to another host, we can be sure that it will eventually reach it. This is important because IP and the layers below are inherently unreliable; there is no mechanism to re-send packets that get lost in transit. TCP ensures reliable delivery over this inherently unreliable channel by providing several services: in-order data delivery, error detection through checksums, retransmission of lost data, and de-duplication of duplicate segments received due to the system of retransmissions.

To provide these services TCP uses sequence numbers to label the segments. When sending a TCP segment, the sender sets a timer. For each segment received, the receiving party sends an acknowledgement segment back to the sender with the sequence number of the segment being acknowledged included in the TCP segment header. If the sender does not receive an acknowledgement before the timer expires, the sender re-sends the unacknowledged segment. This ensures that any lost segments are re-sent until an acknowledgement is received by the sender to confirm successful receipt of the segment. However, since acknowledgments can also be lost, this can lead to duplicate segments being received. Discarding duplicates is handled through the sequence numbers, by which the receiver can recognize duplicates. The sequence numbers are also used to ensure in-order delivery of data.

TCP is a connection-oriented, client-server protocol. Maintaining a connection facilitates coordination of sequence numbers and the maintenance of state at both ends to keep track of which segments have been sent, have been acknowledged, or are in need of retransmission. This requires an initial negotiation called the 'three-way handshake' in order to establish a connection.

The three-way handshake begins with the TCP client sending a `SYN` segment (a segment with the `SYN` boolean flag in its header set to true), to the TCP server to initiate a connection. The listening server TCP socket receives the `SYN` segment and a new socket object is created defined by a four-tuple: the IP address and port number of the server and the IP address and port number of the client. This dedicated connection socket will be used for the lifetime of the connection. The server then sends back a `SYN / ACK` segment to the client. The client then sends an `ACK` segment and, at this point, application data can begin to be sent.

This whole process introduces an entire round-trip of latency before application data can begin to be sent. In addition, the system of acknowledgements, retransmissions, and in-order delivery (which can lead to Head-of-Line blocking) add a great deal of complexity. TCP ameliorates the impact on performance this complexity brings with it through mechanisms like pipelining, flow control and congestion avoidance, but there is still an impact on performance. For many applications this performance hit is worth it, but other applications may not need all of the services that TCP provides. For such applications, UDP may be a better fit.

Like TCP, UDP provides interprocess communication between networked processes, with multiplexing and demultiplexing provided by a system of port numbers. Of the reliability services that TCP provides, UDP offers only basic error detection through checksums. This unreliability makes UDP faster than TCP, but it also offers flexibility. Developers can implement only the reliability features they need on top of UDP for the specific needs of their application. UDP is a often chosen for applications like voice calling, video calling, and competitive multiplayer games, where latency (or 'lag') is a much greater problem than lost packets.

Protocols at each layer from the Physical layer to the Transport layer combine to offer reliable inter-process end-to-end communication between networked processes running on hosts on different networks around the world. These protocols make the Internet possible, but they don't in themselves define the services available on the Internet. These services require Application layer protocols. There are various services that are accessible through the Internet, with the most prominent being the World Wide Web, or simply the web. The ubiquity of the web has often lead people to confuse it with the Internet itself, but it is simply one of the services and applications the underlying Internet sustains.

When we enter a URL like `http://www.example.com/index.html` into the address bar of a web browser, a series of processes takes place before the web page can be displayed. A URL, or Uniform Resource Locator, identifies a resource on the Web. A resource is a generic term for anything that you can access on the web with a URL. A URL is a string of characters and consists of several components. The scheme (here `http`) tells the browser what family of protocols should be used in accessing the resource. The `http` scheme is related to the HTTP family of protocols, which stands for HyperText Transfer Protocol.

An Application layer protocol, HTTP is the primary protocol of the web. HTTP defines how the messages passed between web client and web server should be structured. HTTP communications follow a simple pattern called the HTTP request/response cycle. An HTTP client sends a request message to a web server and then waits for an response. The server always sends a response, even if the response is simply an error message. HTTP is a connectionless, stateless protocol, which means that each request/response cycle is treated as independent of any previous requests and responses. This means that web developers have to employ a variety of techniques to give web applications an appearance of statelessness.

After we enter `http://wwww.example.com/index.html` into the address bar, our browser prepares an HTTP request to the server named in the URL. Requests and responses are essentially text messages. The first line of the request, known as the request or start line, contains the HTTP method, the path, and the version of HTTP we are using. When, as here, we are retrieving content from the server, we generally use the `GET` HTTP method. If we were sending data to the server to alter data stored on the server, we would generally use the `POST` request. There are a handful of other methods.

As well as a scheme and a host, our URL contains a path component, `/index.html`. The path is the specific resource we are requesting from the server. In the early days of the web, paths corresponded to actual Unix-style pathnames on the web server's filesystem; this might still be the case, but since so much web content is now dynamically generated rather than static files, the path might now derive its meaning for the server from the web application logic instead of referring to an actual file.

An HTTP request may also contain headers, which are key-value pairs. From HTTP/1.1 onwards, a `Host` header became mandatory, whose value field in our case would be `www.example.com`. HTTP requests might also have a body, depending on the HTTP method used. The body contains data to be sent to the server. `GET` requests do not contain a body, though they can pass limited information to the server through the URL itself in the form of a query string. A query string component comes after the path, beginning with a `?` character, and contains key-value pairs; the query string is commonly used to pass search terms to search engines.

The host part of the URL gives the human-readable domain name of the server, but our HTTP request will need to be sent over the Internet, which relies on IP addressing. Resolving a human-readable domain name to its corresponding IP address is done by the Domain Name System (DNS). DNS is a hierarchical, distributed database that maps domain names to IP addresses. The database is distributed world-wide in a hierarchically traversable fashion, so that no single DNS server needs to keep a complete record of every domain name mapping. If the DNS server of our Internet Service Provider (ISP) does not have a record for `example.com`, the query is passed to another server further up the hierarchy, and if that server cannot find a record then the query will be passed on again, and so on until the query is resolved. 

Our HTTP request is encapsulated as the data payload of a TCP segment, whose Source Port will be randomly chosen and whose Destination Port, since we are sending our data to an HTTP server, will be port `80`. The protocols of common Internet services such as HTTP have well-known ports on which servers listen for incoming messages. Next, the TCP segment is encapsulated as the data payload of an IP packet, whose Destination IP Address is filled in thanks to a DNS query for `example.com`. The packet is then encapsulated as an Ethernet frame and sent via the switch to our router, our default gateway to other networks.

From our local router, the packet takes a series of hops between routers across the Internet and finally arrives at the router directly connected to our destination network. The packet is sent to the server, which de-encapsulates the various headers and trailers and passes the HTTP request to the web server process running on that machine. The web server processes the request and prepares an HTTP response.

An HTTP response is structured similarly to a request. Instead of a request line, the response begins with a status line, which contains a status code and accompanying status text which indicates the outcome of the request. For successful requests, this will be `200 OK`. Next, there are optional headers and an optional body. The body of the request often contains a requested resource, such as an HTML page.

When the HTTP response has been created, it will then be encapsulated in a TCP segment, which in turn is encapsulated in an IP packet and so on. The packet is sent back to the server's local gateway and back across the Internet to our router and finally to our computer. Our system strips the various headers and footers and delivers the HTTP response to our browser. The browser interprets and renders the HTML, which usually involves making additional requests for the content referenced by the HTML document: JavaScript files, CSS stylesheets, images, and so on. Each of these HyperText-referenced resources must be fetched from the server with an HTTP request/response cycle of its own.









**What is a MAC address and what is its role in network communication?** 
**Give an overview of the Link/Data Link Layer**
**What is included in an Ethernet frame?**
**Give an overview of the Internet/Network Layer and it's role.**
**What is IP?**
**What is IP address?** 
**What are the components of IP addresses?** 
**What is a packet in computer networking?**
**Why do we need both MAC addresses and IP addresses?** 
**What is DNS and how does it work?**
**How do port numbers and IP addresses work together?**
**What is a checksum and what is it used for? How is it used?**
**Give an overview of the Transport Layer.** 
**What are the fundamental elements of reliable protocol?**
**What is pipe-lining protocols? What are the benefits of it?**
**What is a network port?**
**What is a port number?**
**What is a network socket?**
**Is TCP connectionless? Why?**
**How do sockets on the implementation level relate to the idea of protocols being connectionless or connection-oriented?** 
**What are sockets on implementation and on a theoretical level?** 
**What does it mean that the protocol is connection-oriented?**
**What is a three-way handshake? What is it used for?**
**What are the advantages and disadvantages of a Three-way handshake?** 
**What are multiplexing and demultiplexing?**
**How does TCP facilitate efficient data transfer?**
**What is flow control? How does it work and why do we need it?**
**How TCP prevents from receiver's buffer to get overloaded with data?**
**What is congestion avoidance?**
**What is network congestion?**
**How do transport layer protocols enable communication between processes?**
**Compare UDP and TCP. What are similarities, what are differences? What are pros and cons of using each one?** 
**What does it mean that network reliability is engineered?**
**Give an overview of the Application Layer.** 
**What is HTML?**
**What is a URL and what components does it have?**
**What is a Query string? What it is used for?**
**What URL encoding is and when it might be used for?**
**Which characters have to be encoded in the URL? Why?**
**What is www in the URL?** 
**What is URI?**
**What is the difference between scheme and protocol in URL?**
**What is HTTP?**
**What is the role of HTTP?**
**Explain the client-server model of web interactions, and the role of HTTP as a protocol within that model**
**What are HTTP requests and responses? What are the components of each?**
**Describe the HTTP request/response cycle.**
**What is a** s**tate in the context of the 'web'?**
**What is** s**tatelessness?**
**What is a stateful Web Application?**
**How can we mimic a stateful application?**
**What is the difference between stateful and stateless applications?**
**What does it mean that HTTP is a 'stateless protocol?** 
**Why HTTP makes it difficult to build a stateful application?**
**How the idea that HTTP is a stateless protocol makes the web difficult to secure?** 
**What is a `GET` request and how does it work?** 
**How is `GET` request initiated?**
**What is the HTTP response body and what do we use it for?**
**What are the obligatory components of HTTP requests?** 
**What are the obligatory components of HTTP response?**
**Which HTTP method would you use to send sensitive information to a server? Why?**
**Compare `GET` and `POST` methods.**
**Describe how would you send a `GET` request to a server and what would happen at each stage.**
**Describe how would you send `POST` requests to a server and what is happening at each stage.**
**What is a status code? What are some of the status codes types? What is the purpose of status codes?** 
**Imagine you are using an HTTP tool and you received a status code `302`. What does this status code mean and what happens if you receive a status code like that?** 
**How do modern web applications 'remember' state for each client?**
**What role does AJAX play in displaying dynamic content in web applications?**
**Describe some of the security threats and what can be done to minimize them?**
**What is the Same Origin Policy? How it is used to mitigate certain security threats?**  

**What is CORS?**

**What determines whether a request should use `GET` or `POST` as its HTTP method?**
 **What is the relationship between a scheme and a protocol in the context of a URL?**
 **In what ways can we pass information to the application server via the URL?**
 **How insecure HTTP message transfer looks like?**
 **What services does HTTP provide and what are the particular problems each of them aims to address?**
 **What is TLS Handshake?**
 **What is symmetric key encryption? What is it used for?**
 **What is asymmetric key encryption? What is it used for?**
 **Describe SSL/TLS encryption process.**
 **Describe the pros and cons of TLS Handshake**
 **Why do we need digital TLS/SSL certificates?** 
 **What is it CA hierarchy and what is its role in providing secure message transfer?**
 **What is Cipher Suites and what do we need it for?**
 **How does TLS add a security layer to HTTP?**
 **Compare HTTP and HTTPS.**
 **Does HTTPS use other protocols?** 
 **How do you know a website uses HTTPS?**
 **Give examples of some protocols that would be used when a user interacts with a banking website. What would be the role of those protocols?** 
 **What is server-side infrastructure? What are its basic components?**
 **What is a server? What is its role?** 
 **What are optimizations that developers can do in order to improve performance and minimize latency?**