for _ in range(int(input())):
    n, x = map(int, input().split())
    if n == 1:
        print(0)
    else:
        r = [str(i) for i in range(n) if i != x]
        if len(r) < n:
            r.append(str(x))
        print(" ".join(r))


    