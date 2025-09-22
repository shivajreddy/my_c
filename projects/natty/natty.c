#include <fcntl.h>
#include <pty.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <unistd.h>

// master file descriptor
static int32_t masterfd;

int main(void) {
    char* file_name = "test.txt";
    int fd = open(file_name, O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "Failed to open %s", file_name);
        exit(1);
    }

    char buf[100];
    int n = read(fd, buf, sizeof(buf));
    write(1, buf, n);

    return 0;
}

int mains(void) {

    if (forkpty(&masterfd, NULL, NULL, NULL) == 0) {
        execlp("/usr/bin/bash", "bash", NULL);
        perror("execlp");
        return EXIT_FAILURE;
    }

    int fd = open("test2.txt", O_RDONLY);
    printf("fd=%i\n", fd);

    bool running = true;
    fd_set fdset;
    while (!running) {
        FD_ZERO(&fdset);
        FD_SET(masterfd, &fdset);

        select(masterfd + 1, &fdset, NULL, NULL, NULL);
    }

    printf("Hello there\n");
    return EXIT_SUCCESS;
}
