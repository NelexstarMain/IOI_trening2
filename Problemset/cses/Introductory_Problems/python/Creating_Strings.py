from itertools import permutations

n = input()

all_perms = permutations(n)

unique_perms = set(''.join(p) for p in all_perms)

print(len(unique_perms))
for perm in sorted(unique_perms):
    print(perm)
