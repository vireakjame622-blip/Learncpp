#pragma once
#include <vector>
#include <stdexcept>
#include <utility>

using namespace std;

// SOLUTION: Array Algorithms
inline int findMax(const vector<int>& arr) {
    if (arr.empty()) {
        throw invalid_argument("Array is empty");
    }
    int maxVal = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

inline int findMin(const vector<int>& arr) {
    if (arr.empty()) {
        throw invalid_argument("Array is empty");
    }
    int minVal = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

inline double calculateAverage(const vector<int>& arr) {
    if (arr.empty()) {
        throw invalid_argument("Array is empty");
    }
    double sum = 0.0;
    for (int val : arr) {
        sum += val;
    }
    return sum / arr.size(); // safe double division
}

inline void reverseInPlace(vector<int>& arr) {
    if (arr.empty()) return;
    size_t left = 0;
    size_t right = arr.size() - 1;
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}
