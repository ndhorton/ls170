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
    * If this s is configured to allow cross-domain access to Origin A, then it must include the appropriate `Access-Control-Allow-Origin` header in its response
    * If the header is present and grants access, then the browser will subsequently accept the response and process it
    * If the header is missing, or denies access, the browser won't accept and process the response
* The same-origin policy is an important guard against session hijacking attacks and serves as a cornerstone of web application security

**Session Hijacking**

* The session id serves as that unique token used to identify each session
* Usually the session id is implemented as a random string and comes in the form of a cookie stored client-side
* With the session id in place on the client side, now every time a request is sent to the server, this data is added and used to identify the session
* This is how the authorization systems of many web applications work
* When a user's username and password match, the session id is stored on their browser so that on the next request they won't have to re-authenticate
* Unfortunately, if an attacker gets hold of the session id, both the attacker and the user now share the same session and both can access the web application
  * In session hijacking, the user won't even know an attacker is accessing his or her session
  * The hijacker doesn't even need to know the username or password
* There are common countermeasures against session hijacking
  * One popular method of guarding against session hijacking is resetting sessions
    * With authentication systems, this means a successful login must render an old session id invalid and create a new session id
    * On the next sensitive request, the victim will be required to authenticate
    * At this point, the session id will change and the attacker will be logged out
    * Likewise, if the attacker attempts to make a sensitive request, they will be presented with a page asking them to login using the user's password, which the hijacked session id can't tell them
    * Most websites implement this technique by making sure users authenticate when entering any potentially sensitive area, such as charging a credit card or deleting an account
  * Another mitigation is to set an expiration time on sessions
    * Sessions that do not expire give an attacker an infinite amount of time to pose as the real user
    * Expiring sessions after, e.g., half an hour, gives the attacker a far narrower window to access the app
  * A primary solution to this problem is to use HTTPS across the entire app to minimize the chance that an attacker can get to the session id

**Cross-Site Scripting (XSS)**

* Cross-site scripting, or XSS, is a security concern for all web developers
* An XSS attack could happen if you allow users to input HTML or JavaScript that ends up being displayed by the site directly
  * For example, a form that allows you to submit comments that are then displayed at the bottom of the page
  * Because this is a normal HTML `<textarea>`, users are free to input anything into the form
  * This means users can add raw HTML and JavaScript into the text area and submit it to the server
* If the server then doesn't do sanitize the input, this input is then injected into the page contents and *the browser will interpret the HTML and JavaScript and execute it*
* Attackers can craft ingeniously malicious HTML and JavaScript and be very destructive to both the server and future visitors to the page
  * For example, an attacker could use JavaScript to grab the session id of every future visitor of this site and then come back and assume their identity
  * This could happen without the victims ever knowing about it
* The malicious code would bypass the Same Origin Policy because the code lives on the site

**Potential Solutions for Cross-Site Scripting**

* One way to prevent this kind of attack is ensuring you always sanitize user input
  * This is achieved either by eliminating problematic input such as `<script>` tags, or by disallowing HTML and JavaScript altogether
* The second way to guard against XSS is to escape all user input data when displaying it
  * If users should be allowed to input HTML and JavaScript, then when you print it out, make sure to escape it so that the browser does not interpret it as code but simply displays the characters as text

**HTML Escaping**

* To escape a character means replacing an HTML reserved characters with a combination of ASCII characters, which tell the client to display that character as is, and not to process it
* This helps prevent malicious code from running on a page
* These combinations of ASCII characters are called **HTML Entities**
* Entities are used to implement reserved characters or to express characters that cannot easily be entered with the keyboard
  * The combination of ASCII characters representing an HTML character is called an `Entity Name` 
  * Each entity has a `Name` and a `Number`
  * For instance, the `<` symbol (used in HTML tags) has the `Entity Name` of `&lt;` and an `Entity Number` of `&#60;`
  * The digits of the `Entity Number` correspond to the decimal representation of the reserved character's ASCII code

3:9 **<u>Summary</u>**

* HTTP is inherently unsecure. Security can be increased by using HTTPS, enforcing Same-Origin Policy, and using techniques to prevent Session Hijacking and Cross-site Scripting



## Be aware of the different services that TLS can provide, and have a broad understanding of each of those services





