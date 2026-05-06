name = open("names.txt",'w')
vowels = ['a','e','i','o','u']

for i in range(5):
    x = input("Enter name: ")
    x = x.strip()
    if x[0].lower() in vowels or x[-1].lower() not in vowels:
        name.write(x+'\n')

name.close()