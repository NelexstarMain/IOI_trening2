def read_int():
    return int(input())

def read_ints():
    return list(map(int, input().split()))

matrix = []
N, M = 0, 0

def can_achieve(target_max_val: int) -> bool:
    critical_cells = []

    for i in range(N):
        for j in range(M):
            if matrix[i][j] > target_max_val + 1:
                return False
            if matrix[i][j] > target_max_val:
                critical_cells.append((i, j))

    if not critical_cells:
        return True

    x0, y0 = critical_cells[0]

    # Kandydat 1: Wiersz x0 + wspólna kolumna
    possible_cand1 = True
    common_c = -1
    for x, y in critical_cells:
        if x != x0:
            if common_c == -1:
                common_c = y
            elif common_c != y:
                possible_cand1 = False
                break
    if possible_cand1:
        return True

    # Kandydat 2: Kolumna y0 + wspólny wiersz
    possible_cand2 = True
    common_r = -1
    for x, y in critical_cells:
        if y != y0:
            if common_r == -1:
                common_r = x
            elif common_r != x:
                possible_cand2 = False
                break
    return possible_cand2

def solve():
    global N, M, matrix

    N, M = read_ints()
    matrix = [read_ints() for _ in range(N)]

    low, high = 0, 100
    ans = 100

    while low <= high:
        mid = (low + high) // 2
        if can_achieve(mid):
            ans = mid
            high = mid - 1
        else:
            low = mid + 1

    print(ans)

# Główna pętla
t = read_int()
for _ in range(t):
    solve()
