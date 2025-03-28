# 1

Required components

* Method
* Path (inclding query parameters)
* From HTTP/1.1 onward, we need a Host header
* From HTTP/1.0 onward, we need the HTTP version

Additional components

* Additional headers
* For certain methods like POST, a Body

# 2

Required components

* Status code and status text (the status text has been dropped in HTTP/2
onward)

Additional components

* Headers
* Body

# 3

GET is the default or most common request method. The browser makes a GET
request when entering a URL or clicking a link. GET requests are used to
retrieve data from the server, e.g. a web page.

POST requests are used to send data back to the server, e.g. submitting a form.

Search forms are an exception to this rule, in that they typically use GET
requests to send data as query parameters.
