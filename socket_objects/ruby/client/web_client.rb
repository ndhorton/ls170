#!/bin/env ruby

require 'socket'

path = "/index.html"
request = "GET #{path} HTTP/1.0\r\n\r\n"

sock = TCPSocket.new 'www.google.com', 80
sock.print(request)
response = sock.read
headers, body = response.split("\r\n\r\n", 2)
puts headers
puts body
sock.close

