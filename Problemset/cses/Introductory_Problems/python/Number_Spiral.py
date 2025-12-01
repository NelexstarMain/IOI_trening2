for _  in range(int(input())):
    y, x = map(int, input().split(" "))

    r = 0
    x_num = x**2 if x%2 == 1 else (x-1)**2 + 1
    y_num = y**2 if y%2 == 0 else (y-1)**2 + 1

    if x > y:
        if x % 2 == 0:
            r = x_num + (y - 1)
        else:
            r = x_num - (y - 1)
    
    elif y > x:
        if y % 2 == 0:
            r = y_num - (x - 1)
        else:
            r = y_num + (x - 1)
        
    elif x == y:
        n = x-1
        r = n*(n+1) + 1

    print(r)
