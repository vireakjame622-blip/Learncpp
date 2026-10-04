#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <string>

using namespace std;

int main() {
    TEST_SUITE("03_balanced_parentheses (Stack LIFO Bracket Matching)");

    // Condition 1: Empty and single pair
    TEST_CONDITION(isBalanced("") == true, "Empty string is balanced", "Empty is balanced");
    TEST_CONDITION(isBalanced("()") == true, "'()' is balanced", "Simple round brackets");
    TEST_CONDITION(isBalanced("[]") == true, "'[]' is balanced", "Simple square brackets");
    TEST_CONDITION(isBalanced("{}") == true, "'{}' is balanced", "Simple curly braces");

    // Condition 2: Multiple matching sequential & nested
    TEST_CONDITION(isBalanced("()[]{}") == true, "'()[]{}' is balanced", "Sequential bracket pairs");
    TEST_CONDITION(isBalanced("{[()]}") == true, "'{[()]}' is balanced", "Nested bracket pairs");
    TEST_CONDITION(isBalanced("((({{{[[[]]]}}})))") == true, "Deeply nested brackets are balanced", "Deep nesting");

    // Condition 3: Mismatches and interleaving
    TEST_CONDITION(isBalanced("(]") == false, "'(]' is NOT balanced", "Type mismatch");
    TEST_CONDITION(isBalanced("([)]") == false, "'([)]' is NOT balanced", "Interleaved brackets");
    TEST_CONDITION(isBalanced("]") == false, "Single closing bracket ']' is NOT balanced", "Empty stack on closing");
    TEST_CONDITION(isBalanced("(") == false, "Unclosed opening bracket '(' is NOT balanced", "Non-empty stack at end");

    // Condition 4: Brackets inside realistic code text
    string codeSnippet = "if (a[i] == (b + c)) { return fn(arr[0]); }";
    TEST_CONDITION(isBalanced(codeSnippet) == true, "Real C++ code snippet is balanced", "Ignore non-bracket characters");

    TEST_REPORT();
}
