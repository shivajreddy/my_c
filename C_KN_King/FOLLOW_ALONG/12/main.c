#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

size_t my_strlen(char *str)
{
    int size = 0;

    char *curr = str;
    while (*curr != '\0') {
        size++;
        curr++;
    }

    return size;
}

int main()
{
    puts("hello there");
    puts("hello there");

    printf("%zu\n", my_strlen("reddy"));
    printf("%lu\n", strlen("reddy"));
}
size_t strlen(const char *__s);
