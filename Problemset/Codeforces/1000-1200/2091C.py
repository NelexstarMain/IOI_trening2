# https://codeforces.com/problemset/problem/2091/C
# 1000

t = int(input())

for _ in range(t):
    n = int(input())
    r = [0] * (n)

    if n % 2 == 1 or n == 1:
        for i in range(1,n):
        
            d = n-i
            number = i
            r[i-d] = number
            
        r[0] = n

        print(" ".join(map(str, r)))
            
    else:
        print("-1")