#pragma once
#include <vector>
#include <utility>

using namespace std;

// SOLUTION: Bubble Sort with Early Exit Optimization
inline void bubbleSort(vector<int>& arr) {
    if (arr.size() <= 1) return;
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, array is sorted!
        if (!swapped) break;
    }
}
