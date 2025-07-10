from collections import Counter


for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split(" ")))


    c = Counter(a)

    v = [value for value in c.values()]
    m = max(v)
    v = set(v)
    
    for i in range(2, m+1):
        if i in v:
            continue
        else:
            print(m - i)
            break
    else:
        print(i)



        