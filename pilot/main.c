#include <stdio.h>
#include "math.h"

int main(void) {

  char letters[10] = {'f', 'a', 'm', 'i', 'l', 'a', 'r' };

  printf("%p\n", letters);
  printf("%c\n", *letters);
  printf("%c\n", *(letters+1));
  printf("%c\n", *(letters+2));
  printf("size of array: %lu bytes\n", sizeof(letters));
  printf("%c\n", *(letters+20));

  // print all the letters in the array
  for(int i=0; i<sizeof(letters);i++)
    printf("%d:%c\n", i, letters[i]);

  printf("%d+%d=%d\n", 10, 20, add(10, 20));
  printf("%d+%d=%d\n", 10, 20, add(10, 20));
  printf("%d+%d=%d\n", 10, 20, add(10, 20));
  printf("%d+%d=%d\n", 10, 20, add(10, 20));
  printf("%d-%d=%d\n", 10, 20, subtract(10, 20));
  printf("%d-%d=%d\n", 10, 20, subtract(10, 20));
  /*
  - Array
  creating an array will set the value of the variable to the
  pointer of the first element with type of the elmenet that
  the array holds.

  int arr[6] = {16, 17, 18, 19, 20, 21};
  printf("arr: %p\n", arr);
  printf("arr.size %d\n", sizeof(arr));
  printf("*arr %d\n", *arr);
  printf("*arr+1 %d\n", *(arr + 1));


  - Pointer Arithmetic

  */
  /* Pointer arithmetic
  int x = 10;

  int *ptr_x = &x;
  printf("ptr_x: %p\n", ptr_x);
  printf("*ptr_x: %d\n", *ptr_x);

  ptr_x += 1; // will point to garbage value
  printf("ptr_x: %p\n", ptr_x);
  printf("*ptr_x: %d\n", *ptr_x);
  */

  /*
  char letter = 'a';
  printf("letter: %c\n", letter);
  printf("size of letter: %d bytes\n", sizeof(letter));

  char *ptr_letter = &letter;
  printf("&letter: %p\n", &letter);
  printf("ptr_x: %p\n", ptr_letter);
  */
}
