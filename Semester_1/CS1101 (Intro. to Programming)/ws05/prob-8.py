"""Define a function f(x) which takes argumnet x and returns x**0.95.
Then reassign x = f(x) until x<2 and count the number of iterations"""

def f(x):
    return x**0.95

count,a =0,10

#Loop to count number of iterations
while a>=2:
    a = f(a)
    count+=1

print("Number of iterations is",count)


