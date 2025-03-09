#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
        struct addrinfo hints;
        struct addrinfo *res;
        int sockfd;

        // first load up address structs with getaddrinfo()

        memset(&hints, 0, sizeof hints);
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;

        getaddrinfo("www.google.com", "80", &hints, &res);

        // make a socket

        sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

        // connect!

        connect(sockfd, res->ai_addr, res->ai_addrlen);

        char request[64] = "GET / HTTP/1.0\r\n\r\n";
        send(sockfd, request, strlen(request), 0);
        
        char buffer[1024];
        int bytes_received = 0;

        while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
                buffer[bytes_received] = '\0';
                printf("%s", buffer);
                fflush(stdout);
        }

        if (bytes_received < 0) {
                perror("recv failed");
        }

        close(sockfd);
}
