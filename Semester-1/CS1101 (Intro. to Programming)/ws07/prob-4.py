f = open("roll-marks.txt",'r')
roll_marks = f.read()
roll, marks = [], []
f.close()

l = roll_marks.split('\n')

while l.count('')!=0:
    l.remove('')

for i in l:
    roll.append(int(i.split()[0]))
    marks.append(int(i.split()[1]))

print("Original roll: ", roll)
print("Original marks: ",marks)

new = open("new-marks.txt",'w')
excellent = open("excellent.txt",'w')
highest = marks[0]

for i in range(len(marks)):

    if marks[i]<40:
        marks[i]+=5
    elif marks[i]>85 and marks[i]<90:
        marks[i]+=2
    new.write(f"{roll[i]} {marks[i]}\n")

    if marks[i]>=90:
        excellent.write(str(roll[i])+'\n')
    
    if marks[i]>highest:
        highest = marks[i]

new.close()
excellent.close()
print("Highest marks of new-marks.txt is ",highest)


