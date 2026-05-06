f = open("roll-marks.txt",'r')
roll_marks = f.read()
marks = []
f.close()

l = roll_marks.split('\n')

while l.count('')!=0:
    l.remove('')

for i in l:
    marks.append(int(i.split()[1]))

for i in range(len(marks)-1):
    for j in range(len(marks)-1):
        if marks[j] > marks[j+1]:
            marks[j], marks[j+1] = marks[j+1], marks[j]

sort = open("sorted-marks.txt",'w')
for i in marks:
    sort.write(str(i)+'\n')
