for _ in range(int(input())):
    n, x = map(int, input().split(" "))

    a = list(map(int, input().split(" ")))

    f = a.index(1)
    l = len(a) - 1 - a[::-1].index(1)

    if l-f >= x:
        print("NO")
    else:
        print("YES")



