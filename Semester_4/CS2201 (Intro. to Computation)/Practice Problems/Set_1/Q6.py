# QUESTION
# Write a Python program to remove the K'th element from a given list, and print the updated list.
# Original list:
# [1, 1, 2, 3, 4, 4, 5, 1]
# After removing an element at the kth position of the said list:
# [1, 1, 3, 4, 4, 5, 1]

l = eval(input("Enter list: "))
pos = int(input("Enter the position: "))

l.pop(pos-1)
print(l)
