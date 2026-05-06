# QUESTION
# Create a 1-D NumPy array containing 9 elements, taken as inputs from the user. Now, use array slicing to accomplish the following:
# a. Print the last 3 elements from the array
# b. Print the first 3 elements from the array
# c. Print the middle 3 elements from the array
# d. Print the 5th-last element to 2nd-last element (included) using negative slicing
# e. Replace every second element starting from index 1 of the array with 0, and print the updated array

import numpy as np
arr = np.empty(9)

# User input
for i in range(9):
    x = int(input("Enter element: "))
    arr[i] = x

print(arr[-3:])
print(arr[:3])
print(arr[3:6])
print(arr[-5:-1])

for i in range(1,9,2):
    arr[i] = 0

print(arr)