# Practical Networking - Networking Fundamentals: how data flows through the Internet #

## 1. Network Devices ##

<u>**Video 1 - Hosts, IP Addresses, Networks**</u>

* **Hosts** are any device which **sends** or **receives** traffic

Computer, laptop, phones, printers, servers, cloud resources like cloud servers, IoT devices

Anything that sends or receive traffic over a network



Hosts typically fall into the categories

* Clients
* Servers

* Clients initiate requests, Servers respond
  * the terms Client and Server are relative to a specific communication

* Servers are simply computers with software installed which responds to specific requests

Most popular web servers (software) 2024, market share:

1. Nginx - 46.7%
2. Apache - 12.75%
3. LiteSpeed Web Server - 12.4%
4. Apache HTTP Server - 12.25%
5. Microsoft IIS (Internet Information Services) - 8.71%
6. Others - 7.19% 



* An **IP Address** is the identity of each host on the Internet

  * IP addresses are 32 bits

  * Represented as four **Octets**

  * Each Octet can be 0-255

* Hierarchically assigned (known as **Subnetting**, which is not covered in this series but Practical Networking have a 7-part series on just **Subnetting**) 

* A **Network** is what transports traffic between Hosts

  * Logical grouping of hosts which require similar connectivity
  * Networks can contain other networks, sometimes called **Sub-Networks** or **Subnets**
  * Networks connect to other networks
  * Internet



<u>**Video 2 - Hub, Bridge, Switch, Router**</u>

Mainly focusing on switches and routers, but starting with simpler/earlier tech, repeaters, hubs and bridges

* Data crossing a wire decays as it travels
* **Repeaters** regenerate signals
  * Allow communications across greater distances
* Connecting Hosts directly to each other doesn't scale
* We need a central device to which all hosts connect and which connects all hosts with each other: a **hub**, a **bridge**, or a **switch**
  * A **Hub** is simply a multi-port **Repeater**
    * Hub repeats signal across multiple ports
    * Facilitates scaling communication between additional hosts
    * Yet everyone receives everyone else's data
  * A **Bridge** sits between **Hub**-connected devices
    * Bridges only have two ports
    * Bridges learn which hosts are on each side
    * Bridges contain communication to the side necessary
    * First type of device that contains packets to the relevant networks
  * A **Switch** is a combination of **Hubs** and **Bridges**
    * Multiple Ports
    * Learns which hosts are on each port, on a per-port (per-host) basis
    * **Switches** facilitate communication **within** a network
    * Hosts on a Network share the same IP address space
    * A network is a grouping of hosts which require similar connectivity
* A **Switch** facilitates communication **within** networks
* A **Router** facilitates communication **between** networks
  * A Router provides traffic control point (security, filtering, redirecting) between networks
  * Routers learn which networks they are attached to on each of its interfaces
  * Known as Routes - stored in a **Routing Table**
  * **Routing Table** - all networks a Router knows about
  * A Router has an IP address in each network it is attached to, meaning each of the Router's interfaces has an IP address in the network it is attached to
  * Each of the Router's interface IP addresses serves as a **Gateway**
  * A **Gateway** - each host's way out of their local network
* **Routers** create the Hierarchy in Networks and the entire Internet
* In simple terms, the Internet is nothing more than a bunch of different Routers



* **Routing** is the process of **moving data between networks**
  * A **Router** is a device whose primary purpose is Routing
* **Switching** is the process of **moving data within networks**
  * A **Switch** is a device whose primary purpose is switching

However, there are many other Network Devices

* Access Points
* Firewalls
* Load Balancers
* Virtual Switches (cloud)
* Virtual Routers (cloud)
* Layer 3 Switches
* IDS / IPS
* Proxies

and so on. All of them perform Routing and/or Switching.



So

* **Hosts** are any device which **sends** or **receives** traffic
  * Clients and Servers
* An **IP Address** is the **identity of each host**
* A **Network** is what **transports traffic between hosts**
  * Logical grouping of hosts which require similar connectivity
  * Subnetworks, Subnets
* **Repeaters** regenerate signals
* **Hubs** are simply **multi-port Repeaters**
* **Bridges** sit between **Hub-connected hosts**
* **Switches** facilitate communication **within** a network
  * Perform **Switching** function
* **Routers** facilitate communication **between** networks
  * Perform **Routing** function
  * Gateways, Routes, Routing Table, Routing

## 2. OSI Model - Practical Perspective ##

**<u>Video 3 - OSI Model: A Practical Perspective</u>**

* The purpose of networking is to allow two hosts to share data with one another
* Hosts must follow a set of rules
* OSI model divides rules of networking into 7 layers
  * Each layer serves a specific function
  * If all layers are functioning, hosts can share data
* Layer 1 - Physical - Transporting Bits
  * Computer data exists in the form of bits (1s and 0s)
  * Something has to transport those bits between hosts
  * Layer 1 technologies
    * cables - Twisted Pair (Ethernet), Coaxial, Fiber
    * Wi-Fi (radio waves)
    * Repeaters
    * Hubs (multi-port repeaters)
* Layer 2 - Data Link - Hop to Hop
  * Interacts with the Wire (i.e. Physical Layer)
  * Puts bits on the wire, retrieves bits from the wire
    * Network Interface Card (NIC)
    * Wi-Fi Access Cards
    * Switches
  * Addressing Scheme - MAC addresses (Medium Access Control)
    * 48 bits, represented as 12 hex digits
  * Windows uses commas to separate hex digit pairs; Unix/Linux uses colons instead of commas; Cisco servers use periods to separate groups of four hex digits
  * Every NIC has a unique MAC address
* Layer 3 - Network - End to End
  * Addressing Scheme - IP addresses
    * 32, bits represented as 4 octets, each 0-255
  * Layer 3 technologies
    * Routers
    * Hosts
    * Anything with an IP address
* ARP - Address Resolution Protocol
  * Links a L3 address to a L2 address



**<u>Video 4 - OSI Model: A Practical Perspective - Part 2</u>**

* Layer 4 - Transport - Service to Service
  * Distinguish data streams
  * Addressing scheme - Ports
    * 0-65535 - TCP - favors reliability
    * 0-65535 - UDP - favors efficiency
  * Servers listen for requests to pre-defined, well-known Port numbers
  * Clients randomly choose a Port number as Source Port when making requests
  * Clients then listen on the chosen Port for response from the server
* Layers 5, 6, 7 - Session, Presentation, Application
  * Distinction between these layers is somewhat vague
  * Every application is essentially free to implement the **functions** of all three layers as the application choses
  * Often simply considered as a single Application Layer (as in TCP/IP model and others)
* Encapsulation process
  * Data produced at the Session/Presentation/Application layer is taken as data payload of a TCP segment (or UDP datagram) when the Transport L4 header is added for service-to-service delivery
  * The segment or datagram is passed down the stack to the Network layer where it is encapsulated in an IP packet with a Network L3 header for end-to-end delivery
  * The packet is handed down the stack to be encapsulated with a L2 header into an Ethernet frame for hop-to-hop delivery
* Ethernet frame then taken over the Physical layer wire as bits
* The receiving host then does the opposite process - de-encapsulation
  * Interprets bits off the wire as an Ethernet frame
  * Data Link layer checks L2 header, discards header, passes data payload up the stack
  * Network layer checks L3 header, discards header, passes data payload up the stack
  * Transport layer (e.g. TCP) checks header for Destination port, strips header, sends data payload to appropriate service/process/application
  * Application processes the data
* Neither of the following is a strict rule - exceptions exist:
  1. Network devices operate at specific layers
  2. Network protocols operate at specific layers
* For example, some routers need to look at TCP headers for NAT multiplexing, so the router is not **purely** an L3 device in this role
* Another example is ARP, which straddles L3 and L2
* Therefore, the OSI Model is a **model**, not a set of rigid rules
  * Conceptualizes what functions are required for data to flow through the Internet



**<u>Lesson 3 - Everything Hosts do to Speak on the Internet - video 1</u>**

Two scenarios

1. Hosts connected directly to each other (whether through switches or simply with a LAN cable)l: a host communicating to another host on the **same** (local) network
2. Hosts connected on opposite sides of a router: a host communicating to another host on a **foreign** network

The important point made initially is that hosts don't know what they're connected to, and we are discussing what the host itself does to communicate. So what a host does to communicate is the same if we have two computers connected together with an ethernet cable as it would be if we have a more realistic local network with one or more switches etc.

And likewise, what a host does to communicate is the same regardless of whether it is communicating to a host on another LAN in the same building with a single router connecting the two LANs, or whether the host is communicating to a host on the other side of the internet whose LAN is separated by many, many routing devices.

So these two scenarios illustrate all of the communication that occurs on the internet from the perspective of each host.



**Scenario 1: Hosts are directly connected (same local network)**

* Both hosts have a NIC, and therefore a MAC address
* Both hosts are configured with an IP address and a Subnet Mask
  * Subnet Mask identifies the size of the IP network

* Host A has some Data to send to Host B
  * Networking doesn't care what this data is - it's just `1` and `0`

* Host A knows the IP address of Host B
  * Maybe user typed the IP address, like `ping 10.1.1.33`
  * Maybe IP address was acquired through DNS
    * DNS converts Domain Name -> into IP address
  * Host A knows `10.1.1.33` is in its own IP Network (subnet)

* Host A can create the L3 header to attach to the Data

  * Layer 3 - Network - end-to-end delivery

* Host A does not know Host B's MAC address

  * Host A must use Address Resolution Protocol (ARP) to resolve Host B's MAC address

    * Host A sends an ARP request out on the network

    * The ARP request has an L2 header, but the destination MAC address is obviously not the one we are requesting. Instead, the ARP request is sent as a broadcast to everyone on the network. So the destination MAC address is `ffff.ffff.ffff`, the specially-reserved MAC address for Broadcast to everyone on local network, PDU is delivered to everyone on local network

    * ARP Request asks for the MAC address associated with target IP, essentially asking, 'if anyone out there has the IP `10.1.1.33`, send me your MAC address'

      * ARP Request includes sender's MAC address

      * ARP Mappings are stored in an ARP cache. Every device that has an IP address has an ARP cache

      * Upon receiving ARP request, Host B populates its ARP cache with an entry for Host A using the information from the request

    * Host B responds by sending an ARP Response

      * ARP Response is sent Unicast (directly to Host A)
      * Since Host B knows MAC address of Host A, it can construct an L2 header with a Destination MAC Address of Host A's MAC address

    * Upon receiving ARP response, Host A can finish populating the ARP cache entry for Host B

    * Host A creates L2 Header for hop-to-hop delivery

    * Data is sent to Host B

    * Upon receiving the PDU, Host B discards L2 header

    * Host B discards L3 header

    * Data is processed by Application

    * Further data exchange between hosts is simple

      * Both hosts have what they need to create L3 and L2 headers

* ARP links an L3 address (IP) to an L2 address (MAC)



Seven attributes of Subnetting:

1. Network ID - First IP address in Sub-Network, coupled with CIDR/Subnet Mask, identifies the range of IP addresses pertaining to the subnet
2. Broadcast ID - Last IP address in Sub-Network
3. First Host IP - next address after Network ID, so `Network ID + 1`
4. Last Host IP - last address before Broadcast ID, so `Broadcast ID - 1`
5. Next Network - Network ID of the *next* Sub-Network, so `Broadcast ID + 1`
6. Number of IP Addresses - number of IP addresses in Sub-Network (two of which are not usable)
7. CIDR/Subnet Mask - converting between CIDR and Subnet Mask

`/24`, `/25`, `/26`, `/27` - this is CIDR (Classless Inter-Domain Routing) notation, and denotes the size of the subnet



**<u>Lesson 3 - Everything Hosts do to Speak on the Internet - video 2</u>**



So the example topology is Host A connected to Router connected to Host C

* Host A, Host C, and the Router have MAC and IP addresses

* Host A has some data to send to Host C

  * Host A knows Host C's IP address
    * provided by user or application

  * Host A knows Host C's IP address is on a foreign network

* Host A creates a L3 header

  * Layer 3 - Network - End to End (IP packet)

* Host A needs to create a L2 header

  * Layer 2 - Data Link - Hop to Hop
  * Since our destination host is on a foreign network, the next hop is to the Router (default gateway)
  * So the purpose of this L2 header is to take the data from Host A to the Router

* Host A's ARP cache is empty, so Host A make an ARP request for the MAC address of the Router

* Host A uses ARP to resolve the MAC address of the Router's IP

  * Router IP address is configured as the Default Gateway of Host A
  * When you connect a computer to the internet, there are three things you have to configure: an IP address, a subnet mask, and a Default Gateway, all of which are generally resolved through DHCP with a DHCP server sending a response to your computer's initial DHCP 'hello'. On a Windows computer you can use `ipconfig` from the command line to see these things. On Linux you can use `ip address` and `ip route`.
  * This is how Host A knows the Router's IP address.
  * Host A sends ARP request asking for the MAC address that is mapped to the Router's IP address, including its own ARP mapping in the request
  * Router receives this and generates an ARP response with the mapping of the Router's IP to its MAC

* Host A populates its ARP cache with the mapping of the Router's IP address to the Router's MAC address

* Host A now creates L2 header

* Data is sent to the Router

  * Router discards L2 header
  * From now on, the Router takes over
  * Router adds L2 header for the next hop, and so on

* Host A's job is done



* Host A's first step when sending data is always the same:
  * Determine if target IP is on **local** or **foreign** network
  * If foreign, then ARP for Default Gateway
  * If local, then ARP for Target IP



<u>Lesson 4: Everything Switches do to facilitate communication **within** a network - Part 1</u>

* **Switching** is the process of **moving data within networks**
  * **Switches** are devices whose primary purpose is Switching



* Switches are L2 devices - they only use L2 header to make decisions, the ip packet within the frame is simply data (payload)
* If we are simply focusing on a simple switch, we can remove IP/Network layer from topology altogether



* Switches use and maintain a **MAC Address Table**
  * Mapping of Switch Ports to MAC addresses
* MAC address table starts out empty
  * As data flows through the network, switch populates MAC address table
* Switches perform only three actions:
  * Learn - Update MAC Address Table with mapping of Switch Port to Source MAC
  * Flood - Duplicate and send frame out all switch ports (except receiving port)
  * Forward - Use MAC Address Table entry to deliver Frame to appropriate switch port
* These three actions are the rules of Switching in general
* Host A sends data with L2 header over the wire destined for Host D
* The switch receives the frame on Port 5. The switch Learns, populating its MAC address table with a mapping of Port 5 to the Source MAC Address of the frame.
* The switch will Learn the Source MAC Address of every frame it receives
* The switch however does not currently have the mapping for the Destination MAC address in its table
* This means the switch has no option but to Flood. This ensures that whichever machine connected to it has that Destination MAC gets the frame
* When Flooding, the switch did not send the frame out of the Port the frame came in on - Port 5
* When Host B and Host C receive the frame, they check the Destination MAC and simply discard it as not pertaining to them
* Host D checks the Destination MAC Address and accepts the frame for processing
* Host D generates response to send back to Host A
* Host D sends response data with L2 header over the wire
* Response frame arrives at the switch on Port 8
* Switch Learns the mapping of Port 8 to Host D's MAC address (enters it in its MAC address table)
* Switch checks the Destination MAC address of the frame and this time finds the mapping for Host A's MAC Address in its table - Port 5
* Switch Forwards the frame out Port 5



* This process would be exactly the same if Host A were sending data to a Router on the local network, instead of Host D, in order to send it over the Internet to a host on a different network

* Traffic going THROUGH the switch
* Switch has a MAC address but it was not involved in the above process
* If we are sending something TO the switch, then the MAC address of the switch is involved
* In this case however, the switch would also need an IP address, and if it has an IP address it is acting as a host on the network and not a simple switch
* Then the process would be as described in the Host lessons
* This sending to and receiving from the switch might happen with a managed switch if we were logging in with Telnet or SSH in order to configure the switch (or monitor network activity?)
* But for traffic flowing THROUGH the switch, the switch's MAC and potential IP are completely uninvolved
* So in its Switching role of facilitating communication over a local network, the switch's address is not involved





<u>Lesson 4: Everything Switches do to facilitate communication **within** a network - Part 2</u>

* A Broadcast frame that arrives in a switch will always be flooded
* A Unicast frame will only be flooded if the switch does not have the Destination MAC address in its MAC address table
* VLAN - Virtual Local Area Network
  * VLANs allow us to divide a switch's ports into isolated, independent groups
  * Divides a switch into multiple 'mini-switches'
  * Each VLAN can Learn, Flood, or Forward independently from the other VLANs in the switch
  * Each VLAN has its own MAC address table
* Multiple Switches
  * Switches on the same LAN maintain multiple independent MAC address tables
  * They do not share information with each other's tables
  * A single switch port can Learn multiple MAC address mappings
  * This is how all the destination MAC addresses accessed through the switch connected to a single switch port can be accessed

+

<u>Lesson 5: Everything Routers do to facilitate communication **between** networks - Part 1</u>

* Routers are connected to a network (just like hosts)
  * Routers have an IP address and a MAC address **on each Interface**
* RFC 2460: Internet Protocol, Version 6 (IPv6) Specification
  * node - a device that implements IPv6
  * router - a node that forwards IPv6 packets not explicitly addressed to itself
  * host - any node that is not a router
* Routers forward packets not destined to themselves (unlike hosts)
* Routers maintain a map of all the Networks they know about
  * Routing Table
  * Inside the the Routing Table are Routes
  * Each Route is a set of instructions for how to reach a specific network
  * If a Router receives a packet with an unknown IP destination, packet is dropped
* Routing Table can be populated via three methods
  1. Directly Connected - Routes for the Networks which are attached to the Router's Interfaces
  2. Static Routes - Routes manually provided by an Administrator
  3. Dynamic Routes - Routes learned automatically from other Routers
     * Dynamic Routing Protocols - RIP, OSPF, BGP, EIGRP, IS-IS



<u>Lesson 5: Everything Routers do to facilitate communication **between** networks - Part 2</u>

* Routers also have ARP Tables - mapping of L3 to L2 address
  * Everything with an IP address has an ARP Table
  * Start Empty - populated as needed with network traffic - unlike Routing tables
* Routing table has to be populated ahead of time - unlike ARP
  * If a Router receives a packet for an unknown IP destination it drops the packet
  * With ARP, if a Router does not know the destination MAC address, it simply sends out an ARP request
* Routers use both Routing Table and ARP Table to move data across the internet
* Each Router involved in a path across the Internet:
  * Looks up Destination IP in Routing Table to determine Next-Hop IP
  * Adds an L2 header with Destination MAC of next Router's MAC
    * Performs ARP as necessary
* This is repeated until the packet reaches the router that the destination host is connected to
* The Internet is essentially a series of Routers handing packets off to other Routers



**<u>Lesson 5: Router Hierarchies and Route Summarization - Part 3</u>**

* Routers are typically connected in a hierarchy (rather than linearly)
  * Easer to scale
  * More consistent connectivity throughout the entire topology
* Router Hierarchy allows for Route Summarization
  * Reduce number of Routes in Routing Table
    * There are three things in descending order of importance the Router considers when choosing between multiple Routes:
      1. Route Specificity - more specific is better
      2. Admin Distance - particular to the routing protocol (RIP, EIGRP, OSPF, etc); lower is better
      3. Metric - lower is better
    * If all three of those items are the same for multiple routes, the Router will load-balance packets across multiple paths (ECMP - Equal Cost Multi-Path)
  * Default Route - ultimate route summary
    * `0.0.0.0 / 0` - every IPv4 address
    * "for everything else, go here"



**<u>Lesson 6: Network Protocols - ARP, FTP, SMTP, HTTP, SSL, TLS, HTTPS, DNS, DHCP</u>**

* A protocol is a set of **rules** and **messages** that form an **Internet standard**
  * ARP - Address Resolution Protocol - RFC 826
    * Resolves IP to MAC mappings
  * FTP - File Transfer Protocol
    * allows client and server to send and receive files from each other
    * `RETR` command, etc
  * SMTP - Simple Mail Transfer Protocol
    * allows client and server to exchange emails with one another
    * `HELO` message, response code `250`, etc
  * HTTP - Hypertext Transfer Protocol
  * SSL - Secure Sockets Layer
  * TLS - Transport Layer Security
* Hosts are any device which sends or receive traffic
  * Clients and Servers
  * Servers are computers with software that responds to requests
  * From a host-to-host networking perspective, both client and server follow the same rules
* DNS - Domain Name System protocol
  * Converts Domain Name into IP Address
    * This is true for email mail servers, etc, as well as web servers
* Every host needs four items for Internet Connectivity
  1. IP Address - Host's identity on the internet
  2. Subnet mask - size of host's network, allows it to determine if an IP address is local or foreign
  3. Default Gateway - Router's IP Address
  4. DNS Server IP(s) - translate domain names to IPs
* DHCP - Dynamic Host Configuration Protocol
  * DHCP Server provides IP/SM/DG/DNS for Clients
  * Host sends Discover message
  * DHCP Server sends Offer response back to client containing the host's assigned IP/SM/DG/DNS



<u>**Bonus video: OSI Model Layers 5, 6, and 7 - Session, Presentation, Application**</u>

* OSI model was created before the era of "Personal Computers"
* Computers were mainframes etc
  * User access via dumb terminals
* Layer 5 - Session - distinguishes between **user sessions**
  * Identifies user independently from L2, L3, L4 addresses
  * Originally used to distinguish between multiple users using the same service on a single mainframe
  * Each user could have a unique identifying L5 ID to keep their information going to them only
  * We could see HTTP Cookies as providing a similar function
  * Cookies can preserve a user 'session' even if the user is logging in from different networks (home wifi, coffee shop wifi etc)
  * Allows the network to identify a **user** independently of L2-L4 addresses
* Layer 6 - Presentation - how to interpret bits - data encoding
  * Base64 - 6 bit characters
  * Hexadecimal - 4 bit characters
  * Numbers / Integers - 32 bit or 64 bit
  * HTTP uses ASCII extended encoding - groups bits into 8-bit bytes
* Layer 7 - Application - what do we do with the data?
  * `GET` in HTTP means something - request a webpage
  * `GET`, `POST`, `HEAD`, etc are Application layer commands



* FTP has no session layer, it depends on L2-L4 to identify a session and if we change networks we need to log back in
* FTP also uses extended ASCII to interpret the Presentation of data
* FTP has its own Application commands: `GET`, `PUT`, `PASV` etc



* Since every networking application protocol will implement these three layers differently, and may not implement some of them at all, it makes sense to combine them into a single Application layer



<u>**Bonus Video: HTTP vs HTML: Unveiling Network Protocols using Telnet**</u>



