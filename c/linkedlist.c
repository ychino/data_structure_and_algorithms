#include <stdio.h>
#include <stdlib.h>

// Represents a node
typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    // List of size 0, initially not pointing to anything
    node *list = NULL;

    // First node
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    // Add number 1 to the first node and list points to it. The first node is pointing nothing
    n->number = 1;
    n->next = NULL;
    list = n;

    // Second node
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    // Add number 2 to the second node. The second node is pointing nothing
    n->number = 2;
    n->next = NULL;
    // Add the second node to the end of the list
    list->next = n;

    // Third node
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    // It can follow multiple nodes with this syntax, using the next pointer
    // over and over, to add the third node to the end of the list. In practice, this should use loop
    list->next->next = n;

    // Print numbers in the list
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    // Free list
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}