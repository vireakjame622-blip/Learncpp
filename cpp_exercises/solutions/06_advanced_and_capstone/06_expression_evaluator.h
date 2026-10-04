#pragma once
#include <string>
#include <vector>
#include <stack>
#include <cctype>
#include <stdexcept>

using namespace std;

// Verified Solution for Exercise 6.4: Infix Arithmetic Expression Evaluator
inline int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

inline int applyOp(int a, int b, char op) {
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
    stack<int> values;
    stack<char> ops;

    for (size_t i = 0; i < tokens.length(); ++i) {
        if (isspace(static_cast<unsigned char>(tokens[i]))) continue;

        if (isdigit(static_cast<unsigned char>(tokens[i]))) {
            int val = 0;
            while (i < tokens.length() && isdigit(static_cast<unsigned char>(tokens[i]))) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }
            values.push(val);
            i--;
        }
        else if (tokens[i] == '(') {
            ops.push(tokens[i]);
        }
        else if (tokens[i] == ')') {
            bool matched = false;
            while (!ops.empty()) {
                if (ops.top() == '(') {
                    ops.pop();
                    matched = true;
                    break;
                }
                if (values.size() < 2) throw invalid_argument("Malformed expression");
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            if (!matched) throw invalid_argument("Mismatched parentheses");
        }
        else if (tokens[i] == '+' || tokens[i] == '-' || tokens[i] == '*' || tokens[i] == '/') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) {
                if (values.size() < 2) throw invalid_argument("Malformed expression");
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(tokens[i]);
        } else {
            throw invalid_argument("Invalid character in expression");
        }
    }

    while (!ops.empty()) {
        if (ops.top() == '(') throw invalid_argument("Mismatched parentheses");
        if (values.size() < 2) throw invalid_argument("Malformed expression");
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    if (values.empty()) return 0;
    return values.top();
}
