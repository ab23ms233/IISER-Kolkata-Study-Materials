# QUESTION
# From a list [ [1, 2, 3, 4, 11], [100, 55, 80, 33, 22] ] create an equivalent numpy array arr. Apply an appropriate slicing operation on arr to print:
# [[ 4 11]
# [33 22]]

import numpy as np

l = [[1, 2, 3, 4, 11], [100, 55, 80, 33, 22]] 
arr = np.array(l)

print(arr)
print(arr[:,3:])