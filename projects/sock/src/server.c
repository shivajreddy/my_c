/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int server(int portno) {
    int sockfd, newsockfd;
    socklen_t clilen;
    char buffer[256];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /*
    struct sockaddr_in serv_addr = { .sin_family = AF_INET6,
                                     .sin_addr.s_addr = INADDR_ANY,
                                     .sin_port = htons(portno) };
    */
    struct sockaddr* serv_addr = malloc(sizeof(struct sockaddr));
    serv_addr->sin_family = AF_INET6;
    serv_addr->struct sockaddr_in cli_addr;

    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    memset(buffer, 0, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Here is the message: %s\n", buffer);

    n = write(newsockfd, "I got your message", 18);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}
