#include <bits/stdc++.h>
using namespace std;

const string CHARSET = "abcdefghijklmnopqrstuvwxyz";

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

// Generuje słowo o długości od 1 do max_len
string random_word(int max_len) {
    if (max_len < 1) max_len = 1;
    uniform_int_distribution<int> dist_len(1, max_len);
    int len = dist_len(rng);

    string s;
    s.reserve(len);
    uniform_int_distribution<int> dist_char(0, CHARSET.size() - 1);
    for (int i = 0; i < len; i++)
        s.push_back(CHARSET[dist_char(rng)]);
    return s;
}

// Generuje N słów o sumarycznej długości <= S
void generate_test_case(int N, int S) {
    vector<string> words;
    words.reserve(N);

    int remaining = S;

    for (int i = 0; i < N; i++) {
        int max_len_for_word = remaining - (N - i - 1); // zostaw przynajmniej 1 znak na każde kolejne słowo
        if (max_len_for_word < 1) max_len_for_word = 1;

        string w = random_word(max_len_for_word);
        words.push_back(w);
        remaining -= w.size();
    }

    cout << words.size() << "\n";
    for (auto &w : words) cout << w << "\n";
}

int main(int argc, char* argv[]) {
    int N = (argc > 1 ? stoi(argv[1]) : 5);
    int S = (argc > 2 ? stoi(argv[2]) : 200);

    generate_test_case(N, S);
}
