#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MYPORT "3490"   // the port users will be connecting to
#define BACKLOG 20      // how many pending connections queue will hold

int main(void)
{
        struct sockaddr_storage their_addr;
        socklen_t addr_size;
        struct addrinfo hints;
        struct addrinfo *res;
        int sockfd;
        int new_fd;

        // don't forget error checking when doing this for real!

        // first, load up address structs with getaddrinfo()
        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_PASSIVE;

        getaddrinfo(NULL, MYPORT, &hints, &res);

        // make a socket, bind it, and listen on it
        sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        bind(sockfd, res->ai_addr, res->ai_addrlen);
        listen(sockfd, BACKLOG);

        // now accept an incoming connection
        addr_size = sizeof(their_addr);
        new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);

        // ready to communicate on socket descriptor new_fd

        close(new_fd);
        close(sockfd);
}

