for _ in range(int(input())):
    n, m, k = map(int, input().split())

    ml = list(map(int, input().split()))
    kl = set(map(int, input().split()))

    r = []

    if len(kl) == n:
        print("1" * m)

    elif len(kl) + 1 == n:
        for i in ml:
            if i in kl:
                r.append("0")
            else:
                r.append("1")

        print("".join(r))

    else:
        print("0" * m)
