def solve_case(n, a, b):
    ops = []

    def swap(arr, i):
        arr[i], arr[i+1] = arr[i+1], arr[i]

    def apply(op_type, i):
        ops.append((op_type, i + 1)) 
        if op_type == 1:
            swap(a, i)
        elif op_type == 2:
            swap(b, i)
        elif op_type == 3:
            a[i], b[i] = b[i], a[i]

    for i in range(n):
        if a[i] > b[i]:
            apply(3, i)

    for i in range(n):
        for j in range(n - 1):
            if a[j] > a[j + 1]:
                apply(1, j)

    for i in range(n):
        for j in range(n - 1):
            if b[j] > b[j + 1]:
                apply(2, j)

    return ops


t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    ops = solve_case(n, a, b)
    print(len(ops))
    for op in ops:
        print(*op)
