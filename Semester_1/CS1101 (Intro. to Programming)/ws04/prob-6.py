num = int(input("Enter the cutoff: "))
a,b = 1,1

while a<num:
    print(a)
    a, b = b, a+b
    