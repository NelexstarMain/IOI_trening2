for _ in range(int(input())):
    n, j, k = map(int, input().split(" "))
    a = list(map(int, input().split(" ")))

    s = a[j-1]

    if k == 1:
        if s == max(a):
            print("YES")
        else:
            print("NO")

    else:
        print("YES")
