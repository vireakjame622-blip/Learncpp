#pragma once
#include <cstddef>
#include <algorithm>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 05_pointers_and_references
//    OR:
//    .\run_tests.bat 05_pointers_and_references
// ============================================================================

// EXERCISE 1.5: Pointers, References & Memory Manipulation
// CADT Lab Session 01 - Exercises 8 & 9
//
// TASKS:
// 1. swapByReference(int& a, int& b):
//    - Swaps the values of two integers using C++ references.
//    - Modifies the original caller variables directly without copying.
//
// 2. swapByPointer(int* a, int* b):
//    - Swaps the values of two integers using raw pointers.
//    - GUARD CONDITION: If either a or b is nullptr, do nothing and return false!
//    - If both are valid, swap *a and *b and return true.
//
// 3. clampValue(int* valPtr, int minVal, int maxVal):
//    - If valPtr is nullptr, do nothing.
//    - Otherwise, if *valPtr < minVal, set *valPtr = minVal.
//    - If *valPtr > maxVal, set *valPtr = maxVal.
//
// 4. sumArrayViaPointer(const int* arr, size_t size):
//    - Computes and returns the sum of array elements using pointer traversal
//      (e.g. pointer arithmetic *(arr + i) or ptr++).
//    - If arr is nullptr or size == 0, return 0.

inline void swapByReference(int& a, int& b) {
    // TODO: implement swap using reference
    (void)a; (void)b;
}

inline bool swapByPointer(int* a, int* b) {
    // TODO: implement null check and pointer dereference swap
    (void)a; (void)b;
    return false;
}

inline void clampValue(int* valPtr, int minVal, int maxVal) {
    // TODO: check nullptr, clamp *valPtr within [minVal, maxVal]
    (void)valPtr; (void)minVal; (void)maxVal;
}

inline int sumArrayViaPointer(const int* arr, size_t size) {
    // TODO: implement pointer arithmetic sum
    (void)arr; (void)size;
    return 0;
}
