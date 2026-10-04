#pragma once
#include <vector>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 04_merge_sort
//    OR:
//    .\run_tests.bat 04_merge_sort
// ============================================================================

// EXERCISE 2.4: Merge Sort (Divide & Conquer)
// CADT Lab Session 02 & DSA Week 2
//
// TASK:
// Implement mergeSort(vector<int>& arr)
// 1. Recursive divide-and-conquer: split array into left and right halves.
// 2. Recursively sort each half until size <= 1.
// 3. Merge two sorted halves back into a single sorted array.
//
// Time Complexity: O(n log n) in all cases (best, average, worst).
// Space Complexity: O(n) auxiliary space for merging.

inline void mergeHelper(vector<int>& arr, int left, int mid, int right) {
    // TODO: Merge arr[left..mid] and arr[mid+1..right]
    (void)arr; (void)left; (void)mid; (void)right;
}

inline void mergeSortRecursive(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortRecursive(arr, left, mid);
    mergeSortRecursive(arr, mid + 1, right);
    mergeHelper(arr, left, mid, right);
}

inline void mergeSort(vector<int>& arr) {
    if (arr.size() <= 1) return;
    mergeSortRecursive(arr, 0, static_cast<int>(arr.size()) - 1);
}
