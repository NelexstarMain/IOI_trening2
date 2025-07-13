# https://codeforces.com/problemset/problem/2092/C
# 1200

t = int(input())
 
for test in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    ans, cnt = 0, 0
    for i in a:
        ans += i
        cnt += i % 2
        
    if not cnt or cnt == n:
        print(max(a))
    else:
        print(ans - cnt + 1)


