#pragma once
#include <stack>
#include <stdexcept>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 04_min_stack
//    OR:
//    .\run_tests.bat 04_min_stack
// ============================================================================

// EXERCISE 4.4: Min Stack (O(1) Minimum Element)
// CADT DSA Week 4 & cpp-stack-queue.html
//
// TASK:
// Implement a MinStack class that supports push, pop, top, and retrieving
// the minimum element in CONSTANT TIME O(1)!
//
// Methods:
// - push(val): Push val onto the stack
// - pop(): Remove top element (throw runtime_error if empty)
// - top(): Return top element (throw runtime_error if empty)
// - getMin(): Return minimum element in the entire stack in O(1) time
//             (throw runtime_error if empty)
//
// Hint: Maintain an auxiliary stack `min_stack_` that tracks the minimum
// at each level, or store pairs `(value, current_min)`!

class MinStack {
public:
    void push(int value) {
        // TODO: implement
        (void)value;
    }

    void pop() {
        // TODO: implement (throw if empty)
    }

    int top() const {
        // TODO: implement (throw if empty)
        if (empty()) throw runtime_error("Stack is empty");
        return 0;
    }

    int getMin() const {
        // TODO: implement in O(1) time (throw if empty)
        if (empty()) throw runtime_error("Stack is empty");
        return 0;
    }

    bool empty() const {
        return main_stack_.empty();
    }

    size_t size() const {
        return main_stack_.size();
    }

private:
    stack<int> main_stack_;
    stack<int> min_stack_;
};
