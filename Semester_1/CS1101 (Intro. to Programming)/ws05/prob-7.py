"""Define a function which takes t as input and returns tan(2t).
Write a loop to calculate tan 2t for t = 0,10,20,.....,90"""

import math

def f(t):
    return math.tan(2*t*math.pi/180)

#Loop to calculate desired output
for i in range(0,91,10):
    print(f(i))