# Lesson 6: The Evolution of Network Technologies #

## 6:2 What to Focus On ##

* **Be aware of how and *why* HTTP is evolving** - an awareness of the history of HTTP, and the changes it has undergone over time, can provide us with more insight into the work-arounds used to deal with some of its limitations
* **Be aware of the functionality that browser APIs can provide** - modern browsers provide numerous APIs that provide functionality which HTTP alone cannot
* **Be aware that Client-Server isn't the only *network paradigm*** - being aware that other network paradigms exist can be useful when making high-level design decisions about networked applications



## 6:3 HTTP: Past, Present, and Future

**<u>HTTP/0.9</u>**

* Released in 1991, the original version that only has a version number retrospectively
* Sometimes referred to as the 'one line protocol' because there were no request headers or body
* Only method was `GET`
* Path referenced a path on the server rather than a complete URI/URL, since connection would already have been established via some other means such as Telnet
* A response was simply a single hypertext document with no headers or other meta-data (even status codes)
* The end of the response was signaled by the server closing the connection
* Berners-Lee also created the WorldWideWeb browser, also known as Nexus. This only worked on the NeXT computer system
* Nicola Pellow, an intern at CERN, was recruited to write the Line Mode Browser, which was operated via command-line and displayed responses in the terminal. The Line Mode Browser was cross-platform

**<u>HTTP/1.0</u>**

Between 1991 and 1996 a number of developments contributed toward mass adoption of the internet and the web:

* The NCSA built on Nexus and Line Mode Browser to produce NCSA Mosaic, which paved the way for the first commercial browser: Netscape Navigator 1.0
* Telecommunications companies started providing Internet access via dial-up connections
* The World Wide Web Consortium (W3C) and the HTTP Working Group (HTTP-WG) were formed. The existence of these organizations provided a framework for the documentation and standardization of web technologies, as well as a structured approach to their continued development
* A number of improvements to HTTP, which expanded the capabilities of HTTP/0.9. Many of these improvements were ad-hoc and experimental. In May 1996, HTTP/1.0 was published as an informational RFC, RFC1945, as an attempt to document the growing set of practices and usage patterns. This document was not an official standard.

The developments documented by RFC1945 included the introduction of HTTP headers, the new methods `HEAD` and `POST`, and the status line in responses.

<u>**HTTP/1.1**</u>

* Initially release as RFC2068 in 1997, and then updated as RFC2616 in 1999, HTTP/1.1 was the first standard version of HTTP.
* HTTP/1.1 sought to resolve various ambiguities and interoperability issues in the previous version, as well as providing much needed performance improvements to better serve the type of content that was now being produced for the web
* HTTP/1.1 provided connection re-use. Previously, each request and response cycle required opening and closing a new TCP connection. This was hugely sub-optimal in terms of performance
* Connection re-use made pipelining possible
* HTTP/1.1 also introduced cache-control mechanisms
* HTTP/1.1 introduced more HTTP Methods: `PUT`, `DELETE`, `TRACE`, and `OPTIONS`

**<u>HTTP/2</u>**

* HTTP/2 was standardized in 2015
* Although HTTP/1.1 had solved many problems of earlier versions, it started to have drawbacks when supporting modern web applications of ever increasing complexity and interactivity
* Techniques such as AJAX meant that dozens of HTTP requests might be necessary to render a single page and provide the functionality necessary
* Although HTTP/1.1 pipelining allows multiple requests to be sent at once, there are limitations to the efficiencies that this can achieve. The main drawback is that the server must respond to the requests in the order they are sent. A request that takes a long time to process can delay subsequent requests: a Head-of-Line blocking situation.
* HTTP/2 aims to resolve this by providing multiplexing instead of pipelining. Multiple requests can be sent in parallel without dependence on message order
* HTTP/2 provides other new features such as the compression of headers

**<u>HTTP/3</u>**

* HTTP/3 uses the QUIC protocol to provide the reliability and security features traditionally provided by a combination of TCP and TLS



So

* HTTP/1.0 - RFC1945 (not a standard) https://tools.ietf.org/html/RFC1945
* HTTP/1.1 first standard - RFC2068  https://www.ietf.org/rfc/rfc2068.txt
* HTTP/1.1 update - RFC2616 https://www.ietf.org/rfc/rfc2616.txt
* HTTP/2.0 - RFC7540 https://datatracker.ietf.org/doc/html/rfc7540 (since updated)
* HTTP/3.0 - RFC9114 https://datatracker.ietf.org/doc/html/rfc9114
* Extensible Prioritization Scheme for HTTP - RFC 9218 - covers both and HTTP/3 priority scheme, original HTTP/2 priority trees being deemed too complex



**<u>HTTP/3 Explained book</u>**

* Although HTTP/2 solves HTTP HOL blocking by using multiplexing instead of pipelining, TCP still uses pipelining, and blocking can still be a problem
* When network conditions are *very* poor, HTTP/1.1 using several TCP sockets can actually be faster than a multiplexed HTTP/2 connection over a single TCP socket
* HTTP/3 uses QUIC rather than TCP, and can send multiplexed *streams* (sometimes called *substreams*) at the transport layer, meaning that if there are retransmissions needed on one stream, the other streams will not be blocked
* We might wish a new Transport layer protocol to exist alongside TCP and UDP
* In fact, SCTP exists in theory and has several of the desirable characteristics, but the practicalities of deploying a new Transport protocol on the Internet make this prohibitive
* Existing Internet infrastructure middleboxes (NAT boxes, routers, firewalls, load balancers) often permit only TCP or UDP and are deployed in abundance between users and the servers they need to reach
* Introducing a new protocol would mean a large number of these Internet nodes would drop packets that they could not identify as encapsulating TCP segments or UDP datagrams, and even if changes could be made at the software/firmware/device levels, the intervening percentage of dropped packets is considered prohibitively high
* Furthermore, operating system kernels would need to be updated to deal with the new transport layer protocol. This would also be a slow and expensive process
* Many TCP improvements standardized by the IETF are not widely deployed or used because they are not broadly supported by existing devices and systems
* SCTP is a reliable transport layer protocol with streams, and for WebRTC there are even existing implementations using it over UDP. This was considered not good enough compared to QUIC for several reasons, including:
  * SCTP does not fix the head-of-line blocking problem for streams (the implementation of streams used by SCTP was intended to solve HOL blocking but does not)
  * SCTP requires the number of streams to be decided at connection setup
  * SCTP does not have a solid TLS/security story
  * SCTP has a 4-way handshake, QUIC offers 0-RTT
  * QUIC is a bytestream like TCP, SCTP is message-based
  * QUIC connections can migrate between IP addresses but SCTP cannot

Ossification:

* Middle-boxes are the heterogeneous devices that exist across the internet between the two end-points that are the primary parties in a traditional network data transfer
* Middle-boxes route IP packets between networks, they block malicious traffic, they do Network Address Translation, they improve performance, some try to spy on traffic, and so on
* In order to perform their duties these boxes must know about networking and the protocols that are monitored or modified by them. The software they run for this purpose is not always updated frequently
* While they are glue components that keep the Internet together they are also often not keeping up with the latest technology
* The middle of the network typically does not move as fast as the edges -- the clients and servers of the world
*  These middle-boxes were often deployed some time ago, when certain network protocols had a specific feature set. Introducing new features or changes in behavior that were not previously a part of these protocols can cause aging middle-boxes to interpret packets exhibiting the protocol changes as corrupt or malicious. Such traffic may well just be dropped or delayed to the degree that users really do not want to use those features
* This is called **Protocol Ossification**
* For instance, some boxes between a client and a server will spot unknown new TCP options and block such connections since they do not know what the new options are
* If allowed to detect protocol details, systems learn how protocols typically behave and over time it becomes impossible to change them
* An effective way to combat ossification is to encrypt as much of the communication as possible in order to prevent middle-boxes from seeing much of the protocol passing through



Secure:

* QUIC is always secure. There is no clear-text version of the protocol so to negotiate a QUIC connection always means cryptography and security with TLS 1.3.
* This prevents ossification as well as other sorts of blocks and special treatments, as well as making sure QUIC has all the secure properties of HTTPS that web users have come to expect and want
* There are only a few initial handshake packets that are sent in the clear before the encryption protocols have been negotiated



Reduced latency:

* QUIC offers both 0-RTT and 1-RTT handshakes that reduce the time it takes to negotiate and setup a new connection. Contrast to the 3-way handshake of TCP
* In addition, QUIC offers "early data" support from the get-go which allows more data and it is used more easily than TCP Fast Open
* With the stream concept, another logical connection to the same host can be done at once without having to wait for the existing one to end first
* TCP Fast Open (RFC 7413) was published in December 2014 and that spec describes how applications can pass data to the server to be delivered in the first TCP SYN packet
* Actual support for this has been fraught with problems. Several networks have been identified to interfere with TFO traffic and they have thus actively ruined such TCP handshakes

Process:

* The initial QUIC protocol was designed by Jim Roskind at Google and originally implemented in 2012
* Back then, QUIC stood for "Quick UDP Internet Connections" but that has been dropped
* Google subsequently deployed QUIC implementations in their browser and in their server-side services (gmail, Google search, youtube, etc)
* The first internet draft for QUIC was sent for standardization to the IETF in 2015
* In 2016, a QUIC working group was approved and began work on the standard
* The Google version of the protocol was quickly adopted before standardization, and in 2017 Google claimed that 7% of all internet traffic was using Google QUIC

IETF:

* The QUIC working group whose task was to standardize QUIC within the IETF quickly decided that QUIC should be able to transport more than HTTP.
* Google-HTTP only ever transported HTTP/2 frames using the HTTP/2 frame syntax
* IETF-QUIC based its encryption and security on TLS 1.3 instead of the "custom" approach used by Google-QUIC
* In order to satisfy the demand that QUIC transport more than HTTP, the architecture was split into two separate layers: the transport QUIC and the "HTTP over QUIC" layer, the latter of which was renamed HTTP/3 in November 2018
* This layer split has caused IETF-QUIC to differ significantly from Google-QUIC
* The working group prioritized standardization of HTTP over QUIC, leaving non-HTTP transports to later work
* The IETF-QUIC protocol was standardized and publish in May 2021 as RFC 9000
* Google has slowly incorporated details of the IETF standard into its version and now claims to be using IETF-QUIC
* Most new implementations under development have decided to focus on IETF-QUIC and are not compatible with the Google version

HTTP/2 Experience:

* The HTTP/2 spec RFC 7540 was published in May 2015, just a month before QUIC was brought to the IETF
* HTTP/2 laid the foundation for changing HTTP over the wire and the HTTP/2 working group was of the mindset that the new standard allowed iterating new version of HTTP much faster than previously
* With HTTP/2 users and software stacks got used to the idea that HTTP could no longer be assumed to be a done with a text-based protocol in a serial manner
* HTTP/3 builds upon HTTP/2 and follows many of the same concepts, but some specifics are moved from the HTTP layer to QUIC



UDP:

* QUIC is a transfer protocol implemented on top of UDP
* Based on UDP, QUIC uses UDP port numbers to identify specific network services on a given IP address
* All known QUIC implementations are currently in user-space, which allows for more rapid evolution than kernel-space implementations typically allow
* There are enterprises and other network setups that block UDP traffic on other ports than 53 (used for DNS)
* Others throttle such data in ways that makes QUIC slower than TCP based protocols. There is no limit to what some operators may do
* For the forseeable future, all use of QUIC-based transports will probably have to be able to gracefully fall back to another TCP-based alternative
* While UDP is not a reliable transport, UDP adds a layer on top of UDP that introduces reliability. It offers re-transmission of packets, congestion control, pacing and the other features otherwise present in TCP



Streams:

* Similar to SCTP, SSH, and HTTP/2, QUIC features separate logical streams within the physical connections. A number of parallel streams that can transfer data simultaneously over a single connection without affecting the other streams.
* A connection is a negotiated setup between two end-points similar to how a TCP connection works
* A QUIC connection is made to a UDP port and IP address, but once established the connection is associated by its "connection ID"
* Over an established connection, either side can create streams and send data to the other end. Streams are delivered in-order and they are reliable, but different streams may be delivered out-of-order
* QUIC offers flow control on both connection and streams
* QUIC guarantees in-order delivery of streams, but not between streams. This means that each stream will send data and maintain its data order, but the streams themselves may reach the destination in a different order than the application sent them.
* In QUIC, a lost packet only affects the stream to which the lost packet belongs

Fast handshakes:

* QUIC offers both 0-rtt and 1-rtt connection setups, meaning that in the best case, QUIC needs no extra round-trips at all when setting up a new connection
* The 0-RTT handshake only occurs if there has been a previous connection established to a host and a secret from that connection has been cached
* QUIC allows a client to include data already in the 0-RTT handshake. The server can then include data earlier in its responses
* QUIC uses TLS 1.3 (RFC 8446) as transport security and there are never unencrypted QUIC connections
* TLS 1.3 has several advantages over earlier versions, but the primary advantage is that 1.3 changed the handshake to require fewer roundtrips,  reducing protocol latency

Transport and application:

* The IETF QUIC protocol is a transport protocol, on top of which other application protocols can be used
* The initial application layer protocol is HTTP/3 (h3)
* The transport layer supports connections and streams
* The legacy Google version of QUIC glued transport and HTTP together as a special-purpose send-http/2-frames-over-udp protocol

HTTP/3 over QUIC:

* The HTTP layer, HTTP/3, does HTTP-style transports, including HTTP header compression using QPACK - similar to the HTTP/2 compression named HPACK
* The HPACK algorithm depends on ordered delivery of the streams themselves, so it was not possible to reuse it for HTTP/3 without modification since QUIC offers streams that can be delivered out of order. QPACK can be seen as the QUIC-adapted version of HPACK



## 6:4 Web Performance and HTTP Optimizations ##

**<u>Browser Optimizations</u>**

There are many browser optimizations and they vary from browser to browser, but there are two major types of browser optimization:

* Document-Aware Optimizations -- these occur when the browser can identify and prioritize fetching resources. The goal is to more efficiently load a page by prioritizing certain resources (e.g. CSS layouts and JS scripts)
* Speculative Optimizations -- these occur when the browser learns the usage patterns of the user over time and attempts to predict user actions.



**<u>Latency as the main limiter</u>**

'Since we can't eliminate latency, as developers we need to do whatever we can to mitigate its impact. We can do all kinds of optimizations ranging from eliminating unnecessary roundtrips, minimizing resources to be fetched, adding components to our system, and many more'.

**<u>Further Optimizations</u>**

* Do you need all of those resources? -- since every image, video, stylesheet, and script, can add to our total number of requests, TCP connections, and latency overhead, one of the most effective things we can do is limit the number of resources that need to be fetched.

* Compression techniques --rather than reducing the number of resources to be fetched, compression reduces the size of those resources, meaning less data and more efficient data transfer.  As well as `gzip` and other compression algorithms, there is the technique of **minification**: removing redundant whitespace, comments, formatting etc from text assets before they are sent to the user. There are utilities which minify files in this way.

* Minification: the process of removing unnecessary or redundant data without affecting how the resource is processed by the browser. Mostly applies to HTML, CSS, and JS files.
* Some minification tools: `HTMLMinifier`, `CSSNano`, `csso`, `UglifyJS`, `Closure Compiler`, or the `PageSpeed Module` for Apache or Nginx.

* Reusing TCP Connections -- we can reduce TCP handshake roundtrip latency by reusing a TCP connection to fetch multiple resources. Such connections are usually referred to as **keepalive connections**
* Keepalive connections are standard behavior in HTTP/1.1 and so all modern browsers will attempt to reuse a TCP connection automatically as long as the server cooperates.
* To make sure that you're leveraging keepalive connections, you need to check your app and server configs to ensure they support keepalive connections
* If you are stuck with HTTP/1.0, you can enable keepalive connections by adding the `Connection: Keep-Alive` header to your HTTP requests/responses
* Pay attention to any HTTP libraries and frameworks to make sure they either have keepalive connections as default, or let you enable them

**<u>DNS Optimizations</u>**

* We can limit use of external resource references to only those situations where looking up a new domain name is absolutely necessary
* Another approach is to download and self-host resources instead of linking to them externally. However, if the external resource is provided by a CDN (Content Delivery Network), the fact that the CDN hosts the content near the user's edge can provide a performance gain in latency which outweighs the savings in DNS lookup. Also, if the external host is a popular site, the DNS mapping may already be cached in the user's browser
* Some DNS providers are faster than others

**<u>Caching</u>**

* Server-side caching is useful, especially for dynamically-generated web pages
* A cache is a separate component from the web server or application server and stores recently accessed/generated content
* If a generated page is cached, then the next time the user visits, the same page can be served from the cache instead of needing to be generated anew by the application server
* This reduces generation time and frees up the application server to process fewer requests
* Adding a cache is not a trivial solution

## 6:5 Browser Networking APIs ##

* One area HTTP with its request-response cycle falls down on is **real-time data synchronization**
* Example feature: someone on facebook likes your post and shortly after a notification appears to tell you this. This has happened as a result of something on the server, not the client. Yet with HTTP, the client must request something in order for the server to send information to the client.
* Modern browsers provide several APIs that can be leveraged to provide this kind of feature

**<u>XHR</u>**

* XHR stands for XMLHttpRequest -- XML is a markup language that defines a set of rules for encoding documents, but XHR can also use JSON, HTML, or plain text
* XHR enables clients to manage requests and responses programmatically and asynchronously
* Asynchronous JavaScript permits a web app to perform other actions while waiting for an update from the server
* Asynchronous JavaScript differs from synchronous JavaScript in which the web app has to pause and wait for the server's update before allowing any other actions to be taken
* XHR is a key component of Aynchronous JavaScript and XML (AJAX). AJAX is now a fundamental building block of nearly every modern web app
* In the early days of the web, nearly every clicked link or button cause the browser to send a new request to the server. When the server responded, the browser almost always had to completely draw a new page, even if it was the same unchanged page. This was frustratingly slow
* The advent of XHR (early-to-mid 2000s) meant that web pages could send a request to the server and then use the response to alter just a small part of the page in the browser. This made the Web fast and interactive
* With AJAX, we can write some JavaScript to respond to a user action, such as clicking on a link or part of a page, and, in response, we can fetch some data from the server and update part of the page through DOM manipulation
* As well as being used as part of AJAX, XHR can provide the sort of real-time notification functionality described earlier
* Since we can manage requests and responses asynchronously and programmatically, we can write a script that runs in the background of our application and issues a request to the server periodically (say, every 60 seconds) to check for updates
* This kind of implementation is referred to as **polling**
* Since ordinary polling can lead to a lot of unnecessary checks where there is nothing to update, there is a more efficient version called **long-polling**. With long-polling, the client makes a request, but rather than returning an empty or negative response, the server keeps the connection idle until an update is available and *then* issues a response
* XHR is popular for "real-time" delivery of data updates via the use of polling or long-polling, but it may not be the most performant solution when compared to the SSE and WebSocket APIs
* XHR is optimized for communicating with HTTP requests and responses, but doesn't support one side streaming messages to the other

**<u>SSE</u>**









