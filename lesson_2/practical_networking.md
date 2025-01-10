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



**<u>Video 4 - OSI Model: A Practical Perspective - Part 2</u>**