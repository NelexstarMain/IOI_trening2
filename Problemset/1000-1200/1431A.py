from collections import Counter

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    
    a.sort()
    max_profit = 0

    for i in range(n):
        price = a[i]
        buyers = n - i  
        profit = price * buyers
        max_profit = max(max_profit, profit)

    print(max_profit)
