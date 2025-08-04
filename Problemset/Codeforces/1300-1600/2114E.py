from math import inf
from sys import setrecursionlimit


def solve(v, p, mini, maxi):
    global res
    res[v] = max(arr[v], mini * -1 + arr[v])
    mini = min(arr[v], maxi * -1 + arr[v])
    for u in gr[v]:
        if u == p:
            continue
        solve(u, v, mini, res[v])


setrecursionlimit(400_000)
t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    gr = [[] for _ in range(n)]
    for j in range(n - 1):
        v, u = map(int, input().split())
        gr[v - 1].append(u - 1)
        gr[u - 1].append(v - 1)
    res = [0] * n
    solve(0, -1, 0, 0)
    print(*res)