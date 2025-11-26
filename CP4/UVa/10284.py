import sys

def solve():
    # Definicje kierunków ruchów dla figur
    # Skoczek (Knight) - 8 skoków
    knight_moves = [
        (-2, -1), (-2, 1), (-1, -2), (-1, 2),
        (1, -2), (1, 2), (2, -1), (2, 1)
    ]
    
    # Król (King) - 8 pól dookoła
    king_moves = [
        (-1, -1), (-1, 0), (-1, 1),
        (0, -1),           (0, 1),
        (1, -1),  (1, 0),  (1, 1)
    ]

    # Czytamy wejście linia po linii
    lines = sys.stdin.read().splitlines()

    for fen in lines:
        if not fen:
            continue
            
        # 1. Budowanie planszy 8x8 z FEN
        board = [[' ' for _ in range(8)] for _ in range(8)]
        row = 0
        col = 0
        
        for char in fen:
            if char == '/':
                row += 1
                col = 0
            elif char.isdigit():
                # Cyfra oznacza liczbę pustych pól
                col += int(char)
            else:
                # Litera oznacza figurę
                board[row][col] = char
                col += 1
        
        # 2. Obliczanie atakowanych pól
        # Tworzymy tablicę boolean: True jeśli pole jest atakowane
        attacked = [[False for _ in range(8)] for _ in range(8)]
        
        for r in range(8):
            for c in range(8):
                piece = board[r][c]
                if piece == ' ':
                    continue
                
                # Konwersja na małą literę dla uproszczenia (z wyjątkiem pionów)
                p_lower = piece.lower()
                
                # --- Piony (Pawn) ---
                if p_lower == 'p':
                    # Biały (P) bije w górę (r-1), Czarny (p) bije w dół (r+1)
                    # W FEN wiersz 0 to góra planszy.
                    direction = -1 if piece == 'P' else 1
                    
                    # Pion atakuje na skos
                    for dc in [-1, 1]:
                        nr, nc = r + direction, c + dc
                        if 0 <= nr < 8 and 0 <= nc < 8:
                            attacked[nr][nc] = True

                # --- Skoczek (Knight) ---
                elif p_lower == 'n':
                    for dr, dc in knight_moves:
                        nr, nc = r + dr, c + dc
                        if 0 <= nr < 8 and 0 <= nc < 8:
                            attacked[nr][nc] = True

                # --- Król (King) ---
                elif p_lower == 'k':
                    for dr, dc in king_moves:
                        nr, nc = r + dr, c + dc
                        if 0 <= nr < 8 and 0 <= nc < 8:
                            attacked[nr][nc] = True

                # --- Figury Liniowe (Rook, Bishop, Queen) ---
                # Wieża: prosto, Goniec: skos, Hetman: oba
                else:
                    directions = []
                    if p_lower == 'r' or p_lower == 'q':
                        directions.extend([(0, 1), (0, -1), (1, 0), (-1, 0)]) # Poziomo/Pionowo
                    if p_lower == 'b' or p_lower == 'q':
                        directions.extend([(1, 1), (1, -1), (-1, 1), (-1, -1)]) # Skosy
                    
                    for dr, dc in directions:
                        nr, nc = r + dr, c + dc
                        while 0 <= nr < 8 and 0 <= nc < 8:
                            attacked[nr][nc] = True
                            # Jeśli trafimy na jakąkolwiek figurę (swoją lub wroga),
                            # przestajemy "iść" dalej w tym kierunku (blokada)
                            if board[nr][nc] != ' ':
                                break
                            nr += dr
                            nc += dc

        # 3. Zliczanie bezpiecznych pustych pól
        safe_count = 0
        for r in range(8):
            for c in range(8):
                if board[r][c] == ' ' and not attacked[r][c]:
                    safe_count += 1
                    
        print(safe_count)

if __name__ == "__main__":
    solve()