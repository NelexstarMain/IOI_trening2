# https://codeforces.com/problemset/problem/2104/C
# 1100

def beats(n, x, y):
    if x == 0:
        return y == n - 1
    if x == n - 1:
        return y != 0
    return x > y
 
for _ in range(int(input())):
    n = int(input())
    owner = input()
    good = False
    for i in range(n):
        if owner[i] != 'A':
            continue
        good_move = True
        for j in range(n):
            if owner[j] == 'B' and beats(n, j, i):
                good_move = False
        if good_move:
            good = True
    if good:
        print('Alice')
    else:
        print('Bob')