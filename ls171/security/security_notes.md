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



5:1 **<u>Introduction</u>**

* HTTP is a text-based protocol. HTTP Requests and Responses are transferred across the network in plain text
* HTTP is a relatively simple protocol, with quite a basic message structure and set of rules
* These characteristics make it easier to design and build applications that interact with the protocol, the downside is a lack of security
  * If an HTTP Request or Response is intercepted, the contents of that message can easily be read
* It is also difficult to know if the source of an HTTP response is trustworthy, or if an HTTP message has been tampered with in transit
* There are many situations where the ability to securely transfer data is vital
  * HTTP is used in applications that provide services such as online shopping or banking, as well as many other use cases where security is paramount



5:2 **<u>What to Focus On</u>**

* HTTP on its own doesn't provide any means of secure message transfer
  * Using TLS adds a level of security that HTTP lacks
* TLS provides for secure message exchange over an unsecure channel
* There are multiple aspects to security
  * TLS provides a number of different services



5:7 **<u>Summary</u>**

* HTTP Requests and Responses are transferred in plain text; as such they are essentially insecure
* We can use the Transport Layer Security (TLS) protocol to add security to HTTP communications





## Be aware of the different services that TLS can provide, and have a broad understanding of each of those services



5:3 **<u>The Transport Layer Security</u>**

* The Transport Layer Security (TLS) protocol started life as a protocol called SSL (Secure Sockets Layer)
  * SSL was a proprietary protocol developed by Netscape
  * SSL was standardized and renamed TLS by the IETF in 1999
    * TLS and SSL are often used interchangeably
    * People say SSL Certificates when they are referring to TLS Certificates, Public Key Certificates
* There have been several versions of TLS since 1999, the most recent being TLS 1.3
* There are three important security services provided by TLS:
  * Encryption
  * Authentication
  * Integrity
* Encryption: a process of encoding a message so that it can only be read by those with an authorized means of decoding the message
* Authentication: a process to verify the identity of a party in the message exchange
* Integrity: a process to detect whether a message has been interfered with or faked
* It isn't mandatory for an application which uses TLS that all three of these services are used simultaneously
  * You could, e.g., design your application to accept encrypted messages from a sender without authenticating who they are
  * In practice however, all three services are generally used together to provide the most secure connection possible



5:4 **<u>TLS Encryption</u>**

* Caesar cipher -- simple substitution cypher, letter substitution encrypts the text
* Vigenere cipher -- letter substitution using a tabula recta and keyword, only those in possession of the keyword can decrypt the encrypted text

**Symmetric Key Encryption**

* The underlying concept seen in the Vigenere cipher, where sender and receiver share a common key, is still used in modern cryptographic systems
* This is known as **symmetric key encryption**
  * The same key used to encrypt the message is then used to decrypt the message
  * This relies on both parties in the communication having access to the key and no one else having access to the key
  * This works fine if the key can be exchanged securely, as in person, but poses problems over the internet
  * We cannot send the key in a readable format since it could be intercepted by a third party and used to decrypt our subsequent messages

**Asymmetric Key Encryption**

* Asymmetric Key Encryption, or Public Key Encryption, uses a pair of keys: a public key and a private key
  * In this system, the key used to encrypt a message and the key used to decrypt it are non-identical
  * The public key is used to encrypt and the private key is used to decrypt
  * Messages encrypted with the public key can only be decrypted with the private key
  * The public key is made openly available but the private key is kept in the sole possession of the message receiver
  * This form of encryption/decryption is a one-way process
    * The same key pair used to send a secure message to a party cannot be used by that party to send a response
    * Using this system, the receiver would need the public key of the sender in order to encrypt a response

**The TLS Handshake**

* To securely send messages via HTTP we want both the request and response to be encrypted in such a way that they can only be decrypted by the intended recipient

* The most efficient way to do this is via symmetric key cryptography

  * The algorithms for asymmetric key cryptography are far more computationally intense
  * For large volumes of data, the difference in efficiency between the two methods of encryption/decryption become significant

* TLS uses a combination of asymmetric and symmetric key cryptography

  * The bulk of the message exchange is conducted using symmetric key encryption
  * The initial symmetric key exchange is conducted using asymmetric key encryption
  * The process by which the initial secure connection is set up is conducted during what is known as the TLS handshake

* TLS assumes TCP is being used at the Transport layer, and the TLS Handshake takes place after the TCP handshake

  1. The TLS Handshake begins with the client sending a `ClientHello` message to the server, immediately after the TCP `ACK`
     * The `ClientHello` message contains the maximum version of TLS that the client supports, and a list of Cipher Suites that the client supports
  2. On receiving the `ClientHello` message, the server responds with a `ServerHello` message, which sets the TLS version and Cipher Suite, along with the server's certificate, which contains its public key, and a `ServerHelloDone` marker which indicates to the client that the server has finished with this phase of the handshake
  3. Once the client receives the `ServerHelloDone` marker, it initiates the key exchange process
     * This key exchange process enables both client and server to securely obtain a copy of the symmetric encryption key that will be used for the bulk of the secure message transfer between parties
     * The exact process for generating the symmetric keys will vary depending on which key exchange algorithm was selected as part of the Cipher Suite (e.g. RSA, Diffie-Hellman, etc)
     * For RSA,
       * The client generates what's called a 'pre-master secret', encrypts it using the server's public key, and sends it to the server as part of a `ClientKeyExchange` message
       * The server receives the encrypted 'pre-master secret' and decrypts it using its private key
       * Both client and server use the 'pre-master secret'  along with some other pre-agreed parameters to generate the same symmetric key
       * As part of the communication which includes the `ClientKeyExchange` message, the client also sends a `ChangeCipherSpec` flag, which tells the server that encrypted communications should now start using the symmetric keys, along with a `Finished` flag to indicate that the client is now done with the TLS Handshake
  4. The server sends a message with `ChangeCipherSpec` and `Finished` flags. The client and server can now begin secure communication using the symmetric key

  LS: "We certainly don't expect you to memorize every detail of the various steps involved. Instead, try to form a high-level mental model for how it works. Note also that the exact process will vary according to which version of TLS is used."

* Client sends `ClientHello`
* Server responds with `ServerHello`/`Certificate`/`ServerHelloDone`
* Client sends `ClientKeyExchange`/`ChangeCipherSpec`/`Finished`
* Server responds with `ChangeCipherSpec`/`Finished`

* The TLS Handshake has three main purposes
  * Agree  which version of TLS to be used in establishing a secure communication
  * Agree on the algorithms that will be included in the cipher suite
  * Enable the exchange of the symmetric key that will be used for message encryption

* This complexity impacts performance
  * The TLS handshake can add up to two round-trips of latency before any application data is sent
  * This is in addition to the initial round-trip resulting from the TCP handshake
* There is also the Datagram Transport Layer Security (DTLS), which is based on TLS and is used for UDP rather than TCP

**Cipher Suites**

* A cipher is a cryptographic algorithm
  * A set of steps for performing encryption, decryption, and other related tasks
* A cipher suite is a suite, or set, of ciphers
* TLS uses different ciphers for different aspects of establishing and maintaining a secure connection
  * There are many different algorithms for performing the key exchange process, for carrying out authentication, for symmetric key encryption, and for checking message integrity
* The algorithms for performing each of these tasks, when combined, form the cipher suite
* As part of the `ClientHello` message in the TLS Handshake, the client sends a list of algorithms it supports for each required task, and the server chooses from these according to which algorithms it also supports



5:5 **<u>TLS Authentication</u>**

* Encryption without authentication does not prevent a malicious third party posing as the party you wish to communicate with, e.g. a hacker might impersonate your bank
  * Having encryption in this situation does not make you safer, and might even make you more willing to share privileged information
  * Therefore, we need a means of identifying the other party in our message exchange
* During the TLS Handshake, as part of its response to the `ClientHello` message, the server provides its certificate
  * Part of the function of the certificate is to provide the server's public key to the client to encrypt the symmetric key exchange portion of the handshake
  *  Another function of this certificate is to identify the party providing it
* The certificate contains various pieces of information, including who the owner is
  * However, on its own, the certificate proves nothing; a third party might easily acquire such a certificate and then present it as its own
  * The certificate, and the public key it contains, are only part of an overall system of authentication
* The exact way the public key is used during this process varies depending on the Authentication algorithm selected as part of the Cipher Suite. Generally, it will be something like:
  * The server sends its certificate, which includes its public key
  * The server creates a 'signature' in the form of some (session-specific) data encrypted with the server's *private key*
  * The signature is transmitted in a message along with the original data from which the signature was created
  * On receipt of the message, the client decrypts the signature using the server's public key and compares the decrypted data to the original version
  * If the two versions match then the encrypted version could only have been created by a party in possession of the private key.
* Following a process such as this, we can identify that the server which provided the certificate during the initial part of the TLS Handshake is in possession of the private key, and is therefore the actual owner of the certificate
  * However, what is to stop a malicious third-party creating their own key pair and certificate identifying them as, say, a well-known bank?
  * It is easy to create a fake digital certificate -- how are we to know if a certificate is genuine or not?
  * This is where Certificate Authorities come in

**Certificate Authorities and the Chain of Trust**

* Certificate Authorities (CAs) are trustworthy sources that issue TLS certificates
* When a CA issues a certificate, the CA
  * **Verifies that the party requesting the certificate is who they say they are** -- the way this is done varies by CA and partially depends on the type of certificate being issued. In the case of a domain validated server certificate, for example, it can involve proving that you own the domain by uploading a specific file to a server that is accessible by the domain for which the certificate is being issued
  * **Digitally signs the certificate being issued** -- this is often done by encrypting some data particular to the certificate with the CA's own private key and using this encrypted data as a 'signature'. The unencrypted version of the data is also added to the certificate. In order to verify that the certificate was issued by the CA, the signature can be decrypted using the CA's public key and checked for a match against the unencrypted version
* There are different levels of Certificate Authority
  * An **Intermediate CA** can be any company or body authorized by a **Root CA** to issue certificates on its behalf
  * A widely-used Intermediate CA is Let's Encrypt, who provide free, automated certificates
  * The Intermediate CAs will have their certificates signed, possibly other Intermediate CAs, up a chain until we reach a Root CA
  * Root CA certificates are self-signed. Root CAs are where the chain of trust ends
* Client software, such as browsers, store a list of these root authorities along with their Root Certificates (which include public keys)
  * When receiving a certificate for checking, the browser can go up the chain to the Root Certificate stored in its list
* The purpose of this chain-like structure is the level of security it provides
  * The private keys of the Root CAs are kept behind many layers of security in order to be kept as inaccessible as possible
  * This is partly why Root CAs do not issue end-user certificates, but leave that up to the Intermediate CAs
  * If the private key of a Root CA were to become compromised, the Root CA can revoke the certificate for Intermediate, therefore invalidating all of the certificates down chain, and simply issue a new one
* Root CAs are trusted because of their reputations gained through prominence and longevity
  * Root CAs are a small group of organizations approved by browser and operating system vendors
* Ultimately this system still relies on trust, and as such isn't infallible



5:6 **<u>TLS Integrity</u>**

* The Encryption and Authentication capabilities of TLS already provide us with a fairly secure system. To add a further layer of security, TLS provides functionality to check the integrity of data transported via the protocol

**TLS Encapsulation**

* The OSI model defines TLS as a Session layer protocol, and so existing in between the Application layer (where HTTP resides) and the Transport layer (where TCP resides). When thinking about TLS, it is useful to think of it as operating between HTTP and TCP
* When it is transporting application data, TLS encapsulates that data in the same way that we've seen with other Protocol Data Units
  * The data to be transported forms a payload, and meta data is attached in the form of header and trailer fields
* The TLS PDU is known as a TLS Record
  * Header
    * Content Type
    * TLS Version
    * Length
  * Data Payload
  * Trailer
    * MAC (Message Authentication Code)
    * Padding
* The main field of interest in terms of message integrity is the MAC (Message Authentication Code) field

**Message Authentication Code**

* The MAC field is similar in concept to the checksum fields we've already seen in other PDUs. However, there is a difference in implementation as well as overall intention
  * The checksum field in, say, a TCP Segment is intended for error detection (i.e. to test if some data was corrupted in transport)
  * The intention of the MAC field in a TLS record is to add a layer of security by providing a means of checking that the message hasn't been altered or tampered with in transit
* The way this is implemented is through the use of a hashing algorithm
  * The sender creates what is called a *digest* of the data payload
    * This is effectively a small amount of data derived from the actual data that will be sent in the MAC field
    * The digest is created using a specific hashing algorithm combined with a pre-agreed hash value
    * The hashing algorithm to be used and the has value will have been agreed as part of the TLS Handshake process when the Cipher Suite is negotiated
  * The sender will then encrypt the data payload using the symmetric key, encapsulate it into a TLS Record, and pass this record down to the Transport layer to be sent to the other party
  * Upon receipt of the message, the receiver will decrypt the data payload using the symmetric key
    * The receiver will then also create a digest of the payload using the same algorithm and hash value
    * If the digest created by the receiver matches the digest received in the MAC field, this confirms the integrity of the message

5:7 **<u>Summary</u>**

* TLS encryption allows us to encode messages so that they can only be read by those with an authorized means of decoding the message
* TLS encryption uses a combination of Symmetric Key Encryption and Asymmetric Key Encryption. Encryption of the initial key exchange is performed asymmetrically, and subsequent communication is symmetrically encrypted
* The TLS Handshake is the process by which a client and a server exchange encryption keys
* The TLS Handshake must be performed before secure data exchange can begin; it involves several round-trips of latency and therefore has an impact on performance
* A cipher suite is the agreed set of algorithms used by the client and server during the secure message exchange
* TLS authentication is a means of verifying the identity of a participant in a message exchange
* TLS Authentication is implemented through the use of Digital Certificates
* Certificates are signed by a Certificate Authority and work on the basis of a Chain of Trust which leads to one of a small group of highly trusted Root CAs
* The server's certificate is sent during the TLS Handshake process
* TLS Integrity provides a means of checking whether a message has been altered or interfered with in transit
* TLS Integrity is implemented through the use of a Message Authentication Code (MAC)





TLS

Encryption

TLS Handshake

* Client sends `ClientHello` to server, advertising its available ciphers and max TLS version
* Server sends back a `ServerHello` message containing its TLS certificate and setting the cipher suite and TLS version
* Client confirms the legitimacy of the certificate via the Chain of Trust. Client sends back a message encrypted with the server's public key beginning the symmetric key exchange. Here, asymmetric key cryptography is used as a secure channel for the exchange of the symmetric key. The precise details of this exchange depend on the algorithm used to generate the session's symmetric key. Once both parties have generated the symmetric key, the server sends a message to the client with the `ChangeCipherSpec` and `Finished` flags set, and the symmetric key is used for encryption during the remainder of the TLS session.

The whole handshake adds up to 2 round-trips of latency before any application data is sent, and that is in addition to the round-trip required for the TCP handshake, which takes place before the TLS handshake begins.

The confirmation of the certificate is actually more complex than that. In addition to sending the certificate as a response to the `ClientHello` message, the server also sends a 'signature' encrypted with the server's private key, along with the original un-encrypted data used for the signature. The client decrypts the signature, using the public key given in the certificate, and compares the data to the decrypted signature; if they match, this means the signature could only have been produced by a party in possession of the server's private key. The certificate is also checked using the Chain of Trust.





Authentication

Integrity

