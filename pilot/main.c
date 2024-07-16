/* ************************************************************
* Author: Shiva                                               *
* Purpose: Learning C                                         *
* Materil: Books, Videos                                      *
************************************************************ */

#include <stdio.h>

void print_array(int* arr);
// void print_grid(int* grid);

int main(void) {
  // int grid[3][4] = {{1, 2, 3}, {21, 31, 41}, {300, 400, 500}};
  // printf("grid = %p\n", grid);
  // printf("grid[0] = %p\n", grid[0]);
  // printf("*grid[0] = %d\n", *grid[0]);
  // printf("grid[0] = %d\n", grid[2][1]);

  const int r = 3;
  const int c = 4;
  int grid[r][c] = {{}};

  int arr[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  int n = sizeof
  print_array(arr, n);
}




void print_array(int* arr) {
  printf("size of arr: %d\n", sizeof(arr));
  printf("size of arr[0]: %d\n", sizeof(arr[0]));
  int size = sizeof(arr) / sizeof(arr[0]);
  printf("size : %d\n", size);

  for (int idx=0; idx<size; idx++)
    printf("%d:%d\n", idx, arr[idx]);

}

// void print_grid(int* grid);
