// QUESTION

// Implement a login interface using a do-while loop, asking a person his/her username and password, and allowing access in case of successful authentication. Assume that you have a known list of usernames in an array: UserNames, and the corresponding passwords (in the same order) in another array: Passwords. That is, array element UserName[i] corresponds to array element Passwords[i].

// Once the person inputs the username, search for the same in UserNames, and if it matches an element in UserNames, ask for the password, which you search in Passwords. You may use the code of “linear search” on slide number 23 of “Loops” on the WeLearn page for the course.

// If the username and password match, print a message ‘Welcome!’ In case of a mismatch, print an appropriate message and ask if the person wants to continue; if yes, ask for the username and password again; else, terminate the loop.

// Note: You may assume that both the username and passwords are integers. In the later versions, you should be able to consider strings.

#include <stdio.h>

// Function for sum of digits
int sum_of_digits(int num)
{
    int remainder;
    int sum = 0;

    while (num)
    {
        remainder = num % 10;
        sum += remainder;
        num = num / 10;
    }

    return sum;
}

// Function for checking if the credentials are correct
// Incorrect Username --> Returns -1
// Correct Username; Incorrect Password --> Returns 0
// Correct Username; Correct Password --> Returns 1
int check_credentials(int Usernames[], int Passwords[], int size)
{
    int username, password;

    printf("Enter username: ");
    scanf("%d", &username);

    for (int i = 0; i < size; i++)
    {
        // Correct Username
        if (Usernames[i] == username)
        {
            printf("Enter password: ");
            scanf("%d", &password);

            if (Passwords[i] == password) // Correct Password
            {
                return 1;
            }
            else // Incorrect Password
            {
                return 0;
            }
        }
    }

    return -1;
}

void main()
{
    // Generating Username and Passwords
    int size = 5;
    int Usernames[size];
    int Passwords[size];
    int initial_username = 101;
    int username;

    for (int i = 0; i < size; i++)
    {
        username = initial_username + i;
        Usernames[i] = username;
        Passwords[i] = sum_of_digits(username); // Password is the sum of the digits of the username
    }

    // Checking for correct login credentials
    int choice;

    do
    {
        int result = check_credentials(Usernames, Passwords, size);

        if (result == 1)
        {
            printf("Welcome!\n");
            break;
        }
        else if (result == 0)
        {
            printf("Incorrect Password\n");
        }
        else
        {
            printf("Incorrect Username\n");
        }

        // If the user wants to continue
        printf("Do you wish to continue?\nIf yes, enter 1\nIf no, enter 0\n");
        scanf("%d", &choice);
        printf("\n");
    } while (choice);
}