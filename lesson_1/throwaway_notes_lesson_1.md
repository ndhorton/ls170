# Lesson 1: The Internet #

## 1:1 - Introduction ##

'The focus of this course is network communication, and how that forms the basis for the way networked applications function.'

'As we progress through the course we will look to build a mental model of communication between networked applications as the interaction of multiple different protocols (systems of rules).'

'Starting with what actually constitutes the internet at a physical level, we will work our way up through various layers of abstraction to gain a deeper understanding of what is actually happening under the hood when applications communicate with each other over the network.'

* Network communication forms the basis for how networked applications function
* A network protocol is a system of rules
* Communication between networked applications involves the interaction of multiple different protocols



## 1:2 - What to Focus On

'This lesson explores the underlying infrastructure of the internet and the protocols that support that infrastructure.'

'We don't expect you to memorize every single detail of how things work at this level, that's the domain of network engineering. As a developer or software engineer, it helps to have a high-level picture of how the underlying infrastructure functions. Much of the specific detail isn't necessary.'

'The idea instead is to build the general mental models that will provide sufficient context to understand protocols operating at higher levels of abstraction, such as TCP and HTTP.'

'Higher-level protocols, such as TCP and HTTP, rely on the underlying network infrastructure in order to function. As such, they are bound by the limitations of that infrastructure, such as network bandwidth and latency. Understanding these limitations provides important context when learning about those protocols.'

'The protocols that support network functionality are essentially logical sets of rules that have been designed and engineered to be the way they are. Viewing them as such makes them easier to break down and contextualize'

'The Internet Protocol (IP) is a key part of the functionality of the internet. Make sure to form a clear mental model of what it does.'

* A deep and detailed understanding of the network infrastructure is the domain of network engineering. Software engineers require a more high-level overview of how the infrastructure works.
* Higher level protocols like TCP and HTTP depend on the network infrastructure and are therefore bound by its limitations: network bandwidth, latency, and so on.
* Networking protocols are logical sets of rules designed for a specific purpose
* The Internet Protocol (IP) is a key part of the internet's functionality



Things to focus on for lesson 1:

* 'Build a general picture of the network infrastructure'
* 'Be aware of the limitations of the physical network'
* 'Understand that protocols are systems of rules'
* 'Learn that IP enables communication between devices'



## 1:4 - What is the Internet?

* In the early 1970s, Vint Cerf and Bob Kahn began working on the design of what is now the Internet.
* This was the result of what is now called the ARPANET (Advanced Research Projects Agency Network), the first packet-switched computer network that was first used in 1969 and decommissioned in 1989. ARPANET's main use was for academic and research purposes. ARPANET was a US Defense Department research project. Paul Baran was trying to build a communications system that would survive a nuclear attack. For this, he hit on the idea of the idea of a decentralized network which would employ his novel idea of packet-switching. (Packet-switching was also invented independently by Welsh computer scientist Donald Davies.) ARPANET was a successful experiment in building such a network (another attempt was the French CYCLADES network).

* The Internet is a network of networks



Paul Baran described, in a 1964 RAND Corporation report, a hypothetical military network having to resist a nuclear attack. The network involved standardized message blocks, bearing source and destination addresses, being stored and forwarded by computer nodes in a meshed computer network with high redundency.

In 1967, Donald Davies published a seminal article in which he introduced the terms 'packet' and 'packet switching'. His proposed core network, while similar to Baran's, was developed entirely independently.



**What is a Network?**

'At the most basic level, it's two devices connected in such a way that they can communicate or exchange data. A primitive implementation of this would be connecting two computers directly to each other using a LAN cable, and configuring their network settings in such a way that they form a distinct network.'

**Local Area Network (LAN)**

'A much more common scenario, such as in an office environment, would be multiple computers and other devices connected via a **network bridging device** such as a **hub** or, more likely, a **switch**. The computers are all connected to this device via network cables, and this forms the network.'

A home network follows the same basic principle but often involves a wireless hub or switch so that devices can connect wirelessly instead of with cables. This implementation is called WLAN, or Wireless LAN.

'The key thing to understand here is that the scope of communications is limited to devices that are connected (either wired or wirelessly) to the network switch or hub, which imposes some geographical limitations. That's the 'local' in Local Area Network.'

**Inter-network Communication**

'In order to enable communication between networks, we need to add routers into the picture. Routers are network devices that can route network traffic to other networks. Within a Local Area Network, they effectively act as gateways into and out of the network.'

**A Network of Networks**

'We can imagine the internet as a vast number of these networks connected together. In between all  of the sub-networks are systems of routers that direct the network traffic.'

'The actual network topology of the overall network is a bit more complex than that, but in terms of having a mental model on which to build more abstract networking concepts it should suffice'

* At it's simplest, a network is two devices connected so they communicate or share data.
* A primitive network could be simply two computers connected by a LAN cable, with their network settings configured to form a discrete network of two computers.
* A LAN generally consists of a hub or switch that connects an office or a home full of computers and other devices.
* Individual LANs are connected to one another with a router, or system of routers. A router will act as a gateway to an individual network, both to send and receive data from other networks.



## 1:5 Protocols ##

* The Internet consists of countless types of devices from countless manufacturers built at various different epochs running a gigantic variety of software. Protocols allow all these devices to communicate.

'In simple terms, we can think of a protocol as a *system of rules*. In terms of computer networks, we can be a bit more specific: A set of rules that govern the exchange or transmission of data.'

* With respect to computer networks, a protocol is a set of rules that govern the exchange or transmission of data.

Some of the most widely used protocols include:

* IP
* SMTP
* TCP
* HTTP
* Ethernet
* FTP
* DNS
* UDP
* TLS

Aside:

A packet is also called a datagram, a term created in the early 70s by combining data and telegram by the CCITT (now ITU-T) rapporteur on packet switching, Halvor Bothner-By.

IP is a connectionless protocol that handles internetwork routing, addressing, and packet delivery between computers on different networks.

TCP is a connection-oriented protocol that provides reliable, ordered, and error-checked delivery of a stream of bytes between applications running on hosts communicating via an IP network.

UDP is a connectionless datagram service that is faster than TCP but does not offer its guarantees and reliability. Used to prioritize speed over consistency of data delivery.

End aside

The reasons there are so many protocols include:

* Different protocols have been developed to handle different aspects of network communication.
* Different protocols have been developed to handle the same aspect of network communication differently depending on use-case priorities.

Protocols for different aspects of communication:

In natural language, we can think of the importance of word order as part of the *syntactical rules* that govern the *structure* of a message. A message here is a speech act within a conversation.

A different aspect of communication is the *flow* and *order* of all the messages in the conversation. For instance, we may need to speak in turn rather than simultaneously. We can think of these as *message transfer rules* for how to conduct speech.

TCP and HTTP would be examples of two protocols that address different aspects of communication; TCP provides for the transfer of messages between applications, while HTTP defines the structure of those messages.



Different Protocols for the same aspect of communication:

All these situations have different rules governing message transfer: a student asking a question in class; an informal conversation between a group of friends; a presentation at a conference.

TCP and UDP are examples of protocols that address the same aspect of communication, the transfer of messages between applications, but do so differently.



## 1:6 A Layered System

It can be useful to group protocols together according to the aspect of communication they address. We can then think of those protocol groups as functioning within **layers** of an overall system of communication.

By modularizing a highly complex system into a layered system, we can gain an overview and then focus in on one particular layer to more closely understand what is happening at that particular layer of the system.

For network communication, there are many different models that attempt to do this. The two most popular are the **OSI model** and the **Internet Protocol Suite** (also known as the TCP/IP model or DoD model). There is some equivalence, yet also some overlap, between the respective layers of the two models.

<u>OSI model</u>

7. Application

6. Presentation

5. Session

4. Transport

3. Network

2. Data Link

1. Physical

aside:

The **Open Systems Interconnection** (**OSI**) **model** is a reference model from the International Organization for Standardization (ISO) that "provides a common basis for the coordination of standards development for the purpose of systems interconnection". In the OSI reference model, the communications between systems are split into seven different abstraction layers: Physical, Data Link, Network, Transport, Session, Presentation, and Application.

The model partitions the flow of data in a communication system into seven abstraction layers to describe networked communication from the physical implementation of transmitting bits across a communications medium to the highest-level representation of data of a distributed application. Each intermediate layer serves a class of functionality to the layer above it and is served  by the layer below it.

end aside



<u>Internet Protocol Suite model</u>

4. Application

3. Transport

2. Internet

1. Link



aside: 

The **Internet protocol suite**, commonly known as **TCP/IP**, is a framework for organizing the set of communication protocols used in the Internet and similar computer networks according to functional criteria. The foundational protocols in the suite are the Transmission Control Protocol (TCP), the User Datagram Protocol (UDP), and the Internet Protocol (IP). Early versions of this networking model were known as the Department of Defense (DoD) model because the research and development were funded by the United States Department of Defense through DARPA.

The Internet protocol suite as defined in RFC 1122 and RFC 1123 is a model of networking developed contemporarily to the OSI model, and was funded primarily by the U.S. Department of Defense. It was the foundation for the development of the Internet. It assumed the presence of generic physical links and focused primarily on the software layers of communication, with a similar but much less rigorous structure than  the OSI model.

end aside



* The top layer of the Internet Protocol Suite (Application) mostly maps to the top three layers of the OSI model (Application, Presentation, Session).
* The third layer of the Internet Protocol Suite (Transport) mostly maps to the fourth layer of the OSI model (Transport)
* The second layer of the Internet Protocol Suite (Internet) mostly maps to the third layer of the OSI model (Network)
* The first layer of the Internet Protocol Suite (Link) mostly maps to the bottom two layers of the OSI model (Data Link and Physical)

'The reason for the different number of layers between the two models is due to the difference in approach each model takes. The Internet Protocol Suite divides the layers in terms of the **scope of communications** within each layer (within a local network, between networks, etc). The OSI model divides the layers in terms of the functions that each layer provides (physical addressing, logical addressing and routing, encryption, compression, etc).'

**Data Encapsulation**

One concept common to the OSI and TCP/IP models (and most other network communication models) is the idea of data encapsulation. In programming, encapsulation can mean hiding the internal representation of an object and preventing it from being accessed from outside the object.

'The idea is similar in network models. Here we are essentially hiding data from one layer by encapsulating it within a data unit of the layer below.'

**Protocol Data Units**

'Within our network models, a Protocol Data Unit (PDU) is an amount or block of data transferred over a network. Different protocols or protocol layers refer to PDUs by different names. At the Link/Data Link layer, for example, a PDU is known as a *frame*. At the Internet/Network layer it is known as a *packet*. At the Transport Layer, it is known as a *segment* (TCP) or *datagram* (UDP).'

'In all cases, the basic concept is effectively the same; the PDU consists of a header, a data payload, and in some cases a trailer or footer.'

Header and trailer:

The exact structure of the header (and if included, trailer) is different from protocol to protocol, but they always serve to provide protocol-specific metadata about the PDU. For instance, an IP packet header would include fields for the Source IP Address and Destination IP Address, in order for the packet to be routed correctly.

Data payload:

The PDU from one layer, including the header (and trailer, if any) is encapsulated as the data payload of a protocol in the layer below. This continues down to the lowest level in a sort of Russian dolls effect.

This means that there is proper separation of concerns between protocols at different layers. The TCP protocol, for instance, does not need to know what kind of Application layer PDU it is encapsulating, whether HTTP or SMTP; it needs no information about the higher level protocol at all. All the protocol needs to know is that it needs to encapsulate *some data* from the layer above and provide the result of the encapsulation to the layer below. The lower layer protocol essentially offers a 'service' to the layer above it. 



## 1: 7 The Physical Network ##

'In the previous two assignments, we've looked at several concepts:

* Protocols act as systems of rules for network communication.
* Groups of protocols work in a layered system. Protocols at one layer provide services to the layer above.
* Data is encapsulated into a Protocol Data Unit (PDU), creating separation between protocols operating at different layers.



Since physical laws and rules place constraints on how a network transports data from place to place in a physical sense, and since this in turn impacts on how protocols function at a more abstract level, we need at least a cursory understanding of the physical network.

How fast an electrical signal or light can travel, what distance a radio wave can reach -- such things determine the physical characteristics of a network.

**<u>Bits and Signals</u>**

The OSI model defines a Physical layer as the lowest level of its model (Layer 1). The Internet Protocol Suite model does not concern itself much with physical interfaces, but it includes some physical functions in the Link layer.

The functionality at this level is essentially concerned with the transfer of bits, and for bits to be transported they must be converted into signals: electrical signals, light signals, or radio waves.



Bandwidth is measured by bit rate: how many bits per (usually) second. Bandwidth is the maximum transmission capacity of a device.

Latency is a different measure: the time it takes for a bit to travel from one place to another, from the source to the requesting device.

There is also the question of types of transmission medium and signal loss. Standard ethernet cables have significant signal loss over distances as low as a few hundred feet. 

In general, light travels much faster than electricity, even with much thicker electrical wires. Furthermore, light experiences far less signal loss. For distances like an ocean, we use fiber optic cables. A fiber optic cable is a thread of glass engineered to reflect light. The light bounces up and down through the extent of the cable.

However, light cable is expensive and hard to work with. Much of the internet still consists of copper cables.

Wireless parts of the network typically use radio waves to transmit bits. Radio waves cannot travel very far without signal loss.

**<u>Characteristics of a Physical Network</u>**

* The two main performance characteristics of a physical network are latency and bandwidth.

* Latency is a measure of the **time** it takes for some data to get from one point in the network to another.
* Bandwidth is a measure of the **quantity** of data that can be transmitted within a given unit of time, usually a second

'Simply increasing bandwidth doesn't necessarily improve the performance of a network. We'll explore the reasons for this when we look at TCP and UDP in a later lesson'

**<u>The Elements of Latency</u>**

'We can think of latency as a measure of delay. Data starts at one location at a certain point in time. At a later point in time, it reaches another location. The difference between these two points in time is the delay.'

'There are actually different *types* of delay that go together to determine the overall latency of a network connection.'

* Propagation delay
* Transmission delay
* Processing delay
* Queuing delay

'The total latency between two points, such as a client and a server, is the sum of all the delays above. This value is usually given in milliseconds (ms)'



'There are some other terms that you may encounter in a discussion about latency:'

* Last-mile latency
* Round-trip Time (RTT)
* Network Hops



The `traceroute` command is a utility for displaying the route and latency of a path across a network.

**<u>Bandwidth</u>**

'Bandwidth varies across the network, and isn't going to be at a constant level between the start point and the end point of our data's journey. For example, the capacity of the core network is going to be much higher than the part of the network infrastructure that ultimately connects to your home or office building.'

'The bandwidth that a connection receives is the lowest amount at a particular point in the overall connection. A point at which bandwidth changes from relatively high to relatively low is generally referred to as a bandwidth bottleneck.'

'Low bandwidth can be an issue when dealing with large amounts of data. As we'll see later in the course, however, latency can be a much more serious limitation on the performance of a networked application.'

**Limitations of the Physical Networks**

There's not a lot software engineers can do about the limitations of the physical network itself.

'If  we want to improve the performance of the applications we build, then our influence is limited to the implementation of the application in terms of how we use the higher-level protocols. As we'll see later in the course, however, an understanding of these physical limitations can impact the way we think about those higher-level protocols, and therefore the decisions we make about how we use them within our applications.'



## The Link/Data Link Layer ##

The devices (hosts (computers), switches, routers, etc) at the physical layer being connected together with cables and wireless is not enough in itself for these devices to communicate, since they have no innate rules of communication.

'One of the most important rules for transferring data from one place to another is identifying the device to which we want to send that data. The protocols operating at this layer [the Link or Data Link layer] are primarily concerned with the identification of devices on the physical network and moving data over the physical network between the devices that comprise it, such as hosts (e.g. computers), switches, and routers.'

Within both the OSI model and the Internet Protocol Suite, 'we can thing of what happens at this layer as an interface between the workings of the physical network and the more logical layers above.'

'The most commonly used protocol at this layer is the Ethernet protocol.'

The specifications for Ethernet cables are governed by the same IEEE standards that include the Ethernet communication protocols that operate at this layer of the network.

'Two of the most important aspects of Ethernet are **framing** and **addressing**.'

**<u>Ethernet Frames</u>**

'Ethernet Frames are a Protocol Data Unit, and encapsulate data from the Internet/Network layer above. The Link/Data Link layer is the lowest layer at which encapsulation takes place.'

'At the physical layer, the data is essentially a stream of bits in one form or another without any logical structure. An Ethernet Frame adds logical structure to this binary data. The data in the frame is still in the form of bits, but the structure defines which bits are actually the data payload, and which are metadata to be used in the process of transporting the frame.'

'An Ethernet-compliant network device is able to identify the different parts of a frame due to the fact that different "fields" of data have specific lengths in bytes and appear in a set order.'



* Preamble and SFD/SOF (Start of Frame Delimiter) generally aren't considered part of the frame but are sent just prior to the frame as a synchronization measure which notifies the receiving device to expect frame data and then identify the start point of that data. The preamble is seven bytes (56 bits) long and the SFD is one byte (8 bits). Both use a repeated pattern that can be recognized by the receiving device, which then knows that the data following after is the frame data.
* Frame Header fields:
  * Destination MAC Address (6 bytes, or 48 bits)
  * Source MAC Address (6 bytes)
  * Length (2 bytes)
  * DSAP (1 byte)
  * SSAP (1 byte)
  * Control (1 byte)
* Data Payload (between 42 and 1497 bytes)
* Frame Footer (Trailer)
  * Frame Check Sequence (FCS) (4 bytes)



We don't need to memorize all the fields. We mainly need to remember Source and Destination MAC Address, and Data Payload. It is important to understand that an Ethernet Frame is structured data.



**Interframe Gap (IFG)**

'As well as using the Preamble and SFD to prepare the receiving device for receiving the frame data, Ethernet also specifies an interframe gap (IFG). This gap is a brief pause between the transmission of each frame, which permits the receiver to prepare to receive the next frame.'

'The length of this gap varies according to the capability of the Ethernet connection. For example, for 100 Mbps Ethernet, the gap is 0.96 microseconds (or just under one millionth of a second)'.

'This Interframe Gap contributes to the Transmission Delay element of latency.'



<u>**Differences Between Ethernet Standards**</u>

The above Ethernet frame structure is the one specified by the IEEE 802.3 Ethernet standard. This is the most popular and widely used today. There are/were others.

In terms of understanding the general function of an Ethernet frame, the standard is not important. The main elements to be aware of are the Data Payload, which is used as an encapsulation mechanism for the layer above, and the Source and Destination MAC Addresses, which are used to direct the frame between network devices. These fields exist in all Ethernet standards.



<u>**MAC Adresses**</u>

Earlier, we said the most basic network might be two devices connected to each other. 'In this situation, if one device wants to send a message to another device, there is no identification needed. The recipient can just assume that the message is intended for it since it is the only possible recipient.'

'Once we start adding more devices to our network, the picture becomes more complicated.'

'One such situation is several computers connected via a network hub. A hub is a basic piece of network hardware that replicates a message and forwards it to all of the devices on the network. This is fine if you want to send a particular message to the entire network. Most of the time this is not the case and the message is intended for a specific device. This is where addressing comes in.'



'Every network-enabled device, e.g. a Network Interface Card (NIC) that you would find in a PC or laptop, is assigned a MAC [short for Medium Access Control, or Media Access Control] Address when it is manufactured. In theory, MAC addresses should be unique. In practice, this is not always the case, though it rarely presents a problem. since this address is linked to the specific physical device, and (usually) doesn't change, it is sometimes referred to as the *physical address* or *burned-in address*. MAC Addresses are formatted as a sequence of six two-digit hexadecimal numbers, e.g. `00:40:96:9d:68:0a`, with different ranges of addresses being assigned to different network hardware manufacturers.'

'In our hub scenario, each receiving device would check its MAC Address against the Destination MAC Address in the Frame to check if it was the intended recipient. If it wasn't, then it would just ignore the frame.'

'Sending every frame to every device on the network isn't very efficient, especially for large networks. These days it is rare that you'll find a network that uses a hub; most modern networks instead use switches. Like a hub, a switch is a piece of hardware to which you connect devices to create a network. Unlike a hub, however, a switch uses the destination address in order to direct a frame *only* to the device for which it is intended.'

So, a computer on the network sends a frame to the switch, and the switch consults its MAC Address table, which maps port numbers to MAC addresses. It then forwards the frame only to the computer whose MAC address matches the Destination MAC Address in the frame header.

'A switch directs the frames to the correct device by keeping and updating a record of the MAC addresses of the devices connected to it, and associating each address with the Ethernet port to which the device is connected on the switch. It keeps this data in a MAC Address Table.'

**<u>A Problem of Scale</u>**

The MAC Addressing system works well for LANs, where all devices are connected by a switch that can keep a record of each device's address. In theory, we could conduct inter-network communication just by using MAC addresses. We could maybe design routers that kept records of which MAC addresses could be accessed via which routers on the wider network of networks. In practice, this would be impossible to scale because of certain characteristics of MAC addresses.

* MAC addresses are physical rather than logical. Each MAC address is tied to a specific physical device.
* MAC addresses are flat rather than hierarchical. Each MAC address is a single sequence of hexadecimal values and can't be broken down into sub-divisions

Keeping track of which physical MAC addresses were part of which local network would be impossible at a global scale. Since MAC addresses are physical, devices, especially laptops and phones, would constantly change which local network they were attached to. And since MAC addresses are flat, every router would need to keep track of every address in the world, an impossible amount of data. 



Communication between computers on different local networks is what the Internet Protocol is for.



## The Internet/Network Layer ##

In the OSI model, the Network layer is layer 3 (between the Data Link layer and the Transport layer). In the Internet Protocol Suite, the Internet layer is layer 2 (between the Link and Transport layers). The primary purpose of the protocols at this layer is to facilitate communication between hosts (e.g., computers) on different networks.

The Internet Protocol (IP) is the predominant protocol used at this layer for inter-network communication. There are two versions of IP currently in use: IPv4 and IPv6.

The primary features of both versions are:

* Routing capability via IP addressing
* Encapsulation of data into packets



**Data Packets**

'The Protocol Data Unit (PDU) within the IP Protocol is referred to as a *packet*. A packet is comprised of a Data Payload and a Header. Just as with Ethernet Frames, the Data Payload of an IP Packet is the PDU from the layer above (the Transport layer). It will generally be a TCP segment or a UDP datagram. The Header is split into logical fields which provide metadata used in transporting the packet. Again, as with Ethernet Frames, the data in the IP Packet is in bits. The logical separation of those bits into header fields and payload is determined by the set size of each filed in bits and the order within the packet.'

IP packet:

* Header
  * Version
  * IHL
  * DSCP
  * ECN
  * Total Length
  * Identification (ID)
  * Flags
  * Fragment Offset
  * TTL
  * Protocol
  * Checksum
  * Source IP Address
  * Destination IP Address
  * Options
* Data Payload



IPv4 Header (only some of the fields described):

Version: this indicates the version of the Internet Protocol used, e.g. IPv4

ID, Flags, Fragment Offset: these fields are related to fragmentation. If the Transport layer PDU is too large to be sent as a single packet, it can be fragmented, sent as multiple packets, and then reassembled by the recipient.

TTL: every packet packet has a Time to Live (TTL) value. This is to ensure that any packets which don't reach their destination for some reason aren't left to endlessly bounce around the network. The TTL indicates the maximum number of network 'hops' a packet can take before being dropped. At each hop, the router which processes and forwards the packet will decrement the TTL value by one.

Protocol: this indicates the protocol used for the Data Payload, e.g. TCP, UDP, etc.

Checksum: this is an error checking value generated via an algorithm. The destination device generates a value using the same algorithm and if it doesn't match, it drops the packet. IP doesn't manage retransmission of dropped packets. This is left to the layers above to implement.

Source Address: the 32-bit IP address of the source (sender) of the packet.

Destination Address: the 32-bit IP address of the destination (intended recipient) of the packet.

**IP Addresses (IPv4)**

Video:

In the 1970s, there was no standard way for networks to communicate with each other.

Vint Cerf and Bob Kahn invented the Internet Protocol as a standard protocol for inter-network communication.

The Internet is a design philosophy and an architecture expressed in a set of protocols.

IPv4 - 32 bits, 8 bits for each section

Country/network

Region/network/sub-network

Subnetwork

Device

(remember subnet mask etc from How Linux Works)

IPv4 was designed in 1973, widely adopted in the 1980s, provides for more than 4 billion unique addresses for devices connecting to the internet

IPv6 uses 128 bits for each address, providing 340 undecillion unique addresses

The DNS system maps DNS names to IP addresses

DNS servers are connected in a distributed hierarchy, divided into zones, splitting up responsibility for major domains, e.g. `.org`, `.com`, `.net` etc.

DNS was created to be an open public communication protocol for government and educational institutions. Because of its open nature, it is vulnerable to cyberattacks. For instance, DNS spoofing, where a hacker hacks into a DNS server and changes its table to map a DNS name to a malicious IP address.

IP and DNS are designed to scale limitlessly.

'Unlike MAC addresses, IP Addresses are logical in nature. This means they are not tied to a specific device, but can be assigned as required to devices as they join a network. The IP address that the device is assigned must fall within a range of addresses available to the local network that the device is connected to. This range is defined by a network hierarchy, where an overall network is split into logical subnetworks, with each defined by the range of IP addresses available to it.'

IPv4 addresses are 32 bits in length, divided into four sections of eight bits each. When converted from binary to decimal, each of those sections provides a range of numbers between `0` and `255`, because 2 to the power of 8 is 256.

'A basic example of this hierarchy in action would be if all the addresses in the range `109.156.106.0` to `109.156.106.255` were assigned to a single local network. Each network defines the address at the start of the range, e.g. `109.156.106.0`, as the network address, and the address at the end of the range, e.g. `109.156.106.255`, as the broadcast address. Addresses between the network and broadcast address, `109.156.106.1` to `109.156.106.254` can be allocated to individual devices on the network.'

'The network address of the range is used to identify a specific network segment. What this means is that a router that wants to forward an IP packet to any address in the entire range only needs to keep a record of which router on the network controls access to the segment with that network address. This logic is what creates the hierarchical structure, and means that routers don't need to keep records of every single device within an addressable range.'

'This splitting of a network into parts is known as sub-netting. By dividing IP address ranges further, subnets can be split into smaller subnets to create even more tiers within the hierarchy.'

At the Ethernet and physical layers, network segment means something different (various connection scenarios).

At the IP/Internet/Network layer, network segment means subnet.

**Routing and Routing Tables**

'All routers on the network store a local routing table. When a IP packet is received by a router, the router examines the destination IP address and matches it against a list of network addresses in its routing table. As explained above, these network addresses define a range of addresses within a particular subnet. The matching network address will determine where in the network hierarchy the subnet exists. This will then be used to select the best route for the IP packet to travel.'

video: Packets, routers, and reliability

The path data takes from one computer on the internet to another need not follow a fixed path. The path may change during a session.

The data travels in a packet; in reality, some data representing a song, a Word document, or whatever, might need to be broken down into many packets. The routes taken by all these packets may be different. The path a packet takes will vary depending on network congestion etc.

Each packet has the source and destination address. Routers act like traffic managers to keep the packets moving smoothly regardless of dynamic network conditions. The packets representing a single piece of data may arrive at different times and out of order.

As part of the Internet Protocol, every router keeps track of multiple paths a packet might take, and it chooses the Cheapest Available Path for each packet based on destination address. Cheapest means lowest in time, but also non-technical factors such as politics and relationships between companies are taken into account. Often the most direct route is not the best. Having options for paths makes the network fault-tolerant. Reliability is a key principle for the Internet.

TCP manages the sending and receiving of all data as packets. TCP is like a guaranteed mail service. When receiving packets, TCP does a full inventory and sends back acknowledgements of all packets received. If there are no packets missing, we are done. If TCP finds packets missing, it requests the server to resend the missing packets.

TCP and routers scale without limit. Because of the principles of fault tolerance and redundancy, the more routers we add, the more reliable the Internet becomes. We can also grow and scale the Internet without interruption of service for anyone using it.

**<u>IPv6</u>**

The structure of IPv4 addresses means there is a logical maximum of around 4.3 billion addresses.

'Due to the popularity of the Internet, it is anticipated that this pool of addresses will eventually be depleted. Since the late 1990s, the Internet Engineering Task Force (IETF) have been working on a new version of the Internet Protocol called IPv6. Since IPv6 uses 128-bit addresses (eight 16-bit blocks), this increases the theoretical number of possible addresses to approximately 340 undecillion (340 billion billion billion billion).'

'As well as a difference in address structure, IPv6 has some other differences with IPv4 such as a different header structure for the packet and a lack of error checking (it leaves this to the Link Layer checksum)'.

**Networked Applications**

Whereas the Ethernet protocol provides communication between devices on the same network, the Internet Protocol enables communication between two networked devices anywhere in the world. We can send a message from one device on the internet and it can reach another.

If we want to create networked applications, however, communication between devices isn't enough. A single client device can have many applications running on it (web browsers, an email client etc). A server can have many services running (web server, file server, mail server etc). Being able to send data from one device to another isn't sufficient to ensure that a specific application on the client can access the right service on the server.

TCP and UDP enable communication between specific applications.



The Summary is very useful for this lesson.



Crash Course Computer Science:



#28 Computer Networks

Ethernet was developed in the early 70s at Xerox PARC

The general term for Ethernet network segments and MAC addressing is Carrier Sense Multiple Access, or CSMA. The 'Carrier' in this case is any shared transmission medium that carries data - copper wire in the case of Ethernet, and the air carrying radio waves for wifi.

Really good explanation of collision domains, exponential backoff, role of switches, etc.

Circuit switching - like old operator-controlled telephone lines

Called circuit switching because you're literally switching whole circuits to route traffic to the correct destination. It works fine, but it's relatively inflexible and expensive, because there's often unused capacity.

Message switching - hops between network nodes. If one node is congested, we can route through another path of nodes. Number of hops is called the hop count. The threshold at which circular or problematic routing can be assumed is called the hop limit.

Big messages can clog up the network. The solution is to chop up the large messages into packets.

Chopping up data into small packets, and passing these along flexible routes with spare capacity, is so efficient and fault-tolerant, it's what the whole internet runs on today. This routing approach is called Packet Switching.

It also has the advantage of being decentralized. Today, routers all over the globe work cooperatively to find efficient routings, exchanging information with each other using special protocols, such as the Internet Control Message Protocol (ICMP) and the Border Gateway Protocol (BGP).

LANs are connected to a WAN (often an ISP) (or usually a hierarchy of WANs) and these WANs eventually connect to the backbone of the internet, made up of gigantic routers with super-high bandwidth connections running between them.



#29 The Internet

IP packets do not contain information on which application to give the data to. For this, we need a higher level protocol, such as TCP or UDP.

User Datagram Protocol (UDP) datagrams consist of a header and a data payload. The UDP header contains a port number. Every Internet networked application will ask the operating system for a port number. When the computer receives a UDP datagram, it will pass the data to the appropriate port based on the number in the UDP header and the application listening at that port will receive it.

IP gets the packet to the right computer, but UDP gets the packet to the right program running on that computer.

The UDP header also contains a checksum, which allows the data to be verified for correctness. However, UDP does not offer facilities to resend a datagram, only to alert the application that data was lost/corrupted, so the app will usually just discard that datagram. Further, UDP does not reply with confirmation that a datagram was received to the sending computer, so the sender has no way of knowing if the data is getting through. For some applications, this is fine, since UDP is simple and fast. Skype, for instance.

Programs that need confirmation and resending capabilities use the Transmission Control Protocol (TCP).

TCP segments contain additional metadata, including sequential numbers so that segments received out of order can be put into correct order. TCP also requires that when the data has been correctly received and the checksum passes, the receiving host sends an acknowledgement (ACK) of receipt to the sending host. If the sender does not receive an ACK, it will wait a certain amount of time and resend the segment. If for some reason the segment was received but the ACK wasn't sent or was lost, this doesn't matter; the duplicate segment will simply be discarded.

The success rate of ACKs and the round trip time of sending and acknowledging can be used to infer network congestion. TCP uses this information to adjust how fast it sends segments, exercising congestion control.

TCP can thus handle out-of-order delivery, dropped segments including retransmission, and even throttle its transmission rate according to available bandwidth.

The downside of TCP relative to UDP is that the ACKs double network traffic for the same quantitiy of data sent. That overhead, including associated delays, is sometimes not worth the increased robustness. So for certain kinds of applications, such as multiplayer games, UDP is preferable.

Domain Name System (DNS)

DNS server maps readable names to IP address and port number

Domain structure is a hierarchical tree.

Top level domains

Second level domains

Sub-domain of parent



#30 The World Wide Web

The World Wide Web is a huge distributed application running on millions of servers worldwide, running on top of the Internet. It is accessed with a special program called a web browser.

The value of hyperlinked information was conceptualized by Vannevar Bush in 1945. He published an article describing a hypothetical machine called a Memex. He described hyperlinked text as 'associative indexing, whereby any item may be caused at will to select another immediately and automatically'. 'The process of tying two things together is the important thing... Thereafter, at any time, when one of those items is in view, the other [item] can be instantly recalled merely by tapping a button.'

In order for the hyperlinks in hypertext to link to another page, each page needs an address, called a Uniform Resource Locator (URL).

When you type a domain name like `www.google.com` into the bar of a web browser, the first thing your computer does is a DNS lookup to retrieve an IP address and a port number. The standard port number for web pages is port 80. Your computer then opens a TCP connection to a computer running a special piece of software called a web server. At this point, all your computer has done is open a connection to the web server at `google.com`. The next step is to ask that web server for the hypertext page. To do this it uses the Hypertext Transfer Protocol (HTTP).

The first documented version of this protocol specification was HTTP 0.9, created in 1991. It only had one command, `GET`.

We send a `GET` request to the web server as a raw ASCII text command and it responds by sending the hypertext file we requested. The file is interpreted by our web browser and displayed on the screen.

Later versions of HTTP added status codes, which were prefixed to any hypertext following a `GET` request. For instance, code `200` means `OK`. Status codes in the 400s are reserved for client errors.

Web page hypertext is stored as standard text. Therefore we need a markup language to indicate hypertext elements. For this, the Hypertext Markup Language (HTML) was developed. The first version of HTML was HTML 0.8, created in 1990, and included eighteen commands to markup pages.

HTML tags like `<h1>` must sometimes be closed `</h1>`.

The anchor `a` tag denotes an actual hypertext link, with the destination page being denoted as a hypertext reference, `href`. A hypertext reference is the most fundamental attribute in HTML, which allows users to create links within a web page.

For instance, `<a href=https://google.com>Google's Homepage</a>`

HTML 5 has over a hundred different tags.

The first Web Browser was written by Tim Berners-Lee over the course of two months in 1990 while he was working at CERN in Switzerland. To do this he created the fundamental web standards HTML, URLs, and HTTP as open standards, allowing anyone to develop web servers and browsers.

This permitted a team at the National Center for Supercomputing Applications at the University of Illinois in Urbana-Champaign to create the Mosaic web browser in 1993, the first browser to successfully render embedded images within hypertext pages. (Previous browsers had displayed images in separate windows). Mosaic introduced bookmarks, and had a friendly GUI interface. 

Over the 1990s, various web browser emerged, included Netscape Navigator, Microsoft Internet Explorer, Opera, Omniweb, and Mozilla.

Various web servers were created, including Apache and Microsoft's Internet Information Services.

Jerry Yang and David Filo created 'Jerry and David's Guide to the World Wide Web' in January 1994. In April, they renamed it 'Yahoo!'. The word 'YAHOO' is a backronym for 'Yet Another Hierarchically Organized Oracle', or 'Yet Another Hierarchical Officious Oracle'. The `yahoo.com` domain was created on January 18, 1995.

As the web grew, human edited directories like Yahoo! became unwieldy, and so search engines were developed.

The earliest search engine that operated like the ones we use today was JumpStation, created by Jonathon Fletcher in 1993 at the University of Sterling. This consisted of three pieces of software that worked together. The first was a Web Crawler, software that followed every link it could find on the web. Every time it found links on a page that had new links, it would add those to its list. Secondly, the search engine had an every expanding Index that recorded the terms on the pages the web crawler had visited. The final piece was a search algorithm that consulted the index.

The search rankings were determined by simple factors, such as how many times the search term appeared on the page. However, this could be easily gamed.

Google's search engine side-stepped this problem by ranking pages according to how many other pages linked to the page. This started as a research project called BackRub at Stanford in 1996.

Net neutrality:

In short, network neutrality is the principle that all packets on the internet should be treated equally. All packets, regardless of whether they are those of an ordinary person or a multinational corporation, should move at the same speed and priority.

But many companies would prefer that their data would be transported preferentially.

The default ports for the web are actually 80 (http) and 443 (https)

