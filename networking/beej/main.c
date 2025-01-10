#include <arpa/inet.h>
#include <fcntl.h> // For open()
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // for read() write() close()

#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUFFER_SIZE 256

int main() {
  puts("NETWORKING");

<<<<<<< HEAD
  struct sockaddr_in sa;
  inet_pton(AF_INET, "10.12.110.57", &(sa.sin_addr));

  // getaddrinfo();
=======
  int status;
  struct addrinfo hints = {.ai_family = AF_UNSPEC,
                           .ai_socktype = SOCK_STREAM,
                           .ai_flags = AI_PASSIVE};
  struct addrinfo *servinfo; // will point to the reslts

  memset(&hints, 0, sizeof hints);

  if ((status = getaddrinfo(NULL, "3490", &hints, &servinfo)) != 0) {
    fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
    exit(1);
  }

  freeaddrinfo(servinfo);
>>>>>>> refs/remotes/origin/main

  return EXIT_SUCCESS;
}
