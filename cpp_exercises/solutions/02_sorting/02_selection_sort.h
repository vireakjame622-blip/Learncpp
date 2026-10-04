#pragma once
#include <vector>
#include <utility>

using namespace std;

// SOLUTION: Selection Sort
inline void selectionSort(vector<int>& arr) {
    if (arr.size() <= 1) return;
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; ++i) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
        }
    }
}
