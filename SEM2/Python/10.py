l=int(input("Lower range of numbers to be squared:"))
r=int(input("Upper range of numbers to be squared:"))
li=[]
for x in range(l,r+1):
    li.append(x*x)
print("All squares in list: ",li)
fli = list(filter(lambda x: x%2==0, li))
print("Even squares in list: ",fli)