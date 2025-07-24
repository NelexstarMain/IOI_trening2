#include <bits/stdc++.h>

int binarysearch_recursive(const std::vector<int>& array, int value, int l, int r) {
    if (l > r) return -1;

    int mid = l + (r - l) / 2;

    if (array[mid] == value) {
        return mid;
    } else if (array[mid] < value) {
        return binarysearch_recursive(array, value, mid + 1, r);
    } else {
        return binarysearch_recursive(array, value, l, mid - 1);
    }
}

int binarysearch(int value, std::vector<int> array) {
    std::sort(array.begin(), array.end());
    return binarysearch_recursive(array, value, 0, array.size() - 1);
}

int main() {
    std::vector<int> arr = {2, 54, 32, 657, 32, 3, 4, 5, 6, 7};
    std::cout << binarysearch(5, arr);
}
