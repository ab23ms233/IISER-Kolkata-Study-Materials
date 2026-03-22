// QUESTION

// Use Valgrind to check for memory leaks in the following code:

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
    int *a;
    a = (int*)malloc(5*sizeof(int));
    free(a);
    
    printf("%d\n", a[0]);
}
