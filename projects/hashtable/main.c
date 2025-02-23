#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_SIZE 10

typedef struct Person {
  char name[MAX_NAME];
  int age;
  // .. add other stuff later, maybe
} Person;

// HASH FUNCTION
unsigned int hash(char *name) {
  unsigned int check_sum = 0;
  for (size_t i = 0; i < strlen(name); i++) {
    check_sum += (int)name[i]; // ascii code
  }
  return check_sum;
}

void test(char *name) {
  //
  printf("%s => %u \n", name, hash(name));
}

int main() {
  // char *name = "shiva reddy";
  // for (size_t i = 0; i < strlen(name); i++) {
  //   printf("%ld : %c : %d\n", i, name[i], (int)name[i]);
  // }

  test("Jacob");
  test("Natalie");
  test("Sara");
  test("Mpho");
  test("Tebogo");
  test("Ron");
  test("Jane");

  return EXIT_SUCCESS;
}
