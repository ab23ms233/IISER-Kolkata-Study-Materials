# QUESTION
# Write a python program to  swap the left and right halves of an input string s; the middle element will be unchanged for an odd length string. E.g. ‘kripa’ will be converted to ‘paikr’; ‘aman’ will be converted to ‘anam’.

s = input("Enter string: ")
n = len(s)
new = ""

# Length of string is even
if len(s)%2 == 0:
    left, right = s[:n//2], s[n//2:]
    new = right + left
    
# Length of string is odd
else:
    left, right = s[:n//2], s[n//2+1:]
    mid = s[n//2]
    new = right + mid + left

print(new)