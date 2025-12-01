n = int(input())
a = list(map(int, input().split()))

d = {}
l = ans = 0

for r in range(n):
    if a[r] in d:
        l = max(l, d[a[r]] + 1)
    d[a[r]] = r
    ans = max(ans, r - l + 1)

print(ans)
