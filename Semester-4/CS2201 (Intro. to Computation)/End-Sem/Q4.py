#!/usr/bin/env python
# coding: utf-8

# In[45]:


database = ["what a nice weather", "it is a good weather", "i see a gigantic building", "i see a huge building", "what a gorgeous flower", "it was a fast delivery"]
sent_words = []
all_words = []
duplicate_words = []

for sentence in database:
    semantics = sentence.split()
    sent_words.append(semantics)
    
    for word in semantics:
        if word not in all_words:
            all_words.append(word)
        else:
            if word not in duplicate_words:
                duplicate_words.append(word)
            

print(sent_words)
print()
print(all_words)
print()
print(duplicate_words)


# In[51]:


for i in range(len(duplicate_words)):
    word = duplicate_words[i]
    
    if word in all_words:
        all_words.remove(word)

print(all_words)


# In[52]:


#word = input("Enter a word: ")
sent_word = sent_words[:]
word = "huge"

def semantics(word):
    word_semantics = []
    
    for words in sent_word:
        for i in range(len(words)):
            if words[i] == word:
                word_semantics = words[:i] + words[i+1:]
                return word_semantics
    
    if len(word_semantics) == 0:
        print("Word is not present in database")

known_semantic = semantics(word)
print(semantics(word))


# In[54]:


common_list = []

for i in range(len(all_words)):
    semantic = semantics(all_words[i])
    common = 0
    
    for i in range(len(semantic)):
        if semantic[i] == known_semantic[i]:
            common += 1
    common_list.append(common)

print(common_list)


# In[ ]:


for 

