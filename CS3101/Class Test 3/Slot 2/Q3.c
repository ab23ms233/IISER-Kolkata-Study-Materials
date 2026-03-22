#include <stdio.h>
#include "myheader.h"

// Function to print an array
void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void main()
{
    // User input for dimension of array
    int dimension;
    printf("Enter dimension of vector: ");
    scanf("%d", &dimension);
    printf("\n");

    int vec1[dimension], vec2[dimension];
    int comp1, comp2;

    // User input for vector 1
    for (int i = 0; i < dimension; i++)
    {
        printf("Enter vector 1 component %d: ", i + 1);
        scanf("%d", &comp1);

        vec1[i] = comp1;
    }
    printf("\n");

    // User input for vector 2
    for (int i = 0; i < dimension; i++)
    {
        printf("Enter vector 2 component %d: ", i + 1);
        scanf("%d", &comp2);

        vec2[i] = comp2;
    }
    printf("\n");

    // Printing vectors 1 and 2
    printf("Vector 1: ");
    print_array(vec1, dimension);
    printf("Vector 2: ");
    print_array(vec2, dimension);

    // Calculating dot product
    int result = dot(vec1, vec2, dimension);
    printf("Dot Product: %d", result);
}