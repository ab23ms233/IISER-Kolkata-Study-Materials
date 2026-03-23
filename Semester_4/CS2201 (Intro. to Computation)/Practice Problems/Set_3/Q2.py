# QUESTION
# Using Newton-Raphson method find as many roots as you can of the equation f(x) = x3 + x2 - x = 0 in the interval [0, 1]. Note that the first order derivative of f(x) is 3x2 + 2x - 1. You may plot f using a web application like Desmos to first identify the roots visually and choose appropriate initial approximations for the Newton-Raphson method.

# Defining function
def g(x):
    return x**3 + x**2 - x

# Defining derivative
def der_g(x):
    return 3*x**2 + 2*x - 1

# Tabulation
def tabular(start, stop, step):
    x_1 = start
    x_2 = x_1 + step
    
    if g(x_1) == 0:
        return (x_1, x_1)
    elif g(x_1)*g(x_2) < 0:
        return (x_1, x_2)
    else:
        return tabular(x_2, stop, step)
    
# Newton Raphson method
def NewtonRaphson(x):
    if g(x) == 0:
        return x
    else:
        x = x - g(x)/der_g(x)
        return NewtonRaphson(x)

# Applying methods to find root
start, stop = 0, 1
step = 0.05
x1, x2 = tabular(start, stop, step)
root = NewtonRaphson(x2)

print(root)
