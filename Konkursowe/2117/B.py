for _ in range(int(input())):
    n = int(input())

    a = []
    b = []

    for i in range(1, n+1):
        if i % 2 == 1:
            a.append(i)
        else:
            b.append(i)

        
    c = a + b[::-1]
    print(" ".join(list(map(str, c))))