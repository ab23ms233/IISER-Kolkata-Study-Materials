#!/usr/bin/env python
# coding: utf-8

# Importing Libraries

# In[ ]:


from sklearn.neighbors import KNeighborsClassifier


# Training the model

# In[19]:


#x = [(Income, CGPA)]
#y = [Waiver]
x = [(44000, 8.7), (40000, 8.1), (1200000, 7.9), (1000000, 8), (800000, 7.5), (49000, 7.1), (50000, 7.7), (500000, 9), (200000, 8.2), (53000, 7.3)]
y = [1,1,0,0,0,0,0,0,0,0]

#Testing Data
x_test = [(30000, 9.3), (41000, 7), (38000, 7.9)]
ids = ["25MS002", "25MS005", "25MS007"]

#Create and train the KNN classifier
knn = KNeighborsClassifier(n_neighbors=3)  # You can change k here
knn.fit(x, y)
    
#Make predictions
y_pred = knn.predict(x_test)


# Checking who are entitled for waiver

# In[21]:


for i in range(len(y_pred)):
    if y_pred[i] == 1:
        print(f"{ids[i]} is entitled to a waiver")
    else:
        print(f"{ids[i]} is not entitled to a waiver")


# In[ ]:




