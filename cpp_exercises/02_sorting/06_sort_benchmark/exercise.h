#pragma once
#include <vector>
#include <chrono>
#include <functional>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 06_sort_benchmark
//    OR:
//    .\run_tests.bat 06_sort_benchmark
// ============================================================================

// EXERCISE 2.6: Sort Performance Benchmark (<chrono>)
// CADT Lab Session 02 - Setup & Bonus Challenge
//
// TASK:
// Implement measureSortTimeMicroseconds(sortFn, arr):
// 1. Accepts a sorting function pointer and a vector passed BY VALUE.
//    (Passing by value ensures each benchmark gets its own fresh, unsorted copy).
// 2. Uses chrono::high_resolution_clock to record start and end time.
// 3. Calls sortFn(arr).
// 4. Returns the duration in microseconds as a long long.

inline long long measureSortTimeMicroseconds(function<void(vector<int>&)> sortFn, vector<int> arrCopy) {
    // TODO:
    // 1. auto start = chrono::high_resolution_clock::now();
    // 2. sortFn(arrCopy);
    // 3. auto end = chrono::high_resolution_clock::now();
    // 4. return chrono::duration_cast<chrono::microseconds>(end - start).count();
    (void)sortFn; (void)arrCopy;
    return 0;
}
