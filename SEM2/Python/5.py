
def fib_gen():
    memo = {}
    def fibo(n):
        if n in memo:
            return memo[n]
        if n<2:
            return n
        fib = fibo(n-1)+ fibo(n-2)
        memo[n]=fib
        return fib
    count=0
    while count<7:
        yield fibo(count)
        count+=1
f = fib_gen()
for _ in range(7):
    print(next(f))
    """ a=0
    b=1
    yield a
    yield b
    while True:
        c=a+b
        a=b
        b=c
        yield b
f=fibo()
for i in range(7):
    print(next(f)) """