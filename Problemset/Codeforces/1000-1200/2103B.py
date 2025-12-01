# https://codeforces.com/problemset/problem/2103/B
# 1100

for _ in range(int(input())):
    n = int(input())
    a = input().strip()
    cnt = 0
    for i in range(n-1):
        if a[i] != a[i+1]: cnt += 1
    if cnt == 0:
        print(n + int(a[0] == "1"))
    elif cnt == 1:
        print(n + 1)
    else:
        print(n+cnt-1 - int(a[0] == "0" and cnt > 2))