from bisect import bisect_left

for _ in range(int(input())):
    n, m = map(int, input().split())
    a = sorted(list(map(int, input().split())))
    ans = 0
    for k in range(1, n):
        x = m - bisect_left(a, k)
        y = m - bisect_left(a, n - k)
        ans += x * y - min(x, y)
    print(ans)