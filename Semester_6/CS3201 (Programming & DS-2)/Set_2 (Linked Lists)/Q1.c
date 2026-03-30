// QUESTION
// Write a program in C to make two linked lists from a linked list L: one having the numbers of L divisible by N and the other containing the rest.


#include <stdio.h>
#include "SinglyLinkedList.h"

// Function to split linked list (**start1 is a pointer to start1)
void splitN(node *start, node **start1, node **start2, int N)
{
    node *ptr = start;

    // Traversing the linked list
    while (ptr != NULL)
    {
        // If element divisible by N 
        if (ptr->info%N == 0)
        {
            *start1 = addatend(*start1, ptr->info);
        }
        // If element is not divisible by N
        else
        {
            *start2 = addatend(*start2, ptr->info);
        }

        ptr = ptr->link;
    }
}


void main()
{
    // Initialising start node
    node *startL = NULL;

    // No. of elements in linked list
    int element, num;
    // printf("Enter the number of elements of the linked list: ");
    // scanf("%d", &num);
    int l[] = {2, 5, 8, 10, 12, 14};
    num = sizeof(l)/sizeof(l[0]);
    
    // User input for elements
    for (int i = 0; i < num; i++)
    {
        // printf("Enter element %d: ", i+1);
        // scanf("%d", &element);
        element = l[i];

        // Adding elements to LL
        startL = addatend(startL, element);
    }
    
    // Printing LL
    printf("Original Linked List: ");
    print_list(startL);
    printf("\n");

    // Integer for division
    int N;
    printf("Enter integer to check divisibility: ");
    scanf("%d", &N);

    // Splitting LL
    node *start1 = NULL, *start2 = NULL;
    splitN(startL, &start1, &start2, N);

    // Printing new LLs
    printf("Divisible by %d: ", N);
    print_list(start1);
    printf("Rest: ");
    print_list(start2);
}