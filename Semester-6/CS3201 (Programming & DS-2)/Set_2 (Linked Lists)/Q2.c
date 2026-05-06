// QUESTION
// Write a program in C to check whether two singly linked lists are identical.


#include <stdio.h>
#include "SinglyLinkedList.h"

// Function to check whether 2 LLs are identical
// Returns 1 if identical
// Returns 0 if not
int isIdentical(node *start1, node *start2)
{
    node *ptr1 = start1, *ptr2 = start2;

    // Traversing 2 LLs
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->info != ptr2->info)  // Elements are not identical
        {
            return 0;
        }
        ptr1 = ptr1->link;
        ptr2 = ptr2->link;
    }

    // Checks whether LLs are of identical length
    return (ptr1 == NULL && ptr2 == NULL);
}


void main()
{
    // Initialising parameters
    node *start1 = NULL, *start2 = NULL;
    node *start[] = {start1, start2};

    // Defining arrays for making LLs
    int size1, size2;
    int l1[] = {1, 2, 2, 4, 5};
    size1 = sizeof(l1)/sizeof(l1[0]);
    int l2[] = {1, 2, 3, 4};
    size2 = sizeof(l2)/sizeof(l2[0]);

    int *l[] = {l1, l2};
    int sizes[] = {size1, size2};
    int num, element;

    // User/Array input for LL data
    for (int i = 0; i < 2; i++)
    {
        // printf("Enter number of elements of LL %d: ", i+1);
        // scanf("%d", &num);
        num = sizes[i];

        for (int j = 0; j < num; j++)
        {
            // printf("Enter element %d: ", j+1);
            // scanf("%d", &element);
            element = l[i][j];
            start[i] = addatend(start[i], element);
        }

        // Printing the LLs
        printf("Linked List %d: ", i+1);
        print_list(start[i]);
        printf("\n");
    }

    // Checking whether identical
    int result = isIdentical(start[0], start[1]);

    if (result == 0)
    {
        printf("Linked Lists are not identical");
    }
    else
    {
        printf("Linked Lists are identical");
    }
}