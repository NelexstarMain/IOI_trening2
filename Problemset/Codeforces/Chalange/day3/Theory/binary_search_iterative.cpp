#include <bits/stdc++.h>

int binarysearch(int value, std::vector<int> array) {
    
    std::sort(array.begin(), array.end());
    
    int l = 0, r = array.size()-1;

    while (l <= r) {
        int mid = l + ((r-l)/2);
        if (array[mid] == value) {
            return mid;
        } else if (array[mid] < value) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return 0;
}

int main() {
    std::vector<int> arr = {2, 54, 32, 657, 32, 3, 4, 5, 6, 7};
    std::cout << binarysearch(5, arr);

}