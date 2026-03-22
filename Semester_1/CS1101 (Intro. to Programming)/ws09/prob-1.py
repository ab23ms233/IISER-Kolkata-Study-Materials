# Opeening the file
f = open("Grades1.dat",'r')
data = f.readlines()
print(data)
names, grades = [], []

# Reading and storing data in 2 lists
for i in data:
    position = i.find('\t')
    names.append(i[:position])
    grades.append(i[position+1:-1])
    
f.close()

# Sorting the lists according to grade
for j in range(len(names)-1):
    for i in range(len(names)-1):
        if grades[i] < grades[i+1]:
            grades[i], grades[i+1] = grades[i+1], grades[i]
            names[i], names[i+1] = names[i+1], names[i]

# Storing sorted data in another file
grade_name = open("Info1.txt", 'w')

for j in range(len(names)):
    grade_name.write(grades[j]+'\t')
    grade_name.write(names[j] + '\n')

grade_name.close()