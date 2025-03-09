#!/bin/env ruby

# Ruby's Socket class features five important methods:
#   * sock.bind(addr) -- binds the socket to the packed address string
#   * sock.listen(backlog) -- places socket in listening state
#   * sock.accept -- accepts a new connection (returns a new socket)
#   * sock.connect(addr) -- connects the socket to a host/port
#   * sock.recvfrom(len[,flags]) -- receives data from the socket,
#       and returns a string containing the data and peer address

# For TCP client connections, we use the TCPSocket class
# Once we have a socket open, we can read from it like any IO object
# We must close it like a file

require 'socket'

hostname = 'localhost'
port = 2000

sock = TCPSocket.new hostname, port  # opens a TCP connection to localhost:2000

while line = sock.gets
  puts line
end
sock.close

