#include <errno.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_PORT 4221

int main() {

  int server_fd;

  // domain = AF_INET, type = stream-socket, protocol=> 0 means use default
  // default protocol for stream-socket is TCP
  // default protocol for datagram-socket is UDP
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == -1) {
    printf("Socket creation failed: %s...\n", strerror(errno));
    return 1;
  }

  // Since the tester restarts your program quite often,
  // setting SO_REUSEADDR ensures to not run into 'Address already in use'
  int reuse = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) <
      0) {
    printf("SO_REUSEADDR failed: %s \n", strerror(errno));
    return 1;
  }

  // Create the server's socket address
  const struct sockaddr_in serv_addr = {
      .sin_family = AF_INET,
      .sin_port = htons(SERVER_PORT),
      .sin_addr = {htonl(INADDR_ANY)}, // u32
  };

  socklen_t len = sizeof(serv_addr);

  // Bind the address to the fd
  int binding_result = bind(server_fd, (struct sockaddr *)&serv_addr, len);
  if (binding_result != 0) {
    printf("Bind failed: %s \n", strerror(errno));
    return 1;
  }

  int connection_backlog = 5;
  // Start listening for requests
  int listen_result = listen(server_fd, connection_backlog);
  if (listen_result != 0) {
    printf("Listen failed: %s \n", strerror(errno));
    return 1;
  }

  struct sockaddr_in client_addr;
  int client_addr_len;

  printf("Waiting for a client to connect...\n");
  client_addr_len = sizeof(client_addr);

  // keep accepting requests
  system("clear"); // clearn console
  int total_handled_requests = 1;
  for (;;) {
    // Accept a client connection
    int client_fd;
    client_fd =
        accept(server_fd, (void *)&client_addr, (void *)&client_addr_len);
    printf("client_fd: %d\n", client_fd);

    if (client_fd == -1) {
      printf("ERROR: %s\n", strerror(errno));
      continue;
    }

    printf("CLIENT CONNECTED\n");

    // Read the request from client
    char buffer[100]; // buffer to read client data
    read(client_fd, buffer, sizeof(buffer));
    printf("Received request: %s\n", buffer);

    // Send HTTP Response
    const char *response =
        "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!";
    ssize_t response_result = send(client_fd, response, strlen(response), 0);

    printf("Response result: %ld\n", response_result);
    total_handled_requests += 1;
    printf("total_handled_requests: %d\n", total_handled_requests);

    // close clinet connection
    close(client_fd);
  }

  close(server_fd);

  return 0;
}
