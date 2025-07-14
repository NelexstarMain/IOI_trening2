
a = input()
n = len(a)

max_count = 0
start = 0
letter = a[0]


for i in range(1, n):
    if a[i] == letter:
        continue
    else:
        max_count = max(max_count, i - start)
        start = i
        letter = a[i]
    
else:
    max_count = max(max_count, n - start)



print(max_count)