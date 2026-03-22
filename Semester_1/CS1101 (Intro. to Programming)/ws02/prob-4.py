# program to compute arithmetic progression
a = 2 # initial
r = 3 # increment
for i in range(10):
    print( '%3d %6d' %(i+1, a*(r**i) ))
print()
