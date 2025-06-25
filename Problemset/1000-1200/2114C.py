# https://codeforces.com/problemset/problem/2114/C
# 1000
def solve():
    n = int(input())
    a = list(map(int, input().split()))

    if n == 0:
        print(0)
        return

    num_arrays = 1
    last_val_in_current_array = a[0] 

    for i in range(1, n):
        if a[i] >= last_val_in_current_array + 2:
            num_arrays += 1
            last_val_in_current_array = a[i]
        else:
            pass

    print(num_arrays)

for _ in range(int(input())):
    solve()
