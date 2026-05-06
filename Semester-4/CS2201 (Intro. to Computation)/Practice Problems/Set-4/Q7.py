# QUESTION
# Define a function calc_area (using def) that takes a radius (r) and returns the area of a circle (use math.pi). Take a list radius_list containing five radii values and use calc_area to store the corresponding areas in another list area_list.

import math

# Define the function to calculate area of a circle
def calc_area(r):
    return math.pi*r**2

# Taking input for radius list
radius_list = eval(input("Enter radii: "))
area_list = []

# Calculating area for each radius
for r in radius_list:
    area = calc_area(int(r))
    area_list.append(area)

print(area_list)