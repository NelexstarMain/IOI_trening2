#

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    result = []

    for k in range(1, n + 1):
        max_sum = 0
        for i in range(n):
            temp = a[:i] + a[i+1:] + [a[i]] 
            current_sum = sum(temp[-k:]) 
            max_sum = max(max_sum, current_sum)

        result.append(str(max_sum))

    print(" ".join(result))
