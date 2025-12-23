import math
import random
import time
import sys
import os

# Konfiguracja
WIDTH = 10
HEIGHT = 10
CHARS = [" ", ".", "░", "▒", "▓", "█"] # Od pustki do pełnej plamy
SCALE = 0.3  # Im mniejsza liczba, tym większe i "wolniejsze" plamy
SPEED = 0.1  # Prędkość zmian w czasie

def lerp(a, b, x):
    return a + x * (b - a)

def fade(t):
    return t * t * t * (t * (t * 6 - 15) + 10)

def gradient(h, x, y):
    vectors = [(0,1), (0,-1), (1,0), (-1,0)]
    g = vectors[h % 4]
    return g[0] * x + g[1] * y

# Uproszczona implementacja szumu 2D
p = list(range(256))
random.shuffle(p)
p = p + p

def noise(x, y):
    X = int(x) & 255
    Y = int(y) & 255
    xf = x - int(x)
    yf = y - int(y)
    u = fade(xf)
    v = fade(yf)
    n00 = gradient(p[p[X]+Y], xf, yf)
    n01 = gradient(p[p[X]+Y+1], xf, yf-1)
    n10 = gradient(p[p[X+1]+Y], xf-1, yf)
    n11 = gradient(p[p[X+1]+Y+1], xf-1, yf-1)
    x1 = lerp(n00, n10, u)
    x2 = lerp(n01, n11, u)
    return lerp(x1, x2, v)

def run_animation():
    t = 0
    sys.stdout.write("\033[?25l") # Ukryj kursor
    try:
        while True:
            output = "\033[H--- SYSTEM ANALYSYS ---\n"
            for y in range(HEIGHT):
                line = ""
                for x in range(WIDTH):
                    # Pobieramy wartość szumu i mapujemy ją na znaki
                    # Dodajemy 't', aby plamy ewoluowały w czasie
                    n = noise(x * SCALE, y * SCALE + t)
                    # Normalizacja n (-1 do 1) na indeks tablicy CHARS
                    idx = int(((n + 1) / 2) * (len(CHARS) - 1))
                    idx = max(0, min(len(CHARS) - 1, idx))
                    line += CHARS[idx] + " "
                output += line + "\n"
            
            output += "-----------------------\n"
            sys.stdout.write(output)
            sys.stdout.flush()
            t += SPEED
            time.sleep(0.1)
    except KeyboardInterrupt:
        sys.stdout.write("\033[?25h\n")

if __name__ == "__main__":
    os.system('cls' if os.name == 'nt' else 'clear')
    run_animation()