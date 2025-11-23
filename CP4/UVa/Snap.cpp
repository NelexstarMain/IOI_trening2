#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(bool first) {
    if (!first) std::cout << "\n"; 

    std::string ja, jo; 
    std::cin >> ja >> jo;
    
    std::vector<char> jav, jov;
    std::queue<char> jaq, joq; 

    for (int i = 0; i < ja.size(); i++) jav.push_back(ja[i]);
    for (int i = 0; i < jo.size(); i++) jov.push_back(jo[i]);

    int jai = 0, joi = 0; 
    int round = 0;

    while (true) {
        round++;
        if (round > 1000) {
            std::cout << "Keeps going and going ..." << "\n";
            break;
        }
        if (jai >= jav.size()) {
            if (jaq.empty()) { std::cout << "John wins.\n"; return; }
            
            jav.clear();
            std::string temp;
            while(!jaq.empty()) {
                temp += jaq.front();
                jaq.pop();
            }
            for(char c : temp) jav.push_back(c);
            
            jai = 0;
        }

        if (joi >= jov.size()) {
            if (joq.empty()) { std::cout << "Jane wins.\n"; return; }
            
            jov.clear();
            std::string temp;
            while(!joq.empty()) {
                temp += joq.front();
                joq.pop();
            }
            for(char c : temp) jov.push_back(c);
            
            joi = 0;
        }

        
        jaq.push(jav[jai]);
        joq.push(jov[joi]);
        
        jai++;
        joi++;
        if (jav[jai] == jov[joi]) {
            if (rand() / 141 % 2 == 0) {
                while (!joq.empty()) {
                    jaq.push(joq.front());
                    joq.pop();
                }
                
                std::cout << "Snap! for Jane: ";
                std::string out;
                std::queue<char> copy = jaq;
                while(!copy.empty()) {
                    out += copy.front();
                    copy.pop();
                }
                std::reverse(out.begin(), out.end());
                std::cout << out << "\n";

            } else {
                while (!jaq.empty()) {
                    joq.push(jaq.front());
                    jaq.pop();
                }

                std::cout << "Snap! for John: ";
                std::string out;
                std::queue<char> copy = joq;
                while(!copy.empty()) {
                    out += copy.front();
                    copy.pop();
                }
                std::reverse(out.begin(), out.end()); 
                std::cout << out << "\n";
            }
        }
    }
}

int main() {
    fast_io();
    int t; 
    if (std::cin >> t) {
        bool first = true;
        while (t--) {
            solve(first);
            first = false;
        }
    }
    return 0;
}