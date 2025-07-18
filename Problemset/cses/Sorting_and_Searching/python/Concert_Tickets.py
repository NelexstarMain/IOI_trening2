n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a.sort()

def binary(num, a) -> int:
    left = 0
    right = len(a) - 1
    res = -1
    while left <= right:
        mid = (left + right) // 2
        if a[mid] <= num:
            res = mid
            left = mid + 1
        else:
            right = mid - 1
    return res  

for price in b:
    idx = binary(price, a)
    if idx != -1:
        print(a[idx])
        a.pop(idx) 
    else:
        print(-1)  
