#include <stdio.h>

int main() {

  // Exercises
  /* 4.1
    (a) i = 5; j = 3;
    printf("%d %d", i / j, i % j);

    (b) i = 2; j = 3;
    printf("%d", (i + 10) % j);

    (c) i = 7; j = 8; k = 9;
    printf("%d", (i + 10) % k / j);
    int i = 7, j = 8, k = 9;
    printf("%d\n", (17) % 9 / 8); // 1
    printf("%d\n", (17) % 9);     // 8
    printf("%d\n", 8 / 8);        // 1

    (d) i = 1; j = 2; k = 3;
    printf("%d", (i + 5) % (j + 2) / k);
  */
  int i = 7;
  int j = 6 + (i = 2.5);
  printf("%d\n", i);
  printf("%d\n", j);
}
