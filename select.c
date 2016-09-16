/*
** select.c -- a select() demo
*/

#include <stdio.h>       // for printf, NULL
#include <sys/select.h>  // for select, FD_ISSET, FD_SET, FD_ZERO, fd_set
#include <sys/time.h>    // for timeval

#define STDIN 0 // file descriptor for standard input

int main(void) {
    struct timeval tv;
    fd_set readfds;

    tv.tv_sec = 2;
    tv.tv_usec = 500000;

    FD_ZERO(&readfds);
    FD_SET(STDIN, &readfds);

    // don't care about writefds and exceptfds:
    select(STDIN + 1, &readfds, NULL, NULL, &tv);

    if (FD_ISSET(STDIN, &readfds)) {
        printf("A key was pressed!\n");
    } else {
        printf("Timed out.\n");
    }

    return 0;
}
