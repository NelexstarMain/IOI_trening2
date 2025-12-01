t = int(input())
for _ in range(t):
    n, m = map(int, input().split(" "))
    a = list(map(int, input().split(" ")))
    m_list = list(map(int, input().split(" ")))  # lista dostępnych wartości m

    # Dla każdego a[i] twórz zbiór możliwych wartości:
    # a[i] oraz m - a[i] dla każdego m w m_list
    options = []
    for x in a:
        opts = set()
        opts.add(x)
        for m in m_list:
            opts.add(m - x)
        options.append(sorted(opts))

    # Spróbuj znaleźć jedną niemalejącą ścieżkę
    found = False

    from collections import deque
    queue = deque()
    for val in options[0]:
        queue.append((1, val))  # (indeks, poprzednia_wartość)

    while queue:
        i, last = queue.popleft()
        if i == n:
            found = True
            break
        for val in options[i]:
            if val >= last:
                queue.append((i + 1, val))
                break  # wystarczy jedna droga

    print("YES" if found else "NO")
