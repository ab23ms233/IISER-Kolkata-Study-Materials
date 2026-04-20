#include <stdio.h>

// Function to print the hash table
void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n"); 
}

// Function to create an empty hash table initialized with -1
int* empty_hash_table(int table[], int tsize)
{
    for (int i = 0; i < tsize; i++)
    {
        table[i] = -1;
    }
    return table;
}

// Function to perform linear probing for inserting elements into the hash table
void linear_probing(int table[], int m, int arr[], int size)
{
    int h, H, inserted = 0;

    // Traversing through the input array
    for (int i = 0; i < size; i++)
    {
        int element = arr[i];
        h = element%m;  // Hash value

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
                H = (h+j)%m;

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
    h = key%m;  // Hash value
    // If element is found at the hash value index
    if (key == table[h])
    {
        printf("%d found at position %d\n", key, h);
        return h;
    }
    // Handling collision using linear probing
    for (int j = 1; j < m; j++)
    {
        H = (h+j)%m;
        if (key == table[H])
        {
            printf("%d found at position %d\n", key, H);
            return H;
        }
    }
    // If element is not found in the hash table
    printf("%d not found\n", key);
    return -1;    
}

// Function to delete an element from the hash table
void delete(int table[], int m, int key)
{
    int h, H, found = 0;
    h = key%m;  // Hash value
    // If element is found at the hash value index
    if (table[h] == key)
    {
        table[h] = -1;
        printf("%d deleted from position %d\n", key, h);
        found = 1;
    }
    // Handling collision using linear probing
    else
    {
        for (int j = 1; j < m; j++)
        {
            H = (h+j)%m;
            if (key == table[H])
            {
                table[H] = -1;
                printf("%d deleted from position %d\n", key, H);
                found = 1;
                break;
            }
        }
    }
    // If element is not found in the hash table
    if (!found)
        printf("%d not found\n", key);
    // Print the hash table
    print_array(table, m);    
}

void main()
{
    // Preparing the input array and hash table
    int m = 10;
    int arr[] = {12, 34, 21, 32, 25, 14, 31, 53, 64, 17, 29};
    int size = sizeof(arr)/sizeof(arr[0]);
    int table[m];
    int* hash_table = empty_hash_table(table, m);

    // Inserting, searching and deleting elements from the hash table using linear probing
    linear_probing(hash_table, m, arr, size);
    printf("\n");
    int index = search(hash_table, m, 32);
    printf("\n");
    delete(hash_table, m, 34);
}