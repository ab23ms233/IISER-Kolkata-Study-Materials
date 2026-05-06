#include <stdio.h>
#include "heaps.h"

void main()
{
    int arr[] = {4, 1, 3, 2, 7, 9, 10, 14, 8, 16};
    int size = sizeof(arr) / sizeof(arr[0]);

    int index = 3, element = arr[index];

    // Implementing max heapify
    maxHeapify(arr, size, index);
    print_array(arr, size);
    printf("\n");
    // Implementing build max heap
    buildmaxHeap(arr, size);
    print_array(arr, size);
    printf("\n");
    // Implementing heap sort
    heapSort(arr, size);
    print_array(arr, size);
}