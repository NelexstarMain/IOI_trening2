# https://codeforces.com/problemset/problem/2078/B
# 1100

def solve():
    n, k = map(int, input().split(" "))

        
    r = []

    if n > 2:
        if k % 2 == 0:
            for _ in range(n-2): r.append(n-1)
        else:
            for _ in range(n-2): r.append(n)

    r.append(n)
    r.append(n-1)

    print(" ".join(list(map(str, r))))


for _ in range(int(input())):
    solve()
        