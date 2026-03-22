// QUESTION

// Write a C program to take first name (e.g., “Sachin”), middle name (e.g., “Ramesh”) and surname (e.g., “Tendulkar”) as input as separate strings, use string operations to store the full name in the format: first_name first_letter_of_middlename. surname (e.g., “Sachin R. Tendulkar”) in another string and print it.

#include <stdio.h>
#include <string.h>

void main() {
    char first_name[20], middle_name[20], last_name[20];
    char midname_short[4], name[62];

    // strcpy(first_name, "Arya");
    // strcpy(middle_name, "Srabanti");
    // strcpy(last_name, "Basak");

    printf("Enter first name: ");
    gets(first_name);
    printf("Enter middle name: ");
    gets(middle_name);
    printf("Enter last name: ");
    gets(last_name);
    printf("\n");

    // printf("First name: %s\n", first_name);
    // printf("Middle name: %s\n", middle_name);
    // printf("Last name: %s\n", last_name);

    // sprintf(name, "%s %c. %s", first_name, middle_name[0], last_name);
    midname_short[0] = middle_name[0];
    midname_short[1] = '.';
    midname_short[2] = ' ';
    midname_short[3] = '\0';

    strcpy(name, first_name);
    strcat(name, " ");
    strcat(name, last_name);
    printf("Full name: %s\n", name);
}