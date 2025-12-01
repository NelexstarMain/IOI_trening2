for _ in range(int(input())):
    a = input()
    num = 0
    dir = -1
    num_2 = 0
    directions = {
        "(": 1,
        ")": -1
    }
    for i in range(len(a)):
        if directions[a[i]] == dir:
            continue
        else:
            dir *= -1
            num += 1

    for i in range(len(a)):
        if a[i] == "(" and a[-(i+1)] == ")":
            continue
        else:
            break

                  

    if (num // 2) == 1:
        print("NO")
    elif num_2 // 2 > len(a) // 2:
        print("NO")
    else:
        print("YES")



