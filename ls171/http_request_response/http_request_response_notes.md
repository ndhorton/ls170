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

* The server returns this status code when the requested resource cannot be found

**500 Internal Server Error**

* A `500` status code says "there's something wrong on the server side"
  * Someone with access to the server will have to debug and fix the problem
  * This is why you sometimes see a vague error message asking you to contact the System Administrator

Aside: a `301` status code is a permanent redirect, and a `303` status code is like a `302` except it specifies that the method of the request the client makes to `Location` should be `GET`

**Response Headers**

* Response headers offer more information about the resource being sent back
* Some common response headers are:
  * `Content-Encoding:` -- the type of encoding used on the data
  * `Server:` -- name of the server
  * `Location:` -- notify client of new resource location
  * `Content-Type:` -- the type of data the response contains
* Response headers contain additional metadata about the response data being returned

* HTTP is nothing more than an agreement in the form of formatted text that dictates how a client and server communicate
* The most important parts of an HTTP response are
  * status code
  * headers
  * message body



## Be able to describe the HTTP request/response cycle

3:4 **<u>HTTP Book: Processing Responses</u>**

* HTTP is nothing more than an agreement in the form of formatted text that dictates how a client and server communicate





## Be able to explain what status codes are, and provide examples of different status code types

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

* The server returns this status code when the requested resource cannot be found

**500 Internal Server Error**

* A `500` status code says "there's something wrong on the server side"
  * Someone with access to the server will have to debug and fix the problem
  * This is why you sometimes see a vague error message asking you to contact the System Administrator

Aside: a `301` status code is a permanent redirect, and a `303` status code is like a `302` except it specifies that the method of the request the client makes to `Location` should be `GET`





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



**<u>3:4 HTTP Book: Stateful Web Applications</u>**

* HTTP is a stateless protocol
  * The server is not required as part of the protocol to hang on to information between each request/response cycle
* Each request made to a resource is treated as a brand new entity, and different requests are not aware of each other
* This statelessness allows HTTP and the web to be very distributed (because, for instance, any server in a cluster can handle any incoming request without needing to be aware of previous request/response cycles), and also makes the web more difficult to control
* Yet this statelessness also makes it more difficult for web developers to build **stateful** applications
* Many familiar web apps give the appearance of having a certain state. When we have provided our username and password to Facebook, we expect to be able to click around the site while remaining 'logged in'; and yet every click initiates a new stateless HTTP request/response cycle in which each HTTP request is inherently unaware of the preceding request where we gave our authentication credentials. How does the Facebook server identify your client and remember you are currently logged in?
* Important techniques for building these kinds of stateful application logics on top of a stateless Application layer protocol are:
  * Sessions
  * Cookies
* In days gone by, another approach was to use query parameters to retain state. This is now very seldom used in modern websites

It's important to note that the original use case of Cookies was for the client to store state in the Cookie on the local storage, rather than just a Session ID. In this way, the client was in charge of storing all application state. A Session ID means that the server stores the bulk of the application state relating to the client and only issues a session ID token to be stored in the Cookie on the client-side. There also are alternatives to Cookies for storing state client-side. So while a Session ID is typically given to the client in a Cookie, these technologies are not always combined. Likewise, AJAX often makes use of Cookies and Session IDs, but other means of maintaining a 'session' are available. So all these techniques should be understood as discrete elements, even if they are often combined, and there exist alternatives to each.

The Session ID is used to identify the client so that the server can refer to information about the user retained on the server.

Cookies are used to transmit data from server to client in a way that can be stored by the client and then sent to the server with each new request.

AJAX is used to make web pages appear more continuously dynamic in a way that disguises the fact that each change in the page can only come about through additional requests from client to server (even if it is the JavaScript running in the browser that is quietly making additional requests, rather than any action by the user).  

**Sessions**

* The stateless HTTP protocol is somehow being augmented so as to maintain a sense of statefulness in the application
* With some help from the client (i.e. the browser), HTTP can be made to act as if it were maintaining a stateful connection with the server, even though it is not
* One way to accomplish this is by having the server send some form of a unique token to the client
* Whenever a client makes a request to the server, the client includes the token as part of the request, and the server can identify the client based on the token
* In web development, this unique token is called the **session identifier**, or **session id**
* This mechanism of passing a `session id` back and forth between the client and server creates a sense of persistent connection between requests
* Web developers can leverage this faux statefulness to build sophisticated applications even though each request is technically stateless and unaware of the previous or the next one
* This sort of faux statelfulness has consequences:
  * Every request must be inspected to see if it contains a session identifier
  * If the request does contain a session id, the server must check to ensure that this session id is still valid
    * The server must maintain rules about session expiration
    * The server must decide how to store its session data
  * The server needs to retrieve the session data based on the session id
  * The server needs to recreate the application state (e.g. the HTML for a web request) from the session data before sending the response
* The server has to work very hard to simulate a stateful experience, and every request still gets its own response, even if most of that response is identical to the previous response

**Cookies**

* One way to store session information is in a browser cookie
* A cookie is a piece of data that's sent from the server and stored in the client during a request/response cycle
* **Cookies** or **HTTP Cookies** are small files stored in the browser and can contain session information
* By default, most browsers have cookies enabled
* When you access any website for the first time, the server sends information about the session and sets it in your browser cookie on the client computer
  * The actual application session data is generally stored on the server
* The client side cookie is compared with the server-side session data on each request to identify the current session
* This way, when you make another request to the same website, your session will be recognized because of the stored cookie with its associated information
* The server transmits the cookie data to the client in a `Set-Cookie` header
* The client can then send a `Cookie` header in its subsequent responses containing the same session data, uniquely identifying the client/browser
* The client can store cookies persistently, allowing us to bypass the need provide our login details again even if we shut down the computer and return to the website days later
* When a session id is sent by the server and saved as a cookie in your browser, the session id can then be sent back to the server on every subsequent request; the server can now uniquely identify your client
* When the server receives a request with a session id, the server will look for the associated data based on that id, and in that associated session data is where the server "remembers" the state of the application for that client (or more precisely, for that session id)
* The session id is stored client-side and used as a key to the session data stored server side
* This is how web applications work around the statelessness of HTTP
* It is important to be aware of the fact that the id sent with a session is unique and expires in a relatively short time
  * This means that you are required to log in again once it expires
  * If we log out, the session id information is gone
  * If we manually remove the session id from our browser, we are then effectively logged out
* Session data is generated and stored on the server-side and the session id is sent to the client in the form of a cookie
  * Web applications take advantage of this to mimic a stateful experience on the web



From LSBot, in reference to my asking if the way web applications build a stateful experience over a stateless, connectionless protocol is analogous to the way TCP provides a reliable connection over an unreliable, connectionless protocol (IP): "This directly parallels how web applications use mechanisms like cookies and session IDs to build statefulness over HTTP. In both cases, **a higher-level protocol or application logic is compensating for the limitations of a lower-level protocol by adding the functionality needed for a more sophisticated interaction model.It's a perfect example of how the internet's layered architecture allows each protocol to focus on solving specific problems while relying on other layers to provide complementary functionality**."



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
* Unlike `POST`, `GET` requests typically do not have a body
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

**<u>3:4 HTTP Book: Stateful Web Applications</u>**

**AJAX**

* AJAX stands for **Asynchronous JavaScript and XML**
* AJAX allows browsers to issue requests and process responses *without a full-page refresh*
* If you are logged into Facebook, the server has to generate the initial page you see, and the response is a pretty complex and expensive HTML page that your browser displays. The Facebook server has to add up all the likes and comments for every photo and status, and present it in a timeline for you. This would be a very expensive page to re-generate for every request (remember, every action you take -- clicking a link, submitting a form -- issues a new request)
* "When AJAX is used, all requests sent from the client are performed *asynchronously*, which means that the page doesn't refresh" -- what this actually means is that the ability for JavaScript to make requests asynchronously means that sending a request and waiting for a response from the server is not a blocking action. With synchronous JS, a request would cause all JavaScript on the page to wait until the request returned, making partial page refresh through DOM manipulation almost as slow and costly as a full page refresh
* If we navigate to `https://www.google.com` and begin typing in the search bar on the webpage, every letter we type results in a new request and the page updates dynamically to show suggested searches without the whole page being refreshed
  * This is because an AJAX request is triggered with every key-press
  * The responses from these requests are being processed by some callback
  * A **callback** is a piece of logic you pass on to some function to be executed after a certain event has happened
  * In this case a callback is triggered when the response is returned
  * The callback that's processing these asynchronous responses is updating the HTML DOM with new search results
  * This state of the page changes based on data exchanged with the server without the user clicking a link, typing in a URL, or submitting a form; yet it is still the result of many stateless HTTP request/response cycles
* AJAX requests are just like normal requests: they are sent to the server with all the normal components of an HTTP request, and the server handles them like any other request
  * The difference is that instead of the browser refreshing and processing the response, the response is processed by a callback function, which is usually some client-side JavaScript code
* These are just some of the techniques web developers use to mimic statefulness despite working with HTTP, a stateless protocol
* Cookies and sessions are a primary way that modern web apps remember state for each client
* AJAX plays a role in displaying dynamic content in web applications

