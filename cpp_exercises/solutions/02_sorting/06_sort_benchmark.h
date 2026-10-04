#pragma once
#include <vector>
#include <chrono>
#include <functional>

using namespace std;

// SOLUTION: Sort Performance Benchmark (<chrono>)
inline long long measureSortTimeMicroseconds(function<void(vector<int>&)> sortFn, vector<int> arrCopy) {
    auto start = chrono::high_resolution_clock::now();
    sortFn(arrCopy);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}
