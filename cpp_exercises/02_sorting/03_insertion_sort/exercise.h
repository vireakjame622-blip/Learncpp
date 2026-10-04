#pragma once
#include <vector>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 03_insertion_sort
//    OR:
//    .\run_tests.bat 03_insertion_sort
// ============================================================================

// EXERCISE 2.3: Insertion Sort
// CADT Lab Session 02 - Exercise 3 & Week 2 Slides
//
// TASK:
// Implement insertionSort(vector<int>& arr)
// 1. Loop i from 1 to n - 1.
// 2. key = arr[i].
// 3. j = i - 1.
// 4. While j >= 0 and arr[j] > key, shift arr[j] rightward to arr[j + 1], then j--.
// 5. Place key at arr[j + 1].
//
// Time Complexity:
// - Best case (already sorted): O(n)
// - Worst case (reverse sorted): O(n^2)

inline void insertionSort(vector<int>& arr) {
    // TODO: Implement insertion sort
    (void)arr;
}
