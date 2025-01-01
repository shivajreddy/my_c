#include <stdio.h>

// STRUCT TAGS
struct part // struct tag, can use the name 'part' again
{
    int val1;
    int val2;
};
int part = 99; // can use, cuz the name of struct tag is `struct part`

// Defining a struct(user-defined) type
typedef struct Part // 8 Bytes
{
    int val1; // 4 Bytes
    int val2; // 4 Bytes
} Part;

void foo()
{
    struct Part part1 = { .val1 = 20, .val2 = 30 };
    struct Part part2;
    part2 = part1; // shallow copying, for example if there are pointers, only
                   // copies the pointers, but not the value of the pointer. So
                   // technically, it makes an entire copy, it is for the
                   // programmer to check if they are using any pointers

    // Check the memory address of ppties of both instances
    printf("part1.val1    :%i\n", part1.val1);
    printf("&(part1.val1) :%p\n", &(part1.val1));
    printf("part1.val2    :%i\n", part1.val2);
    printf("&(part1.val2) :%p\n", &(part1.val2));

    size_t s = sizeof(struct Part);
    printf("size of Part: %zu\n", s);

    printf("part2.val1    :%i\n", part2.val1);
    printf("&(part2.val1) :%p\n", &(part2.val1));
    printf("part2.val2    :%i\n", part2.val2);
    printf("&(part2.val2) :%p\n", &(part2.val2));
}

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
    foo();

    int x = 99;
    int *ptr = &x;
    printf("&X: %p\n", &x);
    printf("&X: %p\n", ptr);

    int y = 20;
    int *ptr2 = &y;
    printf("&y: %p\n", &y);

    // printf("y = %i", y);
    printf("guess x: %i\n", (*(--ptr2)));

    print_person(&p);
    printf("%i", p.age);

    char buff[256];
    printf("%ld bytes\n", sizeof(buff));

    printf("size of char: %ld\n byte", sizeof(char));

    printf("%d", 256 * 8);

    // printf("Hello World\n");
    // printf("Hello World\n");
}
