from collections import deque

n, x = map(int, input().split())
a = list(map(int, input().split()))

a.sort()
dq = deque(a)

boats = 0

while dq:
    if len(dq) >= 2 and dq[0] + dq[-1] <= x:
        dq.popleft()  
        dq.pop()     
    else:
        dq.pop()      
    boats += 1

print(boats)
