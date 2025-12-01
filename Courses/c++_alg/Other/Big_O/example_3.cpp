#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime>    
#include <algorithm> 

using namespace std;

int binarySearch(int num, const vector<int>& array) {
    int left = 0;
    int right = (int)array.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == num) {
            return mid;
        } else if (array[mid] < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    srand(time(nullptr));

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 10000000;  
    }

    sort(v.begin(), v.end());  

    int target = rand() % 1000000;
    cout << "Start" << endl;
    int index = binarySearch(target, v);

    if (index != -1)
        cout << "Znaleziono " << target << " na pozycji " << index << endl;
    else
        cout << "Nie znaleziono " << target << endl;


    cin >> n;
    return 0;
}
