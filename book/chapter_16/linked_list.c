
/*
 * Implement a linked list
 */

#include <stdio.h>

// Linked List Node
typedef struct Node
{
    int value;
    struct Node *next; // why should we use 'struct tag',
                       // instead of 'struct type'
} Node;

void print_linked_list(struct Node *root)
{
    int x = 10;
    for (int i = 0; i < x; i++) {
        printf("%i", i);
    }
}
