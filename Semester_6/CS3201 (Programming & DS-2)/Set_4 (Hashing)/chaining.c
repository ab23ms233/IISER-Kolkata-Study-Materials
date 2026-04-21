#include <stdio.h>
#include "DoublyLinkedList.h"

// Function to print the hash table
void print_table(node *arr[], int size)
{
    node *p;
    // Traversing through the hash table
    for (int i = 0; i < size; i++)
    {
        printf("[%d] ", i);

        p = arr[i];
        while (p != NULL)
        {
            printf("%d ", p->info);
            p = p->next;
        }
        printf("\n");
    }
    printf("\n");
}

// Function to create an empty hash table initialized with NULL
void empty_hash_table(node *table[], int tsize)
{
    for (int i = 0; i < tsize; i++)
        table[i] = NULL;
}

void chaining(node *table[], int tsize, int arr[], int size)
{
    int h, element;
    // Traversing through the input array
    for (int i = 0; i < size; i++)
    {
        element = arr[i];
        h = element % tsize; // Hash value
        // Inserting element at the end of the linked list at the hash value index
        table[h] = insert(table[h], element);
        printf("%d inserted at position %d\n", element, h);
    }
    // Print the hash table
    print_table(table, tsize);
}

// Function to search an element in the hash table
// Returns the index of the element if found, otherwise returns -1
int search(node *table[], int tsize, int key)
{
    int h = key % tsize; // Hash value
    node *p = table[h];
    // Traversing the linked list at the hash value index
    while (p != NULL)
    {
        // If element is found
        if (p->info == key)
        {
            printf("%d found at position %d\n", key, h);
            return h;
        }
        p = p->next;
    }
    // If element is not found in the hash table
    printf("%d not found in hash table\n", key);
    return -1;
}

// Function to delete an element from the hash table
void delete(node *table[], int tsize, int key)
{
    int h = key % tsize;
    table[h] = del(table[h], key);
    print_table(table, tsize);
}

void main()
{
    // Preparing the input array and hash table
    int m = 10;
    int arr[] = {12, 34, 21, 32, 25, 14, 31, 53, 64, 17, 29};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *table[m];
    empty_hash_table(table, m);

    // Inserting, searching and deleting elements from the hash table using chaining
    chaining(table, m, arr, size);
    int index = search(table, m, 32);
    delete(table, m, 53);
}