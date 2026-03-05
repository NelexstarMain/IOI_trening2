#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class UnionFind {                        
private:
    vi p, rank, setSize, fakeNode;                        
    int fakeIdx;
    vector<long long> sumSet; 
public:
    UnionFind(int N) {
        p.assign(N + 1, 0);
        for (int i = 0; i < N + 1; ++i) p[i] = i;
        rank.assign(N + 1, 0);                          
        sumSet.assign(N + 1, 0);
        for (int i = 1; i < N + 1; ++i) sumSet[i] = i;
        setSize.assign(N + 1, 1);                        
        fakeNode.assign(N + 1, 0);
        for (int i = 1; i < N + 1; ++i) fakeNode[i] = i; 
        fakeIdx = N + 1;
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int sizeOfSet(int i) { return setSize[findSet(fakeNode[i])]; } 

    void unionSet(int i, int j) {
        if (isSameSet(fakeNode[i], fakeNode[j])) return;                
        int x = findSet(fakeNode[i]), y = findSet(fakeNode[j]);         
        if (rank[x] > rank[y]) swap(x, y);           
        p[x] = y;                                    
        if (rank[x] == rank[y]) ++rank[y];           
        setSize[y] += setSize[x];                    
        sumSet[y] += sumSet[x]; 
    }

    long long sumOfSet(int i) {
        return sumSet[findSet(fakeNode[i])];
    } 


    void moveSet(int i, int j) {
        if (isSameSet(fakeNode[i], fakeNode[j])) return;                
        // add a fake variable
        p.push_back(fakeIdx);
        rank.push_back(0);
        sumSet.push_back(i);
        setSize.push_back(1);
        sumSet[findSet(fakeNode[i])] -= i;
        setSize[findSet(fakeNode[i])] -= 1;
        fakeNode[i] = fakeIdx++;
        unionSet(i, j);
    }

};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        UnionFind uf(n);
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            if (x == 1) {
                int a, b;
                cin >> a >> b;
                uf.unionSet(a, b);
            } else if (x == 2) {
                int a, b;
                cin >> a >> b;
                uf.moveSet(a, b);
            } else {
                int a;
                cin >> a;
                cout << uf.sizeOfSet(a) << " " << uf.sumOfSet(a) << endl;
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}