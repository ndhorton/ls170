# URLs

* Be able to identify the components of a URL, including query strings
* Be able to construct a valid URL
* Have an understanding of what URL encoding is and when it might be used



## Be able to identify the components of a URL, including query strings

3:4 **<u>HTTP Book: What is a URL?</u>**

**<u>URL Components</u>**

* **scheme** -- comes before the colon and two forward slashes and tells the web client how to access the resource, e.g. `http`
* **host** -- where the resource is hosted or located, e.g. a domain name like `www.google.com`
* **port** -- the TCP port number, only needed if you want to use a port other than the default
* **path** -- shows what local (to the given host) resource is being requested
* **query string** -- used to send data to the server
  * **query parameters**

The non-optional parts of a URL are **scheme** and **host**. Obviously modern web browser can often find the right scheme if we only type in the host, but the browser must fill in the missing scheme, in a similar way to adding the default port.

**<u>Query Strings/Query Parameters</u>**

* Parts of a query string:

  * `?` -- reserved character that marks the start of the query string

  * `this=that` -- a query parameter name/value pair

  * `&` -- query string separator, a reserved character used when adding more query parameter key/value pairs to the query string

* How the server uses query parameters is up to the server side application.

* Because query strings are passed in through the URL, they are ordinarily only used in HTTP GET requests
  * POST requests do allow query strings, but it is relatively uncommon and shouldn't be used with any info you would not want logged somewhere
* Whenever you type in a URL into the address bar of your browser, you're issuing HTTP GET requests

* Query strings are great to pass in additional information to the server, but there are limits to the use of query strings
  * Query strings have a maximum length. Therefore, if you have a lot of data to pass on, you will not be able to do so with query strings
  * The name/value pairs used in query strings are visible in the URL. For this reason, passing sensitive information like username or password to the server in this manner is not recommended
  * Space and special characters like `&` cannot be used with query strings. They must be URL encoded



## Be able to construct a valid URL







## Have an understanding of what URL encoding is and when it might be used

3:4 **<u>HTTP book: What is a URL?</u>**

**<u>URL Encoding</u>**

* URLs are designed to accept only certain characters in the standard 128-character ASCII character set
* Reserved or unsafe ASCII characters that are not being used for their intended purpose, as well as characters not in the US-ASCII set, have to be encoded
* URL encoding serves the purpose of replacing these non-conforming characters with a `%` symbol followed by two hexadecimal digits that represent the equivalent UTF-8 character
* Each byte in a UTF-8 codepoint gets represented with another `%` followed by the next two hexadecimal digits, e.g. a `£` character becomes `%C2%A3`. Since UTF-8 can be up to four bytes, we can have four `%FF` byte representations together representing a single UTF-8 character, e.g. the character `𐍈` is represented as `%F0%90%8D%88`
* All UTF-8 characters in the extended ASCII character set have single byte UTF-8 codes
* Characters **must** be encoded if
  * They have no corresponding character within the standard ASCII character set. This includes all extended ASCII characters, and all UTF-8 characters that have 2-, 3-, and 4-byte UTF-8 codes
  * The use of the character is unsafe since it may be misinterpreted or modified by some systems. For example, `%` is unsafe since it is used to encode other characters. Other unsafe characters include spaces, quotation marks, the `#` character, `<` and `>`, `{` and `}`, `[` and `]`, and `~`, among others
  * The character is reserved for special use within the URL scheme. Some characters are reserved for a special meaning; their presence in a URL serves a specific purpose. Characters such as `/`, `?`, `:`, `@`, and `&` are all reserved and must be encoded. For example `&` is reserved for use as a query string delimiter. `:` is also reserved to delimit host/port components and user/password
* The only characters that do not need to be encoded are
  * Alphanumeric characters and the characters `$ - _ . + ! ' ( ) " ,` [I'm aware that above it says quotation marks *do* need to be encoded! Quotes are considered unsafe in an HTML context, when the `href` URL is enclosed in quotes, so they should be encoded as well]
  * Reserved characters when used for their special purpose. If they are not being used for their reserved purpose, they must be encoded



From Wikipedia 'Percent-encoding':

* URL encoding, officially known as **percent-encoding**, is a method to encode arbitrary data in a URI
* Only US-ASCII characters are legal in a URI
* The characters allowed in a URI are either *reserved* or *unreserved* (or a percent character as part of a percent-encoding)
  * Reserved characters sometimes or always have a special meaning, e.g. a `/` character separates different parts of a path in a URL
    * Exactly which characters have special meanings partly depends on the scheme, and has also changed as the URI spec has been revised over the years
  * Unreserved characters have no such meanings
* Using percent-encoding, reserved characters are represented using special character sequences
  * We convert the character to its numeric code in US-ASCII hexadecimal representation and if it is a single digit we must add a leading `0`
  * This number is then prefixed with `%`
  * So, e.g., `/` becomes `%2F` or `%2f` (either case will work but upper case is preferred by W3C)



