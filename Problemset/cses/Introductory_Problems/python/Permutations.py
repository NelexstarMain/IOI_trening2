n = int(input())

if n in [2, 3]:
    print("NO SOLUTION")
else:
    a = sorted([i for i in range(1, n+1) if i % 2 == 0])
    b = sorted([i for i in range(1, n+1) if i % 2 == 1])
    print(" ".join(map(str, a + b)))