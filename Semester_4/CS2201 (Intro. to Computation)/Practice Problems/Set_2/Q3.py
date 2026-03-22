# QUESTION
# Take your full name as input and make an abbreviation of your name based on the initials of the names. E.g. if the input is “Subhash Chandra Bose”, the desired output is “S. C. Bose”.

name = input("Enter your name: ")
words = name.split()
abbreviation = ''

for i in range(len(words)-1):
    abbreviation += words[i][0] + '. '

abbreviation += words[-1]
print(abbreviation)
