# Opening file
f = open("Grades2.dat",'r')
data = f.readlines()
print(data)
names, grades = [], []

# Reading and storing data in lists
for i in data:
    position = i.find('\t')
    names.append(i[:position])
    grades.append(i[position+1:-1])
    
f.close()

# Sorting the data according to marks and alphabetical order if marks are same
for j in range(len(names)-1):
    for i in range(len(names)-1):
        if grades[i] < grades[i+1]:
            grades[i], grades[i+1] = grades[i+1], grades[i]
            names[i], names[i+1] = names[i+1], names[i]
        elif (grades[i] == grades[i+1]) and (names[i] > names[i+1]):
                names[i], names[i+1] = names[i+1], names[i]

grade_name = open("Info2.txt", 'w')

# Recording the data in file
for j in range(len(names)):
    grade_name.write(grades[j]+'\t')
    grade_name.write(names[j] + '\n')

grade_name.close()