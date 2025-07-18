n, x = map(int, input().split())
a = list(map(int, input().split()))

value_to_index = {}

for i in range(n):
    complement = x - a[i]
    if complement in value_to_index:
        print(value_to_index[complement] + 1, i + 1)
        break
    value_to_index[a[i]] = i
else:
    print("IMPOSSIBLE")
