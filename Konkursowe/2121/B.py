for _ in range(int(input())):
    n = int(input())

    a = input()
    alf = set()
    alf.add(a[0])

    for i in range(1, n-1):
        l = a[i]
        if l in alf or l in a[(i+1):]:
            print("YES")
            break
        
        else:
            if l not in alf:
                alf.add(l)
            continue

    else:
        print("NO")