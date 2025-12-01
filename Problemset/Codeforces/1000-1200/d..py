def solve():
    n = int(input())
    p = list(map(int, input().split())) 
    s_str = input()

    value_colors = [0] * n 
    for k in range(n):
        value_colors[p[k] - 1] = int(s_str[k])

    memo = [-1] * (n + 1)

    results = []

    for start_value in range(1, n + 1):
        if memo[start_value] != -1:
            results.append(str(memo[start_value]))
            continue

        path_nodes = [] 
        path_visited_indices = {} 
        
        current_value = start_value 
        
        while True:
            if memo[current_value] != -1:
                current_path_black_count = 0
                for node_in_path in path_nodes:
                    if value_colors[node_in_path - 1] == 0:
                        current_path_black_count += 1
                
                memo[start_value] = current_path_black_count + memo[current_value]
                break

            if current_value in path_visited_indices:
                cycle_start_index = path_visited_indices[current_value]
                
                cycle_black_count = 0
                for node_in_cycle_path_index in range(cycle_start_index, len(path_nodes)):
                    node = path_nodes[node_in_cycle_path_index]
                    if value_colors[node - 1] == 0:
                        cycle_black_count += 1
                
                for node_in_cycle_path_index in range(cycle_start_index, len(path_nodes)):
                    node = path_nodes[node_in_cycle_path_index]
                    memo[node] = cycle_black_count
                
                for node_in_path_index in range(cycle_start_index - 1, -1, -1):
                    node = path_nodes[node_in_path_index]
                    next_node = path_nodes[node_in_path_index + 1]
                    
                    black_contribution = 1 if value_colors[node - 1] == 0 else 0
                    memo[node] = black_contribution + memo[next_node]
                
                break

            if value_colors[current_value - 1] == 1:
                for node in path_nodes:
                    memo[node] = 0
                memo[current_value] = 0
                break

            path_visited_indices[current_value] = len(path_nodes)
            path_nodes.append(current_value)
            
            current_value = p[current_value - 1]
        
        results.append(str(memo[start_value]))
    
    print(" ".join(results))

t = int(input())
for _ in range(t):
    solve()