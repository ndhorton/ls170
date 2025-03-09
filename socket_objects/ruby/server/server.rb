#!/bin/env ruby

# For TCP servers we use the TCPServer class

require 'socket'

begin
  server = TCPServer.new 2000  # server bind to port 2000
  loop do
    client = server.accept  # listen for client
    client.puts(Time.now)
    client.puts("Hi there")
    5.times do
      client.puts "."
      sleep 1
    end
    client.puts
    client.puts("Closing the connection. Later!")
    client.close
  end
ensure
  server.close
  puts "Server connection closed"
end

