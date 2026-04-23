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
int left(int size, int index)
{
    if (2*index+1 < size && index >= 0)
        return 2 * index + 1;
    return -1; 
}
// Function to get the index of the right child of a node
int right(int size, int index)
{
    if (2*index+2 < size && index >= 0)
        return 2 * index + 2;
    return -1;
}

// Max heapify function to maintain the max heap property at an index
void maxHeapify(int arr[], int size, int index)
{
    int largest = index;
    int l = left(size, index);
    int r = right(size, index);
    // Finding largest among index, left and right
    if (l < size && arr[index] < arr[l])
        largest = l;
    if (r < size && arr[largest] < arr[r])
        largest = r;

    // If largest is not index, swap and continue heapifying
    if (largest != index)
    {
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, size, largest);
    }
    // print_array(arr, size);
}

// Function to build a max heap from an array
void buildmaxHeap(int arr[], int size)
{
    int start = size/2-1;
    for (int i = start; i > -1; i--)
    {
        maxHeapify(arr, size, i);
        // printf("%d %d\n", i, arr[i]);
        // print_array(arr, size);
    }
        
}
// Function to perform heap sort on an array
void heapSort(int arr[], int size)
{
    buildmaxHeap(arr, size);

    for (int i = size-1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, i, 0);
        // print_array(arr, size);
    }
}