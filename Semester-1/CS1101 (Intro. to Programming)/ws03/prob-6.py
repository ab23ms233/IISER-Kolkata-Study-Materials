"Input: [0,3,1,2,8,9,0,4,7], [0,-1,-3,-4,3,8,9,11,-2]"
num = int(input("Enter the number of items: "))
l,largest,smallest,largest_index,smallest_index = [],0,0,0,0

for i in range(num):
    x = int(input("Enter item: "))
    l.append(x)
print(l)

for j in range(num-1):
    for i in range(num-1):
        if l[i]<l[i+1]:
            l[i],l[i+1]=l[i+1],l[i]

print("The list in descending order is: " ,l)