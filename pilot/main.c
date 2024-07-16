/* ************************************************************
 * Author: Shiva                                               *
 * Purpose: Learning C                                         *
 * Materil: Books, Videos                                      *
 ************************************************************ */

#include <stdio.h>

void print_grid(int *grid, int r, int c);

int main(void) {

  const int r = 3;
  const int c = 4;

  int grid[r][c] = {{10, 20, 30}, {40, 50, 60}};

  printf("%d\n", *grid[0]);
  printf("%d\n", *grid[1]);
  printf("%p\n", grid[0]);

  printf("%d\n", grid[0][0]);
  printf("%p\n", &(grid[0][0]));
}

void print_grid(int *grid, int m, int n) {

  for (int r = 0; r < m; r++) {
    for (int c = 0; c < n; c++) {
      // printf("(%d,%d): %d", r, c, grid[r][c]);
    }
  }
}
