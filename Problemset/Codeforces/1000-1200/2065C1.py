for _ in range(int(input())):
    n, _ = map(int, input().split(" "))
    a = list(map(int, input().split(" ")))
    m = int(input())

    b = [(x, m - x) for x in a]

    prev_values = [b[0][0], b[0][1]]

    for i in range(1, n):
        current_values = [b[i][0], b[i][1]]
        new_prev = []

        for val in current_values:
            if any(prev <= val for prev in prev_values):
                new_prev.append(val)

        if not new_prev:
            print("NO")
            break

        prev_values = new_prev
    else:
        print("YES")
