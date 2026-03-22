# QUESTION
# Using the Tabulation  Method find an interval containing a root of the equation sin(x) + x2 -1 in the interval [0, 1]. You may use the sin() function in the math module.

import math

def f(x):
    return math.sin(x) + x**2 - 1

step = 0.05
start, stop = 0,1.01
x_val = start

while x_val <= stop:
    y_val = f(x_val)
    print(f"{round(x_val, 2)}  {y_val}")
    x_val += step