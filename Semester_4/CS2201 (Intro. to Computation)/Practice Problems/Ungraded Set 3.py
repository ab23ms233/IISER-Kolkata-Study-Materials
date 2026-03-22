#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan 21 10:52:03 2025

@author: ab23ms233
"""

#Q1
import math

def f(x):
    return math.sin(x) + x**2 - 1

start, stop = 0, 1
step = 0.05


#Bisection

#Tabulation
def tabulaion(start, stop, step):
    
    x_1 = start
    x_2 = x_1 + step
    
    if f(x_1) == 0:
        return (x_1, x_1)
    elif f(x_1)*f(x_2) < 0:
        return (x_1, x_2)
    else:
        return tabulation(x_2, stop, step)
    
def Bisection(a, b):
    c = (a+b)/2
    
    if f(c) == 0:
        return c
    elif f(a)*f(c) < 0:
        return Bisection(a, c)
    else:
        return Bisection(c, b)

x, y = tabulaion(start, stop, step)
root = Bisection(x, y)
print(root)

#Q2
def g(x):
    return x**3 + x**2 - x

def der_g(x):
    return 3*x**2 + 2*x - 1

#Tabulation
def tabular(start, stop, step):
    
    x_1 = start
    x_2 = x_1 + step
    
    if g(x_1) == 0:
        return (x_1, x_1)
    elif g(x_1)*g(x_2) < 0:
        return (x_1, x_2)
    else:
        return tabular(x_2, stop, step)
    
#Newton Raphson
def NewtonRaphson(x):
    
    if g(x) == 0:
        return x
    else:
        x = x - g(x)/der_g(x)
        return NewtonRaphson(x)

x1, x2 = tabular(start, stop, step)
root = NewtonRaphson(x2)

print(root)

#Q3
'''l = eval(input("Enter list: "))
i = 0

while i <= len(l)-1:
    j = i+1
    
    while j <= len(l)-1:
        if l[i] == l[j]:
            l.pop(j)
        j += 1
    
    i += 1
        
print(l)'''

#Q4
'''L = [1,2,3,4,5]
s = filter(lambda x:x%2 == 0, L)
L1 = list(s)
print(L1)'''

#Q5
L1 = [1,2,3,4,5]
L2 = [5,4,10,12]
L3 = []

def is_odd(n):
    return n%2!=0

for i in range(max(len(L1), len(L2))):
    
    if is_odd(L1[i]) or is_odd(L2[i]):
        
        if is_odd(L1[i]):
            
            if is_odd(L2[i]):
                element = L1[i] + L2[i]
            else:
                element = L1[i]
                
        elif is_odd(L2[i]):
            element = L2[i]
    
    L3.append(element)
        

#Q6
'''while True:
    num = int(input("Enter number: "))
    
    if num%2 == 0:
        break

#Q7
n = 123
rev = 0

while n >= 0:
    rem = n%10
    rev = rev*10 + rem
    n //= 10
    
print(rev)

#Q8
d = {1 : 'ONE', 2 : 'TWO', 3 : 'THREE', 4 : 'FOUR', 5 : 'FIVE', 6 : 'SIX', 7 : 'SEVEN', 8 : 'EIGHT', 9 : 'NINE'}

digits = list(input("Enter number: "))
word = ''

for i in digits:
    word += d[int(i)] + ' '

word = word[:-1]
print(word)

#Q9
l = eval(input("Enter list: "))
direction = ''
        
if l[0]>l[1]:
    direction = "dec"
else:
    direction = "inc"
    
for i in range(1, len(l)-1):
    if (direction == "inc" and l[i] > l[i+1]) or (direction == "dec" and l[i] < l[i+1]):
        print("Not monotonic")
        break

if i == len(l) - 1:
    if direction == "inc":
        print("Increasing")
    else:
        print("Decreasing")
'''
