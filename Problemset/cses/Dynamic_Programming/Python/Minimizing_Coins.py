n, x = map(int, input().split())
coins = list(map(int, input().split()))

INF = 10**9
dp = [INF] * (x + 1)
dp[0] = 0

for amount in range(1, x + 1):
    for c in coins:
        if amount - c >= 0:
            dp[amount] = min(dp[amount], dp[amount - c] + 1)

print(dp[x] if dp[x] != INF else -1)
