// QUESTION
// Write a program in C to delete duplicates from a sorted single-linked list.


#include <stdio.h>
#include "SinglyLinkedList.h"

// Function to delete duplicates from a ascending-sorted LL
node *delduplicate(node *start)
{
    node *ptr = start, *tmp;

    // Traversing the list
    while (ptr->link != NULL)
    {
        // If duplicate is found, delete
        if (ptr->info == ptr->link->info)
        {
            tmp = ptr->link;
            ptr->link = tmp->link;
            free(tmp);
        }
        ptr = ptr->link;
    }
    return start;
}


void main()
{
    // Parameters
    node *start = NULL;
    int l[] = {1, 1, 2, 2, 3, 4};
    int element, num;
    num = sizeof(l)/sizeof(l[0]);
    // printf("Enter number of elements: ");
    // scanf("%d", &num);

    // User/List input and making LL
    for (int i = 0; i < num; i++)
    {
        // printf("Enter element %d: ", i+1);
        // scanf("%d", &element);
        element = l[i];
        start = addatend(start, element);
    }
    
    // Original list
    printf("Original LL: ");
    print_list(start);

    // After removing duplicates
    start = delduplicate(start);
    printf("LL after deleting duplicates: ");
    print_list(start);
}