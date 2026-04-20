#include <stdio.h>
#include <stdlib.h>

// Creating node structure of the singly linked list
typedef struct NODE
{
    int info;
    struct NODE *link;
} node;

// Function to display elements of the list
void display(node *start)
{
	node *p;
	
	p = start;
	while (p != NULL)
	{
		printf("%d ", p->info);
		p = p->link;
	}
	printf("\n");
}

// Function for adding element at the beginning of the list. 
node *addatbeg(node *start, int data)
{
    // Creating a temporary node 
    node *tmp;
    tmp = (node*) malloc(sizeof(node));
    tmp->info = data;
    tmp->link = start;

    // Assigning the temporary node as start 
    start = tmp;
    return start;
}

// Function for adding element at the end of the list 
node *addatend(node *start, int data)
{
    node *p, *tmp;
	
    // Traversing the list 
    p = start;
    while (p->link != NULL)
    {
        p = p->link;
    }
    // Creating a Temporary Node
    tmp = (node *) malloc(sizeof(node));
    tmp->info = data;
    tmp->link = NULL;

    // Assigning the temporary node as tail
    p->link = tmp;
    return start;
}

// Function for adding data after item
node *addafter(node *start, int data, int item)
{
    node *tmp, *p;
    
    // Traversing the list 
    p = start;
    while (p != NULL)
    {
        // If element is found 
        if (p->info == item)
        {
            // Creating a temporary node 
            tmp = (node *) malloc(sizeof(node));
            tmp->info = data;
            tmp->link = p->link;    // Assigning pointer of temp to the next node 
            p->link = tmp;      // Assigning pointer of item node to temp 
            return start;
        }

        p = p->link;
    }

    // If element is not found in list 
    printf("%d element not present in list\n", item);
    return start;
}

// Function for adding data before item
node *addbefore(node *start, int data, int item)
{
    node *p, *tmp;

    // If item is in the first node 
    if (item ==  start->info)
    {
        return addatbeg(start, data);
    }

    // Traversing the list
    p = start;
    while (p->link != NULL)
    {
        // If element is found 
        if (p->link->info == item)
        {
            // Creating a temporary node 
            tmp = (node*) malloc(sizeof(node));
            tmp->info = data;
            tmp->link = p->link;    // Assigning pointer of temp to item node 
            p->link = tmp;      // Assigning previous node pointer to temp 

            return start;
        }

        p = p->link;
    }

    // If element is not found in list 
    printf("%d element not present in list\n", item);
    return start;
}

// Function for deleting a node with info as data 
node *del(node *start, int data)
{
    node *p, *tmp;

    // If list is empty 
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }

    // If data is in the first node 
    if (start->info == data)
    {
        tmp = start;    // Temp is the first node 
        start = start->link;    // Start is the next node
        free(tmp);     // Temp is freed from heap

        return start;
    }

    // Traversing the list 
    p = start;
    while (p->link != NULL)
    {
        // If element is found 
        if (p->link->info == data)
        {
            tmp = p->link;  // Temp is the node which has data
            p->link = tmp->link;    // Previous node of data points to the node after data (node after tmp). 
            free(tmp);      // Temp is freed from heap

            return start;
        }
        
        p = p->link;
    }

    // If element is not found in list 
    printf("%d element not present in list\n", data);
    return start;
}

// Function to reverse a linked list 
node *reverse(node *start)
{
    node *prev, *next, *ptr;

    prev = NULL;
    ptr = start;    // ptr is used for traversing the list. 

    while (ptr != NULL)
    {
        next = ptr->link;
        prev = ptr;
        ptr = next;
    }

    start = prev;
    return start;
}
