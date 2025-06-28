# https://codeforces.com/problemset/problem/2113/B
# 1200

def solve():
    w, h, a, b = map(int, input().split(" "))
    x1, y1, x2, y2 = map(int, input().split(" "))

    if x1 == x2:
        if abs(y2-y1) % b == 0:
            print("YES")

        else:
            print("NO")

    elif y1 == y2:
        if abs(x1-x2) % a == 0:
            print("YES")
        else:
            print("NO")

    elif abs(y1-y2) % b == 0 or abs(x1-x2) % a == 0:
        print("YES")
    
    else:
        print("NO")

    
for _ in range(int(input())):
    solve()
