#!/usr/bin/env python
# coding: utf-8

# In[21]:


import random
import matplotlib.pyplot as plt


# In[22]:


tom_x = 5
tom_y = 5
tom_x_list, tom_y_list = [5], [5]

jerry_x = 5
jerry_y = 10
jerry_x_list, jerry_y_list = [5], [10]


# In[23]:


N = 1000
toss_outcome = ['H', 'T']

for i in range(N):
    
    #toss = 0 ---> Head
    #toss = 1 ---> Tail
    
    toss = random.randint(0, 1)
    die = random.randint(1, 6)
    
    if toss == 0:
        tom_x += 10
    else:
        tom_x += 0
    
    if die == 1:
        jerry_x += 5
    elif die == 2:
        jerry_x += 10
    elif die == 3:
        jerry_y += 5
    elif die == 4:
        jerry_y -= 5
    elif die == 5:
        jerry_x += 5
        jerry_y += 5
    else:
        jerry_x += 5
        jerry_y -= 5
    
    tom_x_list.append(tom_x)
    tom_y_list.append(tom_y)
    
    jerry_x_list.append(jerry_x)
    jerry_y_list.append(jerry_y)
    
    if (tom_x > 100) or (jerry_x > 100):
        break

print(tom_x, tom_y)
print(jerry_x, jerry_y)


# In[19]:


plt.plot(tom_x_list, tom_y_list, color="blue", ls="solid", marker="o")
plt.plot(jerry_x_list, jerry_y_list, color ="brown", ls="dashed", marker="s")
plt.legend(["TOM", "JERRY"])
plt.show()

if tom_x>100 & jerry_x>100:
    if tom_x>jerry_x:
        print("TOM wins")
    elif jerry_x>tom_x:
        print("JERRY wins")
    else:
        print("Tie between them")
        
elif tom_x > 100:
    print("TOM wins and tom_x:", tom_x)
elif jerry_x > 100:
    print("JERRY wins and jerry_x:", jerry_x)
else:
    print("Nobody wins")


# In[10]:





# In[14]:





# In[ ]:




