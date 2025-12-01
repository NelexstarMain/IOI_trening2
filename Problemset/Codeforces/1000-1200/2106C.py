# https://codeforces.com/problemset/problem/2106/C
# 1000

def solve():
    n, k = map(int, input().split(" "))

    a = list(map(int, input().split(" ")))
    b = list(map(int, input().split(" ")))

    if b.count(-1) == n:
        print(min(a) + k - max(a) + 1)

    else:
        known_sums = set()
        for i in range(n):
            if b[i] != -1:
                known_sums.add(a[i] + b[i])

        if len(known_sums) > 1:
            print(0)
            return

        x = known_sums.pop() 

        for i in range(n):
            if b[i] != -1:
                if not (0 <= b[i] <= k):
                    print(0)
                    return
            else:
                b_val = x - a[i]
                if not (0 <= b_val <= k):
                    print(0)
                    return

        print(1)


t = int(input())
for _ in range(t):
    solve()