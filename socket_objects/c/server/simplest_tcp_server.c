// Server side C program with TCP socket

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const* argv[])
{
        int server_fd; // socket object for listening socket
        int new_socket; // socket object for active connection socket
        ssize_t valread;
        struct sockaddr_in address;
        int opt = 1;
        socklen_t addrlen = sizeof(address);
        char buffer[1024] = { 0 };
        char* hello = "Hello from server";

        // Creating socket file descriptor -- socket()
        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
                        perror("socket() failed");
                        exit(EXIT_FAILURE);
        }

        // Configuring socket -- setsockopt()
        if (setsockopt(server_fd, SOL_SOCKET,
                                SO_REUSEADDR | SO_REUSEPORT, &opt,
                                sizeof(opt)))
        {
                perror("setsockopt() failed");
                exit(EXIT_FAILURE);
        }

        // Configure address struct
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);

        // attaching socket to the port 8080 -- bind()
        if (bind(server_fd, (struct sockaddr*)&address,
                                sizeof(address))
                        < 0)
        {
                perror("bind() failed");
                exit(EXIT_FAILURE);
        }
        // listen()
        if (listen(server_fd, 3) < 0)
        {
                perror("listen() failed");
                exit(EXIT_FAILURE);
        }
        // accept()
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address,
                                        &addrlen))
                        < 0) 
        {
                perror("accept() failed");
                exit(EXIT_FAILURE);
        }
        valread = read(new_socket, buffer, 1024 - 1);
        printf("%s\n", buffer);
        send(new_socket, hello, strlen(hello), 0);
        printf("Hello message sent\n");

        // closing the connected socket
        close(new_socket);
        // closing the listening socket
        close(server_fd);

        return 0;
}

