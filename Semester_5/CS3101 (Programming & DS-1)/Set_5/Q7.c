// QUESTION

// Take three integers a, b and c as input. Store their addresses in pointers p, q and r, respectively. Using these pointers, print the sum and product of a, b and c.

#include <stdio.h>

void main()
{
    int a, b, c;

    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    printf("Enter c: ");
    scanf("%d", &c);

    int *p = &a;
    int *q = &b;
    int *r = &c;

    int product = (*p) * (*q) * (*r);
    int sum = *p + *q + *r;
    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);
}
