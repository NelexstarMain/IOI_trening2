n = int(input())

m = n * (n + 1) // 2  # używamy // zamiast /, by zachować liczbę całkowitą

if m % 2 == 1:
    print("NO")
else:
    print("YES")

    ms = m // 2
    a = []
    b = []
    sum_a = 0
    sum_b = 0

    for i in range(n, 0, -1):
        if sum_a + i <= ms:
            a.append(i)
            sum_a += i
        else:
            b.append(i)
            sum_b += i

    print(len(a))
    print(" ".join(map(str, a)))
    print(len(b))
    print(" ".join(map(str, b)))
