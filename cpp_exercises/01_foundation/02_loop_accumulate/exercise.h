#pragma once
#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 02_loop_accumulate
//    OR:
//    .\run_tests.bat 02_loop_accumulate
// ============================================================================

// EXERCISE 1.2: Loops, Accumulation & Math Functions
// CADT Lab Session 01 - Exercise 5
//
// TASKS:
// 1. sumRange(int a, int b):
//    - Returns the sum of all integers from a to b inclusive.
//    - Note: If a > b, swap them or loop from b to a so it works both ways!
//    - Example: sumRange(1, 5) -> 1+2+3+4+5 = 15
//
// 2. countDigits(long long n):
//    - Returns the count of decimal digits in number n.
//    - Must handle 0 (which has 1 digit!) and negative numbers (e.g. -42 has 2 digits).
//
// 3. factorial(int n):
//    - Returns n! = 1 * 2 * ... * n.
//    - factorial(0) = 1.
//    - If n < 0, throw invalid_argument("Negative factorial undefined").
//
// 4. generateMultiplicationTable(int n, int upTo):
//    - Returns a vector<int> containing {n*1, n*2, ..., n*upTo}.
//    - If upTo <= 0, return an empty vector.

inline long long sumRange(int a, int b) {
    // TODO: implement
    (void)a; (void)b;
    return 0;
}

inline int countDigits(long long n) {
    // TODO: implement
    (void)n;
    return 0;
}

inline long long factorial(int n) {
    // TODO: implement (throw on n < 0)
    (void)n;
    return 0;
}

inline vector<int> generateMultiplicationTable(int n, int upTo = 10) {
    // TODO: implement
    (void)n; (void)upTo;
    return {};
}
