#include <stdio.h>

int isPalindrome(int num) {
    int remainder, reverse_num;
    int num_copy = num;

    while (num) {
        remainder = num%10;
        reverse_num = reverse_num*10 + remainder;
        num = num/10;
    }

    if (num_copy == reverse_num) {
        return 1;
    }
    else {
        return 0;
    }
}

void main() {
    int num;

    printf("Enter number to check for palindrome: ");
    scanf("%d", &num);

    int result = isPalindrome(num);

    if (result == 1) {
        printf("%d is palindrome", num);
    }
    else {
        printf("%d is not palindrome", num);
    }
}