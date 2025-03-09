#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(void)
{
        struct addrinfo hints;
        struct addrinfo *servinfo;  // will point to the results
        
        memset(&hints, 0, sizeof(hints));        // zero the struct
        hints.ai_family = AF_UNSPEC;            // either IPv4 or IPv6
        hints.ad_socktype = SOCK_STREAM;        // TCP stream socket
        hints.ai_flags = AI_PASSIVE;            // sets with local IP address

        if ((status = getaddrinfo(NULL, "3490", &hints, &servinfo)) != 0) {
                fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
                exit(EXIT_FAILURE);
        }
        // servinfo now points to a linked list of 1 or more struct addrinfos


        // free the linked-list of addrinfo nodes
        freeaddrinfo(servinfo); 
}
