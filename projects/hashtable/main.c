#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define TABLE_SIZE 10

typedef struct Person {
  char name[MAX_NAME];
  int age;
  // .. add other stuff later, maybe
} Person;

// HASH FUNCTION
unsigned int hash(char *name) {
  unsigned int hash_val = 0;
  for (size_t i = 0; i < strlen(name); i++) {
    int ch = name[i]; // ascii code
    hash_val += ch;
    hash_val = (hash_val * ch) % TABLE_SIZE;
  }
  return hash_val;
}

Person *hash_table[TABLE_SIZE];

void init_hashtable() {
  // Start with an empty table
  for (size_t i = 0; i < TABLE_SIZE; i++) {
    hash_table[i] = NULL;
  }
}

void print_hashtable() {
  for (size_t i = 0; i < TABLE_SIZE; i++) {
    Person *p = hash_table[i];
    if (p != NULL) {
      printf("[%s , %d]", p->name, p->age);
    } else {
      printf("\t---");
    }
  }
  printf("\n");
}

void test(char *name) {
  unsigned int hash_result = hash(name);
  printf("%s => %u \n", name, hash_result);
}

int main() {
  init_hashtable();
  print_hashtable();

  test("Jacob");
  test("Natalie");
  test("Sara");
  test("Mpho");
  test("Tebogo");
  test("Ron");
  test("Jane");
  test("Maren");
  test("Bill");

  return EXIT_SUCCESS;
}
