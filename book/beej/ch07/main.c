#include <stdio.h>
#include <string.h>

size_t strlen2(const char* s) {
  size_t length = 0;
  while (s[length] != '\0')
    length++;
  return length;
}

void string_literals() {
  // string literals
  char* s1 = "hello";  // immutable fixed size, because its in the code itself,
  // which is an immutable region. so this pointer is actually pointing to
  // the immutable-the immutable-code-region, and hence cant modify string slice
  printf("s1: %s\n", s1);
  printf("The string is %zu bytes long.\n", strlen2(s1));

  printf("s1.size = %ld bytes\n", strlen2(s1));

  // char s2[] = "fox hello hello there";  // mutable fixed size
  char s2[] = "12345 78";  // mutable fixed size
  printf("s2: %s\n", s2);
  // this makes a copy of the immutable-code-region on to the stack,
  // and gives the pointer of the 1st char on this stack
  // puts(s2);

  *s2 = 'z';

  printf("s2.size = %ld ", strlen2(s2));
}

/*
char* copy_string(char* s) {
  char new[10];

  int length = 0;
  while (s[length] != '\0') {
    new[length] = s[length];
    length++;
  }
  return &new[0];
}
*/

void copying_strings() {
  char* s1 = "hello";
  printf("s = %s\n", s1);
  printf("s1.len = %ld\n", strlen2(s1));

  char new[10];
  int length = 0;
  while (s1[length] != '\0') {
    new[length] = s1[length];
    length++;
  }
  puts(new);
  new[0] = 'z';
  puts(new);

  puts("");
  puts("");

  char s[] = "hello there";
  char t[100];

  strcpy(t, s);
  t[0] = 'z';
  puts(s);
  puts(t);
}

int main() {
  // string_literals();
  copying_strings();
  return 0;
}
