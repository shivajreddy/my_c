#include <netdb.h>
#include <netinet/in.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

void error(const char* message) {
    perror(message);
    exit(1);
}

// Create Socket Server
int server3(int port_num) {
    int server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock_fd < 0) error("failed to create the initial socket");

    struct sockaddr_in server_addr = { 0 };
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_num);

    if (bind(server_sock_fd, (struct sockaddr*)&server_addr,
             sizeof(server_addr)) < 0)
        error("Failed to bind server_addr to socket_fd");

    printf("Successfully binded server_addr to server_sock_fd\n");

    const int BACKLOG_CONNECTIONS_LIMIT = 10;
    listen(server_sock_fd, BACKLOG_CONNECTIONS_LIMIT);

    while (1) {
        struct sockaddr_in client_addr = { 0 };
        socklen_t client_len = sizeof(client_addr);

        printf("Waiting for a client...\n");
        int client_sock_fd =
            accept(server_sock_fd, (struct sockaddr*)&client_addr, &client_len);

        if (client_sock_fd < 0) error("Couldn't accept connections on sock_fd");

        printf("Client connected!\n");

        // keep reading from this client until they disconnect
        while (1) {
            char buffer[256] = { 0 };
            ssize_t bytes_read =
                read(client_sock_fd, buffer, sizeof(buffer) - 1);

            if (bytes_read < 0) {
                error("Error reading from socket");
            } else if (bytes_read == 0) {
                // client disconnected
                printf("Client disconnected\n");
                break;
            }

            buffer[bytes_read] = '\0'; // make it a C string
            printf("%s", buffer);
            // printf("Client says: %s\n", buffer);

            const char* reply = "I got your message\n";
            if (write(client_sock_fd, reply, strlen(reply)) < 0)
                error("Error writing reply to client_sock_fd");
        }

        close(client_sock_fd); // done with this client
    }

    close(server_sock_fd);
    return 0;
}

// Create Socket Server
int server(int port_num) {
    // create socket in internet(domain), of type UDP with out locking
    // UDP specified its protocol, so leave the protocol arg as 0
    int server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    // int server_sock_fd = socket(AF_INET6, SOCK_STREAM | SOCK_NONBLOCK, 0);
    if (server_sock_fd < 0) error("failed to create the initial socket");

    // createinternet socket address for server
    struct sockaddr_in server_addr = { 0 };

    // set the values server socket address to internet-ip6-for given portno
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_num);

    printf("LOG: SERVER::created server_addr\n");

    // bind the server_address to the created socket
    // since server_addr is created with the type 'sockaddr_in', cast it to
    // the type 'sockaddr' because thats what 'bind' function expects
    if (bind(server_sock_fd, (struct sockaddr*)&server_addr,
             sizeof(server_addr)) < 0)
        error("Failed to bind server_addr to socket_fd");
    printf("Successfully binded server_addr to server_sock_fd\n");

    // Start Listening for connections
    const int BACKLOG_CONNECTIONS_LIMIT = 10;
    listen(server_sock_fd, BACKLOG_CONNECTIONS_LIMIT);

    while (1) {
        // create internet socket address for client
        struct sockaddr_in client_addr = { 0 };
        socklen_t client_len = sizeof(client_addr);

        printf("Going to start accepting connections now\n");
        int client_sock_fd =
            accept(server_sock_fd, (struct sockaddr*)&client_addr, &client_len);

        if (client_sock_fd < 0) error("Couldn't accept connections on sock_fd");

        // Read the data from socket, and put the data in the buffer
        char buffer[256] = { 0 };
        if (read(client_sock_fd, buffer, sizeof(buffer)) < 0)
            error("Error reading from socket");

        // Use the data from the socket
        printf("HERE IS THE MESSAGE: %s\n", buffer);

        // Write data to the socket
        const char* my_message = "I got your message";
        if (write(client_sock_fd, my_message, strlen(my_message)) < 0)
            error("Error writing my_message to client_sock_fd");

        close(client_sock_fd);
    }

    close(server_sock_fd);

    return 0;
}

// Create Client
int client(const char* host_name, int port_num) {

    int sock_fd = socket(AF_INET6, SOCK_STREAM | SOCK_NONBLOCK, 0);
    if (sock_fd < 0) error("Failed to create sock_fd inside client");

    struct hostent* server = gethostbyname(host_name);

    if (server == NULL) error("There is no such host");

    struct sockaddr_in server_addr = { 0 };
    server_addr.sin_family = AF_INET6;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_num);

    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) <
        0)
        error("Error connecting");

    printf("Please enter message");
    char buffer[256] = { 0 };
    fgets(buffer, sizeof(buffer), stdin);

    if (write(sock_fd, buffer, strlen(buffer)) < 0)
        error("Error writing message to socket");

    memset(buffer, 0, sizeof(buffer));

    if (read(sock_fd, buffer, sizeof(buffer)) < 0)
        error("Error reading from socket");

    printf("Got Message: %s\n", buffer);

    close(sock_fd);

    return 0;
}

int main(void) {
    printf("SOCKET SERVER IN C\n");

    int id = server(9188);
    printf("id: %d\n", id);

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
