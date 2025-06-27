# https://codeforces.com/problemset/problem/2084/B

import math
from collections import Counter

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    x = min(a)


    counter = Counter(a)


    # Zbierz wszystkie pozostałe liczby podzielne przez x
    multiples = []
    for num, cnt in counter.items():
        if num % x == 0:
            multiples.extend([num] * cnt)
    
    if not multiples:
        # brak wielokrotności x – nie da się zrobić gcd = x
        print("NO")
        return


    g = multiples[0]
    for num in multiples[1:]:
        g = math.gcd(g, num)

    if g == x:
        print("YES")
    else:
        print("NO")


t = int(input())
for _ in range(t):
    solve()