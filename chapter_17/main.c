#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(const char *s1, const char *s2);
void print_str(const char *s);

int main() {
  // NULL_POINTER is defined in 6 header files (incuding stdlib.h)
  // malloc is defined in stdlib header file

  /*
  malloc  -> allocates space, DOESN'T INITIALIZE, DOESN't CLEAR SPACE
  calloc  -> allocates space, DOESN'T INITIALIZE
  realloc -> reserves a previously allocated block of memory

  malloc signature
  void *malloc(size_t __size);
  hi
  */

  const char *sentence = "hello \nwow, this is a long sentence huh";
  print_str(sentence);

  void *p;
  p = malloc(999999999999999999);
  // p = malloc(50);

  if (!p)
    printf("ERROR Failed to allocate space\n");

  printf("%lu\n", sizeof(p));
  printf("%d\n", *(int *)p);

  /*
  int arr[5] = {97, 'A', 30, 40};

  void *p;

  p = arr + 1;

  printf("%d \n", *(int *)p);
  printf("%c \n", *(char *)p);
  */
}

char *concat(const char *s1, const char *s2) {
  char *result;

  result = malloc(strlen(s1) + strlen(s2) + 1);

  if (result == NULL) {
    printf("ERROR: Failed to allocated size");
    exit(EXIT_FAILURE);
  }

  strcpy(result, s1);
  strcat(result, s2);

  return result;
}

void print_str(const char *s) {
  int n = strlen(s);
  const char *p = s;

  // while (p < s + n - 1)
  //   printf("%c", *p++);

  // p goes until the `null character`
  while (*p != '\0')
    printf("%c", *p++);
}
