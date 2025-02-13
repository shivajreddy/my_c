// ==================================================
// server
// ==================================================
#include <stdio.h>
#include <stdlib.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define N 4096

char buffer[N];

int main() {

  struct sockaddr_in local;
  local.sin_family = AF_INET;
  inet_pton(AF_INET, "127.0.0.1", &local.sin_addr);
  // inet_pton(AF_INET, "0.0.0.0", &local.sin_addr);
  local.sin_port = ntohs(6969);

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  bind(sock, (void *)&local, sizeof(local));
  listen(sock, 128);
  int client = accept(sock, NULL, NULL);

  write(client, "220 welcome\n", 13);

  int bytesRead = 0, res;
  for (;;) {
    res = read(client, buffer, sizeof(buffer));
    if (res < 0) {
      perror("read");
      // exit(1);
    }
    if (!res)
      break;

    bytesRead += res;
  }

  printf("bytes read: %d \n", bytesRead);

  return EXIT_SUCCESS;
}
