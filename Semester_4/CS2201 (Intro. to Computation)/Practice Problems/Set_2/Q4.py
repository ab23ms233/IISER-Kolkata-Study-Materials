# QUESTION
# Write a program that prints the first 10 elements of a Fibonacci series 1, 1, 2, 3,5, 8, 13,....., where each element is the sum of the two previous elements (the first two numbers are defined to be 1).

a,b = 1,1

for i in range(10):
    print(a)
    print(b)
    a,b = b,a+b