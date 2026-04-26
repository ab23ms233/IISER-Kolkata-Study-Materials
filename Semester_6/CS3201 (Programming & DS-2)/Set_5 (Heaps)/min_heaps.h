// MAX HEAP IMPLEMENTATION
#include <stdio.h>

// Function to print an array
void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}
// Function to get the index of the left child of a node
// Returns -1 if left index is beyond size
int left(int size, int index)
{
    if (2*index+1 < size && index >= 0)
        return 2 * index + 1;
    return -1; 
}
// Function to get the index of the right child of a node
// Returns -1 if right index is beyond size
int right(int size, int index)
{
    if (2*index+2 < size && index >= 0)
        return 2 * index + 2;
    return -1;
}

// Min heapify function to maintain the min heap property at an index
void minHeapify(int arr[], int size, int index)
{
    int min = index;
    int l = left(size, index);
    int r = right(size, index);

    // Finding min among index, left and right
    if (l != -1 && arr[index] > arr[l])
        min = l;
    if (r != -1 && arr[min] > arr[r])
        min = r;

    // If min is not index, swap and continue heapifying
    if (min != index)
    {
        int temp = arr[index];
        arr[index] = arr[min];
        arr[min] = temp;
        // print_array(arr, size);
        minHeapify(arr, size, min);
    }
    // print_array(arr, size);
}

// Function to build a min heap from an array
void buildminHeap(int arr[], int size)
{
    int start = size/2-1;
    for (int i = start; i > -1; i--)
    {
        minHeapify(arr, size, i);
        // printf("%d %d\n", i, arr[i]);
        // print_array(arr, size);
    }
        
}
// Function to perform heap sort on an array
void heapSort(int arr[], int size)
{
    buildminHeap(arr, size);

    for (int i = size-1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        minHeapify(arr, i, 0);
        // print_array(arr, size);
    }
}