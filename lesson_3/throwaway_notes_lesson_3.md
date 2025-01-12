

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

### <u>**Background**</u>

### Introduction ###

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

**<u>Query Strings/Parameters</u>**

`http://www.example.com?search=ruby&results=10`

`?` - reserved character that marks the start of the query string

`search=ruby` - this is a parameter name/value pair

`&` - this is reserved character used when adding more parameters to the query string

`results=10` - this is also a parameter name/value pair



`?` - Begin Query String

`&` - Query String Separator

Parameter Name

Parameter Value

Name/value pairs are passed to the server from the URL. How the server uses these parameters is up to the server side application.

'Because query strings are passed in through the URL, they are ordinarily only used in `HTTP GET` requests. `POST` requests do allow query strings, but it is relatively uncommon and shouldn't be used with any info you would not want logged somewhere... Just know that whenever you type in a URL into the address bar of your browser, you're issuing `HTTP GET` requests. Most links also issue `HTTP GET` requests, though there are some minor exceptions'

'Query strings are great to pass in additional information to the server, however, there are some limits to the use of query strings:'

* Query strings have a maximum length. Therefore, if you have a lot of data to pass on, you will not be able to do so with query strings
* The name/value pairs used in query strings are visible in the URL. For this reason, passing sensitive information like username or password to the server in this manner is not recommended
* Space and special characters like `&` cannot be used with query strings. They must be URL encoded, which we'll talk about next.

**<u>URL Encoding</u>**

'URLs are designed to accept only certain characters in the standard 128-character ASCII character set. Reserved or unsafe ASCII characters which are not being used for their intended purpose, as well as characters not in this set, have to be encoded.'

'URL encoding serves the purpose of replacing these non-conforming characters with a `%` symbol followed by two hexadecimal digits that represent the equivalent UTF-8 character.'

'It's worth knowing that UTF-8 uses 1-4 bytes to represent every possible character in the Unicode character set.'

Some popular characters:

`%20` - space

`%24` - `$` dollar sign

`%C2%A3` - `£` pound sign

`%E2%82%AC` - `€` Euro sign

`%F0%90%8D%88` - whatever `𐍈` is

Notice here, that each byte corresponds to a `%FF` pattern, since two hexadecimal digits can represent the same amount of information as 8 bits, with each digit representing a nibble of that bit. If we have 4 bytes for a UTF-8 Unicode character, we will need 4 `%` symbols each with 2 hex digits.

'It's helpful to remember that all characters in the ASCII character set as well as those in the extended ASCII character set have single-byte UTF-8 codes.`

Characters **must** be encoded if:

1. They have no corresponding character within the standard ASCII character set. This includes all extended ASCII characters and 2-, 3-, and 4-byte UTF-8 characters.
2. The use of the character is unsafe since it may be misinterpreted or modified by some systems
3. The character is reserved for special use within the URL scheme

The characters that can be safely used in a URL are the alphanumeric characters and the characters in the set `$-_.+!'()"`, and reserved characters when used for their reserved purposes can be used unencoded within a URL.

### Preparation ###

Graphical HTTP tools include:

* RapidAPI - Mac only, although there is now RapidAPI Client, a cross-platform tool
* Insomnia - requires login, steals data etc
* Postman - recently changed to require account login, steals data, users angry

I found additionally:

* Bruno
* httpie.io
* ThunderClient - VS Code extension

Also Postman is available as a VS Code extension

The command-line tool we will use is 

* `curl`



### **<u>HTTP</u>** ###

### Making Requests ###

**<u>HTTP Request with a Browser</u>**

Making an HTTP request is as simple as typing a URL into your browser's address bar. The server that hosts the page you requested handles your request and issues a response back to your browser. The browser processes the response that is sent back and displays the site with all colors, images, text, formatting and presentation.

**<u>HTTP Request with an HTTP Tool</u>**

'Because browsers show us the processed version of the response, we don't get to see the raw response the server sent back. How do we see the raw HTTP response data?'

'For that, we can use an HTTP tool and just like the browser did when we entered a URL in the address bar, we can have our HTTP tool issue a request... Our HTTP tool... doesn't process the response and lets us see the raw response data'.

If you are learning about HTTP to become a web developer, you need to learn to read and process raw HTTP response data just by scanning it. You should have a general idea of what a given response is about. With experience, you can dig into the raw data and do some debugging and see exactly what's in the response.

**<u>Using the Inspector</u>** 

'Every modern web browser has a way to view HTTP requests and responses, and it's usually called the **inspector**.'

Chrome vertical ellipsis menu -> More tools -> Developer tools, then choose the Inspect mode by clicking on the arrow-in-box icon at the top-left of the DevTools panel.

`Ctrl+Shift+I` - simply opens DevTools

right-click and choose 'Inspect' option - this means 'Inspect element', it doesn't put it into Inspect mode, just opens DevTools inspecting that one element

`Ctrl+Shift+C` - opens DevTools in Inspect mode

In fact, I think Chrome Web Inspector must be the old name for DevTools more generally. What they do next doesn't seem to involve inspecting elements in the page but looking at the network tab.

In Firefox, Inspector seems to be specifically a DOM node inspector



* HTTP Request Method - the verb that tells the server what action to perform on a resource
* `GET` - method that retrieves information
* `POST` - method that initiates some action on the server, or sends data to the server

* Status Code - response status for a request. Every request gets a response, even if that response is an error. (This ignores that some requests might **time out**)



**<u>`GET` Requests</u>**

'`GET` requests are initiated by clicking a link or via the address bar of a browser.`

* `GET` requests are used to retrieve a resource, and most links are `GET`s
* The response from a `GET` request can be anything, but if it's HTML and that HTML references other resources, your browser will automatically request those referenced resources. A pure HTTP tool will not.

**<u>`POST` Requests</u>**

'`POST` is used when you want to initiate some action on the server, or send data to a server.'

'Typically, from within a browser, you use `POST` when you are submitting a form.'

''`POST` requests allow us to send much larger and sensitive data to the server, such as images or videos.'

'For example, say we need to send our username and password to the server for authentication. We could use a `GET` request and send it through query strings. The flaw with this approach is obvious: our credentials become exposed instantly in the URL; that isn't what we want. Using a `POST` request in a form fixes this problem. `POST` requests also help sidestep the query string size limitation that you have with `GET` requests. With `POST` requests, we can send significantly larger forms of information to the server.'

'How is the data we're sending being submitted to the server since it's not being sent through the URL? The answer to that is the HTTP **body**. The body contains the data that is being transmitted in an HTTP message and is optional. In other words, an HTTP message can be sent with an empty body. When used, the body can contain HTML, images, audio and so on. You can think of the body as the letter enclosed in an envelope, to be posted.'

'The `POST` request generated by the HTTP tool or `curl` is the same as you filling out the form in the browser, submitting that form, and then being redirected to the next page... The `Location` header [in the response to our `POST` request] is an HTTP **response header**... Your browser sees the `Location` header and automatically issues a brand new request to the specified URL, thereby initiating a new, unrelated request.'

'It's critical to understand that when using a browser, the browser hides a lot of the underlying HTTP request/response cycle from you. Your browser issued the initial `POST` request, got a response with a `Location` header, then issued another request without any action from you, then displayed the response from that second request. Once again, if you were using a pure HTTP tool, you'd see the `Location` response header from the first `POST` request, but the tool would not automatically issue a second request for you. (Some HTTP tools have this ability, if you check the "automatically follow redirects" option).'

`curl` will follow redirects with the `-L` flag before the URL on the command line.



<u>**HTTP Headers**</u>

'HTTP headers allow the client and the server to send additional information during the HTTP request/response cycle.'

'Headers are colon-separated name-value pairs that are sent in plain text.'

**<u>Request Headers</u>**

'Request headers give more information about the client and the resource to be fetched.'

Some useful headers:

* Host - the domain name of the server
* Accept-Language - list of acceptable languages
* User-Agent - a string that identifies the client
* Connection - type of connection the client would prefer

Request headers are part of the request sent to the server.

We have learned

* using the 'Inspector'/DevTools to view HTTP requests
* making GET/POST requests with an HTTP tool (Insomnia, Postman, curl)

The most important concepts to understand:

* HTTP method - GET, POST, etc
* path (the resource name and any query parameters)
* headers
* message Body (for POST requests)



### Processing Responses ###

'The raw data returned by the server is called a **response**'

**<u>Status Code</u>**

The HTTP Status Code. The `status code` is a three-digit number the server sends back after receiving a request signifying the status of the request. The `status text` displayed next to the `status code` tersely describes the meaning of the `status code`, e.g. `200 OK`.

Status Code - Status Text - Meaning

`200` - `OK` - the request was handled successfully

`302` - `Found` - the requested resource has temporarily changed. Usually results in a redirect to another URL

`404` - `Not Found` - the requested resource cannot be found

`500` - `Internal Server Error` - the server has encountered a generic error



**<u>`302 Found`</u>**

When a resource is moved, the most common strategy is to re-route the request from the original URL to a new URL. The general term for this kind of re-routing is `redirect`.

When your browser sees a response code of `302`, it knows that the resource has been moved, and follows the new re-routed URL in the `Location` response header.

**<u>`404 Not Found`</u>**

When responding with a `404` status code, the ""`404` page" is sent as html in the body of the response like a normal webpage. The browser will render this like any other page.

**<u>`500 Internal Server Error`</u>**

A `500` status code means that "there's something wrong on the server side". This is a generic error status code and the core problem can be anything from a mis-configured server setting to a syntax error in the application code. Whatever the problem is, it is a problem on the server side. 'Someone with access to the server will have to debug and fix the problem, which is why sometimes you see a vague error message asking you to contact your System Administrator. In the wild, a `500` error can be shown in a variety of ways, just like a `404` page can.'

**<u>Response Headers</u>**

'Response headers offer more information about the resource being sent back.'

Some common resource headers:

* Content-Encoding - the type of encoding used on the data
* Server - the name of the server
* Location - notify client of new resource location
* Content-Type - the type of data the response contains

'Just understand that response headers contain additional meta-information about the response data being returned.'

'HTTP is nothing more than an agreement in the form of formatted text that dictates how a client and server communicate.'

The most important parts of an HTTP response are:

* status code
* headers
* message body, which contains the raw response data



### Stateful Web Applications ###

'We already know that HTTP is stateless. In other words, the server does not hang on to information between each request/response cycle.'

'Each request made to a resource is treated as a brand new entity, and different requests are not aware of each other. This *statelessness* is what makes HTTP and the Internet so distributed and difficult to control, but it's also the same ephemeral attribute that makes it difficult for web developers to build **stateful** web applications.

'As we look around the internet and use familiar applications, we feel that the application somehow has a certain state. For example, when we log in to Facebook or Twitter, we see our username at the top, signifying our authenticated status. If we click around (which generates new requests to Facebook's servers) we are not suddenly logged out; the server response contains HTML that still shows our username, and the application seems to maintain its state.'

'We'll focus on how this happens by discussing some of the techniques being employed by web developers to simulate a stateful experience.'

' Along the way, we'll also discuss some techniques used on the client to make displaying dynamic content easy' - not entirely sure what this means, come back to it

'The approaches we'll discuss are:'

* Sessions
* Cookies
* Asynchronous JavaScript calls, or AJAX



**<u>A Stateful App</u>**

'How does the server know to remember your username and dynamically display it on the page even after sending a new request? This behavior is so common now that we don't think twice about it... It's how all modern web applications work.'

**<u>Sessions</u>**

'It's obvious the stateless HTTP protocol is somehow being augmented to maintain a sense of statefulness. With some help from the client (i.,e., the browser), HTTP can be made to act as if it were maintaining a stateful connection with the server, even though it's not.'

'One way to accomplish this is by having the server send some form of a unique token to the client. Whenever a client makes a request to that server, the client appends this token as part of the request, allowing the server to identify clients. In web development, we call this unique token that gets passed back and forth the **session identifier**.'

* the **session identifier** is a unique token that the server issues to the client; thereafter, the client appends the session identifier to its requests, allowing the server to identify the client

 'this mechanism of passing a `session id` back and forth between the client and server creates a sense of persistent connection between requests. Web developers leverage this faux statefulness to build sophisticated applications. Each request, however, is technically stateless and unaware of the previous or the next one'

'This sort of faux statefulness has several consequences'

* First, every request must be inspected to see if it contains a session identifier.
* Second, if this request does, in fact, contain a session id, the server must check to ensure that this session id is still valid
  * the server needs to maintain some rules with regards to how to handle session expiration
  * the server needs to store the session data in some determined way
* Third, the server needs to retrieve the session data based on the session id
* Finally, the server needs to recreate the application state (e.g. the HTML for a web request) from the session data and send it back to the client as the response

'This means that the server has to work very hard to simulate a stateful experience, and every request still gets its own response, even if most of that response is identical to the previous response.'

'There are many advanced techniques that servers employ to optimize sessions and, as you can imagine, there are also many security concerns. Most of the advanced session optimization and security concerns are out of scope of this book, but we'll talk about one common way to store session information: in a browser cookie'

**<u>Cookies</u>**

'A cookie is a piece of data that is sent from the server and stored in the client during a request/response cycle. **Cookies**, or **HTTP Cookies**, are small files stored in the browser and contain session information.'

* 'By default, most browsers have cookies enabled.'
* 'When you access any website for the first time, the server sends session information and sets it in your browser cookie on your local computer.'
* 'Note that the actual session data is stored on the server.'
* 'The client side cookie is compared with the server-side session data on each request to identify the current session. This way, when you visit the same website again, your session will be recognized because of the stored cookie with its associated information.'
* Cookies are stored persistently by the client/browser. If you reboot your computer, the cookie data persists.

**The most important thing to understand is that the session id is stored on the client, and it is used as a "key" to the session data stored server side. That's how web applications work around the statelessness of HTTP.**

'To recap, we've seen that the session data is generated and stored on the server-side and the session id is sent to the client in the form of a cookie. We've also looked at how web applications take advantage of this to mimic a stateful experience on the web.'

from LSBot:

'While HTTP cookies are a common and widely used method for storing session identifiers, they are not the only form of session identifier token. Let's explore this topic a bit more.According to the "Introduction to HTTP" book, in the "Stateful Web Applications" chapter, cookies are indeed a prevalent method for maintaining session information:"Cookies or HTTP cookies, are small files stored in the browser and contain the session information. By default, most browsers have cookies enabled."However, it's important to note that there are other methods for maintaining session state and identifying users across multiple requests. While the book doesn't explicitly mention alternatives, in web development, there are a few other approaches that can be used:

1. URL Parameters: Session identifiers can be passed as part of the URL. This method is less common now due to security concerns, but it's still a possibility.
2. Hidden Form Fields: Session information can be stored in hidden form fields and submitted with each request.
3. Local Storage or Session Storage: Modern web browsers provide APIs for storing data on the client-side, which can be used to store session identifiers.
4.  JSON Web Tokens (JWTs): These are becoming increasingly popular, especially in single-page applications and mobile apps.

Remember, the choice of session management technique often depends on the specific requirements and constraints of the application you're building.'

**<u>AJAX</u>**

AJAX is an acronym meaning Asynchronous JavaScript and XML. It allows browsers to issue requests and process responses **without a full page refresh**.

'When AJAX is used, all requests sent from the client are performed *asynchronously*, which just means that the page doesn't refresh.'

Using a Google search as an example:

'Every letter you type [in the search box on the Google homepage] is issuing a new request, which means that an AJAX request is triggered with every key-press. The responses from these requests are being processed by some **callback**. You can think of a **callback** as a piece of logic you pass on to some function to be executed after a certain event has happened. In this case, the callback is triggered when the response is returned. You can probably guess that the callback that's processing these asynchronous requests and responses is updating the HTML with new search results.' [not so much search results as search suggestions]

'The main thing to remember is that AJAX requests are just like normal requests: they are sent to the server with all the normal components of an HTTP request, and the server handles them like any other request. The only difference is that instead of the browser refreshing and processing the response, the response is processed by a callback function, which is usually some client-side JavaScript code.'



### Security ###

* The same attributes that make HTTP so difficult to control, also make it difficult to secure.

According to Google's GenAI, 'stateful protocols are generally considered easier for governments to control compared to stateless protocols because they retain information about a communication session, allowing authorities to monitor and potentially restrict traffic based on that context, providing a more granular level of oversight'

**<u>Secure HTTP (HTTPS)</u>**

* In HTTP, both requests and responses are sent as strings; this leaves them vulnerable to **packet sniffing**, whereby a hacker can read the messages being sent back and forth
* Requests can contain the session id; so if someone intercepted a request, they could use the session id to effectively log in to the server as the client the session id pertains to, without even needing to know a username and password
* Secure HTTP, or HTTPS, aims to forestall such attacks
* A resource that's accessed by HTTPS will have `https://` as its scheme in the URL, and when accessed, it will cause the browser to display a lock icon next to the URL in the address bar
* With HTTPS, every request/response is encrypted before being transported on the network
* HTTPS sends messages through a cryptographic protocol called TLS (misleadingly, Transport Layer Security, though it sits roughly at the Presentation layer of the OSI model)
* Earlier versions of HTTPS used SSL, or Secure Sockets Layer, until TLS was developed
* These cryptographic protocols use certificates to communicate with remote servers and exchange security keys before data encryption happens
* You can inspect certificates by clicking on the padlock icon in the web browser's address bar
* Although modern browsers perform a high level check on  a website's certificate, viewing the certificate can serve as an extra security step before interacting with the site



**<u>Same-origin Policy</u>**

NB: The same-origin policy is a security feature of all web browsers since Netscape Navigator introduced JavaScript in the mid-90s. It was originally intended to safeguard JavaScript's programmatic access to the DOM, but its remit expanded somewhat (including protecting access to the global JavaScript object) - source: wikipedia

* The same-origin policy is permits unrestricted interaction between resources originating from the same origin, but restricts certain interactions between resources originating from different origins
* An origin is the triple {scheme, host, port}; all three must match in order for the origin to be the same
* Same-origin policy doesn't restrict all cross-origin requests. Requests such as linking, redirects, or form submissions to different origins are typically allowed
* Same-origin policy also allows embedding resources from other origins, including scripts, css stylesheets, images and media, fonts, and iframes (inline frames, web pages embedded in web pages)
* What is restricted by same-origin policy are cross-origin requests where resources are being accessed programmatically using APIs such as `XMLHttpRequest` or `fetch`

Although secure, the same-origin policy is a problem for web developers who have a legitimate need for making these restricted kinds of cross-origin requests.

* Cross-origin Resource Sharing, or **CORS**, was developed to deal with issues arising from the Same-origin policy
* CORS is a mechanism that allows cross-origin interactions that would normally be restricted to take place
* CORS works by adding new HTTP headers that allow servers to serve resources cross-origin to certain specified origins
* When the client receives some JavaScript from a server, and that JS subsequently asks for a resource in a cross-origin server, then the web browser sends an `Origin:` header to the cross-origin server when it requests the resource; if the cross-origin server is configured to allow this cross-origin request from that specific origin, then it must include the appropriate `Access-Control-Allow-Origin:` header in its response. If the header is present and grants access, then the web browser will accept the response and process it -- if the header is omitted or denies access, the browser won't accept and process the response.

The same-origin policy is an important guard against **session hijacking** attacks and serves as a cornerstone of web application security.



NB: from wikipedia again: the SOP (same-origin policy) "prevents a malicious script on one page from obtaining access to sensitive data on another web page through that page's Document Object Model (DOM). This mechanism bears a particular significance for modern web applications that extensively depend on HTTPS cookies to maintain authenticated user sessions, as servers act based on the HTTP cookie information to reveal sensitive information or take state-changing actions. **A strict separation between content provided by unrelated sites must be maintained on the client-side to prevent the loss of data confidentiality or integrity**... **The same-origin policy applies only to scripts. This means that resources such as images, CSS, and dynamically loaded scripts can be accessed across origins via the corresponding HTML tags**"

**<u>Session Hijacking</u>**

'A session id serves as that unique token used to identify each session.'

NB: In technical terminology, 'Session' and 'Token' -based Authentication are different techniques. Session-based Authentication uses cookies, and is what is being described here

A session id is a unique token issued by a sever. The client logs in with their username and password, usually sent as a `POST` request to the server. The session id is usually implemented as a randomized string and is delivered by the server in the form of a cookie in the `Set-Cookie` header of the response. The client stores this cookie. Thereafter, when the client makes a request, the cookie is sent to the server in the `Cookie` header, authenticating that the client is a specific client. The server can then use the cookie to find the client/user's data in its database.

If an attacker gets hold of the session id, both the attacker and the user now share the same session and both can access the web application. In session hijacking, the user won't even know that the attacker has their session id, and the attacker can access the user's information without even needing their username or password.

**<u>Counter-measures for Session Hijacking</u>**

* Resetting sessions. The authentication system is set up such that a successful login request, where the user enters name and password and submits a form, renders the old session id invalid and creates a new one. With this system in place, on the next request that is deemed sensitive, the application will require a new login; if it is the victim that has made the request, they simply log in again, a new session id is issued, and the attacker can no longer access their session. Many websites implement this technique, and ensure that users re-authenticate whenever sensitive data is involved, such as charging a credit card or deleting the account.

* Expiration time on sessions. Sessions that don't expire give the attacker an infinite time period to pose as the user. If a session expires after 30 minutes, the attacker has a far narrower window to access the app as the user.
* HTTPS across the entire app. HTTPS minimizes the chance that an attacker can get the session id

 

**<u>Cross-Site Scripting (XSS)</u>**

* Cross-site scripting, or XSS, is a type of attack that happens when you allow users to input text that ends up being displayed by the site and do not sanitize the input text for HTML and JavaScript code.
* If the server side doesn't do any sanitization of the input, the user input will be injected into the page contexts, and then client-side the browser will *interprest the HTML and JavaScript and execute it*.
* Attackers can craft ingeniously malicious HTML and JavaScript and be very destructive to both the server as well as future visitors of the page
* An attacker can use JavaScript to grab the session id of every future visitor of the site
* The malicious code will bypass the same-origin policy because the code lives on the site

**<u>Potential solutions for cross-site scripting</u>**

* Always sanitize user input. This can mean eliminating problem HTML tags such as `<script>`, or by disallowing HTML and JavaScript input text altogether.
* Escape all input text when displaying it. This can mean converting all special characters to HTML entities, which tells the client to display those characters rather than process them



## 3:5 Some Background and Diagrams ##

**<u>Client-Server</u>**

To simplify server-side infrastructure, there are three primary components to be aware of:

* **Web Server** - a web server is typically a server that responds to requests for static assets: files, images, css, javascript, etc. These requests don't require any data processing, so they can be handled by a simple web server
* **Application Server** - an application server is typically where application or business logic resides, and is where more complicated requests are handled. This is where your server-side code lives when deployed
* **Data Store** - the application server will often consult a persistent *data store*, like a relational database, to retrieve or create data. Data stores can also be simple files, key/value stores, document stores, and many other variations, as long as it can save data in some format for later retrieval and processing. Regardless of how the persistent data store is implemented, it can be used to *persist* our data between stateless request/response cycles. That is, the data doesn't go away after each cycle, but persists inside the data store

**<u>HTTP over TCP/IP</u>**

HTTP is relying (most of the time) on a TCP/IP connection. HTTP operates at the application layer and is concerned with structuring the messages that are exchanged between applications; TCP/IP ensures that the request/response cycle gets completed between your browser and the server.



## 3:6 URLs ##

'For ease of communication ... it's probably best to just stick with URL ... as far as we're concerned in HTTP, everything is a URL, but some sources may talk about URIs.'

video:

Uniform - relates to a network based resource and provides some standard or uniform way to reference the presence, name and discrete location of that resource

Uniformity is very import, for instance, when designing an Application Programming Interface for a web application. [APIs are very important in building web applications because of the massively distributed and diverse systems involved in web infrastructure]

Uniform Resource Identifier - most generic term, can be a URN or a URL

Uniform Resource Name

Uniform Resource Locator

