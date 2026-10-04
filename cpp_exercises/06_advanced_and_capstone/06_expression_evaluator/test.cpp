#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <stdexcept>

using namespace std;

int main() {
    TEST_SUITE("04_expression_evaluator (Shunting Yard & Stack-Based Arithmetic)");

    // Condition 1: Basic Operations & Precedence
    {
        TEST_EQUAL(evaluateInfix("10 + 20"), 30, "10 + 20 = 30", "Addition");
        TEST_EQUAL(evaluateInfix("50 - 15"), 35, "50 - 15 = 35", "Subtraction");
        TEST_EQUAL(evaluateInfix("6 * 7"), 42, "6 * 7 = 42", "Multiplication");
        TEST_EQUAL(evaluateInfix("100 / 4"), 25, "100 / 4 = 25", "Division");
        TEST_EQUAL(evaluateInfix("2 + 3 * 4"), 14, "2 + 3 * 4 = 14 (* before +)", "Precedence rule");
        TEST_EQUAL(evaluateInfix("20 - 4 / 2"), 18, "20 - 4 / 2 = 18 (/ before -)", "Precedence rule");
    }

    // Condition 2: Parentheses overriding precedence
    {
        TEST_EQUAL(evaluateInfix("(2 + 3) * 4"), 20, "(2 + 3) * 4 = 20", "Parentheses precedence");
        TEST_EQUAL(evaluateInfix("100 / (5 + 15)"), 5, "100 / (5 + 15) = 5", "Parentheses division");
        TEST_EQUAL(evaluateInfix("((2 + 3) * (4 + 1))"), 25, "((2 + 3) * (4 + 1)) = 25", "Nested parentheses");
        TEST_EQUAL(evaluateInfix("3 + 5 * (2 - 8)"), -27, "3 + 5 * (2 - 8) = -27", "Negative result in paren");
    }

    // Condition 3: Exceptions (Division by Zero & Mismatched Brackets)
    {
        TEST_THROWS(evaluateInfix("10 / 0"), runtime_error, "10 / 0 throws runtime_error", "Division by zero guard");
        TEST_THROWS(evaluateInfix("5 + 2 / (3 - 3)"), runtime_error, "Dynamic zero divisor throws", "Division by zero guard");
        TEST_THROWS(evaluateInfix("(5 + 2"), invalid_argument, "Unclosed '(' throws invalid_argument", "Mismatched parens");
        TEST_THROWS(evaluateInfix("5 + 2)"), invalid_argument, "Extra ')' throws invalid_argument", "Mismatched parens");
        TEST_THROWS(evaluateInfix("5 + $"), invalid_argument, "Invalid character throws", "Invalid syntax");
    }

    TEST_REPORT();
}
