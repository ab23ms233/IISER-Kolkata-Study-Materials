#!/usr/bin/env python
# coding: utf-8

# Importing Necessary Libraries

# In[4]:


from scipy import interpolate
import numpy as np


# LAGRANGE INTERPOLATION

# In[5]:


def lagrange_interpolation(x_values, y_values, x_to_interpolate):
    n = len(x_values)
    result = 0.0

    for i in range(n):
        term = y_values[i]
        for j in range(n):
            if i != j:
                term *= (x_to_interpolate - x_values[j]) / (x_values[i] - x_values[j])
        result += term

    return result

# Example data
x_vals = [2014, 2019, 2021, 2023, 2024]
y_vals = [171, 190, 240, 260, 270]  # y = x^2

x_interp = 2022
y_interp = lagrange_interpolation(x_vals, y_vals, x_interp)

print(f"Interpolated value at x = {x_interp} is approximately {y_interp:.4f}")


# In[ ]:




