tt = int(input())
for _ in range(tt):
    n = int(input())
    ans = 1
    cur = 1
    while True:
        if cur >= n:
            print(ans)
            break
        ans += 1
        cur = cur * 2 + 2