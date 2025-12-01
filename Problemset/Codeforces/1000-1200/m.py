for _ in range(int(input())):
    n, m = map(int, input().split(" "))

    r = []

    for _ in range(n):
        a = list(map(int, input().split(" ")))
        s = sum([(n-x)*a[x] for x in range(n)])
        r.append((a, s))


    

