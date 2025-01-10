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



# Lesson 3: Intro to HTTP #

## 3:1 What to Focus On

* Develop a clear understanding of the role of HTTP

HTTP doesn't function in isolation. Build a picture of the functioning of the web as a combination of multiple different technologies, a combination within which HTTP has a specific role.

* Break things down into individual components

Ensure clarity within mental models by breaking down concepts like HTTP and URLs into specific components, and understanding the purpose of those components

## 3:2 The Application Layer ##

The Application Layer is not *the application itself*, but rather **a set of protocols which provide communication services to applications**.

'Because of its emphasis on different functions or services being provided by each layer, the OSI model actually defines two other layers (the Session layer and the Presentation layer) in between the Transport layer and the Application layer. We aren't going to examine the specifics of the responsibilities that the OSI model ascribes to those two layers, as splitting up the responsibilities in this way can over-complicate the picture when it comes to thinking about how networked applications operate at a more practical level.'

In both OSI and TCP/IP models, however, the protocols at the Application layer are the protocols with which networked applications most directly interact. Many networked applications interact with protocols from other layers (opening a TCP socket, for instance); however, it is uncommon for a networked application to interact with layers below the Transport layer.

The protocols in the layers up to and including the Transport layer focus on the establishment and flow of communications; they focus on getting data from endpoint to endpoint. Application layer protocols rely on the layers below to ensure that a message gets to where it is supposed to, and focus instead on the structure of that message and the data that it should contain.

**Application Layer Protocols**

* We can perhaps think of Application layer protocols as the rules for how applications talk to each other at a syntactical level.
* Different types of applications have different requirements for how they communicate at a syntactical level
* There are many different protocols that exist at the Application layer to facilitate the different needs of different types of application
* We will focus on HTTP, since that is the primary protocol used for communication on the Web

## 3:3 HTTP and the Web

* The Internet and the Web are distinct and specific things
* The Internet is essentially a network of networks. It can be thought of as the infrastructure that enables inter-network communication, both in terms of the physical network and the lower-level protocols that control its use

* The World Wide Web, or simply the *web*, is a **service** that can be accessed via the internet
* The Web is a vast information system comprised of resources that are navigable by means of a **URL (Uniform Resource Locator)**
* HTTP is closely tied, both historically and functionally to the web as we know it. It is the primary means by which applications interact with the resources which make up the web

**A Brief History of the Web**

'The idea for the Web was conceived at CERN in 1989 by Tim Berners-Lee, and later formalized as a proposal in 1990 by Berners-Lee and his colleague, Robert Cailliau.'

The problem they were trying to solve is that there was lots of information on CERN computers spread out in different cities and countries. These computers were connected over the network, but the information stored on them was difficult to access. You needed to log on to a specific computer and use a specific program or commands to access the information; the program or commands you needed to use was different from system to system.

Berners-Lee decided to leverage internet connectivity and Hypertext to create an easily accessible information system. 'Within this system the information would exist on the various computers as structured resources, and these resources could all be connected to each other using hyperlinks in order to create a vast, world-wide 'web' of information.'

'Such a system required uniformity. Uniformity in how the resources were structured so that they could all be correctly rendered for viewing, uniformity in how the resources were addressed so that they could be simply and easily located, and uniformity in the way a request for a particular resource was made and the way in which that request was responded to. The means of providing that uniformity in the earliest incarnation of the Web was essentially a combination of three technologies or concepts: HTML, URIs, and HTTP.'

* Hypertext Markup Language (HTML) - the means by which resources are uniformly structured
* Uniform Resource Identifier (URI) - a string of characters which identifies a particular resource. The terms URI and URL (Uniform Resource Locator) are often used interchangeably but there are distinctions.
* Hypertext Transfer Protocol (HTTP) - the set of rules that provides uniformity to the way resources on the web are transferred between applications

## 3:4 HTTP Book: Introduction to HTTP

'Introduction to HTTP, the stateless protocol underlying all of the web. This book will help beginners understand how web applications work, and why building robust and secure web applications is so challenging.'

### Introduction ###

HTTP is at the core of the web, and at the core of dynamic web applications. 'Understanding HTTP is central to understanding how modern web applications work and how they're built.'

---

### Background

**<u>A Brief Overview and History</u>**

All web data -- html, css, JavaScript files, images, videos, etc -- are sent from a web server application to a client web browser application by an Application layer protocol called HTTP.

HTTP is a system of rules, a protocol, that serves as a link between applications and the transfer of hypertext documents. It is an agreement, or message format, of how machines communicate with each other.

HTTP follows a simple model where a **client** makes a **request** to a **server** and waits for a **response**.

Hence, it is referred to as a **request response protocol**.

Think of the request and response as text messages, or strings, which follow a standard format that the other machine can understand.

HTML has been through several changes since its inception. At the start, the protocol dealt only with HTML pages.

1991 - Version 0.9, the first documented version released

1992 - HTTP/1.0 released with the ability to transmit different file types like CSS documents, videos, scripts and images.

1995 - HTTP/1.1 released, introduced ability to reuse established connections for subsequent requests, among a host of other features.

1999 - further improvements were made to HTTP/1.1 in 1999 which resulted in what we mostly see today

2015 - initial spec for HTTP/2 published

2020 -  Security updates to HTTP/2 for TLS 1.3

2022 - HTTP/3 introduced. More updates to HTTP/2. HTTP/3 uses QUIC (officially introduced 2021) instead of TCP. QUIC is a multiplexed transport protocol built on UDP.

**<u>How the Internet Works</u>**

If an IP address is `192.168.0.1` and a port number is `1234`, then the pair is represented `192.168.0.1:1234`.

'An IP Address acts as the identifier for a device or server, which can contain hundreds or thousands of ports, each used for a different communication purpose to that device or server.'

'When we wish to connect to a resource like Google, we type in a URL, not an IP address. How does the computer map `www.google.com` to the appropriate IP address?'

**<u>DNS</u>**

'This mapping from domain name to IP address is handled by the **Domain Name System** or **DNS**. DNS is a distributed database which translates domain names like `www.google.com` to an IP address, so that the IP address can then be used to make a request to the server.'

'DNS databases are stored on computers called **DNS servers**. It is important to know that there is a very large world-wide network of hierarchically organized DNS servers, and no single DNS server contains the complete database.'

'If a DNS server does not contain a requested domain name, the DNS server routes the request to another DNS server up the hierarchy. Eventually the address will be found in the DNS database on a particular DNS server.'

'Your typical interaction with the Internet starts with a web browser when you:

1. Enter a URL like `http://www.google.com` into your web browser's address bar.
2. The browser creates an HTTP request, which is packaged up and sent to your device's network interface.
3. If your device already has a record of the IP address for the domain name in its DNS cache, it will use this cached address. If the IP address isn't cached, a request will be made to the Domain Name System to obtain the IP address for the domain.
4. The packaged-up HTTP request then goes over the Internet where it is directed to the server with the matching IP address.
5. The remote server accepts the request and sends a response over the Internet back to your network interface, which hands it to your browser.
6. Finally, the browser displays the response in the form of a web page.

'The above set of steps is a simplification... The main thing to understand though is that when your browser issues a request, it's simply sending some text to an IP address. Because the client (web browser) and the server (recipient of the request) have an agreement, or protocol, in the form of HTTP, the server can take apart the request, understand its components and send a response back to the web browser. The we browser will then process the response strings into content that you can understand.'



Articles on facebook outage.

'BGP stands for Border Gateway Protocol. It's a mechanism to exchange routing information between autonomous systems (AS) on the Internet. The big routers that make the Internet work have huge, constantly updated lists of the possible routes that can be used to deliver every network packet to their final destinations. Without BGP, the Internet routers wouldn't know what to do, and the Internet wouldn't work.'

'The Internet is literally a network of networks, and it's bound together by BGP. BGP allows one network (say Facebook) to advertise its presence to other networks that form the Internet.'

'The big networks each have an ASN: an Autonomous System Number. An Autonomous System (AS) is an individual network with a unified internal routing policy. An Autonomous System can originate prefixes (say that they control a group of IP addresses), as well as transit prefixes (say they know how to reach specific groups of IP addresses).'

'Every ASN needs to announce its prefix routes to the Internet using BGP; otherwise, no one will know how to connect and where to find [its addresses]'

Domain name - something like `google.com`

URL - something like `https://google.com/`

Here, `.com` is the Top-Level Domain (TLD), and `google` is the Second Level domain (2LD)

If it was `www.google.com`, then `www` would be the 3LD, and so on.

DNS has a 10 seconds timeout limit

The DNS mappings for the DNS system itself stem from publicly-recognized DNS Root servers whose IP address mappings are published by the Internet Assigned Numbers Authority. 'The authoritative name servers that serve the DNS root zone, commonly known as the "root servers", are a network of hundreds of servers in many countries around the world. They are configured in the DNS root zone as 13 named authorities'

`dig` command - DNS lookup utility

`dig` is a flexible tool for interrogating DNS name servers. It performs DNS lookups and displays the answers that are returned from the name server(s) that were queried. Most DNS administrators use `dig` to troubleshoot DNS problems because of its flexibility, ease of use, and clarity of output

`netstat -rn -f inet` - displays your own computer's routing table

The Autonomous Systems are connected via 'Peering', which uses BGP

So Network Address Translation (NAT) is used to multiplex private addresses of hosts on a local network to a single shared public IP address to conserve IPv4 addresses (only 3 billion out of more than 4 billion could even be used because many were reserved for testing, military and security agency demands, etc)

Border Gateway Protocol (BGP) is used to share routing information among the Autonomous Systems (AS) that make up the Internet. One AS might be your ISP, others Facebook, AT&T, etc.

**<u>Clients and Servers</u>**

The most common client is a Web Browser. 'Web browsers are responsible for issuing HTTP requests and processing the HTTP response in a user-friendly manner onto your screen. Web browsers aren't the only clients around, as there are many tools and applications that can also issue HTTP requests'.

'The content you're requesting is located on a remote computer called a server. Servers are nothing more than machines or devices capable of handling inbound requests, and their job is to issue a response back. Often, the response they send back contains relevant data as specified in the request.'

**<u>Resources</u>**

'"Resource" is a generic name for things you interact with on the Internet via a URL. This includes images, videos, web pages and other files. Resources are not limited to files and web pages. Resources can also be in the form of software that lets you trade stock or play a video game. There is no limit to the number of resources available on the Internet.'

**<u>Statelessness</u>**

* A protocol is said to be **stateless** when it's designed in such a way that each request/response pair is completely independent of the previous one.

'It is important to be aware of HTTP as a stateless protocol and the impact it has on server resources and ease of use. In the context of HTTP, it means that the server does not need to hang on to information, or state, between requests. As a result, when a request breaks en route to the server, no part of the system has to do any cleanup. Both these reasons make HTTP a resilient protocol, as well as a difficult protocol for building stateful applications. Since HTTP, the protocol of the [web], is inherently stateless that means web developers have to work hard to simulate a stateful experience in web applications.'

'When you go to Facebook, for example, and log in, you expect to see the internal Facebook page. That was one complete request/request cycle. You then click on the picture -- another request/response cycle -- but you do not expect to be logged out after that action.'

'If HTTP is stateless, how did the application maintain state and remember that you already input your username and password? In fact, if HTTP is stateless, how does Facebook even know that this request came from *you*, and how does it differentiate data from you vs. any other user?'

'There are tricks web developers and frameworks employ to make it seem like the application is stateful...'

'The key concept to remember is that even though you may feel the application is stateful, underneath the hood, the web is built on HTTP, a stateless protocol.'

'[The statelessness of HTTP is] what makes the web so resilient, distributed, and hard to control. It's also what makes it so difficult to secure and build on top of.'

---

### What is a URL? ###

* A Uniform Resource Locator (URL) is the most frequently used part of the general concept of a Uniform Resource Identifier (URI), which specifies how resources are located

**The Real Difference Between a URL and a URI**

* A Uniform Resource Identifier (URI) is a string of characters that uniquely identify a name or a resource on the internet.
* A **URI** *identifies a resource by name, location, or both*.
* A Uniform Resource Locator (**URL**) is a type of URI that specifies not only a resource, but how to reach it on the internet. More specifically, *a URL is a URI that includes a protocol*, like FTP or HTTP
* A Uniform Resource Name (URN) is a type of URI that uses the specific naming scheme of `urn:`
* A URI or URN is like a name, and a URL is like a name plus an address

1. A URI is an **identifier** of a specific resource: books, documents, etc
2. A URL is a special type of identifier that also tells you how to access it: HTTP, FTP, MAILTO, etc
3. If the protocol is either present or **implied** for a domain, you should call it a URL -- even though it's also a URI

**<u>URL Structures</u>**

URLs have their own specific structure. In that structure you have the followng components:

1. Scheme - which protocol you are using to interact
2. Authority - the target you're accessing
   1. userinfo - some kind of user info, possibly PGP key, etc before an `@` sign
   2. host - e.g. `www.example.com`
   3. port - a number following a colon, e.g `:80`
3. Path - which resource you are requesting on the host, using forward slashes to separate (virtual) folders etc
4. Query - `key=value` pairs combined with `&` symbols, following a `?`, e.g. `?search=foo&order=newest`
5. Fragment - target point to jump to within the given page, following a `#`, e.g. `#top`

end of article

<u>**URL Components**</u>

The URL `http://www.example.com:88/home?item=book` can be broken into 5 parts:

1. `http` - the **Scheme**. It always comes before `://` and tells the web client how to access the resource. In this case it tells the web client to use HTTP to make a request. Other URL schemes include `ftp`, `mailto`, and `git`. In the context of URLs, we call this the 'scheme', even if it denotes a protocol.
2. `www.example.com` - the **Host**. It tells the client where the resource is hosted, or located.
3. `:88` - the **Port**, or **Port Number**. Only required if you want to use a port other than the default.
4. `/home` - the **Path**. It shows what local resource is being requested. This part of the URL is not always needed.
5. `?item=book` - the **Query String**, which is made up of **Query Parameters**. It is used to send data to the server. This part of the URL is also optional.

Sometimes the path can point to a specific resource on the host. Sometimes, we may want to include a port number in the URL. This is only done when we want to use a different port number to the default. **Unless a different port number is specified, port `80` will be used by default in normal HTTP requests**. 