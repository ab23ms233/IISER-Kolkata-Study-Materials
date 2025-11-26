#include <stdio.h>
#include <string.h>

void main() {
    // int rows = 10;

    // for (int i = 1; i <= rows; i++)
    // {
    //     for (int j = i; j <= rows-i; j++)
    //     {
    //         printf("%d ", j);
    //     }
    //     printf("\n");
    // }

    const int size = 5;
    char arr[size][10];
    char element[10];

    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%s", &element);

        strcpy(arr[i], element);
    }
    printf("\n");
    
    printf("Array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", arr[i]);
    }
    
}