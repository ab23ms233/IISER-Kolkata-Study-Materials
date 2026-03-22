#SET 2

marks = [5,1,2,3,4,5,45,65,44,445]
failed = 0

"""for i in range(10):
    mark = int(input(f"Enter marks {i+1}: "))
    marks.append(mark)"""
    
for i in range(9):
    for j in range(9):
        
        if marks[j] < marks[j+1]:
            marks[j], marks[j+1] = marks[j+1], marks[j]

print(marks)

for i in marks:
    if i < 45:
        i += 5
        print("Updated:", i)
    	
    if i < 45:
    	print("Failed:", i)
    	failed += 1

f = open("Failed.txt", 'w')
f.write(f"Number of failed students is {failed}")

f.close()
        
