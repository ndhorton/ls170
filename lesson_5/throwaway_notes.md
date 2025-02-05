# Lesson 5 - Transport Layer Security (TLS) #

## 5:2 What to Focus On

* Understand that TLS provides for secure message exchange over an unsecure channel.
* Learn that there are multiple aspects to security - TLS provides a number of different services. Learn what each service provides and the problems it aims to address.

## 5:3 The Transport Layer Security (TLS) Protocol ##

'The Transport Layer Security (TLS) protocol started life as a protocol called SSL (Secure Sockets Layer). This was a proprietary protocol developed by Netscape. Although it was standardized and renamed as TLS in 1999 by the IETF, the terms are still used interchangeably. You'll commonly still hear people talk about SSL Certificates rather than referring to them as TLS Certificates or Public Key Certificates. When you hear SSL being mentioned, just bear in mind that the person saying it is probably referring to TLS, unless they are speaking historically.'

Aside: SSL 3.0 was effectively renamed TLS 1.0 as a face-saving measure to Microsoft, which had attempted development of its own proprietary security protocols for Internet Explorer and Internet Information Services, in order to get MS to agree to cede development of the security protocol to the IETF as an open standard.

There have been several versions of TLS since 1999, the most recent one being TLS 1.3, released August 2018.



There are three important security services provided by TLS:

* Encryption - a process of encoding a message so that it can only be read by those with an authorized means of decoding the message
* Authentication - a process to verify the identity of a particular party in the message exchange
* Integrity - a process to detect whether a message has been interfered with or faked

Each is important in its own right, but combined they provide for very secure message exchange over an unsecure channel.

'It isn't mandatory for an application which uses TLS that all three of these services are used simultaneously. For example, you could design your application to accept encrypted message from a sender without authenticating who they are. In practice, however, all three services are generally used together to provide the must secure connection possible.'

## 5:4 TLS Encryption ##

* TLS sets up an encrypted connection via a process known as the **TLS Handshake**

<u>**Symmetric Key Encryption**</u>

* Symmetric key encryption - sender and receiver share a common encryption key
* In order to work securely, symmetric key encryption depends on both sender and receiver having access to the shared key with no one else being able to access it

What we need is a way to encrypt the encryption key itself, so that even if it is intercepted it cannot be used.

**<u>Asymmetric Key Encryption</u>**

* Asymmetric key encryption/public key encryption - public key and private key pair; public key encrypts a message and private key decrypts it
* Public key is made available to anyone
* Private key is kept secret
* Anyone can send a message to the receiver using the public key to encrypt it
* Only the receiver can decrypt the message, using the private key
* In a two-way message exchange, one public-private pair of keys pertains to one participant and another pair to the other participant



**<u>The TLS Handshake</u>**

To securely send messages by HTTP, we want both the request and response to be encrypted such that they can only be decrypted by the intended recipient. The most efficient way to do this is via symmetric key cryptography. However, this means we need a secure way to exchange the symmetric key.

* TLS uses a combination of symmetric and symmetric cryptography.
* The bulk of the message exchange is conducted by symmetric key encryption
* The initial symmetric key exchange is conducted using asymmetric key encryption
* The process by which the initial secure connection is set up is conducted during what is known as the **TLS Handshake**

* TLS assumes TCP is being used at the Transport Layer
* The TLS Handshake takes place after the TCP Handshake

The TLS Handshake looks something like:

1. The TLS Handshake begins with a `ClientHello` message, which is sent immediately after the TCP `ACK`. Among other things, this contains the maximum version of TLS the client can support, and a list of Cipher Suites that the client supports
2. On receiving the `ClientHello` message, the server responds with a message of its own. This message includes a `ServerHello`, which sets the protocol version and Cipher Suite, as well as other information. As part of this message, the server also sends its certificate (containing its public key), and a `ServerHelloDone` marker which indicates to the client that it has finished with this step of the handshake
3. Once the client has received the `ServerHelloDone` marker, it will initiate the key exchange process. This key exchange process ultimately enables both client and server to securely obtain a copy of the symmetric key. The exact key exchange process depends on which key exchange protocol was selected as part of the Cipher Suite. As an example, the RSA algorithm works in the following way:
   1. The client generates what's known as a 'pre-master secret', encrypts it using the server's public key, and sends it to the server.
   2. The server receives the encrypted 'pre-master secret' and decrypts it using its private key.
   3. Both client and server use the 'pre-master' secret, along with some other parameters, to generate the same symmetric key.
   4. As part of the communication which includes the `ClientKeyExchange` message, (e.g. the pre-master secret), the client also sends a `ChangeCipherSpec` flag, which tells the server that encrypted communications should now start using the symmetric keys. Additionally this communication includes a `Finished` flag to indicate that the client is now done with the TLS Handshake.
4. The server also sends a message with `ChangeCipherSpec` and `Finished` flags. The client and server can now begin secure communication using the symmetric key.

The exact process also depends on which version of TLS is used.

The key points to remember about the TLS handshake process is that it is used to:

* Agree which version of TLS to be used in establishing a secure connection
* Agree on the various algorithms that will be included in the cipher suite
* Enable the exchange of symmetric keys that will be used for message encryption



* One of the implications of the complexity of the TLS handshake is the impact on performance
* The TLS handshake can add up to two round-trips of latency (depending on the TLS version) in establishing a connection between client and server prior to the point where any application data can be sent. This is on top of the initial round trip resulting from the TCP Handshake



* There is a protocol called Datagram Transport Layer Security (DTLS), which is based on TLS. This protocol is specifically for use with network connections which use UDP rather than TCP at the Transport layer.



**<u>Cipher Suites</u>**

* A cipher is a cryptographic algorithm - a set of steps for performing encryption, decryption, and other related tasks
* A cipher suite is a suite, or set, of ciphers
* TLS uses different ciphers for different aspects of establishing and maintaining a secure connection
* There are many algorithms that are concerned with each of these aspects of secure communication: key exchange, authentication, symmetric key encryption, checking message integrity, etc.
* The algorithms for performing each of these tasks, when combined, form the cipher suite. The suite to be used is agreed as part of the TLS handshake
* The client sends a list of the algorithms it supports for each required task, and the server chooses from these according to which algorithms it supports

