import math

def solve():
    n, m, q = map(int, input().split())
    
    a_coords = list(map(int, input().split()))
    a_coords.sort()
    
    for _ in range(q):
        b_coord = int(input())
        
        k = 0
        while k < m and a_coords[k] <= b_coord:
            k += 1
        
        ans = 0
        if k == 0:
            ans = a_coords[0] - 1
        elif k == m:
            ans = n - a_coords[m - 1]
        else:
            ans = (a_coords[k] - a_coords[k - 1]) // 2
        
        print(ans, end=' ')
    print()

t = int(input())
for _ in range(t):
    solve()