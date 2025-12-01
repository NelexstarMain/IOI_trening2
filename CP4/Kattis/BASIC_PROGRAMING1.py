
n, t = map(int, input().split())
A = list(map(int, input().split()))

if t == 1:
    print(7)

elif t == 2:
    if A[0] > A[1]:
        print("Bigger")
    elif A[0] == A[1]:
        print("Equal")
    else:
        print("Smaller")

elif t == 3:
    print(sorted(A[:3])[1])

elif t == 4:
    print(sum(A))

elif t == 5:
    print(sum(x for x in A if x % 2 == 0))
    //new

elif t == 6:
    print(''.join(chr(x % 26 + ord('a')) for x in A))

elif t == 7:
    visited = set()
    i = 0
    while True:
        if i < 0 or i >= n:
            print("Out")
            break
        if i == n - 1:
            print("Done")
            break
        if i in visited:
            print("Cyclic")
            break
        visited.add(i)
        i = A[i]
