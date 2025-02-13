// ==================================================
// client
// ==================================================
#include <memory.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define N 1000000

char buffer[N];

int main() {
  int sock = socket(AF_INET, SOCK_STREAM, 0);

  memset(buffer, 'f', sizeof(buffer));

  struct sockaddr_in remote;
  remote.sin_family = AF_INET;
  inet_pton(AF_INET, "127.0.0.1", &remote.sin_addr);
  // inet_pton(AF_INET, "0.0.0.0", &remote.sin_addr);

  remote.sin_port = htons(6969);

  connect(sock, (void *)&remote, sizeof(remote));
  write(sock, buffer, sizeof(buffer));
  close(sock);
  return 0;
}
