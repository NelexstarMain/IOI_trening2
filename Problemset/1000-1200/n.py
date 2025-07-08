import math
import random

sq = []

def solve():
    n = int(input()) + 1

    max_val = math.ceil(math.sqrt(sum(range(1, n))))
    if sq:
        last = int(math.sqrt(max(sq)))
    else:
        last = 0

    left = [i for i in range(1, n)]

    if max_val > last:
        for i in range(last + 1, max_val + 1):
            sq.append(i**2)

    result = []
    x = 1

    if math.sqrt(sum(range(1, n))) % 1 == 0:
        print("-1")
        return
    else:
        for _ in range(0, n-1):
            dan = [i - x for i in sq[0:max_val]]
            possible = [i for i in left if i not in dan]

            if not possible:
                    

            e = left.pop(left.index(random.choice(possible)))

            result.append(e)
            x += e

    print(result)


for _ in range(int(input())):
    solve()
