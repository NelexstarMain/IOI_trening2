# https://codeforces.com/problemset/problem/2111/B
# 1100



def Fibonacci(n):
    memory = {}
    memory[1] = 1
    memory[2] = 2

    for i in range(3, n + 1):
        a = memory[i-1]
        b = memory[i-2]
        memory[i] = a+b

    return memory

fib = Fibonacci(10)


def solve():
    r = []
    n, m = map(int, input().split(" "))
    for _ in range(m):
        result = 0
        x, y, z = map(int, input().split(" "))
        if x >= fib[n] and y >= fib[n] and z >= fib[n] + fib[n-1]:
            result = 1
        elif x >= fib[n] and y >= fib[n]+fib[n-1] and z >= fib[n]:
            result = 1
        
        elif x >= fib[n] + fib[n-1] and y >= fib[n] and z >= fib[n]:
            result = 1
        else:
            result = 0

        r.append(result)

    print("".join(list(map(str, r))))

for _ in range(int(input())):
    solve()



        
        