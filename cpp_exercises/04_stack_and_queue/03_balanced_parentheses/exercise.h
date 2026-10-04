#pragma once
#include <string>
#include <stack>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 03_balanced_parentheses
//    OR:
//    .\run_tests.bat 03_balanced_parentheses
// ============================================================================

// EXERCISE 4.3: Balanced Parentheses Check
// CADT DSA Week 4 Slide 6 (Stack Applications)
//
// TASK:
// Implement isBalanced(const string& s)
// Check if the parentheses in the string are properly balanced.
// Matching pairs are: '(', ')', '[', ']', '{', '}'.
// Any characters other than brackets should be ignored!
//
// Examples:
// - "" -> true (empty string is balanced)
// - "()" -> true
// - "()[]{}" -> true
// - "(]" -> false
// - "([)]" -> false
// - "{[]}" -> true
// - "int main() { int arr[5]; }" -> true

inline bool isBalanced(const string& s) {
    // TODO: Use stack<char> to track opening brackets
    (void)s;
    return false;
}
