from itertools import compress, count
num = count()
even = [True,False]*10
odd = [False, True]*10
even = compress(num,even)
num=count()
odd = compress(num,odd)
print(odd)
print("The first 10 even numbers: ")
for n in even:
    print(n,end=",")
print()
print("First 10 odd numbers: ")
for x in odd:
    print(x,end=",")