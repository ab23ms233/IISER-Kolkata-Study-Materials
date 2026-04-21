#include <stdio.h>

// Function to print the hash table
void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

// Function to create an empty hash table initialized with -1
void empty_hash_table(int table[], int tsize)
{
    for (int i = 0; i < tsize; i++)
        table[i] = -1;
}

// Function to perform double hashing for inserting elements into the hash table
void doubleHashing(int table[], int m, int n, int arr[], int size)
{
    int h, hp, H, element, inserted = 0;
    // Traversing through the input array
    for (int i = 0; i < size; i++)
    {
        element = arr[i];
        h = element % m; // Hash value
        // Inserting element if hash value is empty
        if (table[h] == -1)
        {
            table[h] = element;
            printf("%d inserted at position %d\n", element, h);
            inserted = 1;
        }
        // Handling collision using double hashing
        else
        {
            // Probing for the next available slot
            for (int j = 1; j < m; j++)
            {
                hp = n - element % n;
                H = (h + hp * j) % m;

                if (table[H] == -1)
                {
                    table[H] = element;
                    printf("%d inserted at position %d\n", element, H);
                    inserted = 1;
                    break;
                }
            }
        }
        // If element could not be inserted
        if (!inserted)
            printf("%d could not be inserted\n", element);

        inserted = 0;
    }
    // Print the hash table
    print_array(table, m);
}

// Function to search an element in the hash table
// Returns the index of the element if found, otherwise returns -1
int search(int table[], int m, int n, int key)
{
    int h, hp, H;
    h = key % m;
    // If element is found at the hash value index
    if (table[h] == key)
        return h;
    // Probing for the element using double hashing
    for (int i = 1; i < m; i++)
    {
        hp = n - key % n;
        H = (h + hp * i) % m; // Modified hash value for probing

        if (table[H] == key)
            return H;
    }
    // If element is not found in the hash table
    return -1;
}

// Function to delete an element from the hash table
void delete(int table[], int m, int n, int key)
{
    int index = search(table, m, n, key);
    // If element is found in the hash table
    if (index != 1)
    {
        table[index] = -1;
        printf("%d deleted from position %d\n", key, index);
    }
    // If element is not found in the hash table
    else
        printf("%d not found\n", key);
    // Print the hash table after deletion
    print_array(table, m);
}

void main()
{
    // Preparing the input array and hash table
    int m = 11, n = 7;
    int arr[] = {75, 66, 22, 34, 45, 10, 12, 33, 89, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int table[m];
    empty_hash_table(table, m);

    // Inserting
    doubleHashing(table, m, n, arr, size);
    printf("\n");

    // Searching
    int search_key = 10;
    int index = search(table, m, n, search_key);

    if (index != 1)
        printf("%d found at position %d\n", search_key, index);
    else
        printf("%d not found in has table\n", search_key);
    printf("\n");

    // Deleting
    int delete_key = 5;
    delete(table, m, n, delete_key);
}