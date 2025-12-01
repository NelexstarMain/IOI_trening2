n = int(input())
a = list(map(int, input().split()))
a.sort()

max_reachable = 1
for x in a:
    if x > max_reachable:
        break
    max_reachable += x

print(max_reachable) 

