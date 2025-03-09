# TCP and UDP 

* Have a clear understanding of the TCP and UDP protocols, their similarities and differences
* Have a broad understanding of the three-way handshake and its purpose
* Have a broad understanding of flow control and congestion avoidance



## Have a clear understanding of the TCP and UDP protocols, their similarities and differences

2:1 **What to focus on**

* Transport layer protocols enable communication between processes

  * Multiplexing and demultiplexing

  * How ports work with IP addresses to provide multiplexing and demultiplexing

* Network reliability is engineered

* Understand the trade-offs between TCP and UDP



<u>2:2 **Communication Between Processes**</u>

* IP provides inter-network communication between hosts
* However, for networked applications to work we need more functionality, and most importantly:
  * A direct connection between networked applications or processes
  * Reliable network communication

* IP provides connections between hosts, or devices, which might be on the same network or on different networks around the world from each other. A message can go from one host to another with IP, but the destination host is as far as IP takes it
* However, there are potentially many networked applications running on a single host. If IP can only get us as far as the host, how do we provide communication between an application running on one host and an application running on another host (or potentially between two different applications or processes running on the same host)?

**<u>Multiplexing and Demultiplexing</u>**

* We can think of the different networked applications or processes running on a device at one time as different distinct *channels* for communication on a host machine
* The source and destination IP addresses in IP packets can be used to identify the host machines involved in a communication. This creates a communication channel between hosts
* So, although we have multiple communication channels *on* a host, with IP addresses we only have a single channel *between* hosts.
* We need a way to transmit these multiple data inputs over a single channel and then separate them out again at the other end
* In the context of a communication network, this idea of transmitting multiple signals over a single channel is known as **multiplexing**, with **demultiplexing** being the reverse process
* Multiplexing is a general concept that can be applied in a variety of contexts within communication networks. Our focus here is at the Transport layer of communication
* This takes place through the use of **network ports**

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

**<u>Sockets</u>**

* A socket is an abstraction for an end-point used for inter-process communication
  * UNIX socket -- a mechanism for communication between local processes running on the same machine
  * Internet socket (e.g., TCP/IP socket) -- a mechanism for inter-process communication between networked processes (usually on different machines)
* An internet socket is an inter-process communication end-point defined by an address-port pair
* In socket programming or network programming terms, the implementation of an internet socket involves instantiating *socket objects*
  * Implementations vary, but many follow the Berkeley/POSIX sockets API model for their interface - `bind()`, `listen()`, `connect()`, `accept()`, etc
* UDP is connectionless
  * The server side instantiates a socket object defined by the IP address of the host and the port assigned to a particular process on that host
  * The object calls a `listen()` method that allows it to wait for incoming messages directed to that particular IP/port pair
  * Such messages could come from any source, at any time, and in any order, but that isn't a concern in a connectionless system
  * The socket simply processes any incoming messages as they arrive and sends any responses as necessary
* TCP is connection-oriented
  * The server side instantiates a socket object defined by the IP address of the host and the port assigned to a particular process running on that host. The socket is told to `listen()` on that port
  * With connection-oriented communication, when a message arrives, a new socket object is instantiated defined by a **four-tuple** of the Source IP Address, Source Port, Destination IP Address, Destination Port
  * This new socket object listens specifically for messages where all four pieces of information matched
  * Any messages not matching this four-tuple would still be picked up by the original socket, which would then instantiate another socket object for the new connection
  * This creates a dedicated virtual connection for communication between a specific process running on one host and a specific process running on another host
  * The advantage of having a dedicated connection like this is that it more easily allows you to put in place rules for reliable data transfer
    * order of messages
    * acknowledgements that messages have been received
    * etc



2:3 **<u>Network Reliability</u>**

* While lower layer protocols such as Ethernet and IP provide checksums to check whether data has become corrupted, if a frame or packet is found to be corrupt then it will simply be dropped. These lower level protocols do not provide for resending lost data
* Therefore, the network up to and including the Internet Protocol is an inherently **unreliable communication channel**
* What we often need is a **reliable communication channel** over which to send data, for web pages, emails, etc
* How can we transfer data reliably over an unreliable channel? We need a system of rules, or protocol, to ensure that all the data that is sent is received at the other end and in the correct order

**Fundamental elements required for reliable data transfer:**

* In-order delivery -- data can be reassembled in the correct order through the use of sequence numbers
* Error detection -- corrupt data is identified using a checksum
* Handling data loss -- missing data is retransmitted based on acknowledgements and timeouts
* Handling duplication -- duplicate data is eliminated through the use of sequence numbers

**<u>Pipelining for Performance</u>**

* Pipelining -- multiple messages are transmitted one after the other without waiting for acknowledgements
  * Go-back-N
  * Selective Repeat
* The sender implements a **window** representing the maximum number of messages that can be in the pipeline at any one time
* Once the sender receives the appropriate acknowledgements for the messages in the window, it moves the window on



2:4 **<u>Transmission Control Protocol (TCP)</u>**

* TCP offers reliable data transfer - "The TCP must recover from data that is damaged, lost, duplicated, or delivered out of order by the internet communication system", RFC793
* TCP provides the abstraction of reliable network communication on top of an unreliable channel. This abstraction hides much of the complexity of reliable network communication from the application layer: in-order delivery, data integrity, de-duplication and retransmission of lost data
* The complexity might be abstracted away, but the performance cost of the complexity is not
* TCP attempts to mitigate the performance cost of reliability through mechanisms for **flow control** and **congestion avoidance**
* TCP provides *reliability* and *data encapsulation and multiplexing through the use of TCP Segments*

**<u>Segments</u>**

* Segments are the Protocol Data Unit (PDU) of TCP - uses combination of header and data payload to provide encapsulation of data from the layer above
* Some of the more important fields in the header in terms of implementing reliability:
  * Checksum -- provides the Error Detection aspect of TCP reliability. The checksum is an error checking value based on the data payload that is generated by the sender using an algorithm. The receiver generates a value by using the same algorithm on the received data payload and if the values don't match, the receiver drops the Segment
  * Sequence Number & Acknowledgement Number -- these two fields are used together to provide for the other elements of TCP reliability such as In-Order Delivery, Handling Data Loss, and Handling Duplication. The precise way TCP uses these fields is out of scope of this course.
* Other fields of interest:
  * Window Size -- related to TCP Flow Control
  * Flags -- the Flag fields are one-bit boolean fields. A couple of these fields, `URG` and `PSH`, are related to how the data contained in the segment should be treated in terms of its importance or urgency. The `SYN`, `ACK`, `FIN`, and `RST` flags are used to establish and end a TCP connection, as well as manage the state of that connection
* A TCP connection is established via what is known as the Three-Way Handshake
* A TCP connection can be closed via what is known as the Four-Way Handshake



## Have a broad understanding of the three-way handshake and its purpose

2:4 **<u>Transmission Control Protocol (TCP)</u>**

**<u>TCP Connections</u>**

* TCP is a connection-oriented protocol. It doesn't start sending data until a connection has been established between application processes
* The TCP Three-Way Handshake establishes a connection
  * This involves the `SYN` and `ACK` flags
* TCP uses the Four-Way Handshake to terminate a connection
  * This involves the `FIN` flag
* The Three-Way Handshake
  * Sender sends `SYN` Segment
  * Receiver receives `SYN` Segment. Responds with `SYN`/`ACK` Segment
  * Sender receiver `SYN`/`ACK` Segment, responds with `ACK` Segment
  * Receiver receives `ACK` Segment, connection is now established
* The `SYN` Segment is a Segment with the `SYN` flag set to `1`
* The `SYN`/`ACK` Segment is a Segment with the `SYN` and `ACK` flags set to `1`
* The `ACK` Segment is a Segment with the `ACK` flag set to `1`
* Upon sending the `ACK`, the sender can immediately start sending data
* The receiver must wait until it has received the `ACK` before it can send any data back to the sender
* One of the main reasons for the Three-Way Handshake process is to synchronize (`SYN`) the sequence numbers that will be used during the connection
* Part of the purpose of the flags in a TCP Segment header is to manage the **connection state**

The connection states are `LISTEN`, `SYN-SENT`, `SYN-RECEIVED`, `ESTABLISHED`, `FIN-WAIT-1`, `FIN-WAIT-2`, `CLOSE-WAIT`, `CLOSING`, `LAST-ACK`, `TIME-WAIT`, and the fictional state `CLOSED`

Most of the time we are concerned with `ESTABLISHED` and `LISTEN` (on the server side). The other states are related to the establishment and termination of a connection

**<u>Three-way Handshake to Establish a Connection, with Connection States</u>**

Client-side

```
Client Start State |	  Client Action				| Client End State
`CLOSED`					 |  Sends a `SYN` Segment	|	 `SYN-SENT`
									 |												|
`SYN-SENT`				 |	Waits to receive an   |	 `SYN-SENT` 
									 |  `ACK to the `SYN` it  |
									 |  sent, as well as the  |
									 |  server's `SYN`				|
									 |												|
`SYN-SENT`				 |	Receives the `SYN ACK`|	 `ESTABLISHED`
									 |  Segment sent by the   |
									 |  server and sends an   |
									 |  `ACK` in response.    |
									 |  The client is now			|
									 |  finished with the			|
									 |  connection            |
									 |  establishment process	|
									 |												|
 `ESTABLISHED`		 | Ready for data transfer|	 `ESTABLISHED`
 									 | Can start sending			|
 									 | application data				|
```

Server-side

```
Server Start State |			Server Action											| Server End State
	`LISTEN`				 | Waits for a connection request					|	`LISTEN`
									 |																				|
	`LISTEN`				 | Recieves `SYN` Segment. Sends a 				|	`SYN-RECEIVED`
									 | `SYN ACK` Segment which serves as both |
									 | its `SYN` and an `ACK` for the client's|
									 | `SYN`																	|
									 |																				|
	`SYN-RECIVED`		 | Waits for an `ACK` for the `SYN` it 		|	`SYN-RECEIVED`
									 | just received													|
									 |																				|
	`SYN-RECEIVED`	 | Receives the `ACK` sent in response to |	`ESTABLISHED`
									 | its `SYN`. The server is now finished	|
									 | with the connection establishment			|
									 | process																|
```

* There is complexity to the way TCP manages connection state
* This complexity relates saliently to the establishment of a connection: the sender cannot send any application data until it has sent the `ACK` Segment
* In practical terms, this means that there is a whole round-trip of latency (RTT) before any application data can be exchanged
* This hand-shake process occurs every time a TCP connection is made, and this clearly impacts the performance of any application using TCP at the transport layer
* TCP involves a lot of overhead in terms of establishing connections, and providing reliability through the retransmission of lost data
* In order to mitigate this additional overhead, it is important that the actual functioning of data transfer when using the protocol occurs as efficiently as possible. In order to aid this goal, TCP provides mechanisms for **flow control** and **congestion avoidance**

So:

* Flow Control aims to prevent sender overwhelming receiver
* Congestion Avoidance aims to prevent sender overwhelming the network capacity



**<u>Disadvantages of TCP</u>**

* There is a latency overhead to establishing a TCP connection due to the handshake process
* TCP exhibits Head-of-Line (HOL) Blocking
  * Head-of line blocking is a general networking concept, and isn't specific to TCP
  * HOL Blocking relates to how issues in delivering or processing one message in a sequence of messages can delay or 'block' the delivery or processing of the subsequent message in the sequence
  * With TCP, HOL blocking can occur as a result of the fact that TCP provides for in-order delivery of segments
  * If one of the segments goes missing and needs to be retransmitted, the segments that come after it in the sequence can't be processed and need to be buffered until the retransmission has occurred
  * This can lead to increased queuing delay, which is one of the elements of latency



## Have a broad understanding of flow control and congestion avoidance

2:4 **<u>Transmission Control Protcol (TCP)</u>**

**<u>Flow Control</u>**

* Flow control is a mechanism to prevent the sender from overwhelming the receiver with too much data at once
* The receiver will only be able to process a certain amount of data in a given time-frame.
  * Data awaiting processing is stored in a 'buffer' or 'queue'. The buffer size will depend on the amount of memory allocated according to the configuration of the OS and the physical resources available
* Each side of a connection can let the other side know the amount of data that it is willing to accept via the `WINDOW` field of the TCP header
  * This Window number is dynamic, and can change during the course of a connection
  * If the receiver's buffer is getting full it can set a lower amount in the `WINDOW` field of a Segment it sends to the sender, and the sender can then reduce the amount of data it sends accordingly
* Although flow control prevents sender from overwhelming receiver, it doesn't prevent sender or receiver from overwhelming the underlying network. For that task, we need **Congestion Avoidance**

**<u>Congestion Avoidance</u>**

* Network Congestion is a situation that occurs when there is more data being transmitted on the network than there is network capacity to process and transmit the data. Excess data can simply be lost
  * IP packets move across the network in a series of hops. At each hop, the packet needs to be processed: the router at that hop runs a checksum on the packet data; it also needs to check the destination address and work out how to route the packet to the next hop on its journey
  * All of this processing takes time, and a router can only process so much
  * Routers use a buffer to store data that is awaiting processing, but if there is more data to be processed than can fit in the buffer, the buffer over-flows and those data packets are dropped
* TCP retransmits lost data
  * If lots of data is lost, that means lots of retransmitted data, which is inefficient
  * Ideally, we want to keep retransmission to a minimum
* TCP actually uses data loss as a feedback mechanism to detect, and avoid, network congestion
  * If lots of retransmissions are occurring, TCP takes this as a signal that the network is congested and reduces the size of the transmission Window
  * The transmission window limits the number of unacknowledged segments that the sender can have at a time
* There are various different algorithms for determining the size of the initial transmission window, and how much it should be reduced or increased by depending on network conditions
  * The exact algorithm or approach used will depend on which variant of TCP is in operation

