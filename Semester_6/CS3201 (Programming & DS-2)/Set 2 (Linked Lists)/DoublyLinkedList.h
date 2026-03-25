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

    if (start != NULL)
    {
        start->prev = tmp;
    }

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

    // List is empty  
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    // Traversing the list 
    while (p != NULL)
    {
        // If element is found
        if (p->info == item)
        {
            // Creating a temporary node 
            tmp = (node *) malloc(sizeof(node));
            tmp->info = data;
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
            return start;
        }
        p = p->next;
    }

    // If element is not found in list
    printf("%d element not present in list\n", item);
    return start;
}

// Function for adding data before item
node *addbefore(node *start, int data, int item)
{
    node *p = start;
    // List is empty 
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }

    // Traversing the list 
    while (p != NULL)
    {
        // If element is found
        if (p->info == item)
        {
            // Creating a temporary node
            node *tmp = (node *) malloc(sizeof(node));
            tmp->info = data;
            tmp->next = p;
            tmp->prev = p->prev;

            // If item is not the first node, then assign the next pointer of the previous node to tmp
            if (p->prev != NULL)
            {
                p->prev->next = tmp;
            }
            // Updating start if item is the first node
            else    
            {
                tmp ->prev = NULL;
                start = tmp;
            }
            p->prev = tmp;
            return start;
        }
        p = p->next;
    }

    // If element is not found in list
    printf("%d element not present in list\n", item);
    return start;
}

// Function for deleting a node with info as data
node *del(node *start, int data)
{
    // List is empty 
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }

    // Traversing the list
    node *p = start;
    while (p != NULL)
    {
        // If element is found
        if (p->info == data)
        {
            // If node to be deleted is the only node 
            if (p->next == NULL && p->prev == NULL)
            {
                start = NULL;
                free(p);
                return start;
            }
            // If node to be deleted is the last node 
            else if (p->next == NULL)
            {
                p->prev->next = NULL;
            }
            // If node to be deleted is the first node
            else if (p->prev == NULL)
            {
                p->next->prev = NULL;
                start = p->next;
            }
            // If node to be deleted is in between the list
            else
            {
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            
            // Freeing the memory occupied by the node
            free(p);
            return start;
        }
        p = p->next;
    }

    // If element is not found in list
    printf("%d element not present in list\n", data);
    return start;
}

// Function to display elements of the list
void display(node *start)
{
    // List is empty 
    if (start == NULL)
    {
        printf("List is empty\n");
    }

    // Traversing the list
    node *p = start;
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->next;
    }
    printf("\n");
}