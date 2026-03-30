#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creating node structure of the doubly linked list
typedef struct NODE
{
    struct NODE *prev;
    char info;
    struct NODE *next;
} node;

// Function for inserting data at the end of the list 
node *insert(node *start, char data)
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
        printf("%c ", p->info);
        p = p->next;
    }
    printf("\n");
}

// Function for abbreviating the name in the list
node *abbreviated(node *start)
{
    node *abbr = NULL;
    node *p = start, *tmpchar = start;  // tmpchar stores the node after a space. Initially, it stores the first character. 

    // Traversing the list
    while (p != NULL)
    {
        // If space is found, add first character of previous name (stored in tmp), followed by dot and space
        // If name = "Arya Basak", tmpchar = node 'A'(initially) and when p is at node ' ', then 'A. ' is added to abbr, and tmpchar is updated to node 'B' for next iteration.
        // If name = "Arya  Basak" or "Arya Basak " (extra spaces), then tmpchar is not updated
        if (p->info == ' ' && p->next != NULL && p->next->info != ' ')
        {
            abbr = insert(abbr, tmpchar->info);
            abbr = insert(abbr, '.');
            abbr = insert(abbr, ' ');
            tmpchar = p->next;
        }
        p = p->next;
    }

    // Adding the last name to abbr, since there is no space after it
    while (tmpchar != NULL)
    {
        abbr = insert(abbr, tmpchar->info);
        tmpchar = tmpchar->next;
    }
    return abbr;
}


void main()
{
    char name[100];
    // strcpy(name, "Narendra Damodardas  Modi ");

    // Input for name
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    // Creating a doubly linked list out of the name string
    node *L = NULL;
    int i = 0;
    while (name[i] != '\0')
    {
        L = insert(L, name[i]);
        i++;
    }
    // Original list
    printf("Original List: ");
    display(L);
    // Abbreviated list
    node *L_abbr = abbreviated(L);
    printf("Abbreviated List: ");
    display(L_abbr);
}