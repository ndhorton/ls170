# Security

* Have an understanding of various security risks that can affect HTTP, and be able to outline measures that can be used to mitigate against these risks

* Be aware of the different services that TLS can provide, and have a broad understanding of each of those services



## Have an understanding of various security risks that can affect HTTP, and be able to outline measures that can be used to mitigate against these risks

**<u>3:4 HTTP Book: Making Requests</u>**

**POST Requests**

* Sending sensitive information through query strings exposes that information in the URL
  * Using a `POST` request in a form fixes this problem



**<u>3:4 HTTP Book: Security</u>**

**Secure HTTP (HTTPS)**

* As the client and server send requests and responses to each other, all information in both requests and responses are being sent as strings
  * If a malicious hacker was attached to the same network, they could employ *packet sniffing* techniques to read the messages being sent back and forth
  * Requests can contain the session id, which uniquely identifies your client to the server
    * If someone copies the session id, they can craft a request to the server and pose as your client, and thereby be logged in without even needing access to your username or password
* This is where Secure HTTP, or HTTPS, helps
* A resource accessed by HTTPS will start with `https://` instead of `http://` and is usually displayed with a lock icon in most browsers
* With HTTPS, every request/response is encrypted before being transported on the network
  * This means if a malicious hacker sniffed out the HTTP traffic, the information would be encrypted and useless
* HTTPS sends messages through a cryptographic protocol called TLS for encryption
  * (Much) earlier versions of HTTPS used SSL, or Secure Sockets Layer, until TLS was developed
* TLS is a cryptographic protocol that uses certificates to communicate with remote servers and exchange security keys before data encryption happens
  * You can inspect these certificates by clicking on the padlock icon that appears before the `https://`
  * Most modern browsers do some high level check on a website's TLS certificate

**Same-origin policy**

* The **same-origin policy** permits unrestricted interaction between resources originating from the same origin, but restricts certain interactions between resources originating from different origins
  * Origin means a combination of the scheme, host, and port
* Some-origin policy doesn't restrict all cross-origin requests
  * Requests such as linking, redirects, or form submissions to different origins are typically allowed
  * Also allowed is the embedding of resources from other origins, such as scripts, CSS stylesheets, images, and other media, fonts and iframes
* What same-origin policy restricts cross-origin requests where resources are being accessed programmatically using APIs such as `XMLHttpRequest` or `fetch()`
* Same-origin policy can pose an issue for web developers who have legitimate need for making these restricted kinds of cross-origin requests
* **Cross-origin resource sharing**, or **CORS**, was developed to deal with this issue
  * CORS is a mechanism that allows interactions that would normally be restricted cross-origin to take place
  * It works by adding new HTTP headers that allow servers to serve resources cross-origin to certain specified origins
    * If your browser downloads some JavaScript from Origin A, and that script then asks for a resource from Origin B, then CORS gets involved
    * Your browser implements this by sending an `Origin:` header to the server in Origin B containing the details of Origin A when it requests the resource
    * If this server is configured to allow cross-domain access to Origin A, then it must include the appropriate `Access-Control-Allow-Origin` header in its response
    * If the header is present and grants access, then the browser will subsequently accept the response and process it
    * If the header is missing, or denies access, the browser won't accept and process the response
* The same-origin policy is an important guard against session hijacking attacks and serves as a cornerstone of web application security



## Be aware of the different services that TLS can provide, and have a broad understanding of each of those services





