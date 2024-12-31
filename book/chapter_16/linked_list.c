
/*
 * Implement a linked list
 */

#include <stdio.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void insert_node(struct Node *prev, struct Node *new_node)
{
    struct Node *nxt = prev->next;
    prev->next = new_node;
    new_node->next = nxt;
}

void print_linked_list(struct Node *root)
{
    struct Node *curr = root;
    while (curr != NULL) {
        printf("%i->", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main()
{
    // Create a sample linked list
    struct Node one = { .value = 1 };
    struct Node two = { .value = 2 };
    struct Node three = { .value = 3 };
    struct Node four = { .value = 4 };
    struct Node five = { .value = 5 };
    struct Node six = { .value = 6 };
    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = &five;
    five.next = &six;

    print_linked_list(&one);

    struct Node nine = { .value = 9 };
    insert_node(&three, &nine);
    print_linked_list(&one);

    return 0;
}
