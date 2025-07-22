import bisect
from typing import List, Tuple

def cut(start: int, end: int, num: int) -> List[Tuple[int, int]]:
    if not start <= num <= end:
        return [(start, end)]
    if start == end == num:
        return []
    if num == start:
        return [(start + 1, end)]
    if num == end:
        return [(start, end - 1)]
    return [(start, num - 1), (num + 1, end)]

n, x = map(int, input().split())
a = list(map(int, input().split()))

r = []

intervals: List[Tuple[int, int]] = [(0, n)]

for pos in a:
    starts = [s for s, _ in intervals]
    i = bisect.bisect_right(starts, pos) - 1

    if 0 <= i < len(intervals) and intervals[i][0] <= pos <= intervals[i][1]:
        old = intervals.pop(i)
        new = cut(*old, pos)
        for inter in new:
            bisect.insort(intervals, inter)

    max_len = max((b - a + 1 for a, b in intervals), default=0)
    r.append(max_len)


print(" ".join([str(x) for x in r]))
