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
* This was the result of what is now called the ARPANET (Advanced Research Projects Agency Network), the first packet-switched computer network that was first used in 1969 and decommissioned in 1989. ARPANET's main use was for academic and research purposes. ARPANET was a US Defense Department research project. Paul Baran was trying to build a communications system that would survive a nuclear attack. For this, he hit on the idea of the idea of a decentralized network which would employ his novel idea of packet-switching. (Packet-switching was also invented independently by Welsh computer scientist Donald Davies.) ARPANET was a successful experiment in building such a network (another was the French CYCLADES network).

* The Internet is a network of networks

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



* We can connect one computer to another with a cable. This is the simplest network.
* A LAN generally consists of a hub or switch that connects an office or a house full of computers and other devices.
* Individual LANs are connected to one another with a router, or system of routers. A router will act as a gateway to an individual network, both to send and receive data from other networks.

