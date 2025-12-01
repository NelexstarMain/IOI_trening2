def solve():
    n, k = map(int, input().split())
    s = input()
    cnt = s.count('1')
    if cnt <= k or n < 2 * k:
        print("Alice")
    else:
        print("Bob")

t = int(input())
for _ in range(t):
    solve()