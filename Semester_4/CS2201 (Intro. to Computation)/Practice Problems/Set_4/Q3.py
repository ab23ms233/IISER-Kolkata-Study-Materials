# QUESTION
# Write a function encrypt() that accepts a string and maps each character of the string to the corresponding alphabet in the opposite order of alphabets. E.g. ‘a’ will be mapped to ‘z’, ‘b’ will be mapped to ‘y’, ‘z’ will be mapped to ‘a’ and so on. So, encrypt() will map ‘zbc’ to ‘ayx’. Assume that the input string is in the lower case. Note that ord(‘a’) gives the ASCII value of the character ‘a’ (i.e. 97) and chr(97) gives the character equivalent of 97 (i.e. ‘a’).

# The program uses the formula: rem = total - num, where total is the sum of ASCII values of ‘a’ and ‘z’ (i.e. 219) and num is the ASCII value of the character to be encrypted.
total = ord("a") + ord("z")

# Defining the encrypt function
def encrypt(s):
    new = ""
    
    for i in s:
        num = ord(i)
        rem = total - num
        element = chr(rem)
        new += element
    
    return new

s = input("Enter string: ")
print(encrypt(s))