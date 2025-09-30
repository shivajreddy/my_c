#include <netinet/in.h>
#include <stdio.h>

int server(int portno);
int client(const char* hostname, int portno);

int main(void) {
    printf("SOCKET SERVER IN C\n");

    int id = server(9188);
    printf("id: %d\n", id);

    struct sockaddr serv_addr;

    /*
    int fd = socket(AF_INET6, SOCK_DGRAM | SOCK_NONBLOCK, 0);
    printf("res = %d\n", fd);

    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) return 1;
    if (flags & O_NONBLOCK) {
        printf("Socket is NON-BLOCKING \n");
    } else {
        printf("Socket is BLOCKING\n");
    }

    close(fd);
    */

    return 0;
}
