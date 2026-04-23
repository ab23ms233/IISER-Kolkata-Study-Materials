#include <stdio.h>
#include "priority_queues.h"

void main()
{
    int arr[] = {16, 14, 8, 1, 4, 2, 10, 3, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int queue[size];
    int heap_size = 0;

    // Insering elements in the priority queue
    for (int i = 0; i < size; i++)
        insert(queue, &heap_size, arr[i]);

    print_array(queue, heap_size);
    printf("\n");
    // Extracting maximum element
    int max = extract_max(queue, &heap_size);
    printf("Max element: %d\n", max);
    print_array(queue, heap_size);
    printf("\n");
    // Increasing key of an index
    increaseKey(queue, 5, 12);
    print_array(queue, heap_size);
}