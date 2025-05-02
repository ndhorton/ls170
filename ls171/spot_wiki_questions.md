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

A Local Area Network is generally multiple computers and other devices connected via cables to a central switch or hub. The computers on the network can exchange data via the central switch or hub. In a Wirless LAN (WLAN), the computers and other devices are connected to the switch or hub through wireless technologies (radio waves). The fact that computers need to be directly connected to the switch or hub, whether via cables or wireless, is what makes a LAN 'local'.



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

An Application layer protocol, HTTP is the primary protocol of the web. HTTP defines how the messages passed between web client and web server should be structured. HTTP communications follow a simple pattern called the HTTP request/response cycle. An HTTP client sends a request message to a web server and then waits for an response. The server always sends a response, even if the response is simply an error message. HTTP is a stateless protocol, which means that each request/response cycle is treated as independent of any previous requests and responses. This means that web developers have to employ a variety of techniques to give web applications an appearance of statefulness.

After we enter `http://wwww.example.com/index.html` into the address bar, our browser prepares an HTTP request to the server named in the URL. Requests and responses are essentially text messages. The first line of the request, known as the request or start line, contains the HTTP method, the path, and the version of HTTP we are using. When, as here, we are retrieving content from the server, we generally use the `GET` HTTP method. If we were sending data to the server to alter data stored on the server, we would generally use the `POST` request. There are a handful of other methods.

As well as a scheme and a host, our URL contains a path component, `/index.html`. The path is the specific resource we are requesting from the server. In the early days of the web, paths corresponded to actual Unix-style pathnames on the web server's filesystem; this might still be the case, but since so much web content is now dynamically generated rather than static files, the path might now derive its meaning for the server from the web application logic instead of referring to an actual file.

An HTTP request may also contain headers, which are key-value pairs. From HTTP/1.1 onwards, a `Host` header became mandatory, whose value field in our case would be `www.example.com`. HTTP requests might also have a body, depending on the HTTP method used. The body contains data to be sent to the server. `GET` requests do not contain a body, though they can pass limited information to the server through the URL itself in the form of a query string. A query string component comes after the path, beginning with a `?` character, and contains key-value pairs; the query string is commonly used to pass search terms to search engines.

The host part of the URL gives the human-readable domain name of the server, but our HTTP request will need to be sent over the Internet, which relies on IP addressing. Resolving a human-readable domain name to its corresponding IP address is done by the Domain Name System (DNS). DNS is a hierarchical, distributed database that maps domain names to IP addresses. The database is distributed world-wide in a hierarchically traversable fashion, so that no single DNS server needs to keep a complete record of every domain name mapping. If the DNS server of our Internet Service Provider (ISP) does not have a record for `www.example.com`, the query is passed to another server further up the hierarchy, and if that server cannot find a record then the query will be passed on again, and so on until the query is resolved. 

Our HTTP request is encapsulated as the data payload of a TCP segment, whose Source Port will be randomly chosen and whose Destination Port, since we are sending our data to an HTTP server, will be port `80`. The protocols of common Internet services such as HTTP have well-known ports on which servers listen for incoming messages. Next, the TCP segment is encapsulated as the data payload of an IP packet, whose Destination IP Address is filled in thanks to a DNS query for `www.example.com`. The packet is then encapsulated as an Ethernet frame and sent via the switch to our router, our default gateway to other networks.

From our local router, the packet takes a series of hops between routers across the Internet and finally arrives at the router directly connected to our destination network. The packet is sent to the server, which de-encapsulates the various headers and trailers and passes the HTTP request to the web server process running on that machine. The web server processes the request and prepares an HTTP response.

An HTTP response is structured similarly to a request. Instead of a request line, the response begins with a status line, which contains a status code and accompanying status text which indicate the outcome of the request. For successful requests, this will be `200 OK`. Next, there are optional headers and an optional body. The body of the request often contains a requested resource, such as an HTML page.

When the HTTP response has been created, it will then be encapsulated in a TCP segment, which in turn is encapsulated in an IP packet and so on. The packet is sent back to the server's local gateway and back across the Internet to our router and finally to our computer. Our system strips the various headers and footers and delivers the HTTP response to our browser. The browser interprets and renders the HTML, which usually involves making additional requests for the content referenced by the HTML document: JavaScript files, CSS stylesheets, images, and so on. Each of these HyperText-referenced resources must be fetched from the server with an HTTP request/response cycle of its own.

Today, websites are likely to use HTTPS, the Secure version of HTTP. The difference is that HTTPS depends on the Transport Layer Security (TLS) protocol to encrypt the text-based HTTP requests and responses so that malicious parties cannot read sensitive information. In addition to encryption, TLS offers authentication and integrity services. TLS authentication verifies the identity of a party in the communication through the use of TLS certificates issued by trusted organizations known as Certificate Authorities (CAs). TLS integrity is a mechanism to detect whether a message has been faked or interfered with through the use of cryptographic hashing algorithms and asymmetric key cryptography.

TLS requires what is known as the TLS handshake before secure messages can be sent. The TLS handshake happens immediately after the TCP handshake and serves several purposes. The client and server need to agree on which version of TLS to use; they need to agree on a 'Cipher Suite', which cryptographic algorithms (ciphers) will be used for the various tasks involved in secure message exchange; and they need to exchange the data necessary for both parties to generate an identical symmetric key, which is used to encrypt and decrypt the messages. During the handshake, the server provides the client with its TLS certificate, which contains a public key to use to asymmetrically encrypt the sensitive data involved in the generation of the symmetric key that is used for application data encryption after the handshake. Since the TLS handshake is a complex process, it can add up to two round-trips of latency in addition to the round-trip required by the TCP handshake.



**What is a MAC address and what is its role in network communication?**

When a network-enabled device like a Network Interface Card (NIC), found in computers and laptops, is produced, it is assigned a Medium Access Control (MAC) Address. The human-readable form of a MAC Address consists of six pairs of hexadecimal digits. Since MAC addresses are generally fixed permanently at manufacture, the MAC address is sometimes called the physical address, or burned-in address.

MAC addresses are used by Data Link layer protocols such as Ethernet and WiFi for addressing individual hosts on the same network. If a host on a Local Area Network needs to send some data to a host on the same network, the data is encapsulated in an Ethernet frame, whose header contains a Source MAC Address and Destination MAC Address fields. The Ethernet frame is sent out through the network interface to the connected central switch.

The switch uses MAC addresses to forward frames to their intended recipient. To do this, the switch consults its MAC Address Table, which maps the Destination MAC Address in an Ethernet header to the specific port on the switch to which that host is connected.

In theory, MAC addresses should be unique, but in reality this is not always the case. Nevertheless, the chance of two devices with identical MAC addresses being attached to the same network is small enough that this rarely causes problems.

MAC Addresses are not suitable for inter-network addressing, which uses IP addressing to route data between networks. Where IP addresses are hierarchically-structured, MAC addresses are flat; where IP addresses are logical, MAC addresses are physical. A MAC address is not hierarchical, which would mean routers would need to keep track of every MAC address of every machine on the Internet to route packets. Furthermore, since MAC addresses are physical, these impossibly vast routing tables would need to be updated every time a portable device like a laptop or phone was disconnected from one network and connected to another.



**Give an overview of the Link/Data Link Layer**

The Link layer of the TCP/IP model roughly corresponds to the Data Link layer of the OSI model. The responsibilities of protocols at this layer are to address devices connected to the physical network and to move data over the network between them. The protocols at this layer are only concerned with moving data across the same network; they are not responsible for routing data between networks.

The form of addressing used at the Data Link layer is the MAC address, an address given permanently to a network-enabled device at manufacture. The most commonly used protocol at this layer is the Ethernet protocol. The PDU of the Ethernet protocol is called an Ethernet frame. An Ethernet frame encapsulates data from the layers above as a data payload, and adds a header and trailer, which contain metadata such as the Source MAC Address and Destination MAC Address.

A simple Local Area Network uses a switch as a central device to direct data traffic between hosts on the same network. Traditional switches operate at the Data Link layer, forwarding a frame received from one host to the host the frame is addressed to by using a MAC Address Table to map the Destination MAC Address given in the frame header to the port of the switch that the destination host is connected to.



**What is included in an Ethernet frame?**

An Ethernet frame consists of a header, an encapsulated data payload, and a trailer. The most salient fields of the header are the Source MAC Address (that of the sender) and the Destination MAC Address (that of the host the frame is intender for). The trailer contains a checksum, the Frame Check Sequence, to detect data corruption. If the checksum generated by the receiver doesn't match the FCS, the frame is dropped without re-transmission.



**Give an overview of the Internet/Network Layer and it's role.**

Protocols at the Internet/Network layer are responsible for enabling inter-network communication. The overwhelmingly dominant protocol at this layer is the Internet Protocol (IP). IP provides routing via IP addresses and encapsulation of data from the layers above (most proximately the Transport layer) as the data payload of a PDU called an IP packet. The header of a packet contains a Source IP Address and a Destination IP address, which is used to route the packet from a host on one network to a host on a different network.

The layer below, the Data Link layer, is responsible for addressing and exchanging data between hosts on the same network. However, the form of addressing used at the Data Link layer, MAC addressing, is not suitable for communication between hosts on different networks. MAC addresses are burned-in and flat. IP addresses, conversely, are logical and hierarchical. An IP address is hierarchical in that its structure reflects the location of the host within a hierarchy of sub-networks. An IP address is logical in that a new IP address can be assigned every time a device is connected to a new network. This means that unlike a MAC address, which is permanently assigned to a device and consists of a flat, mostly arbitrary number, an IP address reflects the current position of the device it identifies within a logical, hierarchical network address space. This allows IP addresses to be used by routers to route data between networks in a series of hops, with each hop bringing the data closer to its destination.

There are two versions of IP in use; IPv4 is the older and still more dominant version, while IPv6 is very gradually being introduced. An IPv4 address is only 32 bits in size, which limits the number of available addresses to around 4.3 billion (2^32). The actual available number is even smaller since some ranges are reserved for various purposes. This limit already requires workarounds involving Network Address Translation (NAT) to serve the existing number of devices. IPv6 addresses are 128-bit, yielding a truly vast address space that should ensure the availability of address spaces for the foreseeable future.

The human readable form of the 32-bit IPv4 address is divided into four groups of eight bits (octets), each of which is represented as a decimal number from 0 to 255, separated from each other by dots. E.g. `106.175.1.203`.

The Internet/Network layer provides the minimum functionality for the Internet to exist, allowing data to be sent from a host on one network to a host on another network, potentially anywhere in the world. However, to actually create a path from an application or process running on the sender to a process running on the receiver, we need protocols at the layer above, the Transport layer.



**What is IP?**

The Internet Protocol (IP) is the overwhelmingly dominant protocol at the Internet/Network layer of network communication. The role of IP is to provide routing through IP addressing, and to encapsulate data from the Transport layer into the data payload of a PDU called an IP packet. 

The older, still dominant version of IP is IPv4. IPv6 is gradually being introduced. IPv4 addresses are only 32 bits in length, which limits the available number of addresses to around 4.3 billion. This limit already requires workarounds in order to serve the existing number of Internet-connected devices. IPv6 addresses are 128 bits, providing a truly vast number of unique IP addresses (2^128), more than enough for the foreseeable future.

The human readable form of a 32-bit IPv4 address is divided into groups of eight bits (octets), each of which is represented as a decimal number from 0 to 255, with the octets separated by dots. E.g., `106.128.1.202`.

IP addresses are logical and hierarchical. IP addresses are logical in that they can be assigned and revoked as devices are connected and disconnected from various networks. The IP address space is divided into a hierarchy of sub-networks (in a scheme known as subnetting). These properties make IP addresses suitable for routing data between different networks, since an IP address essentially gives the current position of a host and its local network within the IP network. This allows routers to route data between networks and across the Internet in a series of hops, with each hop bringing the packet closer and closer to the destination. This is impossible with MAC addresses, since a MAC address is flat (mostly arbitrary) and generally fixed or 'burned-in'.

As well as routing capability via IP addresses, IP provides encapsulation of data from the Transport layer above into the data payload of an IP packet. If the data is large it may be fragmented, sent as multiple packets, and then reassembled by the receiver; several fields of the IP packet header relate to fragmentation including the Fragment Offset field. The header also contains the Source IP Address, Destination IP Address, and a field containing a Time to Live (TTL) value. The TTL value indicates how many hops a packet can take before it is discarded, and is decremented at each hop. This is to prevent routing errors keeping data bouncing around indefinitely and causing network congestion.

IP enables us to send data from a host on one network to a host on another network, potentially on the other side of the world; thus, IP provides the functionality for a minimum viable Internet.



**What is IP address?** 

An IP address is a hierarchical, logical address that is a feature of the Internet Protocol (IP), the dominant protocol at the Network/Internet layer. IP addresses allow data to be routed between a host on one network and and host on another network.

There are two versions of IP in use. The older and still more dominant, IPv4, has 32 bit addresses, while IPv6 has 128-bit addresses. Since 32 bits only provides around 4.3 billion IPv4 addresses, workarounds are already needed to serve the existing number of Internet-connected devices. IPv6's 128 bit address space provides a truly vast number of unique addresses, more than enough for the foreseeable future.

In human readable form, IPv4 addresses are divided into four groups of eight bits, or octets. Each dot-separated octet is represented as a decimal number between 0 and 255. E.g. `106.128.1.233`

MAC addressing, the form of address used by the layer below the Network layer, the Data Link layer, is unsuitable for inter-network addressing since MAC addresses are flat (mostly arbitrary) and burned-in. IP addresses, by contrast, are hierarchical and logical. The IP address space is hierarchically divided into subnetworks of decreasing size (in a scheme known as subnetting). IP addresses are logical in that they can be assigned and revoked as devices are connected to and disconnected from any given subnetwork within the IP network. This means that an IP address gives the current logical position of a host and the subnetwork it is connected to within the overall IP network, and this is why IP addressing is suitable for routing between networks. Routers can route traffic from one network to another, from one router to another, in a series of hops across the Internet, with each hop bringing the data closer to its destination. Each router only needs to maintain records in its routing table for the proximate routers in the IP network hierarchy, whereas with flat MAC addresses, each router would need to maintain the address of every machine on the Internet in order to forward traffic.



**What are the components of IP addresses?** 

Structure of an IP address.

Since these are meant to be questions that expand beyond the course, I think it is also alluding to the Network part and the Host part. The Network part identifies the network to which the device belongs, and determines the range of IP addresses within a certain subnet. This is used by routers to route packets to the correct network defined by the Network address. The Host portion identifies the specific device on the network. This is used to deliver the packet to the specific destination host. The Network address can be derived from an IP address when combined with a Subnet Mask or CIDR Network Prefix. An IP address in binary form is a string of bits. The first N bits form the Network part of the address, that is the part of the address common to all IP addresses within that subnet. The remaining bits identify the particular host within that subnet. The network prefix in CIDR notation gives the number N, the number of bits that define the network. If we set all remaining bits (the Host part) to `0`, we have the Network Address of the subnet. If we set all the remaining bits to `1`, we have the Broadcast address of the subnet. All remaining combination of bits in the Host part are valid IP addresses for individual hosts within the subnet (including the address of the router serving as gateway to the subnet).

The below is mostly from LS, it does not go in to the details of Network Part and Host Part at all:

"IP addresses are logical. This means that they are assigned when a device is connected to a particular network. The IP address the device will be assigned must be chosen from a range of addresses available to the local network to which it is connected. This range is defined by a network hierarchy. The overall network is split into logical subnetworks, with each defined by the range of IP addresses in the subnet. The first address in this range is the Network Address and the last is the Broadcast Address. This division of a network into parts is known as sub-netting. Subnets can be split into further subnets, creating tiers in a hierarchy."

"The Network Address is the first address in a range of IP addresses assigned to a specific network segment, e.g. `109.156.106.0` in the range `109.156.106.0` to `109.156.106.255`. A network address uniquely identifies a network segment within the larger Internet hierarchy. This identification is essential for routing. A router that wants to forward an IP packet to any address in the entire range only needs to keep a record of which router on the network controls access to the segment with that network address. This creates a hierarchical structure that simplifies routing. Network addresses help define the boundaries of subnets. When networks are divided through subnetting, each subnet gets its own network address."

""

**What is a packet in computer networking?**

A packet in computer networking is the PDU of the Internet Protocol, the predominant protocol used at the Network/Internet layer.

**Why do we need both MAC addresses and IP addresses?**

The course itself only covers why we need IP addresses in addition to MAC addresses for inter-network communication. IP addressing was developed because of problems with scalability inherent to MAC addressing.

LSBot on why IP addresses cannot simply replace MAC addresses:

* Hardware Identification. Network interfaces need to be identified at the physical level when they first join a network and before the host receives an IP address
* Local Network Efficiency. On a local network, devices communicate directly via MAC addresses without the overhead of IP processing
* Network Protocol Independence. MAC addressing works regardless of which higher-level protocols are being used, allowing for flexibility in network design.

I think essentially, MAC addresses are protocol-agnostic whereas IP addresses are specific to a more abstract way of delivering data between different networks. Different physical technologies require different protocols beneath the Network layer (e.g. Ethernet vs WiFi) and they can all use MAC addresses to identify different types of physical device. IP addressing works at a more abstract level, where the problem space is more to do with routing (a graph problem essentially) rather than the low-level details of getting bits from one type of physical device across a physical medium to another physical device. The aspects of communication the address schemes deal with are very different, and so IP addresses cannot simply replace or supersede the low-level MAC addresses.



**What is DNS and how does it work?**

The Domain Name System (DNS) is a distributed database that maps memorable Domain Names (such as `www.google.com`) to IP addresses (such as `172.217.169.4`). DNS means that, for instance, people only need to remember the Domain name of a web server and not the IP address, which is generally much harder to remember, and the web browser can automatically make a DNS request in order to obtain the IP address.

DNS databases are stored on DNS servers, which are hierarchically organized. This hierarchical organization means that no single DNS server needs to store the entire database, which would be prohibitively large and complex to update. If a DNS server cannot find a record for a DNS query, the query is relayed to another server in the hierarchy, and so on until the query is resolved.





**How do port numbers and IP addresses work together?**

The combination of an IP address and a TCP or UDP port number combine to enable end-to-end addressing for communication between networked processes running on different devices on different networks. The IP address uniquely identifies a host and the port uniquely identifies a process running on that host.

An IP address and a port number thus define what is known as an Internet socket. An Internet socket, such as a TCP/IP socket, is a communication end-point for inter-process communication between two networked processes, usually though not always running on different machines.

Sockets are implemented as objects, which can maintain state about a connection. For instance, a TCP server will instantiate a TCP/IP listening socket object defined by the IP address of the server and the TCP port that will be used to receive incoming messages. When a client sends a SYN message to the server, the server will instantiate a new TCP/IP socket object defined not only by the IP address/port pair of the server but the address/port pair of the client. These four pieces of information are known as a four-tuple. This new socket object is then used as the communication endpoint for the rest of the TCP handshake and for the lifetime of this connection between client and server.





**What is a checksum and what is it used for? How is it used?**

Checksums are used for error detection by protocols at various different layers of network communication. Every bit of data transmitted over the network is subject to the possibility of errors and data corruption. 

The sender generates a checksum using a common algorithm and the PDU data as input, and then includes the generated value in the checksum field of the PDU header or trailer. In an Ethernet frame, this is the Frame Check Sequence field in the trailer; TCP and UDP PDUs include a Checksum field in the header.

The receiver then inputs the received data into the same algorithm and if the values do not match then an error is detected and the PDU is discarded. Ethernet and UDP simply drop the PDU at this point, but TCP, since it offers reliable data transfer, can then initiate retransmission of the lost data.

Since protocols at the layers above and below implement checksums, this could be seen as making Network layer checksums redundant; IPv4 includes a checksum header, but IPv6 has dispensed with it.



**Give an overview of the Transport Layer.** 

The Transport layer is situated below the Application layer and above the Network/Internet layer. The layers below the Transport layer combine to enable a host on one network to send data to a host on another network. However, once the data reaches the destination host, these lower level protocols cannot direct the data to the application, service or process running on the destination host that the data is intended for.

Furthermore, there may be many networked processes running on a host. Even on a home computer or laptop, we may have a web browser, an email client, a messaging application, and a music streaming service running at the same time. The network layers up to the Internet/Network layer provide what is essentially a single channel of network communication defined by IP addressing. The role of the Transport layer is to multiplex data streams from the various networked processes we have running on a single machine over this single channel and then to demultiplex them at the other end, such that a process running on one host can exchange data with a process running on a different host. This is to say, the Transport layer combines with the lower layers to provide end-to-end inter-process communication between networked processes running on different hosts on different networks.

The predominant protocols at the Transport layer are the Transmission Control Protocol (TCP) and the User Datagram Protocol (UDP). Both TCP and UDP offer multiplexing and demultiplexing of data over a network connection via a system of ports. A port is a number used as a unique identifier for a process running on a host.

The PDU of the TCP protocol is called a TCP Segment, which encapsulates Application layer data as a data payload. A segment header includes fields for the Source Port and Destination Port. The Source Port is the port number (the unique identifier) for the application or process sending the data. The Destination Port is the port number of the process the data is intended for. The TCP segment is encapsulated in turn as the data payload of an IP packet, whose header contains the Source IP Address and Destination IP Address. IP addressing is used to route the packet to the destination host on the destination network. The destination host de-encapsulates the TCP segment, and then the Destination Port is used to direct the data to the correct process running on that host. It is therefore the combination of an IP address and Transport layer port number that forms an end-point for inter-process communication between networked processes. These networked inter-process communication end-points defined by an IP address/port pair are known as internet sockets. This is how multiplexing and demultiplexing is achieved by Transport layer protcols.

In addition to this, TCP provides reliable data transfer over an unreliable connection. None of the protocols at the layers below the Transport layer offer reliable delivery of data. Sometimes packets get lost, or data becomes corrupted and packets are dropped as a result, and neither Data Link protocols nor IP handle re-transmission of lost data. This makes the network below the Transport layer inherently unreliable. TCP offers reliable delivery of data, such that data sent through a TCP/IP internet socket is guaranteed to arrive eventually at its destination socket and in the correct order. TCP offers several services that combine to guarantee reliability: in-order delivery, error detection through checksums, re-transmission of lost data, and de-duplication of duplicate segments that occur as a result of the system of re-transmissions.

To provide these services, TCP uses a system of sequence numbers and acknowledgments. Each segment sent contains a Sequence Number field in the header. IP routes are constantly changing due to network conditions changing, and sometimes packets arrive in a different order to that in which they are sent. The Sequence Number header allows data sent via TCP to be reassembled in the correct order, guaranteeing in-order delivery of data to the destination process. The Sequence Number is also used to discard duplicate segments that arrive as a result of the system of acknowledgements used to handle re-transmission of lost data. When a segment is sent, a timer is set, and if the sender does not receive an acknowledgment for the segment with that sequence number before the timer elapses, the segment is re-sent.

When a receiver receives a segment, the segment is checked for errors using the Checksum provided in the header. If running the same algorithm on the segment data does not produce the same value as that given in the Checksum field, the segment is dropped. Otherwise, the receiver sends an acknowledgment segment back to the sender using the Acknowledgement Number header field to confirm delivery of a segment with a particular Sequence Number. Since acknowledgements can also get lost over the network or not arrive before the timer elapses, the receiver can end up receiving multiple copies of the same segment. De-duplication is handled by discarding all but one copy of a segment with a given sequence number.

When a protocol sends one message and waits for an acknowledgement before sending another, this is known as a stop-and-wait protocol. However, such a strategy does not make full use of available bandwidth. Instead, TCP makes use of a strategy called pipelining. A given number of messages (a number whose variance is known as the 'window' size) are sent over the network without waiting for acknowledgments. These messages are thus fed into the transmission 'pipeline'. Once the acknowledgments come in (after any necessary re-transmissions), the 'window' is moved on to the next subsequence of messages to be sent. There are various algorithms to manage precisely how pipelining occurs, such as Go-Back-N and Selective Repeat, but the principle remains the same.

Pipelining can give rise to a problem known as Head of Line (HOL) Blocking. A consequence of in-order delivery is that if one segment in a sequence of segments is lost and needs to be re-transmitted, subsequent segments in the sequence must be queued in a buffer until the lost segment has been re-transmitted and processed. The subsequent messages are 'blocked' until the delayed message is processed. This delay adds to the total Queuing Delay, one of the elements of network latency.

In order to facilitate the services it offers, TCP is a connection-oriented protocol that requires an initial 'three-way handshake' to initiate a connection. The connection involves a client-server relationship where the server implements a socket object set to listen for incoming messages on a particular TCP port. The port used by the server is often a conventional port used for the particular application service the server provides; e.g., an HTTP server conventionally uses port `80`. The TCP three-way handshake is initiated by a client sending a SYN ('synchronize') segment to the server. At this point, the server creates a new socket object defined not only by the server's IP address and the service's port number but also by the Source IP Address and Source Port of the message received from the client. These four pieces of information define the socket object used for the remainder of the handshake and the connection thereafter, and are called the 'four-tuple'. The server then sends a SYN-ACK ('synchronize-acknowledgement') segment to the client. The client then sends an ACK ('acknowledgement') segment and at this point application data can begin to be transferred. `SYN` and `ACK` are boolean fields in the TCP Segment header.

The entire handshake process therefore adds a round-trip of latency before actual application data can begin to be exchanged. This is just part of the performance price of the complexity involved in TCP's reliable delivery. TCP does employ strategies to mitigate the performance cost in the form of Flow Control and Congestion Avoidance.

Flow Control is a mechanism to avoid overwhelming the receiver with data. Without flow control, the receiver might not be able to process incoming segments fast enough to prevent buffer overflow, which leads to lost data and increased re-transmissions, slowing things down further. To implement flow control, both client and server can set the Window Size header field to limit the rate at which the other party sends data.

If flow control avoids overwhelming the receiver with data, Congestion Avoidance is designed to avoid overwhelming the network itself. Network congestion is a situation where more data is being transferred over the network than there is capacity to buffer, process, and transmit the data. Intermediate network devices such as routers have finite buffer sizes, limits to how fast they can process data, and a finite bandwidth or bitrate for pushing data onto the wire. Congestion avoidance uses data loss, based on the number of re-transmissions occurring, as a feedback mechanism to detect network congestion, and the transmission window can be lowered accordingly. The transmission window affects how many segments are sent at a time without waiting for acknowledgments. The exact algorithm for determining the transmission window's initial size and how much to lower it based on network congestion will depend on the variant of TCP being used.

Despite these mitigations, TCP's complexity makes it slower than UDP. UDP offers multiplexing and demultiplexing via ports, simple error detection through checksums, but does not offer reliable, in-order delivery. For applications that need fast, low-latency data transfer and are not as concerned with reliable delivery, UDP may be the better choice; audio and video calling, DNS queries, and multiplayer video games are examples where UDP is commonly used. As well as speed, UDP offers flexibility; developers are free to implement only such reliability features as they need on top of the UDP protocol.



**What are the fundamental elements of reliable protocol?**

The fundamental elements needed for reliable data transfer are in-order delivery, error detection, re-transmission of lost data, and de-duplication of duplicate messages received as a result of re-transmissions.

**What is pipe-lining in relation to network protocols? What are the benefits of it?**

With reference to reliable data transfer, a 'stop-and-wait' protocol is one where the sender sends a message, starts a timer, and then waits for an acknowledgment to be sent back by the receiver before sending another message. If the timer elapses before an acknowledgement is received, the message is re-sent.

The problem with this system is that the sender spends much of its time waiting for an acknowledgment. Even when no messages go astray, there is still a whole round-trip of latency between each message being sent. This inefficiency is why TCP (Transmission Control Protocol) uses pipelining.

With pipelining, the sender sends a multiple messages one after the other without waiting for acknowledgments. The receiver still sends acknowledgments, and the sender still re-transmits messages that do not receive an acknowledgement before the timer elapses. Thus the system is still reliable. There are different algorithms for implementing pipelining, such as Go-Back-N and Selective Repeat. All approaches use the concept of a 'window' whose size determines how many messages can be sent without waiting for acknowledgments. Once the messages in the window have received acknowledgments, the window is moved on to the next group of messages.

The advantage of pipelining is that it makes efficient use of the available bandwidth; less time is spent simply waiting for acknowledgments and more time can be used for transmitting data.



**What is a network port?**

A network port is an integer in the range 0 to 65,535 that uniquely identifies a process running on a host. The first 1024 port numbers are given over to well-known services. For example, an HTTP server conventionally listens on port `80`, while an HTTPS server conventionally listens on `443`.

Since there are usually multiple networked processes running on a host, and a host has a single IP address, we need a means to direct data from a specific process running on one host to a specific process running on another host. The purpose of ports is to enable multiplexing and demultiplexing of multiple data streams over the single channel represented by an IP address. If the IP address is like the street address of a apartment building, the port functions as an apartment number. Or again, if an IP address is like the telephone number of an office, then the port is like the extension to reach a specific person in that office.

**What is a network socket?**

A network socket is an end-point for inter-process communication between networked processes defined by an address-port pair.

**Is TCP connectionless? Why?**

No, TCP is connection-oriented for the purpose of facilitating reliable data transfer. A connection is established because it makes it easier for both parties to maintain state about sequence numbers, acknowledgements sent or received, and so on. For instance, part of the purpose of the TCP handshake is for both parties to synchronize sequence numbers, to coordinate the meaning of the sequence numbers used in relation to the sequence of messages.

**How do sockets on the implementation level relate to the idea of protocols being connectionless or connection-oriented?**

Sockets are implemented in programming languages as objects. A common API is the Berkeley Sockets API. There are differences between the way socket objects are used for a connectionless protocol like UDP and a connection-oriented protcol like TCP.

For UDP, a process creates a socket object defined by the IP address of the host the process is running on combined with a port number. This socket object is then set to `listen()` for incoming messages. These messages can come from any host in any order.

For TCP, a connection-oriented protocol, things work differently. As before, a socket object is created defined by the IP address of the host and a port number. The socket is set to `listen()`. However, when a SYN message is received from another networked process, a new socket object is created for this specific connection, defined not only by the address-port pair of the receiver but also the address-port pair of the sender. These four piece of information are called the four-tuple. This connection socket object is then used for the remainder of the TCP handshake and all subsequent message exchange for the lifetime of the connection. This leaves the original listening socket object free to receive incoming connection requests from other networked processes, each of which is then given its own connection socket object.



**What are sockets on implementation and on a theoretical level?** 

At the most abstract level, a socket is an communication end-point for inter-process communication. Two common implementations of this abstract concept are the Unix socket and the Internet socket.

A Unix socket is a communication end-point used for inter-process communication between processes running on the same machine. This permits processes running concurrently on the same machine to pass messages and exchange data.

An Internet, like a TCP/IP socket, is a communication end-point used for inter-process communication between networked processes, often though not always running on different hosts. An Internet socket is defined by an IP address/port pair.

**What does it mean that the protocol is connection-oriented?**

A connection-oriented protocol establishes a virtual connection between two communicating parties before any application data is exchanged. Unlike connectionless protocols, connection-oriented protocols maintain a persistent communication channel throughout the entire message exchange.

Connection-oriented protocols facilitate certain services, such as reliable data transfer, but they are heavier in complexity and thus generally less performant. Connection-oriented protocols need some kind of handshake before any data exchange takes place, and generally both parties in the communication need to maintain state about the connection.

**What is a three-way handshake? What is it used for?**

TCP is a connection-oriented protocol. The three-way handshake is a process during which a connection is established.

On the server side, a socket object is created defined by the IP address of the host and a port number; this socket object is set to `listen()` for incoming messages from any source.

TCP segments contain the boolean header fields `SYN` and `ACK` which are used in the three-way handshake. The client sends a `SYN` segment (a segment whose `SYN` field is set to `1`, meaning 'true') to the server. The server then responds with a `SYN`/`ACK` segment (both fields set to `1`) back to the client. The client sends an `ACK` segment to the server, and at this point application data exchange can begin. The handshake establishes a persistent connection, a dedicated communication pathway between the client and server that lasts for the duration of the message exchange, defined by the four-tuple, the IP address/port pair of the server and the IP address/port pair of the client.

**What are the advantages and disadvantages of a Three-way handshake?** 

The advantage of the handshake is that it establishes a connection and facilitates the reliability services offered by TCP. For instance, it allows client and server to synchronize sequence numbers. The disadvantage of the three-way handshake is that it costs an entire round-trip of latency before actual application data can be exchanged.

**What does it mean that network reliability is engineered?**

The underlying network layers beneath the Transport are inherently unreliable. This means that any corrupted packets are simply discarded, and lost packets are not re-transmitted.

Network reliability has therefore been built on top of this inherently unreliable network.

This reliability has been engineered by solving the various problems involved in providing reliability over the unreliable underlying network. This has involved a series of trade-offs, most notably between reliability and performance.

**Give an overview of the Application Layer.** 

The Application layer is the topmost layer of both the OSI model and the TCP/IP model, above the Transport layer. The OSI model defines two layers between the Transport layer and the Application layer (the Session and Presentation layers), but these are rarely of practical use in describing how modern networked applications operate.

The Application layer is still a layer of protocols that address an aspect of communication; it does not represent actual networked applications themselves. For instance, the HTTP protocol is an Application layer protocol, which is made use of by networked applications such as web browsers and web servers.   Application layer protocols are the protocols with which applications most often directly interact, but application may also interact with Transport layer protocols like TCP.

The protocols below the Application layer are mostly concerned with how messages are transferred from one point on the network to another. Application layer protocols are used to give intelligible structure to the messages themselves. Application layer protocols represent syntactical rules for how applications should talk to each other.

Since there are many types of application with very different requirements for how they should communicate, there are many different Application layer protocols. The rules for how an email client should communicate with an email server are very different from the rules for how a web client should communicate with a web server because emails and web pages are very different concerns.

**What is HTML?**

HTML, or HyperText Markup Language, is a markup language used to give uniform structure to web resources. HTML is the language used to create, structure and organize web content, and to give it semantic meaning for the web client. HTML is foundational to almost every website.

**What is a URL and what components does it have?**

A URL, or Uniform Resource Locator, is a string of characters that locates a specific resource. A URL is a subset of the more general concept of a Uniform Resource Identifier (URI), a string of characters that identifies a resource. URLs, in addition to identifying a resource, also specify the location of a resource and a means of accessing it. URLs provide a system of addressing for web resources.

There are several components that make up a URL: scheme, host, port, path, and query string. We can use the following URL as an example: `https://www.google.com/search?q=launch+school`.

The scheme and the host are mandatory components. The scheme tells the web browser how to access the resource. Our example URL has the scheme 'https', which lets the browser know that it needs to use the HTTPS family of protocols to access the resource. The scheme is always followed by `://`. The host is the domain name of the server. The browser can look up the IP address of the server from the domain name via DNS in order to address the IP packet(s) in which the request will be sent to the server. In our example, the host is `www.google.com`.

The third component, the port, is only required if the server is using a port different to the default port. In our example, Google is presumably using port `443`, the default port for HTTPS servers, since we have not specified differently. The port is separated from the host by a `:`.

The next component is the path, which is optional. The path is used to specify a specfic resource on the server. In days gone by, the path generally referenced an actual file within the server's filesystem. Now, with so much web content being dynamically generated by web applications, the meaning of the path is just as likely to be an aspect of the application logic rather than relating to an actual file or directory structure. In our example the path is `/search`.

The final component, also optional, is the query string. The query string begins with a `?` and consists of a series of query parameters, which are key-value pairs where key and value are separated by an `=` symbol. Multiple key-value pairs are separated by `&`. Query strings are used to send a limited amount of non-sensitive data to the server. Our example, a search engine search request, is one of the most common uses of the query string. Our Google search example has the query string `?q=launch+school`. The key `q` takes the value `launch+school`.

**What is a Query string? What it is used for?**

The query string is an optional URL component that can be used to send a small amount of non-sensitive data to the server in the form of query parameters, which are `=`-separated key-value pairs. The query string begins with a `?` and is made up of query parameters, which are separated by `&` if there are more than one.

There are HTTP methods that generally request information or resources from the server, e.g `GET`, and methods that send data to the server in the body of the request in order to change state on the server, e.g. `POST`. In certain circumstances, where there is a small amount of non-sensitive data, such as the terms of a search engine query, a `GET` request is commonly used to send the search terms to the server via the query string of the URL.

Part of the reason for using `GET` in this situation is that even though we are submitting data to the server, the operation is still essentially 'read-only'; even though we are submitting some data, we are simply retrieving information from the server rather than changing state on the server. Furthermore, putting the search terms in the URL works well with browser features like bookmarking. 

Less commonly, the query string can also be used with methods like `POST` in order to send some supplementary data along with the data in the body of the request. However, the information sent in a query string should not be sensitive information; URLs are commonly cached and logged at various points across the network path from client to server, and can generally be assumed to be visible to third-parties; the query string is therefore not suitable for data about the Session, passwords, personal and financial details, etc.



**What URL encoding is and when it might be used for?**

URLs can contain only a subset of the first 128 ASCII characters. Extended ASCII, control characters and whitespace, and non-ASCII Unicode characters cannot be represented as themselves. There are, in addition, certain reserved characters that have special meaning in a URL (such as `&`) that should only be included in literal form for their URL-specific purpose. All characters other than alphanumerics and a handful of punctuation characters must be ensured to be in encoded rather than in their literal form before they are added to a URL.

URL encoding is the process of substituting alternative patterns of acceptable characters for these proscribed characters. The characters are encoded as a representation of the UTF-8 codepoints that make up the character. Each URL encoding pattern consists of a series of between one and four subpatterns; these subpatterns each consist of the reserved `%` character followed by a two-digit hexadecimal representation of one byte of the UTF-8 representation of the character being encoded. For instance, we cannot permit literal spaces in a URL; the one-byte UTF-8 code for a space character is `20` in hexadecimal, and thus the URL encoding for a space is `%20`.



**Which characters have to be encoded in the URL? Why?**

Characters must be encoded before being added to a URL under the following conditions: if they do not fall within the subset of the standard ASCII character set; if the character could be interpreted falsely as a metacharacter reserved to a URL special meaning, or could be wrongly interpreted by systems that commonly interact with URLs (for instance, hypertext references in HTML).

The reason for this is that URLs are restricted to the standard ASCII character set. Even some of these will be interpreted by browsers and other systems as having special syntactical significance within a URL. It is thus necessary to represent these characters safely, so that web systems understand them as data points rather than syntax. Any characters that are not within the standard ASCII set will need to be encoded to be represented within a URL at all.



**What is www in the URL?** 

DNS is a hierarchical system, whereby each dot-separated component in a fully qualified domain name, starting from the right and reading left, represents a narrower, more specific tier of the hierarchy. The component furthest right is the Top Level Domain (TLD), e.g. `com` or `org`. The next component to the left, in combination with the TLD, is generally called the domain name. For example, in `google.com`, `com` is the TLD and `google.com` is the domain name. A component to the left of this is generally called the subdomain, e.g. `www` in `www.google.com`.

`www` is a common subdomain used in the fully qualified domain names of web servers. `www` stands for World Wide Web, and has become the conventional subdomain for websites. This is simply a convention that emerged in the early days of the web, and it is now commonly optional (e.g. `example.com` redirects to `www.example.com` or vice versa.)



**What is URI?**

The concept of the Uniform Resource Identifier (URI) is to provide a system of identification for resources. A URI is a string of characters that identifies a resource. The precise nature of these resources, and the uses of the identifier, vary according to the 'scheme' of the URI. A scheme is a system of rules governing the provision of identifiers within that scheme. URIs are intended to act as distinct points within an information space.

Uniform Resource Locators, URLs, are a subset of URIs that, in addition to providing an identifier for a resource, also provide a means of locating and accessing a resource. We could see URLs as navigable points within the information space of the World Wide Web.

 

**What is the difference between scheme and protocol in URL?**

Within a URL, the scheme, e.g. `http`, generally tells a web client which family of protocols can be used to access a resource: in this case, the HTTP family. Which specific protocol, e.g. HTTP/1.1, will be used for a request involving the URL will generally depend on factors beyond the remit of the URL.

The scheme is a component of the URL,  conventionally given in lowercase, followed by the characters `://`.

Protocols and families of protocols are conventionally given in uppercase. The protocol is the actual set of rules and convention used for network communication.

Within the broader concept of a URI, the scheme is a system under which identifiers can be logically assigned, and within URIs the scheme does not necessarily refer to a communication protocol even indirectly.





**What is HTTP?**

HTTP, or HyperText Transfer Protocol, is an Application layer protocol that provides uniformity to web resource transfer. HTTP is a set of rules that governs how the messages exchanged between web client and web server are structured.

HTTP adheres to a client-server model in which a web client sends a 'request' to a web server and the server replies with a 'response'. The most common web clients are web browsers like Firefox, Chrome etc. Web servers are hosts running web server software (such as Apache or NGINX) that can handle inbound requests, and the role of the server is to send responses back.

All communications take place within this request-response cycle, where each request from a client receives a response from the server, even if the response is an error message. We can think of the requests and responses as text messages structured according to rules that make the messages intelligible by the other party in the communication. Requests consist of a start line, headers and an optional body. Responses consist of a status line, optional headers, and an optional body.

HTTP is a stateless protocol, meaning that each request-response cycle is independent of all previous and following cycles. The web server does not need to maintain state between requests, and if a request breaks en route to the server, no cleanup is necessary. Although this statelessness helps make the web distributed, resilient, and hard to control, it poses problems for web application developers who wish their applications to provide a stateful experience.

HTTP has certain inherent security risks. Being a text-based protocol, HTTP is susceptible to third-parties intercepting messages and reading sensitive information. There are various mitigations against this, most notably HTTPS, HyperText Transfer Protocol Secure, the secure version of HTTP, which uses the Transport Layer Security (TLS) protocol to encrypt messages.

Along with HyperText Markup Language (HTML), and URLs (Uniform Resource Locators), HTTP is one of the foundational technologies of the World Wide Web. The web is a service accessible via the internet, and was developed in the late-1980s by Tim Berners-Lee and Robert Caillau at CERN. 



**What is the role of HTTP?**

HyperText Transfer Protocol (HTTP) is an Application layer protocol that gives uniformity to web resource transfer. HTTP is the primary protocol concerned with data transfer between applications on the World Wide Web, and, along with HTML and URLs, HTTP is one of the foundational technologies of the web. HTML provides a uniform structure to web content, URLs provide a uniform means of accessing resources, and HTTP gives uniformity to the transfer of web resources.

We can see HTTP as the standardized set of rules that governs how information is exchanged between web client and web server. HTTP implements the web's client-server model, wherein a web client sends a request to a server and the server sends back a response to the client. This is called the request-response cycle. Requests and responses can be thought of as text messages or strings. A request consists of a start line, headers, and an optional body. A response consists of a status line, optional headers and an optional body.

HTTP is a stateless protocol, meaning that each request-response cycle is independent of any request-response cycles before or afterward. The server does not need to maintain state between cycles, meaning that if a request breaks en route to the server, there is no cleanup required. This statelessness keeps the web resilient, distributed, and hard to control, but it can pose problems for developers building web applications, who need to find ways to simulate statefulness over a stateless protocol.

Since HTTP is text-based, it is inherently vulnerable to messages being intercepted and read, exposing sensitive data like Session IDs. In order to combat this, there is HTTPS, the Secure version of HTTP. HTTPS relies on the Transport Layer Security (TLS) for secure data transfer.

HTTP's role is to govern the structure of the messages exchanged between web client and web server. However, the role of delivering these messages falls to lower level protocols. Traditionally, HTTP requests and responses were sent over TCP/IP, but HTTP/3 uses the QUIC protocol over UDP.



**Explain the client-server model of web interactions, and the role of HTTP as a protocol within that model**

Web communications follow a client-server model. A web client sends a request to a web server. The web server receives the request, processes it, and sends a response. This is called the request-response cycle. Every request by a client receives a response from the server, even if the response is simply an error message. 

The most common type of web client is a web browser, like Firefox, Chrome, Edge, Safari, etc. A web server is a system whose role is to listen for incoming requests and send appropriate responses. 'Web server' is an overloaded term that can refer both to this computer system and to software running on that system. Furthermore, the server infrastructure of modern websites will tend to have at least three components: the web server, the application server, and the data store.

The web server is the server whose role is to listen for requests and serve content back in responses to those requests. If a request is for a simple file, like a static HTML page, the web server can handle this itself. However, an increasing amount of web content is dynamically generated, and for such requests the web server typically forwards the request to the application server. The application server runs the logic of a web application. The request will be handled by the application server and a response will be generated according to the logic of the web application. This generated content will be returned to the web server, which sends it to the client as an HTTP response. In carrying out its responsibilities, the application server will often consult some kind of persistent data store: a relational database, a key-value store, etc. Regardless of implementation, the role of the data store is to persist state between stateless request-response cycles, to store any data that should not be thrown away after each cycle: user details, online shopping orders, posts on a forum or social media site, etc.

The role of HTTP is that of a standardized set of rules providing uniformity to the structure of requests and responses, so that servers can interpret requests and clients can interpret responses. The responsibility for actually transporting these requests and responses between the client host and server host is delegated to lower level protocols. Previously this was almost invariable TCP and IP, but this has changed with HTTP/3, which uses the QUIC protocol over UDP.



**What are HTTP requests and responses? What are the components of each?**

An HTTP request is a message that a web client sends to a web server, and an HTTP response is the message that a web server sends to the web client in response to a request. The structure of requests and responses is defined by the HTTP (HyperText Transfer Protocol), essentially a set of rules governing how applications should talk to each other on the web. Since HTTP is a text-based protocol, we can think of both requests and responses as text messages exchanged between server and client.

The most common type of web client is a web browser, such as Firefox, Chrome, etc. A web server is a computer system running software like Apache or NGINX. HTTP implements the web's client-server model. A web client sends an HTTP request to a web server, which processes the request and always sends a response, even if the response is an error message.

The components of an HTTP request are: the start line, headers, and an optional body. The start line, or request line, contains the HTTP Method (such as `GET` or `POST`), the path (or, 'request-URI'), and the HTTP version.

HTTP is the primary protocol for the transfer of web resources. A web client generally sends an HTTP request to request the web server transfer a web resource to the web client. The most common HTTP method used for this is `GET`. Sometimes the web client needs to send data to the web server; the most common HTTP method used in this situation is `POST`. Typically, a request is made based on a URL, whether entered by the user in the browser's address bar, or referenced in a web page's HTML.

The path, or request-URI, contains the URL path component and the query string, if there is one.

Since HTTP/1.1, released in 1997, HTTP requests have required at least one header, the `Host` header, whose value is set to the host part of the URL to which the request is made.

Whether an HTTP request has a body or not depends on the HTTP method. `GET` requests should not have a body, though limited amounts of non-sensitive data can be sent to the server via the query string. `POST` requests, often used for form submissions, generally have a body containing data such as user data entered into a form.

The components of an HTTP response are: the status line, optional headers, and an optional body. The status line consists of a status code and accompanying status text. The status line summarizes whether the request was successful or not, and if not, whether some kind of error has occurred, or whether the client needs to follow a redirect to a different URL. Common headers include the `Content-Type` header, which gives the type of data to expect in the body. The body generally contains the requested resource:  an HTML file, a CSS stylesheet, a JavaScript script, an image, etc.



**Describe the HTTP request/response cycle.**

HTTP is a request-response protocol and implements the web's client-server model, wherein a web client sends an HTTP request to a web server, and the web server replies with an HTTP response. This two-part process is known as the request-response cycle.

The request-response cycle begins when a web client, usually a browser, wishes to access a resource on the web server. The client initiates an HTTP request, the server receives and processes the request, and then the server sends an HTTP response to the client.

HTTP is a stateless protocol, which means each request-response cycle is independent from all previous and subsequent request-response cycles. An HTTP request must contain all information that the web server needs to satisfy the request, and the server handles each request without reference to any previous requests sent by the same client.







**What is state in the context of the 'web'?**
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