#!/usr/bin/env python
# coding: utf-8

# In[29]:


import math
import numpy as np
import scipy.integrate as spi


# In[18]:


def f(x):
    return math.sin(x) + x


# RECTANGULAR METHOD

# In[19]:


N = 1000
a, b = 0, 2
h = (b-a)/N
x = a
rect_area = 0

for i in range(N):
    rect_area += h*f(x)
    x += h

print("Retangular method area:", rect_area)


# In[20]:


# 3-math.cos(2)


# TRAPEZOIDAL METHOD

# In[21]:


N = 1000
a, b = 0, 2
h = (b-a)/N
x = a+h
trap_area = 0

for i in range(1, N):
    trap_area += h*f(x)
    x += h

trap_area += h*(f(a)+f(b))/2

print("Trapezoidal method area:", trap_area)


# SIMPSON'S RULE

# In[22]:


N = 1000
a, b = 0, 2
h = (b-a)/(2*N)
x = a+h
simp_area = 0

for i in range(1, 2*N):
    if i%2 == 1:
        simp_area += 4*f(x)
    else:
        simp_area += 2*f(x)
    
    x += h

simp_area += f(a) + f(b)
simp_area = (h/3)*simp_area

print("Simpson rule area:", simp_area)


# ACTUAL AREA

# In[27]:


actual_area = 3 - math.cos(2)
print("Actual Area:", actual_area)


# SCIPY TRAPEZOIDAL METHOD

# In[38]:


N = 1000
a, b = 0, 2

x_trap = np.linspace(a, b, N)
y_trap = np.empty(N)

for i in range(N):
    x = x_trap[i]
    y_trap[i] = f(x)

spi_trap_area = spi.trapz(y_trap, x_trap)
print("Scipy Trapezoidal area:", spi_trap_area)


# SCIPY SIMPSON METHOD

# In[39]:


N = 1000
a, b = 0, 2

x_simp = np.linspace(a, b, 2*N)
y_simp = np.empty(2*N)

for i in range(2*N):
    x = x_simp[i]
    y_simp[i] = f(x)
    
spi_simp_area = spi.simpson(y_simp, x_simp)
print("Scipy Simpson area:", spi_simp_area)


# ERRORS IN DIFFERENT AREAS

# In[40]:


print("Error in Rectangular Method:", abs(actual_area - rect_area))
print("Error in Trapezoidal Method:", abs(actual_area - trap_area))
print("Error in Simpson Rule:", abs(actual_area - simp_area))
print()
print("Error in Scipy Trapezoidal Method:", abs(actual_area - spi_trap_area))
print("Error in Scipy Simpson Rule:", abs(actual_area - spi_simp_area))


# In[ ]:




