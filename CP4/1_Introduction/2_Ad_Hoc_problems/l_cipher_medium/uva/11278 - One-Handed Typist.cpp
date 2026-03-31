#include <bits/stdc++.h>

using namespace std;

int main() {
    string qwerty = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
    string dvorak = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";
    string input;
    while(getline(cin, input)){
        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < qwerty.size(); j++) {
                if (input[i] == qwerty[j]) {
                    input[i] = dvorak[j];
                    break;
                }
            }
        }
        cout << input << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}