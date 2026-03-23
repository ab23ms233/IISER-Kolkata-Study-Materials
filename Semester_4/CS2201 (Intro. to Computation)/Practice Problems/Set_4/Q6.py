# QUESTION
# Print the numpy array [[1,2,3], [4, 5, 6]] column-wise by using slicing.

import numpy as np

arr = np.array([[1,2,3], [4,5,6]])
rows, columns = arr.shape

for row in range(rows):
    print(arr[row])