# class Node:
#     def __init__(self, vals):
#         self.val: tuple = vals 
#         self.children: list[Node] = []

#     def add_child(self, child):
#         self.children.append(child)


# n = int(input())
# a = list(map(int, input().split()))


# root = Node((0, 0))

# current_level = [root]

# for val in a:
#     next_level = []
#     for node in current_level:
#         left = Node((node.val[0] + val, node.val[1]))
#         right = Node((node.val[0], node.val[1]+val))
#         node.add_child(left)
#         node.add_child(right)
        
#         next_level.extend([left, right])

#     current_level = next_level

# print(min([abs(node.val[0]-node.val[1]) for node in current_level]))

n = int(input())
values = list(map(int, input().split()))

a = [(0, 0)]
b = []

for i in range(n):
    for x, y in a:
        b.append((x + values[i], y))
        b.append((x, y + values[i]))
    a = b
    b = []

print(min(abs(x - y) for x, y in a))
