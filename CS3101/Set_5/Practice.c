#include <stdio.h>
#include <string.h>

// int increment(int num) {
//     return num++;
// }

void main()
{
    // int arr[] = {1,2,3,4,5};
    // printf("Enter a number: ");
    // scanf("%d", &n);

    // int *ptr = arr;
    // printf("Value of arr[0]: %d\n", ptr[0]);
    // printf("Address of arr[1]: %d\n", (ptr+1));
    // printf("Address of arr[1]: %d\n", &arr[1]);
    // printf("Value of arr[2]: %d\n", *(ptr+2));
    // printf("Value of arr[3]: %d\n", ptr[3]);

    // int result = increment(n);

    // printf("n: %d", )

    // char name[20];
    // strcpy(name, "Arya");
    // // printf("Value of name: %s\n", name);
    // name[4] = 'b';

    // int i = 0;
    // while (name[i] != '\0')
    // {
    //     printf("%c\n", name[i]);
    //     i++;
    // }

    int n = 5;
    int rows = 5;
    int t0 = 0;
    int t1 = 1;
    int next_term = 0;

    for (int j = 0; j < rows; j++)
    {
        for (int i = 0; i < t1; i++)
        {
            printf("* ");
        }

        printf("\n");
        next_term = t0 + t1;
        t0 = t1;
        t1 = next_term;
    }
}