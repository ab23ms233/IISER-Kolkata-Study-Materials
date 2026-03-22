// QUESTION

// Write programs to print the following patterns (for any n) using loops:

// a) For n  = 10, output:

// 10
// 10 9
// 10 9 8
// ….
// 10 9 8 7 6 5 4 3 2 1

// b) For n = 5, output:

// 1
// 1 1
// 1 1 2
// 1 1 2 3
// 1 1 2 3 5

// c) For n = 5, output:

//             1
//          1     1
//        1    2    1
//     1    3     3    1
//  1    4     6     4    1

// d)  For n = 5, output:

// 5
// 5 4 5
// 5 4 3 4 5
// 5 4 3 2 3 4 5
// 5 4 3 2 1 2 3 4 5

// e) For n = 4, output:

// 1 2 3 4
// 2 3 4
// 3 4
// 4


#include <stdio.h>

void main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    // Part a
    // for (int row = 1; row <= n; row++) {
    //     for (int column = 0; column < row; column++) {
    //         printf("%d ", n-column);
    //     }
    //     printf("\n");
    // }

    // Part b
    // int t0 = 0;
    // int t1 = 1;
    // int next_term;
    // for (int row = 1; row <= n; row++) {
    //     for (int column = 1; column <= row; column++) {
    //         printf("%d ", t1);
    //         next_term = t0 + t1;
    //         t0 = t1;
    //         t1 = next_term;
    //     }
    //     printf("\n");
    //     t0 = 0;
    //     t1 = 1;
    // }

    // Part c
    // for (int row = 0; row < n; row++) {
    //     for (int space = 1; space <= 2*(n-row-1); space++) {
    //         printf(" ");
    //     }
        
    //     int val = 1;
    //     for (int column = 0; column <= row; column++) {
    //         if (column == 0) {
    //             printf("%d", val);
    //         }
    //         else {
    //             printf("%4d", val);
    //         }
    //         val = val*(row-column)/(column+1);
    //     }

    //     printf("\n");
    // }

    // Part d
    // for (int row = 0; row < n; row++) {

    //     for (int reverse = n; reverse >=n-row; reverse--) {
    //         printf("%d ", reverse);
    //     }
    //     for (int backward = n-row+1; backward <= n; backward++) {
    //         printf("%d ", backward);
    //     }

    //     printf("\n");
    // }

    // Part e
    for (int row = 1; row <= n; row++) {
        for (int column = 0; column <= n-row; column++) {
            printf("%d ", row+column);
        }
        printf("\n");
    }
}