// QUESTION
// Write a program in C to remove a node in a doubly linked list if its previous and next nodes have the same info.

#include <stdio.h>
#include "DoublyLinkedList.h"

// Function required
node *delPrevNextSame(node *start)
{
    // Traversing the list
    node *p = start->next;
    while (p->next != NULL)
    {
        // If condition is satisfied
        if (p->next->info == p->prev->info)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
            return start;
        }
        p = p->next;
    }
    // If no node satisfies the criteria
    printf("No nodes satisfy the criteria\n");
    return start;
}

void main()
{
    // Initialising the list
    node *start = NULL;
    int l[] = {1, 2, 3, 2, 4};
    int num = sizeof(l)/sizeof(l[0]);

    // Appending elements to the list
    for (int i = 0; i < num; i++)
    {
        start = insert(start, l[i]);
    }

    // Original list
    printf("Original List: ");
    display(start);
    // Modified list
    node *modified = delPrevNextSame(start);
    printf("Modified List: ");
    display(modified);
}