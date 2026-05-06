# QUESTION
# Given a list L with repeating elements, remove the duplicates. You should not use any temporary list.

# User input
# l = eval(input("Enter list: "))
l = [1, 2, 2, 3, 4, 5, 5]
i = 0

# Without using buil-in functions
# while i <= len(l)-1:
#     j = i+1
    
#     while j <= len(l)-1:
#         if l[i] == l[j]:
#             l.pop(j)
#         j += 1
    
#     i += 1
        
# print(l)

# Using built-in data-structure set
l = list(set(l))
print(l)