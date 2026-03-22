'''For this code the logic that 3 terms which are of the form 2n, n^2-1 and n^2+1 form a pythagorean triplet has been used
2n + n^2-1 + n^2+1 <= 100 which approximately gives -7 < n < 7'''

sum = 100
#Recording the list of entries
req = list()

#Appending [0,0,0]
req.append([0,0,0])

#Iterarting over the values of n
for i in range(-6, 7):
	
	#Pythagorean triplet terms
	term_1 = abs(2*i)
	term_2 = abs(i**2-1)
	term_3 = abs(i**2+1)
	
	element = [term_1, term_2, term_3]
	
	#Add term only if not present previously
	if element not in req:
		req.append(element)

#Adding terms of the type [0,i,i] such that i<=50
for j in range(3, 51):
	req.append([0, j, j])
	
for i in req:
	print(i)

