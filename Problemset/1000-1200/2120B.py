for _ in range(int(input())):
    n, s = map(int, input().split())
    potted_balls = 0

    for _ in range(n):
        dx, dy, x, y = map(int, input().split())
        
        if (dx == dy and x == y) or \
           (dx != dy and x + y == s):
            potted_balls += 1
            
    print(potted_balls)