import math

def solve():
    n = int(input())
    a = list(map(int, input().split(" ")))

    if n <= 2:
        print(-1)
        return

    a.sort()
    initial_sum = sum(a)

    target_person_index = (n // 2) 
    target_wealth = a[target_person_index]

    x_candidate = (target_wealth * 2 * n) - initial_sum + 1
    
    x = max(0, x_candidate)
    
    print(x)

t = int(input())
for _ in range(t):
    solve()