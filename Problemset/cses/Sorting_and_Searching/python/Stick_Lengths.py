n = int(input())
a = list(map(int, input().split()))
a.sort()
median = a[n // 2]

print(sum(abs(x - median) for x in a))
