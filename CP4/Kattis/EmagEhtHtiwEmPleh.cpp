#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    std::string s, curr; std::cin >> s >> curr;
    std::vector<std::string> white, black;
    std::vector<std::vector<char>> chb(8, std::vector<char>(8, ' '));
    if (curr != "Black:") {
        int starta = 0, end = 0;
        for (int i = 0; i < curr.size(); i++) {
            if (curr[i] == ',') {
                white.push_back(curr.substr(starta, end - starta));
                end++;
                starta = end;
            } else {
                end++;
            }
            
        }
        white.push_back(curr.substr(starta, end - starta));
        std::cin >> s;
    } 

    if (std::cin >> curr) {
        int starta = 0, end = 0;
        for (int i = 0; i < curr.size(); i++) {
            if (curr[i] == ',') {
                black.push_back(curr.substr(starta, end - starta));
                end++;
                starta = end;
            } else {
                end++;
            }
            
        }
        black.push_back(curr.substr(starta, end - starta));
    }
    
   
    for (auto const& x: white) {
        char piece_char;
        char file_char;
        char rank_char;
        
        if (x.size() == 3) {
            piece_char = x[0];
            file_char = x[1];
            rank_char = x[2];
        } else { 
            piece_char = 'P'; 
            file_char = x[0];
            rank_char = x[1];
        }
        
        int row_idx = '8' - rank_char; 
        int col_idx = file_char - 'a';  
        
        chb[row_idx][col_idx] = piece_char;
    } 

    for (auto const& x: black) {
        char piece_char;
        char file_char;
        char rank_char;
        
        if (x.size() == 3) {
            piece_char = std::tolower(x[0]); 
            file_char = x[1];
            rank_char = x[2];
        } else {
            piece_char = 'p'; 
            file_char = x[0];
            rank_char = x[1];
        }

        int row_idx = '8' - rank_char;
        int col_idx = file_char - 'a';
        
        chb[row_idx][col_idx] = piece_char;
    }

    std::string line = "+---+---+---+---+---+---+---+---+";
    for (int i = 0; i < 8; i++) {

        std::cout << line << "\n";
        for (int j = 0; j < 8; j++) {
            std::cout << "|";
            char piece = chb[i][j];
        
            char bg_char = ((i+j)%2) ? ':' : '.';
            
            if (piece != ' ') {
                std::cout << bg_char << piece << bg_char; 
            } else {
                std::cout << bg_char << bg_char << bg_char; 
            }
        }
        std::cout << "|\n";
    }
    std::cout << line << "\n";

}

int main() {
    fast_io();
    solve();
    return 0;
}


// White: Ke1,Qd1,Ra1,Rh1,Bc1,Bf1,Nb1,a2,c2,d2,f2,g2,h2,a3,e4
// Black: Ke8,Qd8,Ra8,Rh8,Bc8,Ng8,Nc6,a7,b7,c7,d7,e7,f7,h7,h6
// białe som duże

// PQKNBR