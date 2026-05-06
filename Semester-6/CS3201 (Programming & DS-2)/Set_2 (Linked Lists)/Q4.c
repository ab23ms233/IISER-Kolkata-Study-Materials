// QUESTION
// Consider that two sets are stored in two singly linked lists: L1: {1, 2, 3, 4, 5} and L2: {1, 5, 8, 9} (as examples). Store the intersection and union of these two sets in two new linked lists: L_intersect and L_union, respectively. Since the contents are sets, the order of the elements in the linked lists is not important.

#include <stdio.h>
#include "SinglyLinkedList.h"

// Checks whether an element is present in a singly linked list. 
int isPresent(node *start, int element)
{
    node *p = start;

    while (p != NULL)
    {
        if (p->info == element)
        {
            return 1;
        }
        p = p->link;
    }
    return 0;
}

// Function to find intersection of two linked lists 
node *Intersection(node *start1, node *start2)
{
    node *p1 = start1;
    node *start = NULL;

    // Traversing linked list 1 
    while (p1 != NULL)
    {
        // If element is present in linked list 2, append in intercection
        if (isPresent(start2, p1->info) == 1)
        {
            start = addatend(start, p1->info);
        }
        p1 = p1->link;
    }
    return start;
}

// Function for finding union of two linked lists 
node *Union(node *start1, node *start2)
{
    node *p1 = start1;
    node *start = NULL;

    // Traversing list 1 
    while (p1 != NULL)
    {
        // Appending elements to new linked list 
        start = addatend(start, p1->info);
        p1 = p1->link;
    }

    // Traversing list 2. 
    node *p2 = start2;
    while (p2 != NULL)
    {
        // Appending elements to new linked list if not present previously 
        if (isPresent(start, p2->info) == 0)
        {
            start = addatend(start, p2->info);
        }
        p2 = p2->link;
    }

    return start;
}


void main()
{
    // Parameters 
    node *start[] = {NULL, NULL};
    int num1, num2;
    int l1[] = {1, 2, 3, 4};
    int l2[] = {3, 4, 5, 6};
    num1 = sizeof(l1)/sizeof(l1[0]);
    num2 = sizeof(l2)/sizeof(l2[0]);
    int nums[] = {num1, num2};
    int *l[] = {l1, l2};

    int element, num;

    // User/Array input for making 2 linked lists 
    for (int i = 0; i < 2; i++)
    {
        // printf("Enter number of elements in LL %d: ", i+1);
        // scanf("%d", &num);
        num = nums[i];
    
        for (int j = 0; j < num; j++)
        {
            // printf("Enter element %d: ", j+1);
            // scanf("%d", &element);
            element = l[i][j];
            start[i] = addatend(start[i], element);
        }

        // Printing linked lists
        printf("Original LL %d: ", i+1);
        print_list(start[i]);
        printf("\n");
    }

    node *uni = Union(start[0], start[1]);
    node *intersect = Intersection(start[0], start[1]);
    printf("Union: ");
    print_list(uni);
    printf("Intersection: ");
    print_list(intersect);
}