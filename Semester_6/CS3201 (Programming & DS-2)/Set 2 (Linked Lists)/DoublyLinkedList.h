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
node *addtoempty(node *start, int data)
{
    // Creating a new node for storing data. 
    node *tmp;
    tmp->info = data;
    tmp->next = NULL;
    tmp->prev = NULL;

    // Assigning the tmp node as start 
    start = tmp;
    return start;
}

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

