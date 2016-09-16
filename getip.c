/*
** getip.c -- a hostname lookup demo
*/

#include <arpa/inet.h>  // for inet_ntoa
#include <netdb.h>      // for gethostbyname, herror, hostent, h_addr
#include <stdio.h>      // for printf, fprintf, NULL, stderr
#include <stdlib.h>     // for exit

int main(int argc, char *argv[]) {
    struct hostent *h;

    if (argc != 2) { // error check the command line
        fprintf(stderr, "usage: getip address\n");
        exit(1);
    }

    if ((h = gethostbyname(argv[1])) == NULL) { // get the host info
        herror("gethostbyname");
        exit(1);
    }

    printf("Host name  : %s\n", h->h_name);
    printf("IP Address : %s\n", inet_ntoa(*((struct in_addr *)h->h_addr)));

    return 0;
}
