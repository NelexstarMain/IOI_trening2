n, x = map(int, input().split(" "))

a = list(map(int, input().split(" ")))



index = {a[i]: i for i in range(n)}

pairs = 0


for i in range(1, n):

    b = index[i]

    c = index[i+1]

    if c < b:
        pairs += 1
    else:
        continue



