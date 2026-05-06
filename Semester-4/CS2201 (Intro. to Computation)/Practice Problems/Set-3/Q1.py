# QUESTION
# Using Tabulation method find a better approximate interval in the interval [0, 1] and then on this better interval use Bisection to find the root of the equation sin(x) + x2 -1 = 0 . You may use the sin() function in the math module.

import math

# Defining function
def f(x):
    return math.sin(x) + x**2 - 1

start, stop = 0, 1
step = 0.05

# Tabulation
def tabulation(start, stop, step):
    
    x_1 = start
    x_2 = x_1 + step
    
    if f(x_1) == 0:
        return (x_1, x_1)
    elif f(x_1)*f(x_2) < 0:
        return (x_1, x_2)
    else:
        return tabulation(x_2, stop, step)

# Bisection
def Bisection(a, b):
    c = (a+b)/2
    
    if f(c) == 0:
        return c
    elif f(a)*f(c) < 0:
        return Bisection(a, c)
    else:
        return Bisection(c, b)

# Finding root
x, y = tabulation(start, stop, step)
root = Bisection(x, y)
print(root)