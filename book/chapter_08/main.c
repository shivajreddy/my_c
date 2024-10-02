#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 5
#define C 9

void print_grid_v1(int *grid);
void print_grid(int grid[R][C]);
void print_bool_grid(bool grid[R][C]);

int main() {

  int grid[5][5] = {{8, 3, 9, 0, 10},
                    {3, 5, 17, 1, 1},
                    {2, 8, 6, 23, 1},
                    {15, 7, 3, 2, 9},
                    {6, 14, 2, 6, 0}};

  printf("Rows: ");
  int row_sum = 0;
  for (int r = 0; r < 5; r++) {
    for (int c = 0; c < 5; c++) {
      row_sum += grid[r][c];
    }
    printf("%d ", row_sum);
    row_sum = 0;
  }

  printf("\nCols: ");
  int col_sum = 0;
  for (int c = 0; c < 5; c++) {
    for (int r = 0; r < 5; r++) {
      col_sum += grid[r][c];
    }
    printf("%d ", col_sum);
    col_sum = 0;
  }

  /*
  int grid[R][C];

  srand((unsigned)time(NULL));

  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      int random_number = (rand() % (40 - 10 + 1)) + 10;
      grid[r][c] = random_number;
    }
  }
  */

  // int grid[R][C];
  // print_grid(grid);

  // int grid[R][C] = {3, 4};
  // print_grid(grid);

  // bool grid[R][C] = {true};
  // print_bool_grid(grid);

  // printf("\n");
  // print_grid_v1(grid[0]);
}

void print_3d_matrix(int matrix[][3][4]) {}

void print_grid(int grid[][C]) {
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      // int val = (&grid[r])[c];
      int val = grid[r][c];
      printf("%d ", val);
    }
    printf("\n");
  }
}

void print_bool_grid(bool grid[R][C]) {
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      int val = grid[r][c];
      printf("%d ", grid[r][c]);
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
