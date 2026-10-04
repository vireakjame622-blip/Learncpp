#pragma once
#include <cstddef>
#include <algorithm>

using namespace std;

// SOLUTION: Pointers and References
inline void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

inline bool swapByPointer(int* a, int* b) {
    if (a == nullptr || b == nullptr) {
        return false;
    }
    int temp = *a;
    *a = *b;
    *b = temp;
    return true;
}

inline void clampValue(int* valPtr, int minVal, int maxVal) {
    if (valPtr == nullptr) return;
    if (*valPtr < minVal) {
        *valPtr = minVal;
    } else if (*valPtr > maxVal) {
        *valPtr = maxVal;
    }
}

inline int sumArrayViaPointer(const int* arr, size_t size) {
    if (arr == nullptr || size == 0) return 0;
    int total = 0;
    const int* ptr = arr;
    for (size_t i = 0; i < size; ++i) {
        total += *ptr;
        ptr++;
    }
    return total;
}
