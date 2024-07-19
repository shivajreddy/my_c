#include <stdarg.h>
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

void printd(int num, ...);

int main() {

  int arr[4] = {-78, 56, 12, 67};

  int *p1 = arr;

  // while (p1 < arr + 4) {
  //   printd(*p1++);
  // }

  int x;
  for (x = 0; x < x + 10; x++)
    printd(x);

  // while (x < x + 9)
  //   printd(x);

  /*
  char *input = "aaaabaaaa";

  printf("%d\n", is_palidrome(input));

  const char *my_string = "asldkfjlasdjf lasjf";
  printf(my_string);
  */
}

// default params in C?
void printd(int num, ...) {
  va_list args;
  va_start(args, num);

  int second_arg = va_arg(args, int);
  va_end(args);

  // printf("%d", num);
  if (second_arg) {
    printf("%d\n", num);
  } else {
    printf("%d", num);
  }
}
