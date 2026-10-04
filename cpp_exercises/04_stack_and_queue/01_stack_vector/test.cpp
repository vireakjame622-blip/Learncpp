#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <string>
#include <stdexcept>

using namespace std;

int main() {
    TEST_SUITE("01_stack_vector (LIFO & Vector Operations)");

    Stack<int> s;

    // Condition 1: Initial state & empty exceptions
    TEST_CONDITION(s.empty(), "New stack is empty", "Initial state");
    TEST_EQUAL(s.size(), 0ULL, "Initial size is 0", "Initial size");
    TEST_THROWS(s.pop(), runtime_error, "pop() on empty stack throws runtime_error", "Guard empty pop");
    TEST_THROWS(s.top(), runtime_error, "top() on empty stack throws runtime_error", "Guard empty top");

    // Condition 2: push & LIFO order
    s.push(10);
    s.push(20);
    s.push(30);
    TEST_CONDITION(!s.empty(), "Stack is not empty after pushes", "Check empty()");
    TEST_EQUAL(s.size(), 3ULL, "Stack size is 3", "Check size()");
    TEST_EQUAL(s.top(), 30, "top() is 30 (LIFO: last pushed is on top)", "Check top()");

    // Condition 3: pop
    s.pop();
    TEST_EQUAL(s.size(), 2ULL, "Stack size is 2 after 1 pop", "Check size()");
    TEST_EQUAL(s.top(), 20, "top() is now 20", "Check next top");

    // Condition 4: Pop until empty
    s.pop();
    s.pop();
    TEST_CONDITION(s.empty(), "Stack is empty after popping all elements", "Check empty()");
    TEST_THROWS(s.pop(), runtime_error, "pop() on re-emptied stack throws runtime_error", "Guard empty pop");

    // Condition 5: Stack of strings (Generic Template Verification)
    Stack<string> strStack;
    strStack.push("CADT");
    strStack.push("C++");
    TEST_EQUAL(strStack.top(), string("C++"), "Template works with string", "Stack<T> generic check");

    TEST_REPORT();
}
