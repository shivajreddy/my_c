/* Chapter 16: Types IV: Qualifiers and Specifiers */

#include <stdio.h>
#include <stdlib.h>

void section_16_1() {
  {
    char** p;
    p++;
    (*p)++;
  }

  {
    char** const p;
    // p++;     // Error
    (*p)++;  // Error
  }

  {
    char* const* const p;
    // p++;     // Error
    // (*p)++;  // Error
  }
}

// static -> block scope
void counter(void) {
  static int count = 1;  // This is initialized one time
  printf("This has been called %d time(s) \n", count);
  count++;
}

void section_16_2() {
  counter();
  counter();
  counter();
}
// static -> file scope
static int count = 99;

void section_16_3() {}

int main(void) {
  // section_16_1();
  section_16_2();

  int count = 20;       // local scope
  printf("%d", count);  // uses local scope
  return 0;
}
