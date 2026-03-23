#include <stdio.h>
#include <stdlib.h>

// Creating node structure of the doubly linked list
typedef struct NODE
{
    struct NODE *prev;
    int info;
    struct NODE *next;
} node;

// Function for adding data at the beginning of an empty list 
// node *addtoempty(node *start, int data)
// {
//     // Creating a new node for storing data. 
//     node *tmp;
//     tmp = (node *) malloc(sizeof(node));
//     tmp->info = data;
//     tmp->next = NULL;
//     tmp->prev = NULL;

//     // Assigning the tmp node as start 
//     start = tmp;
//     return start;
// }

// Function for adding data at the beginning of the list 
node *addatbeg(node *start, int data)
{
    // Creating a new node for storing data
    node *tmp;
    tmp = (node *) malloc(sizeof(node));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = start;  
    start->prev = tmp;

    // Assigning the tmp node as start
    start = tmp;
    return start;
}

// Function for inserting data at the end of the list 
node *insert(node *start, int data)
{
    node *tmp;

    // Creating a temporary node 
    tmp = (node *) malloc(sizeof(node));
    tmp->info = data;

    // List is empty 
    if (start == NULL)
    {
        tmp->prev = NULL;
        tmp->next = NULL;
        start = tmp;
        return start;
    }

    // Traversing the list 
    node *p = start;
    while (p->next != NULL)
    {
        p = p->next;
    }

    // Adding tmp at the end 
    tmp->prev = p;
    p->next = tmp;
    tmp->next = NULL;

    return start;
}

// Function for adding data after item
node *addafter(node *start, int data, int item)
{
    node *tmp, *p = start;
    // Creating a temporary node 
    tmp = (node *) malloc(sizeof(node));
    tmp->info = data;

    // Traversing the list 
    while (p != NULL)
    {
        // If element is found
        if (p->info == item)
        {
            tmp->prev = p;
            tmp->next = p->next;

            // If item is not the last node, then assign the previous pointer of the next node to tmp
            if (p->next != NULL)
            {
                p->next->prev = tmp;
            }
            else
            {
                tmp->next = NULL;
            }
            p->next = tmp;
            tmp->next->prev = tmp;
            return start;
        }
        p = p->next;
    }

    // If element is not found in list
    printf("%d element not present in list\n", item);
    return start;
}
