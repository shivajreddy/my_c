#include <netdb.h>
#include <netinet/in.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

void error(const char* message) {
    perror(message);
    exit(1);
}

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <termios.h>
#include <unistd.h>

// Put terminal in raw mode
void enable_raw_mode(struct termios* orig_termios) {
    tcgetattr(STDIN_FILENO, orig_termios); // get current settings
    struct termios raw = *orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO); // disable canonical mode & echo
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

// Restore terminal settings
void disable_raw_mode(struct termios* orig_termios) {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, orig_termios);
}

int client(const char* host_name, int port_num) {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) perror("Failed to create sock_fd inside client");

    struct hostent* server = gethostbyname(host_name);
    if (server == NULL) perror("There is no such host");

    struct sockaddr_in server_addr = { 0 };
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(port_num);

    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) <
        0)
        perror("Error connecting");

    printf("Connected! Start typing (press Ctrl+C to quit)\n");

    struct termios orig_termios;
    enable_raw_mode(&orig_termios);

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1) {
        if (write(sock_fd, &c, 1) < 0) {
            perror("Error writing to socket");
            break;
        }
    }

    disable_raw_mode(&orig_termios);
    close(sock_fd);
    return 0;
}

// Create Client
int client2(const char* host_name, int port_num) {

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) error("Failed to create sock_fd inside client");
    printf("Log: CLIENT::Created sock_fd\n");

    struct hostent* server = gethostbyname(host_name);
    if (server == NULL) error("There is no such host");

    struct sockaddr_in server_addr = { 0 };
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    // server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_num);

    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) <
        0)
        error("Error connecting");
    printf("Successfully connected to the given host\n");

    // Main Loop: Monitor both stdin and the socket
    fd_set read_fds;
    char buffer[256] = { 0 };

    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(STDIN_FILENO, &read_fds);
        FD_SET(sock_fd, &read_fds);
        int max_fd = (sock_fd > STDIN_FILENO ? sock_fd : STDIN_FILENO) + 1;

        if (select(max_fd, &read_fds, NULL, NULL, NULL) < 0) {
            perror("ERRRRRRRRROR");
            break;
        }

        // if user typed something
        if (FD_ISSET(STDIN_FILENO, &read_fds)) {
            memset(buffer, 0, sizeof(buffer));
            if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                printf("EOF on stdin, exiting\n");
                break;
            }
            if (write(sock_fd, buffer, strlen(buffer)) < 0) {
                perror("ERRR WRITE TO SERVER");
                break;
            }
        }
        // if server sent something
        if (FD_ISSET(sock_fd, &read_fds)) {
            memset(buffer, 0, sizeof(buffer));
            if (read(sock_fd, buffer, sizeof(buffer) - 1) <= 0) {
                printf("Server closed connection\n");
                break;
            }
            printf("Server: %s\n", buffer);
            fflush(stdout);
        }
    }

    /*
    printf("Please enter message\n");
    fgets(buffer, sizeof(buffer), stdin);

    if (write(sock_fd, buffer, strlen(buffer)) < 0)
        error("Error writing message to socket");

    memset(buffer, 0, sizeof(buffer));

    if (read(sock_fd, buffer, sizeof(buffer)) < 0)
        error("Error reading from socket");

    printf("Got Message: %s\n", buffer);
    */

    close(sock_fd);

    return 0;
}

int main() {
    printf("PLAYGROUND\n");

    client("localhost", 9188);

    return 0;
}
