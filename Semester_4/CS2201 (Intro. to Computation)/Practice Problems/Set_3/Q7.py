# QUESTION
# Use while loop to reverse an integer stored in a variable n and store the reversed number in a variable rev. You can’t use a list, string operations or any Python functions for reversal.

n = 146
rev = 0

while n > 0:
    rem = n%10
    rev = rev*10 + rem
    n //= 10
    
print(rev)