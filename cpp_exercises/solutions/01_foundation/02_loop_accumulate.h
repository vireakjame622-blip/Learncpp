#pragma once
#include <vector>
#include <stdexcept>
#include <cmath>
#include <algorithm>

using namespace std;

// SOLUTION: Loops, Accumulation & Math
inline long long sumRange(int a, int b) {
    if (a > b) swap(a, b);
    long long total = 0;
    for (int i = a; i <= b; ++i) {
        total += i;
    }
    return total;
}

inline int countDigits(long long n) {
    if (n == 0) return 1;
    // Use positive magnitude
    unsigned long long val = (n < 0) ? -static_cast<unsigned long long>(n) : static_cast<unsigned long long>(n);
    int count = 0;
    while (val > 0) {
        val /= 10;
        count++;
    }
    return count;
}

inline long long factorial(int n) {
    if (n < 0) {
        throw invalid_argument("Factorial is undefined for negative numbers");
    }
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

inline vector<int> generateMultiplicationTable(int n, int upTo = 10) {
    vector<int> table;
    if (upTo <= 0) return table;
    table.reserve(upTo);
    for (int i = 1; i <= upTo; ++i) {
        table.push_back(n * i);
    }
    return table;
}
