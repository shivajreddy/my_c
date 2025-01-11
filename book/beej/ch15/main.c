#include <stdio.h>
#include <stdlib.h>

int main() {

  char* s = "2490";

  unsigned long int x = strtoul(s, NULL, 10);
  printf("%lu\n", x);

  int y = strtol("2183947", NULL, 10);
  printf("%d\n", y);

  return 0;
}
