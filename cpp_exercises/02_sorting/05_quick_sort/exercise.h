#pragma once
#include <vector>
#include <utility>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 05_quick_sort
//    OR:
//    .\run_tests.bat 05_quick_sort
// ============================================================================

// EXERCISE 2.5: Quick Sort (Partitioning)
// CADT Lab Session 02 & DSA Week 2
//
// TASK:
// Implement quickSort(vector<int>& arr)
// 1. Pick a pivot (e.g. arr[high]).
// 2. Partition: rearrange array so elements < pivot are to the left,
//    and elements >= pivot are to the right. Return pivot index.
// 3. Recursively call quickSort on left and right sub-arrays.
//
// Time Complexity:
// - Average: O(n log n)
// - Worst case (bad pivot on sorted array): O(n^2)

inline int partitionLomuto(vector<int>& arr, int low, int high) {
    // TODO: Implement Lomuto partitioning
    (void)arr; (void)low; (void)high;
    return low;
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
