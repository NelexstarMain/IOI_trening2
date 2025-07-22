import bisect

n = int(input())
cubes = list(map(int, input().split()))
tops = []

for c in cubes:
    i = bisect.bisect_right(tops, c)
    if i < len(tops):
        tops[i] = c
    else:
        tops.append(c)

print(len(tops))
