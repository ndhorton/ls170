# Lesson 2: The Transport Layer #

## 2:1 What to Focus on ##

**Learn how transport layer protocols enable communication between processes**

'Spend some time building a mental model for what multiplexing and demultiplexing are. Be clear about how ports work, along with IP addresses, to provide this functionality.'

**Learn that network reliability is engineered**

The Internet and the Web are actually the combination of multiple technologies that have been designed and engineered. Network reliability is one aspect of this.

**Understand the trade-offs**

TCP and UDP are the result of many different design decisions and therefore trade-offs. Spend time learning what TCP and UDP each provide, and what the trade-offs of using each are.

The Summaries are useful and significant in this course.



## 2:2 Communication Between Processes ##

The previous lesson explored the concept of the Internet as a *layered system of communication*. Within this system, each layer provides a certain level of functionality or a service to the layer above. We looked at some of the protocols at each layer in more detail, and at how the Internet Protocol essentially provides the inter-network communication services necessary for what we might think of as a *minimum viable internet*.

'If we want to create modern networked applications however, there's a number of things that we need beyond what IP can provide. Two of the most important things are a direct connection between applications, and reliable network communication.'

In addition to the basic essential inter-network communication between hosts provided by IP, modern networked applications generally require:

* A way for networked applications to communicate directly with specific networked applications on another host
* Reliable network communication

We are taking the first, connection between specific applications or processes, first.

'Let's think about how we can provide end-to-end communication between applications or processes.'

It's important to understand that IP and its system of addressing is concerned with providing communication between *hosts* or *devices*. These hosts may be on the same LAN or a different LAN on the other side of the world. Nevertheless, we can use IP to transmit data from one host to another but not any more than that.

'As we know though, there are potentially many applications running on a single host. If IP can get us as far as the host, how do we provide communication between an application running on one host and an application running on another host (or potentially between two different applications or processes running on the same host)?



**<u>Multiplexing and Demultiplexing</u>**

There may be many networked applications or processes running on a device at one time. All these processes want to be able to send or receive data simultaneously. For instance, Spotify may be playing a song while we work on a Replit and chat on Slack, checking documentation on a web browser, with our email client in the background etc. We can think of these different applications or processes as distinct **channels** for communication on a host machine.

IP packet header contain a source IP address and a destination IP address, with each address identifying a host or device. This creates a communication channel between hosts. So we have many communication channels *on* a host, but only one communication channel *between* the hosts. Thus, what we need is a way to transmit multiple data inputs over this single host-to-host channel and then somehow separate them at the other end.

Another way to think of this, is that we have all these processes (Spotify, various web browser windows, email, Zoom, Slack, etc) on the host, and they are all sending and receiving separate data through one channel. So we need to be able to regulate sending input to the channel. We also need to be able to separate out the data we are receiving from the channel and to give each piece of data to the correct process on our host.

'In the context of a communication network, this idea transmitting multiple signals over a single channel is known as **multiplexing**, with **demultiplexing** being the reverse process. It is a general concept that can be applied in lots of contexts within communications networks... Our focus in this assignment is the application of this concept at the Transport layer of our network communication model. This takes place through the use of **network ports**.'

**<u>Ports</u>**

'In simple terms a port is an identifier for a specific process running on a host. This identifier is an integer in the range 0-65535.'

Sections of this range are reserved for specific purposes:

* 0-1023 are well-known ports. these are assigned to processes that provide commonly used network services. For example, HTTP is port 80, FTP is port 20 and 21, SMTP is port 25, and so on.
* 1024-49151 are registered ports. They are assigned as requested by private entities. For example, companies such as Microsoft, IBM, and Cisco have ports assigned that they use to provide specific services. On some operating systems, ports in this range are also used for allocation as **ephemeral ports** on the client side.
* 49152-65535 are dynamic ports (sometimes known as private ports). Ports in this range cannot be registered for a specific use. They can be used for customized services or for allocation as **ephemeral ports**.

Most services running on servers will likely have a port in the well-known range assigned to them. If you want to connect via HTTP to a web-server running on a host machine, that web-server process will probably have port 80 assigned to it. This is sometimes described as the web server *listening* on port 80.

'A service running on a client machine, for example in a browser running on your laptop, won't use one of these well-known ports, but instead have an *ephemeral* or temporary port assigned to it by the operating system, for example 59258.

To enable multiplexing and demultiplexing, port numbers identifying specific services running on host machines are included in the Protocol Data Units (PDUs) for the Transport Layer. The name and exact structure of these PDUs varies depending on the Transport protocol used, but they will include:

* Source port
* Destination port

The Transport layer PDU encapsulates data from the application layer in its Data Payload, and the source port and destination port numbers within the PDU can be used to direct that data to specific processes on a host. The entire Transport layer PDU is then encapsulated as the data payload in an IP packet. The IP addresses in the packet header can be used to direct the data from one host to another. The IP address and the port number *together* are what enables end-to-end communication between specific applications on different machines.

'The combination of IP address and port number information can be thought of as defining a *communication end-point*. This communication end-point is generally referred to as a *socket*... For now you can just think of [a socket] as the combination of IP address and port number, for example `216.3.128.12:8080`.'

We can think of IP and Transport layer protocols as being like the postal service delivering mail to an apartment building. The IP address is like the apartment building street address; the postman checks the street and building number of the mail, and drops off all the mail for the building. The Transport layer protocol is like the concierge who takes the building's mail and sorts it into individual mailboxes in the foyer for the individual tenants to collect, based on their apartment numbers.

'We can think of the street address of the apartment building as the IP address and the individual apartment numbers as port numbers. Furthermore, the postal service can be thought of as the Internet Protocol, and the building concierge as a Transport layer protocol (e.g. TCP or UDP).'

Aside: TCP/IP Sockets (or UDP/IP) are not the same as thing as Unix Domain Sockets. Unix Domain Sockets are largely concerned with interprocess communication on a single host, whereas TCP/IP sockets are concerned with interprocess communication between processes on different hosts on the network/internet. Edit: this is actually addressed lower down the same page.

**Netstat**

Aside: `netstat` and other `net-tools` utilities have been largely replaced on most operating systems since the turn of the century. On Linux, the `iproute2` suite is now considered to have superseded `net-tools`, and the `ss` (socket statistics) utility replaces `netstat`.

'The important thing to notice here is that the Local Address and Foreign Address are combinations of IP address and port number. As stated earlier, these combinations act as communication end-points or sockets for the transfer of data between applications running on hosts.'



**<u>Sockets</u>**

'At a conceptual level a socket is, as outlined above, an abstraction for an endpoint used for inter-process communication. At an implementation level it can be used to refer to different specific things:'

* UNIX socket: a mechanism for communication between local processes running on the same machine.
* Internet sockets (such as a TCP/IP socket): a mechanism for inter-process communication between networked processes (usually on different machines).

'To confuse matter further, you could have two networked process running on the same machine, such as a webserver running on `localhost` and a browser connecting to that webserver. Those processes would still use internet sockets to communicate, even though communications between them wouldn't travel across the network infrastructure.'

'In this course, what we're primarily interest in is the *concept* of a socket and to a lesser extent the application of this concept for inter-network communication between networked applications, i.e. Internet Sockets.'

We are not going to look much into how Internet Sockets work at a programming level.

'One important thing to be clear on though is that there *is* a distinction between the concept of a network socket and its implementation in code.'

'At a conceptual level a [network/internet] socket is a communication end-point defined by an address-port pair.'

From the TCP RFC: 'To allow for many processes within a single Host to use TCP communication facilities simultaneously, the TCP provides a set of addresses or ports within each host. Concatenated with the network and host addresses from the internet communication layer, this forms a socket.'

However, in socket programming or network programming terms, the implementation of this concept involves instantiating *socket objects*. Implementations vary, but many follow the Berkely sockets API model, with specific functions such as `bind()`, `listen()`, `accept()`, and `connect()`. This can be seen in the documentation for Ruby, Python, Node.js, etc.



**<u>Sockets and Connections</u>**

In an implementation of a connectionless network communication, we could have on socket object defined by the IP address of the host machine and the port assigned to a particular process running on that machine. That socket object could call a `listen()` method that would allow it to wait for incoming messages directed to that particular IP/port pair. Such message could potentially come from any source, at any time, in any order -- but that isn't a concern in a connectionless system; it would simply process any incoming messages as they arrived and send any responses as necessary.

A connection-oriented system works differently. You could have a socket object defined by the host IP address and process port, just as in the connectionless system, also using a `listen()` method to wait for incoming messages. The difference in this connection-oriented implementation would lie in what happens when a message arrives. At this point, we could instantiate a new socket object which is not merely defined by the local IP/port pair of the receiver host/process, but also by the IP/port pair of the sender host/process. The new socket object would now listen specifically for messages where all four pieces of information matched (source port, source IP address, destination port, destination IP address). The combination of these four pieces of information is commonly referred to as a **four-tuple**.

Any messages which don't match this four-tuple would still be picked up by the original socket object, and would result in a new socket object being instantiated that listened specifically for the new connection.

'Implementing communication in this way effectively creates a dedicated virtual connection for communication between a specific process running on one host and a specific process running on another host. The advantage of having a dedicated connection like this is that is more easily allows you to put in places rules for managing the communication such as the order of messages, acknowledgements that messages had been received, retransmission of messages that weren't received, and so on. The purpose of these types of additional communication rules is to add more reliability to the communication.'



## 2:3 Network Reliability ##

A major characteristic of the protocols that are chiefly concerned with the functionality for the lower layers (below Transport in both models) is that they are inherently unreliable. Protocols like Ethernet and IP carry checksum data to check if data has become corrupt, but if the data *is* corrupt then the frame or packet is simply discarded. These protocols have no way to ask for retransmission; there is no way to replace lost data. The network up to and including the Internet Protocol is effectively an **unreliable communication channel**.

'As developers and software engineers, what we often need is a **reliable data channel** over which to send our data... Since at the lower levels of our network we don't have a reliable communication channel, the question then becomes: how can we transfer data reliably over an unreliable channel?'

'What we need to do is develop a system of rules, or a protocol, to ensure that all the data that is sent is received at the other end and in the correct order. What would such a system of rules look like?'

We build up to...

Version 3...

Rules:

* Sender sends one message at a time, with a sequence number, and sets a timeout
* If message received, receiver sends an acknowledgement which uses the sequence number of the message indicate which message was received
* When acknowledgement is received, sender sends next message in the sequence
* If acknowledgement is not received before the timeout expires, sender assumes either the message or the acknowledgement went missing and sends the same message again with the same sequence number
* If the recipient receives a message with a duplicate sequence number it assumes the sender never received the acknowledgement and so sends another acknowledgement for that sequence number and discards the duplicate

Version 3 thus covers...

The fundamental elements required for reliable data transfer:

* In-order delivery: data is received in the order that it was sent
* Error detection: corrupt data is identified using a checksum
* Handling data loss: missing data is retransmitted based on acknowledgements and timeouts
* Handling duplication: duplicate data is eliminated through the use of sequence numbers

'Our protocol as it stands is reliable. Unfortunately, it's not very efficient. One of the main features of our protocol is that each message is sent one at a time, and an acknowledgement is received before the next message is sent. This type of protocol is known as a Stop-and-Wait protocol. It's the 'Wait' part that's the problem here. Within our system, much of the time is spent just waiting for an acknowledgement. This is not an efficient use of bandwidth.



**<u>Pipelining for Performance</u>**

We can improve the throughput of our protocol by sending multiple messages one after the other without waiting for acknowledgements. The receiver still sends acknowledgements, and retransmission still occurs, so this system is still reliable. 'The difference is that multiple messages are being transferred at any one time. This kind of approach is referred to as "**pipelining**".

'There are different ways of implementing this pipelined approach, such as **Go-back-N** and **Selective Repeat**... With both systems, the sender will implement a "window" representing the maximum number of messages that can be in the "pipeline" at any one time, once it has received the appropriate acknowledgements for the messages in the window, it moves the window on'.

The advantage of pipelining is its more efficient use of available bandwidth. Less time is spent waiting for acknowledgements and more time is spent transmitting data.

Finding a balance between reliability and performance is a major task of the Transmission Control Protocol (TCP).



## 2:4 Transmission Control Protocol (TCP) ##

One of the key characteristics of TCP is that it provides reliable data transfer. TCP provides the abstraction of reliable network communication on top of an unreliable channel. This abstraction hides much of the complexity of reliable network communication from the application layer: data integrity, de-duplication, in-order delivery, and retransmission of lost data.

From RFC793: "The TCP must recover from data that is damaged, lost, duplicated, or delivered out-of-order by the internet communication system."

These services that TCP provides make it the protocol of choice for many networked applications. On the other hand, there are performance challenges that come with its complexity. Although the complexity is abstracted away from a developer working at the Application layer, the complexity still exists and has an effect on performance. TCP attempts to balance this impact by providing mechanisms for **flow control** and **congestion avoidance**.

In addition to reliability, TCP provides data encapsulation and multiplexing through the use of TCP **Segments**.



**<u>TCP Segments</u>**

The Segment is the PDU of TCP. Like other PDUs, it uses a combination of headers and payload to provide encapsulation of data from the layer above.

Segment Header and Segment Payload

The fields below are representative of a typical TCP Segment Header

* Segment Header
  * Source Port
  * Destination Port
  * Sequence Number
  * Acknowledgement Number
  * HLEN
  * Reserved
  * Flags
    * URG
    * ACK
    * PSH
    * RST
    * SYN
    * FIN
  * Window Size
  * Checksum
  * Urgent Pointer
  * Options and Padding
* Segment Payload

The Source Port and Destination Port fields provide multiplexing capabilities. Most of the other header fields relate to TCP's implementation of reliable data transfer.

There are a number of TCP variants, and the precise header fields they contain will vary slightly. Most of these variants contain at least the fields shown above.

* Checksum: The Checksum provides the Error Detection aspect of TCP reliability. It is an error checking value generated by the sender using an algorithm. The receiver generates a value using the same algorithm and if it doesn't match, it drops the Segment... Having a Checksum at the Transport layer does render Checksums at lower layers redundant to a certain extent. IPv6 headers don't include a Checksum for this reason, based on the assumption that Checksums are implemented at the Transport or Link/Data Link layers or both.
* Sequence Number and Acknowledgement Number: these two fields are used together to provide  for the other elements of TCP reliability such as In-Order Delivery, Handling Data Loss, and Handling Duplication.
* Window Size: this is related to flow control
* Flags: one-bit boolean fields. URG and PSH are related to how data in the segment should be treated with respect to its importance or urgency. The SYN, ACK, FIN, and RST flags are used to establish and end a TCP connection, as well as manage the state of that connnection.

SYN is an abbreviation of 'synchronize'. ACK is 'acknowledgement'.



**<u>TCP Connections</u>**

TCP is a **connection-oriented** protocol. It doesn't start sending application data until a connection has been established between application processes. To establish a connection, TCP uses what is known as a **Three-way Handshake**. The `SYN` and `ACK` flags are used for this purpose. The `FIN` flag is used in a different process, the **Four-way Handshake**, which is used to terminate a connection.

A simplified view of the Three-way Handshake would be:

* Sender sends SYN segment
* Receiver receives SYN segment, responds with SYN ACK segment
* Sender receives SYN ACK segment, responds with ACK segment
* Receiver receives ACK segment, connection is now established

In the above process

* The sender sends a SYN message (a TCP segment with the `SYN` flag set to `1`)
* Upon receiving this SYN message, the receiver sends back a SYN ACK message (a TCP segment with the `SYN` and `ACK` flags set to `1`)
* Upon receiving the SYN ACK message, the sender then sends an ACK (a TCP segment with the `ACK` flag set to `1`)

Upon sending the ACK, the sender can immediately start sending application data. The receiver must wait until it has received the ACK before it can send any data back to the sender. One of the main reasons for the Three-Way Handshake process is to synchronize (`SYN`) the sequence numbers that will be used during the connection.

Part of the purpose of the flags is to manage the **connection state**.

From RFC973: 'A connection progresses through a series of states during its lifetime. The states are: LISTEN, SYN-SENT, SYN-RECEIVED, ESTABLISHED, FIN-WAIT-1, FIN-WAIT-2, CLOSE-WAIT, CLOSING, LAST-ACK, TIME-WAIT, and the fictional state CLOSED. CLOSED is fictional because it represents the state when there is no TCB, and therefore, no connection.'

Aside: 'Each TCP connection maintains state, usually in a data structure called the "TCP Control Block (TCB)"' (RFC9040)

Most of the time the state we are concerned with is ESTABLISHED, and also LISTEN on the server side. The other states are related to the establishment and termination of connections.

This hand-shaking before a connection is established which TCP requires means there is a round-trip of latency before any application data can be sent. The sender must send its ACK before it can send app data. This impacts on any application using TCP as a Transport layer protocol.

TCP thus involves a lot of overhead in terms of establishing connections, and providing reliability via the retransmission of lost data. 'In order to mitigate this additional overhead, it is important that the actual functioning of data transfer when using the protocol occurs as efficiently as possible. In order to help facilitate efficient data transfer once a connection is established, TCP provides mechanisms for flow control and congestion avoidance.'

**<u>Flow Control</u>**

TCP flow control is a mechanism to prevent the sender overwhelming the receiver with more data than it can process at once. Data that awaits processing is stored in a buffer. The buffer size will vary depending on the OS and resources of the system.

The WINDOW field of a TCP segment allows each side in a connection to let the other know how much data it can accept. The number in the WINDOW field is dynamic, and can change during the course of a connection. If the receiver's buffer is getting full, the receiver can set a lower amount in the WINDOW field of a segment it sends to the sender. The sender can then reduce the quantity of data it is sending accordingly.

Although this **Flow Control** mechanism prevents the two sides in a connection from overwhelming each other, it doesn't prevent them overwhelming the underlying network. For that task, TCP provides a different mechanism: **Congestion Avoidance**.

**<u>Congestion Avoidance</u>**

Network Congestion refers to a situation where there is more data being transmitted on the network than there is network capacity to process and transmit the data.

IP packets move across the networks in a series of hops. 'At each hop, the packet needs to be processed: the router at that hop runs a checksum on the packet data; it also needs to check the destination address and work out how to route the packet to the next hop on its journey to that destination. All of this processing takes time, and a router can only process so much data at once. Routers use a "buffer" to store data that is awaiting processing, but if there is more data to be processed than can fit in the buffer, the buffer over-flows and those data packets are dropped.'

TCP retransmits lost data. 'If lots of data is lost, that means lots of retransmitted data, which is inefficient. Ideally, we want to keep retransmission to a minimum. TCP actually uses data loss as a feedback mechanism to detect, and avoid, network congestion; if lots of retransmissions are occurring, TCP tales this as a sign that the network is congested and reduces the size of the transmission window. The transmission window limits the number of unacknowledged segments that the sender can have at a time.' 

This means that fewer packets are in transit across the network between sender and receiver at any one time.

There are various approaches and algorithms for determining the initial size of the transmission window and how much it should be increased or decreased by depending on network conditions. The exact algorithm used will depend on which variant of TCP is in operation.

**<u>Disadvantages of TCP</u>**

There is a latency overhead involved in establishing a TCP connection due to the handshake process.

Another potential issue with TCP is **Head-of-Line (HOL)** blocking.

'Head-of-line blocking is a general network concept, and isn't specific to TCP. In general terms it relates to how issues in delivering or processing one message in a sequence of messages can delay or "block" the delivery or processing of the subsequent messages in the sequence.'

'With TCP, HOL blocking can occur as a result of the fact that TCP provides for in-order deliver of segments. Although this in-order delivery is one aspect of TCP's reliability, if one the segments goes missing and needs to be retransmitted, the segments that come after it in the sequence can't be processed, and need to be buffered until the retransmission has occurred. This can lead to increased queuing delay which, as we saw in an earlier assignment, is one of the elements of latency.



## 2:5 User Datagram Protocol (UDP)

While TCP implements reliable data transfer through sequencing and retransmission of lost data, as well as providing mechanisms for flow control and congestion avoidance, UDP implements none of these things.

The Protocol Data Unit of UDP is known as a Datagram. Like all of the PDUs we've looked at, the Datagram encapsulates data from the layer above as a payload and adds header information.

The header of a Datagram is very simple. The layout of a UDP Datagram is:

* Header
  * Source Port
  * Destination Port
  * Length - length in bits of entire datagram including header and payload
  * Checksum - optional if using IPv4, mandatory if using IPv6
* Data Payload

Through the use of the Source and Destination port numbers, UDP provides multiplexing in the same way that TCP does. Unlike TCP, however, UDP does nothing to resolve the inherent unreliability of the layers below it. It is easier to define UDP by what it doesn't do (relative to TCP) than by what it does do.

* UDP provides no guarantee of message delivery
* UDP provides no guarantee of message delivery order
* It provides no built-in congestion avoidance or flow control mechanisms
* It provides no connection state tracking, since it is a connectionless protocol

<u>**The Case for UDP**</u>

UDP is much simpler than TCP. This simplicity provides two things to a software engineer: speed and flexibility.

'UDP is a connectionless protocol. Applications using UDP at the Transport Layer can just start sending data without having to wait for a connection to be established with the application process of the receiver.'

'The lack of acknowledgements and retransmissions means that the actual data delivery itself is faster; once a datagram is sent it doesn't have to be sent again. Latency is less of an issue since without acknowledgements data essentially just flows one way: from sender to receiver.'

'The lack of in-order delivery also removes the issue of Head-of-line blocking (at least at the Transport layer)'

* UDP is connectionless, removing the latency inherent to TCP's three-way handshake process
* Lack of acknowledgements and retransmissions means that data transfer is faster. Latency is less of an issue since without acknowledgements data is just flowing one way. And once data is sent, it doesn't need to be sent again.
* The lack of in-order delivery eliminates Head-of-line blocking at the Transport layer

'It's likely that someone building a UDP-based application will want to implement some of the services that UDP doesn't natively provide.'

What services these would be is up to the person building the app. You might want in-order delivery but don't need retransmission, for instance.

'It is left to the software engineer to decide which services to include. These services can then be implemented at the application level, effectively using UDP as a "base template" to build on.'

Examples include voice and video calling apps, and multiplayer online games.

While UDP provides flexibility and freedom, with that freedom comes responsibility. 'There are various best practices that should be adhered to. for example, it would be expected that your UDP-based application implements some form of congestion avoidance to prevent it overwhelming the network.'



## 2:6 Summary ##

* Multiplexing and demultiplexing provide for the transmission of multiple signals over a single channel
* Multiplexing is enabled through the use of network ports
* Network sockets can be thought of as a combination of IP address and port number
* At the implementation level, network sockets can also be socket objects
* The underlying network is inherently unreliable. If we want reliable data transport we need to implement a system of rules to enable it.
* TCP is a connection-oriented protocol. It establishes a connection using the Three-way handshake.
* TCP provides reliability through message acknowledgement and retransmission, and in-order delivery
* TCP also provides Flow Control and Congestion Avoidance
* The main downsides of TCP are the latency overhead of establishing a connection, and the potential Head-of-line blocking as a result of in-order delivery
* UDP is a very simple protocol compared to TCP. It provides multiplexing, but no reliability, no in-order delivery, and no congestion or flow control.
* UDP is connectionless, and so doesn't need to establish a connection before it starts sending data
* Although it is unreliable, the advantage of UDP is speed and flexibility



**Pinned question: "Great explanation..." from guillaume

**Packet Traveling - How Packets Move Through a Network**

Networked devices maintain:

* ARP (Address Resolution Protocol) Table - mapping of IP addresses to MAC addresses. All networked devices maintain an ARP table.
* MAC Address Table - mapping of Switchports to MAC addresses. As traffic flows through a switch, the switch identifies the MAC address of the device at each port. Switches maintain MAC address tables.
* Routing Table - mapping of IP Networks to egress interfaces. A routing table is a map of every network the router knows how to get to, and how to get there. Routers maintain routing tables.

ARP tables and MAC address tables are populated dynamically as traffic moves through a device. Routing tables are populated from Directly Connected interfaces prior to any traffic showing up. This means that the Router knows what the IP address of its interfaces are, and from this it infers the network IP address of the network connected to each of its interfaces. 

1. Host A has Data for Host D
   - Host A already knows Host D's IP Address, identifies from this that Host D is on different network
   - Host A creates a Layer 3 (Network, IP) header
   - Host A needs to learn its Default Gateway's MAC address
2. Host A sends an ARP Request for 11.11.11.1
3. Switch X Receives Frame
   * Switch X Learns MAC Address mapping on port 2, the port Host A is connected to
   * The ARP request is a broadcast frame, which means it is intended to be delivered to everyone on the local network, therefore the switch will duplicate the frame and send it out on every port except the one it came in on. This action is known as Flooding.
   * Switch X Floods Frame out on all ports and all devices on the LAN receive it
4. Host B discards frame since it is for someone else's IP address on the network
5. Router receives ARP request and realizes the request is for its own IP address, the router will therefore accept and process the ARP request
   * Router learns Host A's ARP mapping and saves it in its ARP table
6. Router generates ARP Response
   * since the Router now knows Host A's MAC address, it can send the Response directly to Host A (via the switch) rather than broadcasting
7. Switch X Receives Frame
   * on receiving the frame from the Router on port 3, Switch X learns the MAC address of the Router and adds it to its MAC Address table
   * this frame is a Unicast frame destined for Host A, and Switch X has already learned Host A's MAC address and entered it in its MAC table when Host A made the ARP request.
   * Switch X forwards the ARP Response to Host A
8. Host A receives ARP response and learns MAC address of the Router. Host A enters the MAC address in its ARP table
9. Host A creates Layer 2 (Data Link, Ethernet) header and sends Packet. Whereas the Layer 3 header had Source IP Address of Host A's IP address and a Destination IP address of Host D's IP address, the Layer 2 header has a Source MAC address of Host A's MAC address and a Destination MAC address of the Router's MAC address.
   * The purpose of the Layer 3 header is to go from end-to-end of network delivery, the purpose of the Layer 2 header is to go from hop-to-hop
10. Switch X receives frame
    * Switch X already knows the mapping for port 2 for Host A, so this MAC address entry is simply refreshed
    * Switch X looks up the mapping for the L2 header destination MAC address and finds the Router on port 3
    * Switch X forwards the frame on port 3
11. Router receives Packet and strips L2 header
12. Router determines where to send the Packet to get to the destination IP address. It consults Routing Table
    * Router finds that the destination network exists on one of its interfaces, since it is directly connected to the destination Host D's network
    * Router doesn't have an ARP entry for Host D
    * Router must use ARP protocol to discover it
13. Router sends an ARP Request for Host D's IP address. Again, the ARP Request is a simple broadcast frame that asks, if the machine with this IP address is out there, send me your MAC address
14. etc...

The Routing Table - mapping of IP Network to Interface OR Next Router (also known as the Next Hop IP Address)

Watch the rest of the Practical Networking series this is part of (the newer version)

**<u>Question: Great Illustration of Transport Layer Ideas</u>**

video

idempotency tokens

