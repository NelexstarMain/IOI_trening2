n = int(input())
a = list(map(int, input().split()))

b = set(a)

for i in range(1, n+1):
    if i in b:
        continue
    else:
        print(i)
        break