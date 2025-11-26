#include <stdio.h>

// Function to calculate dot product
int dot(int *vec1, int *vec2, int dimension)
{
    int dot_product = 0;

    for (int i = 0; i < dimension; i++)
    {
        dot_product += vec1[i]*vec2[i];
    }
    
    return dot_product;
}