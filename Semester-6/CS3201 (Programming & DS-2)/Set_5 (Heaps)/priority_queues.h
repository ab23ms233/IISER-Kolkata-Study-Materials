// MAX HEAP IMPLEMENTATION
#include <stdio.h>
#include "max_heaps.h"

// Function to get the index of the parent of a node
int parent(int index)
{
    if (index >= 1)
        return (index-1)/2;
    return -1;
}

// Function to get the maximum element from the max heap
int max(int arr[])
{
    return arr[0];
}
// Function to remove and return the maximum element from the max heap
int extract_max(int arr[], int *size)
{
    // If size is 0, then error
    if (*size == 0)
    {
        printf("No elements in queue\n");
        return -1;
    }
    // Extracting max element and restoring the max heap property
    int max = arr[0];
    arr[0] = arr[(*size)-1];
    (*size)--;
    // print_array(arr, *size);
    maxHeapify(arr, *size, 0);
    return max;
}

// Function to increase the value of a key at an index in the max heap
void increaseKey(int arr[], int index, int key)
{
    // If new key is smaller than current key, then error
    if (key<arr[index])
    {
        printf("New key is smaller than current key\n");
        return;
    }
    
    arr[index] = key;
    while (index>0 && arr[parent(index)] < arr[index])
    {
        // Swap arr[index] and arr[parent(index)]
        int temp = arr[index];
        arr[index] = arr[parent(index)];
        arr[parent(index)] = temp;
        // Move index to parent index
        index = parent(index);
    }
}

// Function to insert a new key in the max heap
void insert(int arr[], int *size, int key)
{
    (*size)++;
    arr[*size-1] = -999;
    increaseKey(arr, *size-1, key);
}
