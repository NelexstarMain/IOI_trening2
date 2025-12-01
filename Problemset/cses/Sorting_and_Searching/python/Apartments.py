n, m, k = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

a.sort()
b.sort()

count = 0
j = 0  

for desired in a:
    while j < m and b[j] < desired - k:
        j += 1
    if j < m and desired - k <= b[j] <= desired + k:
        count += 1
        j += 1

print(count)
