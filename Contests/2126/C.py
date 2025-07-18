for _ in range(int(input())):
    n, k = map(int, input().split(" "))

    a = list(map(int, input().split(" ")))
    dis = a[k-1]

    a.sort()

    f = a[0]

    for i in range(1, n):
        s = a[i]
        if s-f > dis:
            print("NO")
            break
        else:
            f = s
            continue
            
    else:
        print("YES")