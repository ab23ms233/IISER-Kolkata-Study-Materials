// QUESTION

// Implement a login interface using a do-while loop, asking a person his/her username and password, and allowing access in case of successful authentication. Assume that you have a known list of usernames in an array: UserNames, and the corresponding passwords (in the same order) in another array: Passwords. That is, array element UserName[i] corresponds to array element Passwords[i].

// Once the person inputs the username, search for the same in UserNames, and if it matches an element in UserNames, ask for the password, which you search in Passwords. You may use the code of “linear search” on slide number 23 of “Loops” on the WeLearn page for the course.

// If the username and password match, print a message ‘Welcome!’ In case of a mismatch, print an appropriate message and ask if the person wants to continue; if yes, ask for the username and password again; else, terminate the loop.

// To implement the above, assume the most realistic setup where the names and passwords are strings, and you have a database of usernames and passwords to be stored in a file “Username-Password.txt”. First, construct a structure (using struct) USERIDPASSWORD containing the elements username and password (as strings). Only once, use fwrite() to write 20 username-password pairs of USERIDPASSWORD type variables in Username-Password.txt. Then, to implement the interface, read the file using fread() to retrieve the database, and store it in an array of USERIDPASSWORD, and search in this array.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct USERID_PASSWORD
{
    char username[20];
    char password[20];
};

void main()
{
    int num = 8; // 8 username-password pairs to be stored

    // Struct to be written to file
    struct USERID_PASSWORD database_to_write[] = {{"Arya", "Basak"},
                                                  {"Ananya", "Biswas"},
                                                  {"Rishav", "Raj"},
                                                  {"Soham", "Biswas"},
                                                  {"Krishna", "Tiwari"},
                                                  {"Ashutosh", "Jha"},
                                                  {"Anuvansh", "Dixit"},
                                                  {"Khushant", "Tomar"}};

    // Writing to File
    FILE *ptr = NULL;
    ptr = fopen("Database.txt", "wb");

    if (ptr == NULL)
    {
        printf("Error wrtitng to file");
        exit(1);
    }

    fwrite(&database_to_write, sizeof(struct USERID_PASSWORD), num, ptr);
    fclose(ptr);
    printf("Data recorded successfully\n");

    // Reading from File
    ptr = fopen("Database.txt", "rb");

    if (ptr == NULL)
    {
        printf("Error reading from file");
        exit(1);
    }

    // usernames and passwords stores usernames and passwords from file
    char usernames[num][20];
    char passwords[num][20];

    // All data stored in database_to_read in the form of USERID_PASSWORD struct
    struct USERID_PASSWORD database_to_read[num];
    fread(&database_to_read, sizeof(struct USERID_PASSWORD), num, ptr);

    // Copying usernames and passwords from database_to_read to usernames and passwords
    for (int i = 0; i < num; i++)
    {
        strcpy(usernames[i], database_to_read[i].username);
        strcpy(passwords[i], database_to_read[i].password);

        // printf("Username %d: %s\n", i + 1, usernames[i]);
        // printf("Password %d: %s\n", i + 1, passwords[i]);
        // printf("\n");
    }

    fclose(ptr);
    printf("Data read successfully\n");
    printf("\n");

    // Checking for correct username and password
    int repeat = 1;     // If user wants to continue
    char username[20], password[20];
    int username_flag = 0;
    int choice;

    while (repeat)
    {
        username_flag = 0;

        // Reading username
        printf("Enter username: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = 0;

        // Checking is username exists
        for (int i = 0; i < num; i++)
        {
            if (strcmp(username, usernames[i]) == 0)
            {
                username_flag = 1;

                // Reading password
                printf("Enter password: ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = 0;

                // Checking if password is correct
                if (strcmp(password, passwords[i]) == 0)
                {
                    printf("Welcome!\n");
                }
                else
                {
                    printf("Incorrect Password\n");
                }
                break;
            }
        }

        // If username is incorrect
        if (username_flag == 0)
        {
            printf("Incorrect Username\n");
        }
        printf("\n");

        // Whether the user wants to continue
        printf("Do you wish to continue?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf(" %d", &choice);
        printf("\n");

        while (getchar() != '\n');

        if (choice == 2)
        {
            repeat = 0;
        }
    }

    printf("Have a nice day!");
}