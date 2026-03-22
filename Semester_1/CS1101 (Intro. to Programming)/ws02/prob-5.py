n = 31
val_1,val_2 = 1,1
print(1, val_1)
print(2, val_2)
for i in range(2, n):
	print(i+1, '%5d'%(val_1+val_2))
	val_1, val_2 = val_2, val_1+val_2
