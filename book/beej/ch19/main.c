#include <stdio.h>

#define HELLO

int main(void) {
  printf("hello\n");
  printf("hello\n");

#ifdef HELLO
  printf("HEllo is defined");
#else
  printf("HEllo is not-defined");
#endif

  return 0;
}
