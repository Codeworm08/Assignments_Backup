def isPrime(n):
    if n<2:
        return False
    if n==2:
        return True
    for i in range(2,n):
        if n%i==0:
            return False
    return True

def primeGen():
    n = 1
    while True:
        n += 1
        if isPrime(n):
            yield n
if __name__=="__main__":
    p=primeGen()
    while True:
        ch=input("Enter 'Y' to generate a prime number.\nEnter 'Q' to stop:")
        if ch=='Q':
            break
        elif ch=='Y':
            print(next(p))
        else:
            print("Wrong choice.")