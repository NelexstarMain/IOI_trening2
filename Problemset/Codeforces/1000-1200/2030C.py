for _ in range(int(input())):
    n = int(input())
    a = input()

    f = a[0]
    if a[0] == "1" or a[-1] == "1":
        print("YES")

    else:
        for i in range(1, n):
            if f == "1" and a[i] == f:
                print("YES")
                break
            else:
                f = a[i]

        else:
            print("NO")

        
            


    

