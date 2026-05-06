# QUESTION
# Take a number as input (use input()) and using the dictionary d = {1 : 'ONE', 2 : 'TWO', 3 : 'THREE', 4 : 'FOUR', 5 : 'FIVE', 6 : 'SIX', 7 : 'SEVEN', 8 : 'EIGHT', 9 : 'NINE'} only print the number as words. If the input is 1234, the output should be ONE TWO THREE FOUR. Note that, you have to use only this dictionary (and no other source) to convert each digit of the input number to the corresponding word equivalent.

# Defining dictionary
d = {1 : 'ONE', 2 : 'TWO', 3 : 'THREE', 4 : 'FOUR', 5 : 'FIVE', 6 : 'SIX', 7 : 'SEVEN', 8 : 'EIGHT', 9 : 'NINE'}

# Converting digits to a list
digits = list(input("Enter number: "))
word = ''

# Converting each digit to the corresponding word and concatenating them
for i in digits:
    word += d[int(i)] + ' '

# Removing last space
word = word[:-1]
print(word)