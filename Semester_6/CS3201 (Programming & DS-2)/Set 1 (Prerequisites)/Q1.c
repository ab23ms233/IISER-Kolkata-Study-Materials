// Consider the code below. You are supposed to update the value of variable ‘a’ without directly modifying it. That is, you have to modify it through one of the other two variables: b and p. Will the following code modify a? If not, correct it. You are not allowed to introduce new variables.


// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>


// void main()
// {
//     int a, b, *p;
    
//     a = 10;
//     b = a;
    
//     p = &a;
    
//     b++;
    
       
//     printf("a = %d\n", a);
    
//   }


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() 
{
    int a, b, *p;

    a = 10;
    b = a;
    p = &a;

    // Given Code - Does not modify the value of a
    // b++;

    // Modifying a through p
    (*p)++;
    
    printf("a = %d\n", a);
}