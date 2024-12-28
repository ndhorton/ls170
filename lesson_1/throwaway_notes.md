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

