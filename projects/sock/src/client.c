#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int client(const char* hostname, int portno) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent* server;

    char buffer[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr_list[0],
           server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Please enter the message: ");
    fgets(buffer, 255, stdin);

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    memset(buffer, 0, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    close(sockfd);
    return 0;
}
