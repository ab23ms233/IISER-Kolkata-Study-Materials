# QUESTION
# Repeat the problem in (7) using a numpy array radius_np containing five radii values (same as in radius_list) to store the corresponding areas in another numpy array area_np.

import numpy as np

# Initialising arrays
area_np = np.zeros(5)
radius_np = np.random.randint(0, 10, size=(1,5))
print(radius_np)

# Define the function to calculate area of a circle
def calc_area(r):
    return np.pi*r**2

area_np = calc_area(radius_np)
print(area_np)