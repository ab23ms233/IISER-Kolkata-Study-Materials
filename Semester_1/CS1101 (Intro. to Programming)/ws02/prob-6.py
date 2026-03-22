n,m,s = 6,6,0
for i in range(1,n):
	for j in range(1, m):
		s=s+((i-j)/(i+j))
print(s)
