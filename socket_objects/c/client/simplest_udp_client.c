// server side program for UDP connection

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT    5000
#define MAXLINE 1000

// Driver code
int main(void)
{
        char buffer[100];
        char *message = "Hello Server";
        int sockfd;
        int n;
        struct sockaddr_in servaddr;
        
        // clear servaddr
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        servaddr.sin_port = htons(PORT);
        servaddr.sin_family = AF_INET;

        // create datagram socket
        sockfd = socket(AF_INET, SOCK_DGRAM, 0);

        // connect to server
        if (connect(sockfd, (struct sockaddr *)&servaddr,
                                sizeof(servaddr)) < 0) {
                printf("\n Error : Connect Failed \n");
                exit(EXIT_FAILURE);
        }

        // request to send datagram
        // no need to specify server address in sendto
        // connect stores the peers IP and port
        sendto(sockfd, message, MAXLINE, 0,
                        (struct sockaddr*)NULL, sizeof(servaddr));

        // waiting for response
        recvfrom(sockfd, buffer, sizeof(buffer), 0,
                        (struct sockaddr *)NULL, NULL);
        puts(buffer);

        // close the descriptor
        close(sockfd);

        return 0;
}
