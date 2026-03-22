#!/usr/bin/env python
# coding: utf-8

# Importing Necessary Libraries

# In[1]:


import matplotlib.pyplot as plt
import random


# Making the required arrays by random

# In[2]:


March, April, year = [], [], []
no_of_years = 15
upper, lower = 10, 50

for i in range(no_of_years):
    march = random.randint(upper, lower)
    april = random.randint(upper, lower)
    
    March.append(march)
    April.append(april)
    year.append(i+1)


# In[9]:


'''fig, (axm, axa) = plt.subplots(1, 2)

axm.plot(year, March, color="green", ls="dashed", marker="o")
axm.set_xlabel("Year")
axm.set_ylabel("Production")
axm.set_title("March")
axm.legend(["March"])

axa.plot(year, April, color="blue", ls="solid", marker="s")
axa.set_xlabel("Year")
axa.set_ylabel("Production")
axa.set_title("April")
axa.legend(["April"])

fig.tight_layout()
("Mango Production in Uttar Pradesh")
plt.show()'''


# In[17]:


#The figure has 1 row, 2 columns and this is the 1st column
plt.subplot(1,2,1)

#Plotting and setting colors, linestyle and markers
plt.plot(year, March, color="green", ls="dashed", marker="o")

#Setting xlabels, ylabels, title and legend
plt.xlabel("Year")
plt.ylabel("Production")
plt.title("March")
plt.legend(["March"])

#The figure has 1 row, 2 columns and this is the 2nd column
plt.subplot(1,2,2)

#Plotting and setting colors, linestyle and markers
plt.plot(year, April, color="blue", ls="solid", marker="s")

#Setting xlabels, ylabels, title and legend
plt.xlabel("Year")
plt.ylabel("Production")
plt.title("April")
plt.legend(["April"])

#plt.tight_layout() to correct the spacing between subplots
plt.suptitle("Mango Production in Uttar Pradesh")
plt.tight_layout()
plt.show()





