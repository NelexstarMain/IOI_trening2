n, x = map(int, input().split(" "))
a = list(map(int, input().split(" ")))
if x == 1:
    print("IMPOSSIBLE")

else:
    b = a.copy()
    b = set(b)
    for i in range(len(a)):
        if (x-a[i]) in b:
            f = i+1 
            s = a.index((x-a[i]))+1
            if f != s:
                print(f"{f} {s}")
                break
            else:
                continue
            
        else:
            continue

    else:
        print("IMPOSSIBLE")

