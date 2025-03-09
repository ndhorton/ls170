#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#include <stdio.h>
#include <string.h>

int main(void)
{
        int sockfd;
        struct addrinfo hints;
        struct addrinfo *res;

        memset(&hints, 0, sizeof hints);
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_PASSIVE;

        getaddrinfo(NULL, "3490", &hints, &res);

        // make a socket
        sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

        // allow port to be reused if the port fd has not yet been released by the kernel
        int yes=1;
        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes) == -1) {
                perror("setsockopt");
                return 1;
        }

        // bind it to the port we passed in to getaddrinfo()
        bind(sockfd, res->ai_addr, res->ai_addrlen);

        close(sockfd);
}

