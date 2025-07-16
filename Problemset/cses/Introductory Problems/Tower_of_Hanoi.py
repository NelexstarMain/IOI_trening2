moves = []

def hanoi(n, source, dest, aux):
    if n == 1:
        moves.append((source, dest))
    else:
        hanoi(n - 1, source, aux, dest)
        moves.append((source, dest))
        hanoi(n - 1, aux, dest, source)

n = int(input())
hanoi(n, 1, 3, 2)

print(len(moves))
for a, b in moves:
    print(a, b)
