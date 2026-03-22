// QUESTION

// Design an employee leave management system. An employee can have Casual Leave, Special Casual Leave, Vacation Leave, On-duty Leave, and Restricted Holiday Leave, with details shown in the table below. The “Nos” are the number of leaves for each employee.

// Sl no.
// Leave Type
// Nos
// Prerequisites
// 1
// Casual Leave
// 30
// None
// 2
// Special Casual leave
// 15
// Invitation Letter
// 3
// On-duty Leave
// 10
// Invitation Letter
// 4
// Vacation Leave
// 60
// Should be only for June, July, and December
// 5
// Restricted Holiday Leave
// 5
// Should appear in the list of restricted holidays

// Assume that there are 10 employees with unique employee IDs. An employee applying for leave should be able to log in using their username and password (you may reuse the solution from Q2). Once the login is successful, you should ask the employee to choose from the list of leave types showing the number of leave available for that employee. The employee, after choosing the type of leave, also enters the number of days of leave applied (except restricted holiday leave, where only one day at a time is permissible). If that is available, grant immediately for type 1 (Casual Leave) and update the Nos.
// For types 2 and 3, ask the employee if the “invitation letter” is available; if yes, grant and update; otherwise, deny.
// For Vacation leave, also ask for the month for which the leave is applied, and grant based on availability if the month is June, July, or December.
// For restricted holidays, maintain a record of restricted holidays (day, month)  in array(s), storing only for the current year. Ask the employee for the day and month for which leave is requested (restricted holidays can be granted only one day at a time). If the requested date appears in the permitted days (through a search in the array(s)), grant; otherwise, deny.

// For all the leave types, the leave nos will be updated if granted, and a request for a number exceeding the available nos will be denied. The Prerequisites for leave also need to be adhered with. The balance leave will be shown again, and the employee will be asked if the employee wants to continue. Act according to the choice provided using an appropriate loop. After the loop ends, print the final leave balance for that employee for all the leave types.

// Note: This is expected to be a bare-minimum version (call it v1). You should be able to upgrade to superior versions later, after topics like string handling (to handle non-integer variables), I/O (reading and writing floating points, strings, formatting, etc.), functions (modularization; building your own header files), structures (encapsulation of all the details of one employee), files (creation of permanent employee database on hard drive, loading, updating them), complexity of algorithms (writing efficient implementations), efficient searching in the employee database (e.g. binary search) etc. are covered

#include <stdio.h>

void main()
{
    // Generating Username and Passwords
    int size = 10;
    int Usernames[size];
    int Passwords[size];
    int initial_username = 100;

    for (int i = 0; i < size; i++)
    {
        int username = initial_username + i;
        Usernames[i] = username;
        int num = username;
        int sum = 0;

        while (num)
        {
            int remainder = num % 10;
            sum += remainder;
            num = num / 10;
        }

        Passwords[i] = sum;
        printf("Username: %d; Password: %d\n", username, sum);
    }
    printf("\n");

    // Checking for Login Credentials
    int username_flag = -1;
    int password_flag = -1;
    int username, password, choice;

    do
    {
        printf("Enter username: ");
        scanf("%d", &username);
        username_flag = -1;

        for (int i = 0; i < size; i++)
        {
            if (Usernames[i] == username)
            {
                username_flag = i;
                printf("Enter password: ");
                scanf("%d", &password);

                if (Passwords[i] == password)
                {
                    printf("Welcome!\n");
                    password_flag = i;
                }
                else
                {
                    printf("Incorrect Password!\n");
                }
                break;
            }
        }

        if (username_flag == -1)
        {
            printf("Incorrect Username!\n");
        }
        else if (password_flag > -1)
        {
            break;
        }

        printf("Do you wish to continue?\nIf yes, enter 1\nIf no, enter 0\n");
        scanf("%d", &choice);
        printf("\n");
    } while (choice);

    // Generating Leave Arrays for all users
    int casual_leave[size];
    int special_casual_leave[size];
    int on_duty_leave[size];
    int vacation_leave[size];
    int restricted_holiday_leave[size];

    for (int i = 0; i < size; i++)
    {
        casual_leave[i] = 30;
        special_casual_leave[i] = 15;
        on_duty_leave[i] = 10;
        vacation_leave[i] = 60;
        restricted_holiday_leave[i] = 5;
    }

    // Asking for type of Leave and No.
    int leave_choice;
    int user_index = username_flag;
    int repeat = 1;

    while (repeat)
    {
        printf("Which type of leave do you want?\n");
        printf("1. Casual Leave - Available: %d\n", casual_leave[user_index]);
        printf("2. Special Casual Leave - Available: %d\n", special_casual_leave[user_index]);
        printf("3. On-Duty Leave - Available: %d\n", on_duty_leave[user_index]);
        printf("4. Vacation Leave - Available: %d\n", vacation_leave[user_index]);
        printf("5. Restricted Holiday Leave - Available: %d\n", restricted_holiday_leave[user_index]);
        scanf("%d", &leave_choice);

        if (leave_choice == 1) {
            if (casual_leave[user_index] > 0) {
                int days;
                printf("Enter number of days: ");
                scanf("%d", &days);

                if (casual_leave[user_index] - days >= 0) {
                    printf("Your leave is granted!\n");
                    casual_leave[user_index] -= days;
                }
                else {
                    printf("Number of days exceeding the available leaves. Request Denied!\n");
                }

                printf("Available Casual Leaves: %d\n", casual_leave[user_index]);
            }

            else {
                printf("No casual leaves remaining. Request Denied!\n");
            }
        }

        else if (leave_choice == 2){

        }
    }
}