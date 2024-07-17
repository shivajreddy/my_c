#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 5
#define C 9

void print_grid_v1(int *grid);
void print_grid(int grid[R][C]);

int main() {
  int grid[R][C];

  srand((unsigned)time(NULL));

  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      int random_number = (rand() % (40 - 10 + 1)) + 10;
      grid[r][c] = random_number;
    }
  }

  print_grid_v1(grid[0]);

  printf("\n");

  print_grid(grid);
}

void print_grid(int grid[R][C]) {
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      // int val = (&grid[r])[c];
      int val = grid[r][c];
      printf("%d ", val);
    }
    printf("\n");
  }
}

void print_grid_v1(int *grid) {
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      int val = (&grid[r])[c];
      printf("%d ", val);
    }
    printf("\n");
  }
}
