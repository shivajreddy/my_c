#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(const char *s1, const char *s2);
void print_str(const char *s);

int main() {

  // int arr[7] = {10, 20, 30, 40, 50, 60, 70};
  // int arr[7] = {0, 0, 0, 0, 0, 0, 0};
  int arr[7] = {-3, -2, -2, -1, 0, 8, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  // printf("%d\n", n);

  int *l, *r;

  l = arr + (n / 2);
  printf("%d \n", *l);
  while (l >= arr) {
    if (*l > 0)
      break;
    l--;
  }
  printf("%d \n", *l);

  r = arr + n / 2;
  printf("r:%d \n", *r);
  while (r <= arr + n) {
    if (*r > 0)
      break;
    r++;
  }
  printf("%d \n", *r);

  return 0;
  int *p;

  p = arr + 1;
  printf("%d\n", *p);

  // printf("%d\n", *(p + 3 / 2));

  // create an array of strings

  char *word1 = "hello";
  char *word2 = "there";
  char *word3 = "world!";

  /*
  const char *arr[10];
  arr[0] = "hello there";

  printf("%p \n", arr);
  printf("%s \n", arr[0]);
  printf("%s \n", arr[1]);
  printf("%s \n", arr[3]);

  printf("%d \n", *arr[0] == '\0');

  char *empty = "";
  printf("%c \n", *empty);
  */

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

  // const char *sentence = "hello \nwow, this is a long sentence huh";
  // print_str(sentence);

  /*
  void *p;
  p = malloc(999999999999999999);
  // p = malloc(50);

  if (!p)
    printf("ERROR Failed to allocate space\n");

  printf("%lu\n", sizeof(p));
  printf("%d\n", *(int *)p);
  */

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
  // int n = strlen(s);
  // while (p < s + n - 1)
  //   printf("%c", *p++);

  // p goes until the `null character`
  const char *p = s;
  while (*p != '\0')
    printf("%c", *p++);
}
