// QUESTION

// Spot the issues in the program that is supposed to print an incremented version of a variable:

// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>



// void main()
// {
//     int *a;
    
//     *a = 10;
    
//     *a++;
    
//     printf("%d\n", *a);


#include <stdio.h>

void main()
{
    int a;
    a = 10;
    a++;

    printf("%d", a);
}