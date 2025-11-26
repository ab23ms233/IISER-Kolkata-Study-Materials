#include <stdio.h>
#include "Stacks.c"

void main()
{
    int choice;
    int repeat = 1;
    int element;

    while (repeat == 1)
    {
        printf("Choose from one of the following: \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display stack elements\n");
        printf("5. Quit\n");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(element);
            break;
        
        case 2:
            printf("Popped element: %d\n", pop());
            break;

        case 3:
            printf("Top Element: %d\n", peek());
            break;

        case 4:
            printf("Stack elements are: ");
            display();
            break;

        case 5:
            printf("Have a nice day\n");
            break;

        default:
            printf("Wrong Choice");
            break;
        }
        printf("\n");

        printf("Do you want to continue?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%d", &repeat);
        printf("\n");
    }
}