#include <stdio.h>

int main(void) {

  printf("Hello World!\n");
  print("Hello World!\n");

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
