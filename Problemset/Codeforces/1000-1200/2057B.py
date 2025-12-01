from collections import Counter

def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    
    counts = Counter(a)
    
    sorted_counts_freq = sorted(counts.values())

    unique_elements = len(counts)
    
    if k == 0:
        print(unique_elements)
        return

    for count_val in sorted_counts_freq:
        cost_to_remove_all_with_this_freq = count_val 

        if k >= cost_to_remove_all_with_this_freq:
            k -= cost_to_remove_all_with_this_freq
            unique_elements -= 1
        else:
            break
            
    print(max(1, unique_elements))

t = int(input())
for _ in range(t):
    solve()