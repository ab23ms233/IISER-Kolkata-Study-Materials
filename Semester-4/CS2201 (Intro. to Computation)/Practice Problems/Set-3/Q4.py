# QUESTION
# Given a list L = [1, 2, 3, 4, 5], use list comprehension to generate another list L1 containing the even numbers in L

L = [1,2,3,4,5]
s = filter(lambda x:x%2 == 0, L)
L1 = list(s)
print(L1)