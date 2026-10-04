#pragma once
#include <vector>

using namespace std;

// SOLUTION: Insertion Sort
inline void insertionSort(vector<int>& arr) {
    if (arr.size() <= 1) return;
    int n = static_cast<int>(arr.size());
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        // Shift elements of arr[0..i-1] that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
