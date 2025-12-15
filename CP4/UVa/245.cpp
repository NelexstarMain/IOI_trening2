#include <bits/stdc++.h>

using namespace std;

int main() {
    string buf, word, num;
    vector<string> words;
    set<string> s;
    while (getline(cin, buf), buf != "0") {
        for (int i = 0; i < buf.size(); i++) {
            if (isalpha(buf[i])) {
                while (isalpha(buf[i])) {
                    word += buf[i];
                    i++;
                }
                i--;

                if (s.insert(word).second) {
                    words.push_back(word);
                } else {
                    words.erase(find(words.begin(), words.end(), word));
                    words.push_back(word);
                }
                cout << word;
                word = "";
            } else if (isdigit(buf[i])) {
                num = "";
                while (isdigit(buf[i])) { 
                    num += buf[i];
                    i++;
                }
                i--; 
                string wordToReplace = words[words.size() - stoi(num)];
                words.erase(words.end() - stoi(num));
                words.push_back(wordToReplace);
                cout << wordToReplace;
            } else {
                cout << buf[i];
            }
        }
        cout << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}