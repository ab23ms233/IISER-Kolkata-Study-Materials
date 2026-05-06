# QUESTION
# Write a Python program to convert a list of characters into a string.

char_list = eval(input("Enter the list of characters: "))
s = ''

for i in range(len(char_list)):
    s += char_list[i]
print(s)
