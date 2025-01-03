#include <stdio.h>
#include <string.h>

int read_line(char[], int);

int main() {}

// Reads the line and
int read_line(char str[], int max_size)
{
    int ch;
    int i = 0;

    while ((ch = getchar()) != '\n')
        if (i < max_size)
            str[i++] = ch;

    str[i] = '\0';
    return i;
}
