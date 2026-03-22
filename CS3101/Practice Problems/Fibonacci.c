#include <stdio.h>

// RECURSION

// int fibonacci(int num)
// {
//     if (num == 0)
//     {
//         return 0;
//     }
//     else if (num == 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return fibonacci(num - 1) + fibonacci(num - 2);
//     }
// }

// void main()
// {
//     int n;

//     printf("Enter the number of terms: ");
//     scanf("%d", &n);

//     int result = fibonacci(n);
//     printf("Term %d: %d", n, result);
// }

// LOOPS

void main() {
    int t0 = 0;
    int t1 = 1;
    int next_term;

    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 1; i < n; i++) {
        next_term = t0 + t1;
        t0 = t1;
        t1 = next_term;
    }

    printf("Term %d: %d", n, next_term);
}