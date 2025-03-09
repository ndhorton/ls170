#!/bin/env ruby

require 'socket'

begin
  server = TCPServer.new 2000
  loop do
    Thread.start(server.accept) do |client|
      client.puts "Hello!"
      client.puts "Time is #{Time.now}"
      10.times do
        client.puts '.'
        sleep 1
      end
      client.puts
      client.puts "Closing connection. Bye!"
      client.close
    end
  end
ensure
  server.close
  puts "Server socket closed"
end

