# QUESTION
# Consider a list of names of chemical elements (e.g. sodium, potassium etc.) and write a program that finds the longest name in that list. Using “format()” print the longest name thus found with its length.

elements = ["sodium", "potassium", "calcium", "boron", "hydrogen"]
elements_len = list(map(len, elements))
max_len = max(elements_len)
pos = elements_len.index(max_len)
print("The largest character is:", elements[pos])
