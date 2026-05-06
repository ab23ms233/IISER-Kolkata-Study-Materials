// QUESTION

// Write a program to dynamically allocate an array of strings, where you do not know the number of strings (and each string or the length) in advance.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    int num, ch;

    // Input for number of names 
    printf("Enter the number of names: ");
    scanf("%d", &num);
    while ((ch = getchar()) != '\n' && ch != EOF);      // Clearing input buffer before fgets, since scanf leaves \n at the end 
    printf("\n");

    // Allocating memory dynamically for an array of strings 
    char **names, name[50];
    names = malloc(num*sizeof(char *));

    // Taking user input for names
    for (int i = 0; i < num; i++)
    {
        printf("Enter name %d: ", i+1);
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;

        // Using the exact size of the string for storage 
        names[i] = malloc((strlen(name) + 1)*sizeof(char));
        strcpy(names[i], name);
    }
    printf("\n");

    // Printing the names
    for (int i = 0; i < num; i++)
    {
        printf("Name %d: %s\n", i+1, names[i]);
        free(names[i]);
    }
}