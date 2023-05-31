students=[]
subjects=[]
marks=[]
while True:
    students.append(input("Enter student name:"))
    subjects.append(input("Subject name:"))
    marks.append(int(input("Enter marks:")))
    x=input("Enter q to stop. Enter to continue")
    if x=="q":
        break
max_marks=max(map(lambda x: (x[0],x[1],x[2]),zip(students,subjects,marks)),key=lambda x: x[2])
print(max_marks)
