"Input the lists [0,3,1,2,8,9,0,4,7] and [0,-1,-3,-4,3,8,9,11,-2] to check"
num = int(input("Enter the number of items: "))
l,largest,smallest,largest_index,smallest_index = [],0,0,0,0

for i in range(num):
    x = int(input("Enter item: "))
    l.append(x)
    if largest<l[i]:
        largest=l[i]
        largest_index=i
    if smallest>l[i]:
        smallest=l[i]
        smallest_index=i

print(f"The largest item is {largest} and its position is {largest_index}")
print(f"The smallest item is {smallest} and its position is {smallest_index}")