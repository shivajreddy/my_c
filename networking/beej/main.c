#include <fcntl.h> // For open()
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for read() write() close()

#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUFFER_SIZE 256

int main() {
  puts("NETWORKING");

  struct sockaddr_in sa;
  inet_pton(AF_INET, "10.12.110.57", &(sa.sin_addr));

  // getaddrinfo();

  return EXIT_SUCCESS;
}
