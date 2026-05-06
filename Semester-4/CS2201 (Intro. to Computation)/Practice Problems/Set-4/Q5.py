# QUESTION
# Input a list from the user (containing duplicates) and create another list containing only the non-repeating elements. E.g. if the input list is [1, 2, 2, 3, 4, 4, 5], the output list will be [1, 3, 5].

l = eval(input("Enter list: "))
s = set(l)
new_l = list(s)
print(new_l)