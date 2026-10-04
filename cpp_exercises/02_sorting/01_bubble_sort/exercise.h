#pragma once
#include <vector>
#include <utility>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 01_bubble_sort
//    OR:
//    .\run_tests.bat 01_bubble_sort
// ============================================================================

// EXERCISE 2.1: Bubble Sort
// CADT Lab Session 02 - Exercise 1 & Week 2 Slides
//
// TASK:
// Implement bubbleSort(vector<int>& arr)
// 1. Repeatedly compare adjacent elements arr[j] and arr[j+1].
// 2. Swap them if arr[j] > arr[j+1].
// 3. OPTIMIZATION: Keep track of whether any swaps occurred during the pass.
//    If no swaps occurred, the array is already sorted — break early!
//
// Time Complexity:
// - Best case (already sorted with early break): O(n)
// - Worst case (reverse sorted): O(n^2)

inline void bubbleSort(vector<int>& arr) {
    // TODO: Implement bubble sort with early exit flag
    (void)arr;
}
