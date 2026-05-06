# QUESTION
# Given any 2-D NumPy array of dimension , create a 3-D array B of dimension , composed of the  matrix components taken from the top-left, top-right, bottom-left and bottom-right corners of A. Use the concept of array slicing in order to achieve this.

import numpy as np

arr = np.resize([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16], (4,4))
arr_B = np.empty((4,2,2))
arr_B[:1,:2,:2] = np.resize(arr[:2,:2], (1,2,2))
arr_B[1:2, :2, :2] = np.resize(arr[:2, 2:], (1,2,2))
arr_B[2:3, :2, :2] = np.resize(arr[2:,:2], (1,2,2))
arr_B[3:,:2,:2] = np.resize(arr[2:,2:], (1,2,2))

print(arr_B)
print(arr_B.shape)