#pragma once
#include <vector>
#include <utility>

using namespace std;

// SOLUTION: Quick Sort (Lomuto Partitioning)
inline int partitionLomuto(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

inline void quickSortRecursive(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionLomuto(arr, low, high);
        quickSortRecursive(arr, low, pi - 1);
        quickSortRecursive(arr, pi + 1, high);
    }
}

inline void quickSort(vector<int>& arr) {
    if (arr.size() <= 1) return;
    quickSortRecursive(arr, 0, static_cast<int>(arr.size()) - 1);
}
