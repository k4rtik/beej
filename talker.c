/*
** talker.c -- a datagram "client" demo
*/

#include <netdb.h>             // for addrinfo, freeaddrinfo, gai_strerror
#include <stdio.h>             // for fprintf, stderr, NULL, perror, printf
#include <stdlib.h>            // for exit
#include <string.h>            // for memset
#include <sys/socket.h>        // for socket, AF_UNSPEC
#include <unistd.h>            // for close

#define SERVERPORT "4950" // the port users will be connecting to

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    int numbytes;

    if (argc != 3) {
        fprintf(stderr, "usage: talker hostname message\n");
        exit(1);
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    if ((rv = getaddrinfo(argv[1], SERVERPORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // loop through all the results and make a socket
    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) ==
            -1) {
            perror("talker: socket");
            continue;
        }

        break;
    }

    if (p == NULL) {
        freeaddrinfo(servinfo);
        fprintf(stderr, "talker: failed to create socket\n");
        return 2;
    }

    if ((numbytes = sendto(sockfd, argv[2], strlen(argv[2]), 0, p->ai_addr,
                           p->ai_addrlen)) == -1) {
        perror("talker: sendto");
        exit(1);
    }

    freeaddrinfo(servinfo);

    printf("talker: sent %d bytes to %s\n", numbytes, argv[1]);
    close(sockfd);

    return 0;
}
