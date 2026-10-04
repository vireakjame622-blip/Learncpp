# Learn C++ & DSA Practice Suite

A structured repository containing C++ exercises, data structure implementations, and lab session assignments.

---

## 📁 Repository Structure

### 1. [`cpp_exercises/`](./cpp_exercises/)
Comprehensive hands-on exercises with automated unit tests across core C++ and Data Structures topics:
- **01 Foundation**: Conditional ladders, loop accumulation, array algorithms, palindrome checks, pointers & references.
- **02 Sorting**: Bubble sort, selection sort, insertion sort, merge sort, quicksort with benchmarking.
- **03 Linked Lists**: Singly linked list, doubly linked list, cycle detection, list reversal, merge sorted lists.
- **04 Stack and Queue**: Array-backed stack, linked list stack, queue implementations, min stack, balanced parentheses, sliding window maximum.
- **05 Trees**: Binary Search Tree (BST) insertion, traversal, search, height, LCA, validation.

### 2. [`LABSESION/`](./LABSESION/)
Practical laboratory sessions and weekly exercises for C++ programming fundamentals and problem solving.

---

## 🚀 Getting Started

### Prerequisites
- A C++17 (or newer) compatible compiler (e.g., `g++` / GCC, Clang, or MSVC)
- CMake or build scripts included in the exercises

### Running Exercises
Navigate to any exercise directory inside `cpp_exercises/` or `LABSESION/` to compile and run tests.
For example, to run the test suite for an exercise:
```bash
cd cpp_exercises/01_foundation/01_grade_classifier
g++ -std=c++17 -I../../common test.cpp -o test
./test
```
Or run the automated batch test runner scripts:
```powershell
./cpp_exercises/run_tests.ps1
```