# QUESTION
# Create a 1-D NumPy array containing 9 elements, taken as inputs from the user. Now, use a single statement and negative slicing to print the array elements in reverse order.

import numpy as np
arr = np.empty(9)

for i in range(9):
    x = int(input("Enter element: "))
    arr[i] = x

print(arr)
print(arr[::-1])