a = int(input("Enter a number: "))
k = 1
while 2**k < a:
    k+=1
print(k-1)