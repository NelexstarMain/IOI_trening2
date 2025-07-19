n = int(input())
a = list(map(int, input().split()))

min_prefix_sum = 0
max_subarray_sum = float('-inf')
current_sum = 0

for i in range(n): 
    current_sum += a[i]
    max_subarray_sum = max(max_subarray_sum, current_sum - min_prefix_sum)
    min_prefix_sum = min(min_prefix_sum, current_sum)

print(max_subarray_sum)
