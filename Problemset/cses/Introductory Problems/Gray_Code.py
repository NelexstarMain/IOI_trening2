from collections import deque

n = int(input())

start = tuple(0 for _ in range(n))
size = 2 ** n

memo_set = set([start])
memo_list = [start]

queue = deque([start])

while queue and len(memo_list) < size:
    string = queue.popleft()
    for i in range(n):
        new = list(string)
        new[i] = 0 if new[i] == 1 else 1
        print(i, new)
        new_t = tuple(new)
        if new_t not in memo_set:
            memo_set.add(new_t)
            memo_list.append(new_t)
            queue.append(new_t)

for code in memo_list:
    print(''.join(map(str, code)))
