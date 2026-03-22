"Input the lists [0,3,1,2,8,9,0,4,7] and [0,-1,-3,-4,3,8,9,11,-2] to check"
num = int(input("Enter the number of items: "))
l,y = [],0

for i in range(num):
    x = int(input("Enter item: "))
    l.append(x)
    if y<l[i]:
        y=l[i]

print("The largest item is: " ,y)

