#pragma once
#include <string>
#include <vector>
#include <stack>
#include <cctype>
#include <stdexcept>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 06_expression_evaluator
//    OR:
//    .\run_tests.bat 06_expression_evaluator
// ============================================================================

// EXERCISE 6.6: Infix Arithmetic Expression Evaluator (Shunting-Yard)
// CADT Advanced Algorithm & C++ • Stack Applications
//
// TASKS:
// Parse and evaluate arithmetic expressions with operator precedence and parentheses:
// 1. evaluateInfix(const string& expression):
//    - Evaluates integer expressions containing '+', '-', '*', '/', '(', ')' and multidigit integers.
//    - Respects operator precedence: '*' and '/' evaluated before '+' and '-'.
//    - Respects parenthesis grouping: sub-expressions in '()' evaluated first.
//    - Ignores whitespace characters.
//    - Throws runtime_error("Division by zero") if denominator is 0.
//    - Throws invalid_argument on mismatched parentheses or syntax errors.

inline int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

inline int applyOp(int a, int b, char op) {
    // TODO: Perform arithmetic operation. Throw runtime_error on division by 0.
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw runtime_error("Division by zero");
            return a / b;
    }
    return 0;
}

inline int evaluateInfix(const string& tokens) {
    // TODO: Implement two-stack evaluation (values stack and operator stack)
    // 1. If digit: parse full multidigit number and push to values stack
    // 2. If '(': push to ops stack
    // 3. If ')': pop and apply operators until matching '(' is found
    // 4. If operator: while ops stack top has >= precedence, pop and apply. Then push operator.
    // 5. At end: apply remaining operators. Return values.top().
    (void)tokens;
    return 0;
}
