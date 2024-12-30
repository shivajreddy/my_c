#include <stdio.h>

// STRUCTS

struct Person
{
    char name[10];
    int age;
    char sex;
};

void print_person(struct Person *p)
{
    printf("{ ");
    printf("name: %s ", p->name);
    printf("age: %i ", p->age);
    printf("sex: %c ", p->sex);
    printf("}\n");
};

struct Person p = { .age = 29, .name = "shiva", .sex = 'M' };

int main()
{
    print_person(&p);
    printf("%i", p.age);

    char buff[256];
    printf("%ld bytes\n", sizeof(buff));

    printf("size of char: %ld\n byte", sizeof(char));

    printf("%d", 256 * 8);

    // printf("Hello World\n");
    // printf("Hello World\n");
}
