for _ in range(int(input())):
    n = int(input())

    a = list(map(int, input().split(" ")))

    b = list(map(abs, a))
    if n > 2:
        if abs(a[0]) == max(b):
            print("NO")
        else:
            print("YES")

    else:
        print("YES")
