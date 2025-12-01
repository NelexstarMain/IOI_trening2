n = int(input())

r = [str(n)]


while n != 1:
    if n % 2 == 0:
        n = n / 2
    else:
        n *= 3
        n += 1

    r.append(str(int(n)))


print(" ".join(r))
