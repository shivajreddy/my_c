#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_palidrome(char *s) {
  char *e = s + strlen(s) - 1;
  while (s < e)
    if (*s++ != *e--)
      return false;
  return true;
}

int main() {

  char *input = "aaaabaaaa";

  printf("%d\n", is_palidrome(input));
}
