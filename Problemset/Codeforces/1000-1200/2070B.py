# https://codeforces.com/problemset/problem/2070/B
# 1100

def solve():
    n, x, k = map(int, input().split(" "))
    a = input()

    p = x
    l = 0
    for i in range(n):
        if a[i] == "R":
            p += 1
        else:
            p -= 1

        if p == 0:
            l = i+1
            break
    

    else:
        print(0)
        return
    
    p = 0
    t = 0
    for i in range(n):
        if a[i] == "R":
            p += 1
        else:
            p -= 1

        if p == 0:
            t = i+1
            break
    else:
        print(1)
        return

        
    print(((k-l)//t)+1)
    return 


        

for _ in range(int(input())):
    solve()

