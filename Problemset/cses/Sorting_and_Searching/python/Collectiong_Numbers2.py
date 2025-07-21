n, m = map(int, input().split())
a = list(map(int, input().split()))

pos = {a[i]: i for i in range(n)}
rounds = 1 + sum(pos[i] > pos[i + 1] for i in range(1, n))

for _ in range(m):
    x, y = map(int, input().split())
    u, v = a[x-1], a[y-1]

    affected = {i for val in [u, v] for i in (val - 1, val, val + 1) if 1 <= i < n}
    before = sum(pos[i] > pos[i + 1] for i in affected)

    a[x-1], a[y-1] = a[y-1], a[x-1]
    pos[u], pos[v] = pos[v], pos[u]

    after = sum(pos[i] > pos[i + 1] for i in affected)
    rounds += after - before
    print(rounds)
