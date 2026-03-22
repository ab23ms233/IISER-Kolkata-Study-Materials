// QUESTION

// Implement a function F() that takes a first name (length not more than 9 characters) as an argument and “returns” the encrypted key formed by the first character, the last character, and appending the length of the name. E.g., if the first name is “James” the key is “Js5”. Note that to convert a single-digit integer (say, 5) to the corresponding character (here '5') in C, you can add the ASCII value of the character '0' to the integer. Now, you should implement F() in two different ways: i) you pass the ONLY name as an argument and return the key, and ii) you pass BOTH the name and a variable that will store the key as arguments but returns nothing.

#include <stdio.h>
#include <string.h>

// Function for part (i)
char *F1(const char *str_ptr)
{
    char first = str_ptr[0];         // First character
    int length = strlen(str_ptr);    // Length of string
    char last = str_ptr[length - 1]; // Last character

    // Secret Key
    static char key[4];
    key[0] = first;
    key[1] = last;
    key[2] = (length + '0');
    key[3] = '\0';

    return key;
}

// Function for part (ii)
void F2(const char *str_ptr, char *key)
{
    int length = strlen(str_ptr);

    key[0] = str_ptr[0];
    key[1] = str_ptr[length - 1];
    key[2] = (length + '0');
    key[3] = '\0';
}

void main()
{
    char name[9];

    // Reading name from user
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    printf("\n");

    char *ptr1 = F1(name);
    char *ptr2;
    F2(name, ptr2);

    printf("Secret key for %s from F1(): %s\n", name, ptr1);
    printf("Secret key for %s from F2(): %s\n", name, ptr2);
}
