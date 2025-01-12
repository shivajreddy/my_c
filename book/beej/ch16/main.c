/* Chapter 16: Types IV: Qualifiers and Specifiers */

#include <stdio.h>
#include <stdlib.h>

void section_16_1() {
  {
    char** p = NULL;
    p++;
    (*p)++;
  }

  {
    char** const p = NULL;
    // p++;     // Error
    (*p)++;  // Error
  }

  {
    char* const* const p = NULL;
    // p++;     // Error
    // (*p)++;  // Error
  }
}

// static -> block scope
void counter(void) {
  // This is initialized one time, with in the scope of fn counter
  static int count = 1;
  printf("This has been called %d time(s) \n", count);
  count++;
}

void section_16_2_2_1() {
  counter();
  counter();
  counter();
}
// static -> file scope
static int count = 99;

void section_16_2_2_2() {
  {
    int count = 88;         // uses block/local scope
    printf("%d\n", count);  // uses file scope
  }
  printf("%d\n", count);  // uses file scope
}

extern int a;  // can use extern at file scope
void section_16_2_3() {
  // Tell the compiler that 'a' is defined in some other file,
  // which we know will be compiled and linked
  /* this is the error if compiler can't find 'a' at all 
  /usr/bin/ld: /tmp/ccCxGX0U.o: warning: relocation against `a' in read-only section `.text'
/usr/bin/ld: /tmp/ccCxGX0U.o: in function `section_16_2_3()':
main.c:(.text+0xee): undefined reference to `a'
/usr/bin/ld: warning: creating DT_TEXTREL in a PIE
collect2: error: ld returned 1 exit status
  */
  extern int a;  // or at block scope
  a++;
  printf("%d\n", a);
}

// register
void section_16_2_4() {}

int main(void) {
  // section_16_1();
  // section_16_2_2_1();
  // section_16_2_2_2();
  // section_16_2_3();
  section_16_2_4();

  return 0;
}
