// QUESTION
// Write a program in C	programming language to take the principal amount (P), time in years (T), and rate of interest (R) as input and print the Simple Interest (SI) and the Total Amount (A) on the terminal (formula: SI = (P*T*R)/100, A = P + SI).

# include <stdio.h>

void main() {
    float principal, roi;
    int time;

    printf("Enter Pricipal Amount: ");
    scanf("%f", &principal);

    printf("Enter Rate of Interest: ");
    scanf("%f", &roi);

    printf("Enter Time (in years): ");
    scanf("%d", &time);

    float si = (float) (principal*roi*time)/100;
    float amount = si + principal;

    printf("Simple Interest: %f\n", si);
    printf("Amount: %f\n", amount);
}