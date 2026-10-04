#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <stdexcept>

using namespace std;

int main() {
    TEST_SUITE("02_stack_linked_nodes (Week 4 Lab: Custom Node Stack & O(1) Ops)");

    NodeStack ns;

    // Condition 1: Initial state & guard empty case
    TEST_CONDITION(ns.empty(), "New NodeStack is empty", "top_ is nullptr");
    TEST_EQUAL(ns.size(), 0ULL, "Initial size is 0", "size_ is 0");
    TEST_THROWS(ns.pop(), runtime_error, "Guard empty case: pop() throws runtime_error", "Check empty() before pop");
    TEST_THROWS(ns.top(), runtime_error, "Guard empty case: top() throws runtime_error", "Check empty() before top");

    // Condition 2: Push operations
    ns.push(100);
    ns.push(200);
    ns.push(300);
    TEST_CONDITION(!ns.empty(), "NodeStack is not empty after pushes", "empty() is false");
    TEST_EQUAL(ns.size(), 3ULL, "NodeStack size is 3", "Check size increment");
    if (!ns.empty()) {
        TEST_EQUAL(ns.top(), 300, "top() returns 300 (most recently pushed)", "Check top_->data");
    } else {
        TEST_CONDITION(false, "top() returns 300", "push() not yet implemented");
    }

    // Condition 3: Pop operations
    if (!ns.empty()) {
        ns.pop();
        TEST_EQUAL(ns.size(), 2ULL, "Size is 2 after 1 pop", "Check size decrement");
        TEST_EQUAL(ns.top(), 200, "top() is now 200", "Check next node");
    } else {
        TEST_CONDITION(false, "pop() and top() check", "push() not yet implemented");
    }

    // Condition 4: Emptying stack and re-checking guard
    while (!ns.empty()) {
        ns.pop();
    }
    TEST_CONDITION(ns.empty(), "Stack is empty after popping all elements", "All nodes deleted");
    TEST_THROWS(ns.pop(), runtime_error, "Popping re-emptied stack throws runtime_error", "Guard empty");

    TEST_REPORT();
}
