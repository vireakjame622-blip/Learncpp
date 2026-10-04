#pragma once
#include <vector>
#include <stdexcept>
#include <numeric>
#include <utility>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 03_array_algorithms
//    OR:
//    .\run_tests.bat 03_array_algorithms
// ============================================================================

// EXERCISE 1.3: Array & Vector Algorithms
// CADT Lab Session 01 - Exercise 6 & DSA Arrays
//
// TASKS:
// 1. findMax(const vector<int>& arr):
//    - Returns the maximum integer in the array.
//    - If arr is empty, throw invalid_argument("Array is empty").
//
// 2. findMin(const vector<int>& arr):
//    - Returns the minimum integer in the array.
//    - If arr is empty, throw invalid_argument("Array is empty").
//
// 3. calculateAverage(const vector<int>& arr):
//    - Returns the mathematical average as a double.
//    - WATCH OUT FOR INTEGER DIVISION! If sum is int and size is int, (sum / size) drops decimals!
//    - If arr is empty, throw invalid_argument("Array is empty").
//
// 4. reverseInPlace(vector<int>& arr):
//    - Reverses the elements of arr directly in-place without creating a second vector.
//    - Hint: Use two pointers/indices (left = 0, right = arr.size() - 1) and swap.

inline int findMax(const vector<int>& arr) {
    // TODO: implement (throw if empty)
    (void)arr;
    return 0;
}

inline int findMin(const vector<int>& arr) {
    // TODO: implement (throw if empty)
    (void)arr;
    return 0;
}

inline double calculateAverage(const vector<int>& arr) {
    // TODO: implement (throw if empty, cast to double before division)
    (void)arr;
    return 0.0;
}

inline void reverseInPlace(vector<int>& arr) {
    // TODO: implement two-pointer swap
    (void)arr;
}
