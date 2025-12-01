# https://codeforces.com/problemset/problem/2092/B
# 1000

t = int(input())

for _ in range(t):
    n = int(input())
    a, b = str(input()), str(input())

    m = n-1

    if n % 2 == 0:
        m = n+1

    a_1 = [a[i] for i in range(0, n, 2)]
    a_2 = [a[i] for i in range(1, m, 2)]

    b_1 = [b[i] for i in range(0, n, 2)]
    b_2 = [b[i] for i in range(1, m, 2)]

    if a_1.count("1") <= b_2.count("0") and a_2.count("1") <= b_1.count("0"):
        print("YES")

    else:
        print("NO")


        
