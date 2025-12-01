import sys

def solve():
    knight_moves = [
        (-2, -1), (-2, 1), (-1, -2), (-1, 2),
        (1, -2), (1, 2), (2, -1), (2, 1)
    ]
    
    king_moves = [
        (-1, -1), (-1, 0), (-1, 1),
        (0, -1),           (0, 1),
        (1, -1),  (1, 0),  (1, 1)
    ]

    lines = sys.stdin.read().splitlines()

    for fen in lines:
        if not fen:
            continue
            
        board = [[' ' for _ in range(8)] for _ in range(8)]
        row = 0
        col = 0
        
        for char in fen:
            if char == '/':
                row += 1
                col = 0
            elif char.isdigit():
                col += int(char)
            else:
                board[row][col] = char
                col += 1
        
        attacked = [[False for _ in range(8)] for _ in range(8)]
        
        for r in range(8):
            for c in range(8):
                piece = board[r][c]
                if piece == ' ':
                    continue
                
                p_lower = piece.lower()
                
                if p_lower == 'p':)
                    direction = -1 if piece == 'P' else 1
                    
                    for dc in [-1, 1]:
                        nr, nc = r + direction, c + dc
                        if 0 <= nr < 8 and 0 <= nc < 8:
                            attacked[nr][nc] = True

                elif p_lower == 'n':
                    for dr, dc in knight_moves:
                        nr, nc = r + dr, c + dc
                        if 0 <= nr < 8 and 0 <= nc < 8:
                            attacked[nr][nc] = True

                elif p_lower == 'k':
                    for dr, dc in king_moves:
                        nr, nc = r + dr, c + dc
                        if 0 <= nr < 8 and 0 <= nc < 8:
                            attacked[nr][nc] = True

                else:
                    directions = []
                    if p_lower == 'r' or p_lower == 'q':
                        directions.extend([(0, 1), (0, -1), (1, 0), (-1, 0)]) 
                    if p_lower == 'b' or p_lower == 'q':
                        directions.extend([(1, 1), (1, -1), (-1, 1), (-1, -1)])
                    
                    for dr, dc in directions:
                        nr, nc = r + dr, c + dc
                        while 0 <= nr < 8 and 0 <= nc < 8:
                            attacked[nr][nc] = True
                            if board[nr][nc] != ' ':
                                break
                            nr += dr
                            nc += dc

        safe_count = 0
        for r in range(8):
            for c in range(8):
                if board[r][c] == ' ' and not attacked[r][c]:
                    safe_count += 1
                    
        print(safe_count)

if __name__ == "__main__":
    solve()