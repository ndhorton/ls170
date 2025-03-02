## The Internet

- Have a broad understanding of what the internet is and how it works
- Understand the characteristics of the physical network, such as latency and bandwidth
- Have a basic understanding of how lower level protocols operate
- Know what an IP address is and what a port number is
- Have an understanding of how DNS works
- Understand the client-server model of web interactions, and the role of HTTP as a protocol within that model

## TCP & UDP

- Have a clear understanding of the TCP and UDP protocols, their similarities and differences
- Have a broad understanding of the three-way handshake and its purpose
- Have a broad understanding of flow control and congestion avoidance

## URLs

- Be able to identify the components of a URL, including query strings
- Be able to construct a valid URL
- Have an understanding of what URL encoding is and when it might be used

## HTTP and the Request/Response Cycle

- Be able to explain what HTTP requests and responses are, and identify the components of each
- Be able to describe the HTTP request/response cycle
- Be able to explain what status codes are, and provide examples of different status code types
- Understand what is meant by 'state' in the context of the web, and  be able to explain some techniques that are used to simulate state
- Explain the difference between `GET` and `POST`, and know when to choose each
- Have a basic understanding of the asynchronous nature of AJAX, and the kinds of features that it enables for web apps.

## Security

- Have an understanding of various security risks that can affect  HTTP, and be able to outline measures that can be used to mitigate  against these risks
- Be aware of the different services that TLS can provide, and have a broad understanding of each of those services

---

# Notes #

Things that immediately jump out to review:

* latency - elements of latency, references to this are scattered through the second half in relation to things like HOL blocking, evolution of network technology, etc
* TCP vs UDP similarities and differences
* understanding of how DNS works - not much detail on this as I can remember
* URL encoding
* components of HTTP requests and HTTP responses
* status codes
* Understand 'state' in the context of the web and be able to explain some techniques that are used to simulate state
* Explain differences between `GET` and `POST` and know when to choose each
* Basic understanding of the asynchronous nature of AJAX, and the kinds of features that it enables for web apps
* Security risks of HTTP and measures to mitigate against them
* TLS services (encryption, authentication, integrity)

* DNS - this is discussed in the HTTP book in the `Background` page. `6:4 Web Performance and HTTP Optimizations` has a section on DNS optimizations. `6:6 Peer to Peer Networking` mentions DNS in passing because peers do not have a fixed IP address which a DNS hostname can map to. The suggestion being that DNS maps to fixed, stable addresses, not to the transitory IP addresses of peers in a typical P2P network. So DNS is related to the server-based model of networking.

* How the internet works -- in the HTTP book, Background page

'The Internet consists of millions of interconnected networks that allow all sorts of computers and devices to communicate with each other. By convention, all devices that participate in a network are provided unique labels. The general term for this type of label is an IP Address (Internet Protocol Address). An IP address is like a computer's phone number on the Internet. Port numbers add more detail about how to communicate (think of company phone extensions). IP Addresses are represented as: `192.168.0.1`. When a port number is needed the address is specified as `192.168.0.1:1234` where the IP Adress is `192.168.0.1` and the port number is `1234`. An IP Address acts as the identifier for a device or server, which can contain hundreds or thousands of ports, each used for a different communication purpose to that device or server.

When it comes to the wider Internet, effective communication begins when each device has a public IP address provided by an Internet Service Provider. However, when we wish to connect to a resource like Google, we type in a URL, not an IP address. How does the computer map `www.google.com` to the appropriate IP address?' - goes on to talk about DNS under a new heading.

So this section follows on from A Brief Overview and History, which begins with the web browser and typing in a URL. Client-Server nature of HTTP. Webpages consist of HTML, CSS, JS, and media resources of various kinds. HTTP is introduced, brief history.

'This chapter covered an oversimplified interpretation of how the Internet works along with an explanation of a few key terms'

So it covered

* Web browser - client
* HTTP and history of HTTP
* Network of networks - one sentence stand-in for Physical and Link layers - What the Internet IS
* IP addresses
* TCP ports
* DNS (only description of this in LS170)
* Client and server (web server)
* Resources

Also mentions Statelessness but excludes this from 'how the internet works' topics

So the Internet here really means the internet connection between networks. Ethernet and physical medium are both taken for granted (although even out on the internet's routers, each hop still requires a new L2 header etc and obviously physical connections between routers)



So we essentially have two questions:

* What is the Internet - a network of networks that consists of both the network infrastructure (physical devices, wires, radio transmitters, etc) and the protocols that govern and facilitate internetwork communication (Ethernet, IP, TCP, etc)
* How does the internet work? - use HTTP as application layer example. Follow the request down through the layers including a DNS lookup. Then follow its deencapsulation at the other end.

For the second point, LSBot does recommend the Background page of the HTTP book:

'This broad understanding [of how the internet works] would typically encompass:

1. The client-server model of web interactions
2. The role of HTTP as a protocol within that model
3. Understanding of IP addresses and port numbers
4. The function of DNS in translating domain names to IP addresses
5. The journey of data through various network layers (as you mentioned with encapsulation)
6. The physical structure of the internet (LANs, WANs, routers, etc.)'

' It's also worth noting that the study guide mentions having "a basic understanding of how lower level protocols operate," which aligns with your mention of the encapsulation layers and network stack.'



So we have

* The client-server model of web interactions
* The role of HTTP as a protocol within that model
* Understanding of IP addresses and port numbers (TCP and IP)
* The function of DNS in translating domain names to IP addresses
* The journey of data through various network layers (including encapsulation)
* Lower level protocols
* The physical infrastructure of the Internet
