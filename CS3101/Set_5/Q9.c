// QUESTION

// Assume that all the secret codewords (integers) of the members of a gang “Prime Suspects” have a property: the sum of the digits is a prime number (e.g., code word: 111, 10523 etc.).  Write a C program to implement the following scheme. A person inputs the codeword (taken as input by a function getCodeword() and returned to main()). This inputted codeword passes through functions: sumOfDigits() and isPrime() to check whether the aforementioned property is satisfied by the codeword. If yes, there should be a welcome message like “Welcome to Prime Suspect gang!”; else, print an intruder alert message.

#include <stdio.h>
#include <math.h>

// Function to get Codeword
int getCodeword()
{
    int codeword;

    printf("Enter codeword: ");
    scanf("%d", &codeword);

    return codeword;
}

// Function to calculate sum of digits of a number
int sumOfDigits(int num)
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

// Function to check whether a number is prime or not
// Returns 1 if prime
// Returns 0 if it is not prime
int isPrime(int num)
{
    if (num == 1)
    {
        return 0;
    }
    else if (num == 2)
    {
        return 1;
    }

    int factors = (int) pow(num, 0.5);
    for (int i = 2; i <= factors; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}


void main()
{
    int codeword = getCodeword();
    int sum = sumOfDigits(codeword);
    int result = isPrime(sum);

    if (result == 0)
    {
        printf("Intruder ALERT!");
    }
    else
    {
        printf("Welcome to Prime Suspect gang!");
    }
}