for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    if n == 2:
        if abs(a[1] - a[0]) > 1:
            print("NO")
        else:
            print("YES")
        continue

    f = a[0]
    for i in range(1, n):
        s = a[i]
        if abs(s - f) <= 1:
            print("YES")
            break
        elif i + 1 < n and min(f, s) <= a[i + 1] <= max(f, s):
            print("YES")
            break
        elif i - 1 >= 0 and min(f, s) <= a[i - 1] <= max(f, s):
            print("YES")
            break
    else:
        print("NO")

