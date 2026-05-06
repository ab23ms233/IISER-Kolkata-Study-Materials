#!/usr/bin/env python
# coding: utf-8

# In[4]:


#Listing all opening and closing braces
square_b =['[', ']']
round_b = ['(', ')']
curly_b = ['{', '}']

#Function to check for syntax error
def check(s):
    #Extracting all elements of s in list format
    elements = list(s)
    
    #Initialising number of square, round and curly openings as 0
    s_opening, r_opening, c_opening = 0, 0, 0
    
    for i in range(len(elements)):
        element = elements[i]
        
        #Updating the number of opening and closing braces of different types
        if element == square_b[0]:
            s_opening += 1
        elif element == round_b[0]:
            r_opening += 1
        elif element == curly_b[0]:
            c_opening += 1
        elif element == square_b[-1]:
            s_opening -= 1
        elif element == round_b[-1]:
            r_opening -= 1
        elif element == curly_b[-1]:
            c_opening -= 1
        
        #If there is a closing brace before an opening, return False
        if -1 in (s_opening, r_opening, c_opening):
            return False
    
    #If number of opening braces is 0, print True, else False
    if (s_opening, r_opening, c_opening) == (0,0,0):
        return True
    else:
        return False


# In[6]:


test_cases = ['l = [(1, 2), (3, 4)]', 'l = ])1, 2([', 'l = []()', 'l = ([)]', 'l = (1, 2[3, 5{6)]']

#Checking the test cases
for i in range(len(test_cases)):
    if check(test_cases[i]):
        print("The syntax is correct")
    else:
        print("There is an error in the syntax")


# In[ ]:




