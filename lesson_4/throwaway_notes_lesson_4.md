# Lesson 4: Working with HTTP #

## 4:1 What to Focus On ##

* Focus on HTTP - although we're using bash and various network utilities, do not focus on mastering them, focus at all times on what they reveal about how HTTP enables communication between a client and a server
* HTTP is concerned with the structure of messages - HTTP is a set of rules concerned with the syntax and structure of messages exchanged between applications. Working with HTTP is about understanding what those rules mean, and knowing how and when to apply them
* HTTP is a Request-Response protocol - focus on and form a solid mental model around the Request-Response behavior of HTTP



## 4:2 Using Telnet to explore HTTP ##

`telnet google.com 80`

`GET /`



## 4:3 Speaking the Same Language ##

When our request was simply `GET /` we were using HTTP 0.9 format. 'Fortunately, the server at `google.com` can interpret HTTP 0.9 requests'

* Many servers do not support HTTP 0.9 format, but require either HTTP 1.0, HTTP 1.1, or higher

An HTTP 1.0 request looks like:

```
telnet example.com 80
GET / HTTP/1.1
Host: example.com

```

Since we are using HTTP 1.1, we need to include an empty line after the last header included with the request.

* `4xx` level response codes indicate an error or issue on the client side. A `404` error is a general indication that the requested resource does not exist.
* `5xx` level response codes indicate an error on the server. The most common is `500` indicating an internal server error. `5xx` responses are usually outside of the control of the requesting software.
* `3xx` level responses don't indicate errors. Instead, they are generally used in relation to redirection and indicate the client must take some additional action in order to complete the request.

An interesting thing to note is that the `Connection: keep-alive` header-value pair **will keep the TCP connection open**. This is common for `301` and `302` redirect responses.



## 4:4 Implementing Our Own HTTP Server: Project Overview ##

* HTTP is essentially a set of rules for structuring messages between two participants in a message exchange
* It's up to the participants, such as a web browser and a web server, to implement those rules
* Ultimately it is the way that the rules are implemented which determines whether or not a message can be interpreted and also how messages are interpreted

Early web servers following the 0.9 specification only responded to `GET` requests and only served static text files.

* `netcat`



## 4:6  Working with `netcat`



Netcat is a network utility for reading and writing data across network connections through TCP or UDP.

As well as connecting to a domain and port, Netcat permits you to listen at a port for incoming connections.



 ## 4:11 Implementing Our Own HTTP Server: Working with the Browser ##

As we saw, Internet protocols standardize on a new line being represented by `\r\n`, Carriage Return + Line Feed, CRLF.

The end of a request in HTTP is signified by an empty line (`\r\n\r\n`) after the last header.

**Improving the Response**

'One issue with processing a response is knowing where the response message ends. There are various ways in which this can be determined, depending on the type of message. Certain responses, such as `1xx` level responses, `204`, and `304` responses and any response to a `HEAD` request, must not include a body. For theses types of responses, the end of the response message is indicated by the first empty line after the header fields.'

'Other types of responses are assumed to have a body, even if that body is empty. For messages with a body, the size of the message body can be used to determine the end of the message. Calculating the size of the message body can be done in a number of different ways.'

'One of these is for a `Transfer-Encoding` header to be sent as part of the response'. `chunked`, `gzip`, etc...

'Another way to indicate the size of the body is to include a `Content-Length` header. As described in the MDN docs: "The `Content-Length` entity header indicates the size of the entity-body, in bytes, sent to the recipient"'

* `Content-Length` - RFC7230: "... in the absence of `Transfer-Encoding`, an origin server SHOULD send a `Content-Length` header field when the payload body size is known prior to sending the complete header section. This will allow downstream recipients to measure transfer progress, know when a received message is complete, and potentially reuse the connection for additional requests." (For the `400` and `404` responses, the value is set to `0` since there is no body.)
* `Content-Type` - indicates the media type of the resource being sent in the message. Browsers can sometimes ignore this header and determine the content type some other way (MIME sniffing, etc). In general, "it is good practice to include it."



NB: when using `netcat` as client instead of `telnet`, we need to use the `-C` option (capital C) in order to convert Unix `\n` into Internet `\r\n`. `telnet` seems to do this automatically.



## 4:12 Implementing Our Own HTTP Server: Adding Hyperlinks ##



**The HTML Anchor Element**

The HTML Anchor element,  when used with a `href` attribute, creates a *hyperlink*.

Syntax is:

```html
<a href="/path/to/target">Click here!</a>
```

where `path/to/target` could be complete URL, including the scheme and the host, such as `https://launchschool.com`; this could be a file or end-point on the same server or host, or on a completely different one. Or, it could be a path to another file or location on the same server/host, e.g. `/my_file.html`.

**Browsers and Hyperlinks**

If you click on a hyperlink on a webpage displayed in a browser, the browser will automatically issue a `GET` request to the location specified in the `href` attribute. If the value is a complete URL, then the scheme and host from the URL will be used. If the value is just a path, the browser will use the same scheme and host as for the current page.



## 4:13 Summary ##

* HTTP is a text-based protocol. HTTP Requests and Responses involve sending text between the client and server
* In order for the protocol to work, the Request and Response must be structured in such a way that the client and server can understand them.
* With HTTP/1.1, the end of the headers is indicated by *an empty line*.
* The `Content-Length` header can be used to indicate the *size of the body*. This can help determine where the HTTP message should end.











