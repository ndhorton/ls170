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

 



## **<u>Understand the characteristics of the physical network, such as latency and bandwidth</u>**

1:7 **<u>The Physical Network</u>**

"If we drill down through these layers of abstraction, underlying everything at the most basic level is a 'physical' network made of tangivle pieces such as networked devices, cables, and wires. Even the radio waves used in wireless networks, though we can't touch or see them, exist in the physical realm and are bound by physical laws and rules"

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