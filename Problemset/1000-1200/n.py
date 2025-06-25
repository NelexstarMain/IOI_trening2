def solve():
    x, y = map(int, input().split(" "))
    array = [[int(i) for i in input()] for _ in range(x)]

    vectors = []

    rows_to_remove = set()
    cols_to_remove = set()

    for i in range(x):
        if array[i][0] == 1:
            vectors.append([array[i][j] for j in range(0, y)])
            rows_to_remove.add(i)

    for i in range(y):
        if array[0][i] == 1:
            vectors.append([array[j][i] for j in range(0, x)])
            cols_to_remove.add(i)

    for i in range(len(vectors)):
        grupe = True
        for j in range(len(vectors[i])):
            if vectors[i][j] == 1:
                if grupe:
                    continue
                else:
                    print("NO")
                    return
            else:
                grupe = False

    new_array = [[array[i][j] for j in range(y) if j not in cols_to_remove] for i in range(x) if i not in rows_to_remove]
    if any(1 in row for row in new_array):
        print("NO")
        return
    else:
        print("YES")
        

for _ in range(int(input())):
    solve()