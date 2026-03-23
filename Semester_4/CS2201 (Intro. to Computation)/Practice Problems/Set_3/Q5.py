# QUESTION
# Given two lists L1 = [1, 2, 3, 4, 5] and L2 = [5, 4, 10, 12], use list comprehension to generate another list L3 containing the sum of the odd elements in L1 and L2.

# Defining lists
L1 = [1,2,3,4,5]
L2 = [5,4,10,12]
L3 = []

# Traversing both lists and checking for odd elements
for x in L1:
    for y in L2:
        if x%2 != 0 and y%2 != 0:
            L3.append(x+y)
    
print(L3)