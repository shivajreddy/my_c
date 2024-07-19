#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int *arr, int n);

bool is_palidrome(char *s) {
  char *p = s;
  return true;
}

int main() {
  int arr[3] = {10, 20, 30};
  // print_array(arr, 3);

  int *p = arr;
  //
  // while (p < arr + 3)
  //   printf("%d ", *p++);

  printf("%d", p[22]);

  // while (p < arr + 3)
  //   printf("%d ", *p++ = -31);

  /*
  int arr[3] = {10, 20, 30}, x = 20;
  print_array(arr, 3);

  for (int *p = arr; p < arr + 3; p++)
    *p = -31;

  print_array(arr, 3);
  */

  /*
  srand(time(NULL));

  int arr[10] = {};

  int *ptr = &arr[10 / 2];

  while (ptr++ < &arr[10]) {
    *ptr = rand() % 10;
  }

  // print array
  for (int idx = 0; idx < 10; idx++) {
    printf("%d ", arr[idx]);
  }

  printf("\n");

  int *p, *q;
  p = arr;
  q = arr - 2;

  int result = p >= q;

  printf("result: %d", result);
  */

  // *++p
  // *(++p)

  /*
  int arr[3] = {8, 97, 62};
  print_array(arr, 3);

  int *p = arr;

  printf("p=%p\n", p);
  printf("*p=%d\n", *p);

  // *p++ is same as  returning *p; then p = p+1;
  // printf("*p++%d\n", *p++);
  // printf("*p=%d\n", *p);

  // *p++ += 1;
  // *p++ += 1;
  printf("p=%p\n", p);
  printf("*p=%d\n", *p);

  print_array(arr, 3);
  */
}

void print_array(int *arr, int n) {
  for (int idx = 0; idx < n; idx++) {
    printf("%d ", arr[idx]);
  }
  printf("\n");
}
