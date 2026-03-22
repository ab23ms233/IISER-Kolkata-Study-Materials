#include <stdio.h>

void main() {
    // printf("Size of int: %zu bytes\n", sizeof(int));
    // printf("Size of float: %zu bytes\n", sizeof(float));
    // printf("Size of character: %zu bytes", sizeof(char));

    // int a = 34;
    // int *ptr = &a;
    // printf("Value of a: %d\n", *ptr);
    // printf("Address of a: %d\n", ptr);
    // ptr++;
    // printf("Modified address of a: %d\n", ptr);
    // printf("Value at modified address of a: %d", *ptr);

    int arr[] = {10, 30, 21, 12};
    int *ptr = arr;
    printf("Address of arr[0]: %d\n", &arr[0]);
    printf("Address of arr: %d\n", ptr);
    printf("Address of arr: %d\n", arr);
    ptr++;
    printf("Address of arr[1]: %d\n", &arr[1]);
    printf("Address of arr[1]: %d\n", (arr+1));
    printf("Value of arr[1]: %d\n", *(arr+1));
}