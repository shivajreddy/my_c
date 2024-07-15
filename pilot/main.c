#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

struct fat_boy {
  char v[SIZE];
};

typedef struct fat_boy fat_boy;

void find_42(fat_boy boy) {
  int i = 0;

  while (1) {
    if (boy.v[i] == 42) {
      printf("42 is in position: %d\n", i);
      break;
    }
    // i++;
    ++i;
  }
}

int main(void) {
  fat_boy boy;

  srand(time(NULL)); // wtf does this do?

  boy.v[rand() % SIZE] = 42;

  find_42(boy);

  return 0;
}
