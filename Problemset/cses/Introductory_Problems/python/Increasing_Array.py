n = int(input())

a = list(map(int, input().split(" ")))

prev = a[0]
r = 0

for i in range(1, n):
    if a[i] < prev:
        r += prev - a[i]
        a[i] = a[i-1]
        
    prev = a[i]

print(r)

