// Client side C program with TCP socket

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const* argv[])
{
        int status;
        int valread;
        int client_fd; // socket object
        struct sockaddr_in serv_addr;
        char* hello = "hello from client";
        char buffer[1024] = { 0 };

        // create socket with socket()
        if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                printf("\n Socket creation error \n");
                return -1;
        }

        // Configure server address struct
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT);

        // Convert IPv4 and IPv6 addresses from text to binary form
        if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
                printf("\n Invalid address / Address not supported \n");
                return -1;
        }

        // connect()
        if ((status = connect(client_fd, (struct sockaddr*)&serv_addr,
                                        sizeof(serv_addr)))
                        < 0) {
                printf("\n Connection failed \n");
                return -1;
        }

        send(client_fd, hello, strlen(hello), 0);
        printf("Hello message sent\n");
        valread = read(client_fd, buffer, 1024 - 1);
        printf("%s\n", buffer);

        // closing the connected socket
        close(client_fd);

        return 0;
}
