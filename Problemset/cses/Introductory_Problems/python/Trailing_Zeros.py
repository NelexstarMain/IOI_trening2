def t_f(n):
    c = 0
    d = 5
    while d <= n:
        c += n // d
        d *= 5
    return c

n = int(input())
print(t_f(n))