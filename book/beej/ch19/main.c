#include <stdio.h>
#include "bar.h"
#include "common.h"
#include "foo.h"

#define HELLO

void section_19_4() {
#ifdef HELLO
  printf("HEllo is defined\n");
#else
  printf("HEllo is not-defined\n");
#endif

  foo();
  bar();
  common();
}

void section_19_4_1() {
  printf("This function: %s\n", __func__);
  printf("This file: %s\n", __FILE__);
  printf("This line: %d\n", __LINE__);
  printf("Compiled on: %s, %s\n", __DATE__, __TIME__);
  printf("C Version: %ld\n", __STDC_VERSION__);
}

void section_19_4_2() {
#if __STDC_VERSION__ >= 1999901L
  printf("%s\n", );
#endif  // __STDC_VERSION__ >= 1999901L

  printf("%ld\n", __STDC_VERSION__);
  printf("%ld\n", __STDC_VERSION__);
  printf("%ld\n", __STDC_VERSION__);
}

int main(void) {
  // section_19_4();
  // section_19_4_1();
  section_19_4_2();

  return 0;
}
