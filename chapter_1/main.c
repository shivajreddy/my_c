/* ************************************************************
 * Author: Shiva                                               *
 * Purpose: Learning C                                         *
 * Materil: Books, Videos                                      *
 ************************************************************ */

#include <stdio.h>

void print_array(int *arr, int n);
void print_array_chars(char *arr, int n);
void print_grid(int *grid, int r, int c);

int main(void) {

  printf("hello\n");

  // int c[10] = {5, 1, 9, [4] = 3, 7, 2, [8] = 6};
  // print_array(c, 10);

  // char letters[10] = {'a', 'c'};
  // print_array_chars(letters, 10);

  // int boolean_nums[9] = {};
  // print_array(boolean_nums, 9);

  /*
  int a[10][4] = {0};
  print_array(a, 10);

  const int r = 3;
  const int c = 4;

  int grid[r][c] = {0};
  printf("%d", grid);
  */

  /*
  int grid[r][c] = {{10, 20, 30}, {40, 50, 60}};

  printf("%d\n", *grid[0]);
  printf("%d\n", *grid[1]);
  printf("%p\n", grid[0]);

  printf("%d\n", grid[0][0]);
  printf("%p\n", &(grid[0][0]));
  */
}

void print_array(int *arr, int n) {
  for (int idx = 0; idx < n; idx++)
    printf("%d: %d\n", idx, arr[idx]);
}

void print_array_chars(char *arr, int n) {
  for (int idx = 0; idx < n; idx++)
    printf("%d: %c\n", idx, arr[idx]);
}

void print_grid(int *grid, int m, int n) {
  for (int r = 0; r < m; r++) {
    for (int c = 0; c < n; c++) {
      // printf("(%d,%d): %d", r, c, grid[r][c]);
    }
  }
}
