# HTTP and the Request/Response Cycle

* Be able to explain what HTTP requests and responses are, and identify the components of each
* Be able to describe the HTTP request/response cycle
* Be able to explain what status codes are, and provide examples of different status code types
* Understand what is meant by 'state' in the context of the web, and be able to explain some techniques that are used to simulate state
* Explain the difference between `GET` and `POST`, and know when to choose each
* Have a basic understanding of the asynchronous nature of AJAX, and the kinds of features that it enables for web apps



## Be able to explain what HTTP requests and responses are, and identify the components of each

<u>**3:4 HTTP Book: Making Requests**</u>

**HTTP Headers**

* HTTP headers allow the client and the server to send additional information during the HTTP requst/response cycle
* Headers are colon-separated name-value pairs that are sent in plain text (at least before HTTP/2, and ignoring HTTPS TLS encryption)
  * `name:value`

**Request Headers**

* Request headers give more information about the client and the resource to be fetched
* Some useful request headers are:
  * `Host:` -- the domain name of the server
  * `Accept-Language:` -- list of acceptable (natural) languages
  * `User-Agent:` -- a string that identifies the client
  * `Connection:` -- type of connection the client would prefer

* The most important components to understand about an HTTP request are
  * HTTP method
  * path (the resource name and any query parameters) [this is more expansive than the use of the word 'path' in URL components]
  * headers
  * message body (for `POST` requests)



**<u>3:4 HTTP Book: Processing Responses</u>**

**Status Code**

* The **status code** is a three-digit number that the server sends back after receiving a request signifying the status of the request
* The **status text** displayed next to the status code provides the description of the status code
* Some useful status codes to know are:
  * `200 OK` -- the request was handled successfully
  * `302 Found` -- the requested resource has changed temporarily. Usually results in a redirect to another URL
  * `404 Not Found` -- the requested resource cannot be found
  * `500 Internal Server Error` -- the server has encountered a generic error

**302 Found**

* When a resource is moved, the most common strategy is to re-route a request from the original URL to the new URL
* The general term for this kind of re-routing is **redirect**
* When a web browser sees a response code of `302`, it knows that the resource has been moved, and will automatically send a new request to the new re-routed URL, which is given in the `Location` header of the `302` response

**404 Not Found**

* 





## Be able to describe the HTTP request/response cycle

3:4 **<u>HTTP Book: Processing Responses</u>**

* HTTP is nothing more than an agreement in the form of formatted text that dictates how a client and server communicate





## Be able to explain what status codes are, and provide examples of different status code types





## Understand what is meant by 'state' in the context of the web, and be able to explain some techniques that are used to simulate state

3:4 **<u>HTTP Book: Background</u>**

**<u>Statelessness</u>**

* A protocol is said to be **stateless** when it's designed in such a way that each request/reponse pair is completely independent of the previous one
* HTTP is a stateless protocol
* HTTP's stateless means the server does not need to hang on to information, or state, between requests
* As a consequence of HTTP's statelessness, when a request breaks en route to the server, no part of the system has to do any cleanup
* HTTP's statelessness makes the web resilient

  * When a request breaks or fails, the server does not need to perform any cleanup or maintain information about the broken connection; failures are isolated and don't cascade through the system
  * Servers don't need to maintain complex state tracking between requests, which simplifies server design and reduces memory requirements
  * If a server fails, requests can simply be redirected to another server, promoting fault tolerance
* HTTP's statelessness facilitates the distributed nature of the web

  * Requests can be routed to any server in a cluster without needing to synchronize session state between them
* HTTP's statelessness makes the web harder to control

  * Third-party enforcement of content restrictions or rate limiting are harder when there's no inherent relationship between requests
* Since HTTP is stateless, web developers have to work hard to simulate a stateful experience in web applications
  * For instance, on a social media website, developers need to 'simulate' statefulness so that we remain 'logged in' somehow
  * Otherwise, after validating our credentials, we would be immediately logged out again every time we clicked on a link on the page, since HTTP itself treats each request/response as independent of every other
  * There are various techniques for achieving this 'simulation' of statefulness, or building a stateful experience on top of a stateless communication protocol





## Explain the difference between `GET` and `POST`, and know when to choose each

3:4 **<u>HTTP Book: What is a URL?</u>**

* Because query strings are passed in through the URL, they are ordinarily only used in HTTP GET requests
  * POST requests do allow query strings, but it is relatively uncommon and shouldn't be used with any info you would not want logged somewhere
* Whenever you enter a URL into your browser's address bar, your browser is issuing a GET request
* Most hyperlinks also issue GET requests, although there are minor exceptions

<u>**3:4 HTTP Book: Making Requests**</u>

* HTTP Request Method -- the verb that tells the server what action to perform on a resource
  * `GET` and `POST` are the two most common
  * `GET` retrieves information from the server, the most common method
* Every HTTP Request gets a Response even if the Response is an error (although technically a request can also time out)

**GET Requests**

* `GET` Requests are initiated by clicking a link or via the address bar of a browser
  * When you type a URL into your browser's address bar, you are making a `GET` request
  * You are telling the browser to go retrieve the resource at that address
  * The same is true of clicking a link (most of the time)
* `GET` requests are used to retrieve a resource
* Most links are `GET`s
* The response from a `GET` request can be anything, but if it's HTML and that HTML references other resources, your browser will automatically request those referenced resources. A pure HTTP tool will not

**POST Requests**

* `POST` is used when you want to initiate some action on the server, or send or submit data to the server
* Typically from within a browser, you use `POST` when submitting a form
* `POST` requests allow us to send much higher volume and/or sensitive data to the server, such as images or videos, or username and password
* Sending information through query strings exposes that information in the URL
  * For sensitive data, using a `POST` request in a form fixes this problem
  * `POST` requests allow us to send a much greater volume of data than query strings, which are very limited in maximum size
* `POST` requests send information to the server in the request body
  * The body contains the data begin transmitted in an HTTP message and is optional
  * An HTTP message body can be empty
  * When used, the body can contain HTML, images, audio, and so on
  * You can think of the body as the letter enclosed in an envelope
* `Location` is an HTTP response header
  * Your browser sees a Location header in the response and automatically issues a brand new request to the specified URL, thereby initiating a new, unrelated request
* The browser hides a lot of the underlying HTTP request/response cycle from you





## Have a basic understanding of the asynchronous nature of AJAX, and the kinds of features that it enables for web apps





