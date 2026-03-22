// QUESTION

// Assume you have a database of user names and passwords (integers, stored in arrays). Implement a system that allows users to create new user accounts (username and password) and expand the database of user accounts. Later, the same database is searched for usernames and passwords. Design a scheme that makes this search efficient in terms of Big O.

#include <stdio.h>

// Function to print elements of an Array
void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to find Non-Zero Elements of an array
int find_NonZero_Count(int array[], int size)
{
    int nonzero_count = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] != 0)
        {
            nonzero_count++;
        }
    }

    return nonzero_count;
}

// Function for Binary Search
// Returns the index of the element
// Returns -1 if not found
int Binary_Search(int array[], int size, int search_element)
{
    // Conduct search only on non-zero elements
    int nonzero_count = find_NonZero_Count(array, size);
    int start = 0;
    int end = nonzero_count - 1;
    int mid = (end + start) / 2;

    while (start = end + 1)
    {
        if (search_element == array[mid])
        {
            return mid;
        }
        else if (search_element > array[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = (start + end) / 2;
    }

    return -1; // If element is not found
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

    int index = Binary_Search(Usernames, size, username);

    if (index == -1) // Incorrect Username
    {
        return -1;
    }
    else
    {
        printf("Enter password: ");
        scanf("%d", &password);

        if (Passwords[index] == password) // Correct Password
        {
            return 1;
        }
        else // Incorrect Password
        {
            return 0;
        }
    }
}

// Checks if username already exists
// Returns 0 if its exists
// Returns 1 otherwise
int valid_username(int Usernames[], int username, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (Usernames[i] == username)
        {
            return 0;
        }
    }
    return 1;
}

void main()
{
    // Generating and storing Usernames and Passwords
    int size = 20;
    int filled = 10;
    int Usernames[size];
    int Passwords[size];
    int initial_username = 101;
    int initial_password = 1;

    for (int i = 0; i < size; i++)
    {
        // 1st "filled" usernames are of the form 101, 102, ......, 110
        // 1st "filled" passwords are of the form 1, 2, ....., 10
        if (i < filled)
        {
            Usernames[i] = initial_username + i;
            Passwords[i] = initial_password + i;
        }
        // After that, all usernames and passwords are 0 - empty slots
        else
        {
            Usernames[i] = 0;
            Passwords[i] = 0;
        }
    }

    // Printing Usernames and Passwords array
    printf("Usernames: ");
    print_array(Usernames, size);
    printf("Passwords: ");
    print_array(Passwords, size);
    printf("\n");

    // Creating accounts
    int choice = 1;
    int last_index = filled - 1;

    while (choice == 1)
    {
        if (last_index + 1 == size) // If array is full
        {
            printf("Sorry! Our server is full. You cannot create a new account\n");
            break;
        }
        else
        {
            int username, password;
            printf("Enter username: ");
            scanf("%d", &username);

            int valid = valid_username(Usernames, username, size);
            int repeat = 1;

            // Checking if username already exists
            while (repeat)
            {
                if (valid)
                {
                    repeat = 0;
                }
                else
                {
                    printf("Username already exists. Try a different one\n");
                    printf("\n");
                    printf("Enter username: ");
                    scanf("%d", &username);
                    
                    valid = valid_username(Usernames, username, size);
                }
            }

            printf("Enter password: ");
            scanf("%d", &password);
            printf("\n");

            // Initialising credentials
            Usernames[last_index] = username;
            Passwords[last_index] = password;
            last_index++;

            printf("Account created successfully\n");
            printf("Username: %d\n", username);
            printf("Password: %d\n", password);
            printf("\n");

            // If the user wants to continue
            printf("Do you wish to create another account?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%d", &choice);
            printf("\n");
        }
    }

    int result = check_credentials(Usernames, Passwords, size);

    if (result == -1) {
        printf("Incorrect Username\n");
    }
    else if (result == 0) {
        printf("Incorrect Password\n");
    }
    else {
        printf("Welcome!");
    }
}