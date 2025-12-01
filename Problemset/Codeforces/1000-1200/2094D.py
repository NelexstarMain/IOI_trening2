def solve():
    a = str(input())
    b = str(input())

    idx_a = 0
    idx_b = 0

    while idx_a < len(a) and idx_b < len(b):
        current_char = a[idx_a]

        if b[idx_b] != current_char:
            print("NO")
            return

        p_len = 0
        temp_idx_a = idx_a
        while temp_idx_a < len(a) and a[temp_idx_a] == current_char:
            p_len += 1
            temp_idx_a += 1

        s_len = 0
        temp_idx_b = idx_b
        while temp_idx_b < len(b) and b[temp_idx_b] == current_char:
            s_len += 1
            temp_idx_b += 1

        if s_len < p_len or s_len > 2 * p_len:
            print("NO")
            return

        idx_a = temp_idx_a
        idx_b = temp_idx_b

    if idx_a == len(a) and idx_b == len(b):
        print("YES")
    else:
        print("NO")

for _ in range(int(input())):
    solve()