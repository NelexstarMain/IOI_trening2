def solve():
    a, x, y = map(int, input().split())

    if (a < x and a < y) or (a > x and a > y):
        print("YES")
    else:
        print("NO")

num_test_cases = int(input())
for _ in range(num_test_cases):
    solve()