def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    if n == 2:
        print("YES" if sum(a) >= sum(b) else "NO")
        return

    r = [a[i] - b[i] for i in range(n)]
    neg = [x for x in r if x < 0]

    if not neg:
        print("YES")
    elif len(neg) > 1:
        print("NO")
    else:
        s = sum(x for x in r if x < 0)
        print("YES" if all(x >= s for x in r if x > 0) else "NO")

for _ in range(int(input())):
    solve()
