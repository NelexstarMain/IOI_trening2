#include <bits/stdc++.h>

using namespace std;

int solveLeft(const vector<int>& heights){
    int overallMax = 0, currHeight, currMin;
    stack<int> s;
    for (int i = 0; i < heights.size(); i++) {
        currHeight = heights[i];
        if (s.empty() || currHeight >= s.top()) { 
            while (!s.empty() && currHeight >= s.top()) {
                overallMax = max(overallMax, s.top() - currMin);
                s.pop();
            }
            if (s.empty()) {
                currMin = currHeight;
            }
            s.push(currHeight);
        } else { 
            currMin = min(currMin, currHeight);
            s.push(currHeight);
        }
    }
    return overallMax;
}

int solveRight(vector<int> heights){
    int overallMax = 0, currHeight, currMin;
    stack<int> s;
    for (int i = heights.size() - 1; i >= 0; i--) {
        currHeight = heights[i];
        if (s.empty() || currHeight >= s.top()) { 
            while (!s.empty() && currHeight >= s.top()) {
                overallMax = max(overallMax, s.top() - currMin);
                s.pop();
            }
            if (s.empty()) {
                currMin = currHeight;
            }
            s.push(currHeight);
        } else { 
            currMin = min(currMin, currHeight);
            s.push(currHeight);
        }
    }
    return overallMax;
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    cout << max(solveLeft(heights), solveRight(heights)) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}