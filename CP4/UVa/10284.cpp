#include <bits/stdc++.h>

using namespace std;


void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    std::string s;
    std::cin >> s;
    std::vector<std::vector<char>> cb(8, std::vector<char>(8, 0)); 
    std::vector<std::vector<bool>> attacked(8, std::vector<bool>(8, false));
    
    if (s.back() != '/') {
        s += "/";
    }
    int index = 0;
    int x = 0;
    int y = 0; 
    while (y < 8 && index < s.length()) { 
        char c = s[index];
        
        if (c == '/') {
            y++;
            x = 0; 
        } else if (isdigit(c)){ 
            x += (c - '0'); 
        } else {
            if (x < 8 && y < 8) {
                cb[y][x] = c; 
                attacked[y][x] = true; 
            }
            x++;
        }
        index++; 
    }

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            char curr = cb[y][x];
            
            if (curr != 0) { 
                char piece_type = curr; 
                
                int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}; 
                int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1}; 
                if (string("RQBrqb").find(piece_type) != string::npos) {
                    for (int dir = 0; dir < 8; ++dir) {
                        bool is_diagonal = (dir == 0 || dir == 2 || dir == 5 || dir == 7);
                        bool is_straight = !is_diagonal;
                        
                        if ((piece_type == 'R' || piece_type == 'r') && is_diagonal) continue; 
                        if ((piece_type == 'B' || piece_type == 'b') && is_straight) continue; 
                        
                        for (int k = 1; k < 8; ++k) {
                            int next_y = y + k * dy[dir];
                            int next_x = x + k * dx[dir];
                            
                            if (next_y >= 0 && next_y < 8 && next_x >= 0 && next_x < 8) {
                                attacked[next_y][next_x] = true;
                                if (cb[next_y][next_x] != 0) {
                                    break;
                                }
                            } else {
                                break; 
                            }
                        }
                    }
                }

                if (piece_type == 'N' || piece_type == 'n') {
                    int n_dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
                    int n_dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
                    
                    for (int k = 0; k < 8; ++k) {
                        int next_y = y + n_dy[k];
                        int next_x = x + n_dx[k];
                        if (next_y >= 0 && next_y < 8 && next_x >= 0 && next_x < 8) {
                            attacked[next_y][next_x] = true;
                        }
                    }
                }

                if (piece_type == 'K' || piece_type == 'k') {
                    for (int k = 0; k < 8; ++k) {
                        int next_y = y + dy[k]; 
                        int next_x = x + dx[k];
                        if (next_y >= 0 && next_y < 8 && next_x >= 0 && next_x < 8) {
                            attacked[next_y][next_x] = true;
                        }
                    }
                }
                
                if (piece_type == 'P' || piece_type == 'p') {
                    int direction = (piece_type == 'P') ? -1 : 1; 
                    for (int df : {-1, 1}) { 
                        int next_y = y + direction;
                        int next_x = x + df;
                        if (next_y >= 0 && next_y < 8 && next_x >= 0 && next_x < 8) {
                            attacked[next_y][next_x] = true;
                        }
                    }
                }
            }
        }
    }
    
    int attacked_count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (attacked[i][j] == false && cb[i][j] == 0) attacked_count++;
        }
    }
    std::cout << attacked_count << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}