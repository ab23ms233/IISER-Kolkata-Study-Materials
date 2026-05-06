#include <stdio.h>

// Function to print the hash table
void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

// Function to create an empty hash table initialized with -1
void empty_hash_table(int *table, int tsize)
{
    for (int i = 0; i < tsize; i++)
        table[i] = -1;
}

// Function to perform linear probing for inserting elements into the hash table
void linear_probing(int table[], int m, int arr[], int size)
{
    int h, H, inserted = 0;

    // Traversing through the input array
    for (int i = 0; i < size; i++)
    {
        int element = arr[i];
        h = element % m; // Hash value

        // Inserting element if hash value is empty
        if (table[h] == -1)
        {
            table[h] = element;
            inserted = 1;
            printf("%d inserted at position %d\n", element, h);
        }
        // Handling collision using linear probing
        else
        {
            printf("Collision for %d at position %d\n", element, h);
            // Probing for the next available slot
            for (int j = 1; j < m; j++)
            {
                H = (h + j) % m;

                if (table[H] == -1)
                {
                    table[H] = element;
                    inserted = 1;
                    printf("%d inserted at position %d\n", element, H);
                    break;
                }
            }
        }
        // If element could not be inserted
        if (!inserted)
            printf("Hash table is full. %d could not be inserted\n", element);

        inserted = 0;
    }

    // Print the hash table
    print_array(table, m);
}

// Function to search for an element in the hash table
// Returns the index of the element if found, otherwise returns -1
int search(int table[], int m, int key)
{
    int h, H, found = 0;
    h = key % m; // Hash value
    // If element is found at the hash value index
    if (key == table[h])
        return h;

    // Handling collision using linear probing
    for (int j = 1; j < m; j++)
    {
        H = (h + j) % m;
        if (key == table[H])
            return H;
    }
    // If element is not found in the hash table
    return -1;
}

// Function to delete an element from the hash table
void delete(int table[], int m, int key)
{
    // Searching for the element to be deleted
    int index = search(table, m, key);
    // If element is found
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
    int m = 10;
    int arr[] = {12, 34, 21, 32, 25, 14, 31, 53, 64, 17, 29};
    int size = sizeof(arr) / sizeof(arr[0]);
    int table[m];
    empty_hash_table(table, m);

    // Inserting
    linear_probing(table, m, arr, size);
    printf("\n");

    // Searching
    int search_key = 32;
    int index = search(table, m, search_key);

    if (index != 1)
        printf("%d found at position %d\n", search_key, index);
    else
        printf("%d not found in has table\n", search_key);
    printf("\n");

    // Deleting
    int delete_key = 34;
    delete(table, m, delete_key);
}