t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    i = 0
    day = 0

    while i <= n - k:
        if all(a[j] == 0 for j in range(i, i + k)):
            day += 1
            i += k + 1  
        else:
            i += 1

    print(day)
