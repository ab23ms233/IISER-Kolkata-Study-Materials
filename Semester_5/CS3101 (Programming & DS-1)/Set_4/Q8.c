// QUESTION

// Write a C program to take the first name (e.g., “Sachin”) and surname (e.g., “Tendulkar”) as input in separate strings and using string operations to store the full name (“Sachin Tendulkar”) as a single string and print it.

#include <stdio.h>
#include <string.h>

void main() {
    char first_name[20], last_name[20], name[41];

    printf("Enter first name: ");
    gets(first_name);
    printf("Enter last name: ");
    gets(last_name);

    strcpy(name, first_name);
    strcat(name, " ");
    strcat(name, last_name);
    printf("Full name: %s\n", name);

}