for _ in range(int(input())):
    n, s = map(int, input().split())
    a = list(map(int, input().split()))
    min_a = min(a)
    max_a = max(a)

    if s <= min_a:
        print(max_a - s)
    elif s >= max_a:
        print(s - min_a)
    else:
        d1 = abs(s - min_a)
        d2 = abs(s - max_a)
        print(min(d1, d2) * 2 + max(d1, d2))
