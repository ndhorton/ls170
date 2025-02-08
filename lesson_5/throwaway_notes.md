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



## 5:5 TLS Authentication ##

* Encryption alone does not protect you if the source of the data is a malicious third party rather than the party you intended to communicate with
* We need a way of identifying the other party in our communication



* During the TLS Handshake, as part of its response to `ClientHello`, the server provides its certificate, partly because it contains the server's public key
* The certificate also provides a means of identification for the party providing it
* However, the certificate alone proves nothing about ownership, since it is made available to anyone who communicates with the server and they could attempt to use it maliciously. Along with the public key contained within it, the certificate is simply part of a larger system of authentication



There is one thing about public and private keys not made entirely clear thus far. We know that a message encrypted with a public key is only decipherable by means of the private key. However, the reverse is also true: information encrypted with the private key is only decipherable with the public key. This is the mechanism used as part of the authentication process. Since the public key can only be used to decrypt cipher text generated using the private key, then if we can correctly decrypt a message using the public key, it proves that whoever encrypted it had access to the private key (which should only be accessible by the true owner of the public-private key pair).

The exact way the Public Key is used varies according to the Authentication algorithm selected as part of the Cipher Suite. Generally, the process is something like:

* The server sends its certificate, which contains its *public* key
* The server creates a 'signature' in the form of some data encrypted with the server's *private* key
* The signature is transmitted to the client in a message along with the original data from which the signature was created
* On receipt of the message, the client decrypts the signature using the server's *public* key and compares the decrypted data to the original version
* If the two versions match then the encrypted version could only have been created by a party in possession of the private key

'Following a process such as this, we can identify that the server which provided the certificate during the initial part of the TLS Handshake is in possession of the private key, and therefore the actual owner of the certificate.'

However, what is to stop a malicious third-party creating a key pair and a certificate claiming to be, say, a bank? It is certainly possible to create a fake digital certificate. How do we know if a certificate is genuine or not? This is where Certificate Authorities come in.



So the certificate and signature exchange proves that the server is the owner of that certificate. The certificate authority must verify that the certificate correctly identifies a real-world actor/entity.



**<u>Certificate Authorities and the Chain of Trust</u>**

* Certificate Authorities (CA) issue identification/authorization certificates
* When a CA issues a certificate, it does two important things:
  1. **Verifies that the party requesting the certificate is who they say they are** - The way that this is done is up to the CA and will depend to an extent on the type of certificate being issued. In the case of a domain validated server certificate, for example, it can involve proving that you own the domain by uploading a specific file to a server that is accessible by the domain for which the certificate is being issued.
  2. **Digitally signs the certificate being issued** - This is often done by encrypting some data with the CA's own private key and using this encrypted data as a 'signature'. The unencrypted version of the data is also added to the certificate. In order to verify that the certificate was issed by the CA, the signature can be decrypted using the CA's public key and checked for a match against the unencrypted version.
* There are different levels of CA. An 'Intermediate CA' can be any company or body authorized by a 'Root CA' to issue certificates on its behalf. A widely-used Intermediate CA is Let's Encrypt, who provide free, automated certificates
* Root CAs have Root Certificates. Root Certificates are self-signed and are essentially the end-point of the chain of trust
* Client software, such as browsers store a list of these Root Authorities along with their Root Certificates, which contain their public key. When receiving a certificate for checking, the browser can go up the chain of trust to the Root Certificate stored in its list
* Root CAs are essentially a small group of organizations approved by browser and operating system vendors

## 5:6 TLS Integrity ##

**<u>TLS Encapsulation</u>**

* The OSI model defines TLS as a Session Layer protocol
* It can be useful to think of TLS as operating between HTTP (Application Layer) and TCP (Transport Layer)
* Like other protocols, TLS sends messages in a certain format. This format can vary depending on the particular function that TLS is performing
* When transporting application data, TLS encapsulates that data in the same way as with other Protocol Data Units
* Data from the layer above is encapsulated as a data payload, and TLS attaches meta data in header and trailer fields
* The TLS PDU is known as a TLS Record



* TLS Record
  * Header
    * Content Type
    * TLS Version
    * Length
  * Data Payload
  * Trailer
    * MAC - Message Authentication Code
    * Padding

Note that despite sharing the same acronym, the Message Authentication Code is completely unrelated to Medium Access Control addressing.



**<u>Message Authentication Code (MAC)</u>**

'The MAC field is similar in concept to the checksum fields we've already seen in other PDUs, although there is a difference in implementation as well as overall intention. The checksum field in, say, a TCP Segment is intended for error detection (i.e. to test if some data was corrupted during transport). The intention of the MAC field in a TLS record is to add a layer of security by providing a means of checking that the message hasn't been altered or tampered with in transit.'

Aside: In the following, the 'digest' and the data in the MAC field are treated as the same thing. Technically, a *digest* is the fixed-size output of a hash algorithm, whereas the MAC process uses more information to produce the actual MAC code sent in the MAC field. So although related, they aren't actually the same thing.

This is implemented through the use of a cryptographic hashing algorithm that works something like:

1. The sender creates a 'digest' of the data payload. This is effectively a small amount of data derived from the actual data payload. The 'digest' is created using a specific hashing algorithm combined with a pre-agreed hash value. This hashing algorithm to be used and the hash value have been agreed as part of the TLS Handshake process when the Cipher Suite is negotiated.
2. The sender will then encrypt the data payload using the symmetric key, encapsulate it into a TLS record, and pass this record down to the Transport layer to be sent to the other party.
3. Upon receipt of the message, the receiver will decrypt the data payload using the symmetric key. The receiver will then also create a digest of the payload using the same algorithm and hash value. If the digest created by the receiver matches the digest received in the MAC field, this confirms the integrity of the message.



**<u>Summary</u>**

* HTTP Requests and Responses are transferred in *plain text*; as such they are *inherently insecure*.
* We can use the *Transport Layer Security* (TLS) Protocol to add security to HTTP communications.
* *TLS encryption* allows us to *encode messages* so that they can only be read by those with an authorized means of decoding the message.
* TLS encryption uses a combination of *Symmetric Key Encryption* and *Asymmetric Key Encryption*. Encryption of the initial key exchange is performed asymmetrically, and subsequent communications are symmetrically encrypted.
* The *TLS Handshake* is the process by which a client and a server *exchange encryption keys*.
* The TLS Handshake must be performed before secure data exchange can begin; it involves *several round-trips of latency* and therefore has an *impact on performance*.
* A *cipher suite* is the *agreed set of algorithms* used by the client and server during the secure message exchange.
* *TLS authentication* is a means of *verifying the identity* of a participant in a message exchange.
* TLS Authentication is implemented through the use of *Digital Certificates*.
* Certificates are signed by a Certificate Authority, and work on the basis of a *Chain of Trust* which leads to one of a small group of highly trusted *Root CAs*.
* The server's certificate is *sent* during the *TLS Handshake* process.
* *TLS Integrity* provides a means of *checking* whether a message has been *altered or interfered with* in transit.
* TLS Integrity is implemented through the use of a *Message Authentication Code* (MAC).



## Lesson 5 Quiz ##

Question 6:

'Certificates are generally signed by one CA. An  Intermediate CA will sign an end-user's certificate, and a Root CA will  sign the Intermediate CA's certificate. This creates the 'chain' in the  chain of trust.'

'There are actually many CAs. Most of them are Intermediate CAs, with a small, trusted group of Root CAs.'
