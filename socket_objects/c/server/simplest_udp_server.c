// server side program for UDP connection

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT    5000
#define MAXLINE 1000

// Driver code
int main(void)
{
        char buffer[100];
        char *message = "Hello Client";
        int listenfd;
        int len;
        struct sockaddr_in servaddr;
        struct sockaddr_in cliaddr;
        memset(&servaddr, 0, sizeof(servaddr));

        // Create a UDP socket
        listenfd = socket(AF_INET, SOCK_DGRAM, 0);
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        servaddr.sin_port = htons(PORT); // normalize byte order to Network Order (i.e. big-endian)
        servaddr.sin_family = AF_INET;

        // bind server address to socket descriptor
        bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

        // receive the datagram
        len = sizeof(cliaddr);
        int n = recvfrom(listenfd, buffer, sizeof(buffer),
                        0, (struct sockaddr*)&cliaddr, &len); // receive message
        buffer[n] = '\0';
        puts(buffer);

        // send the response
        sendto(listenfd, message, MAXLINE, 0,
                        (struct sockaddr*)&cliaddr, sizeof(cliaddr));
        
        close(listenfd);
        
        return 0;
}
