n = int(input())

for k in range(1, n + 1):
    possible = ((k**2) * (k**2 - 1))/2
    print(int(possible-((k-2)*(k-1))*4))