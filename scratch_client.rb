require 'socket'

s = TCPSocket.new 'localhost', 2000

while line = s.gets  # reads line from socket
  puts line
end

s.close
