#pragma once
#include <vector>
#include <stdexcept>
#include <cstddef>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 01_stack_vector
//    OR:
//    .\run_tests.bat 01_stack_vector
// ============================================================================

// EXERCISE 4.1: Generic Stack (Vector-backed)
// CADT DSA Week 4 & cpp-stack-queue.html
//
// TASK:
// Implement a generic Stack<T> backed by vector<T>.
//
// Required Methods:
// - push(val): Add val to top of stack
// - pop():     Remove top element (throw runtime_error if empty)
// - top():     Return reference to top element (throw runtime_error if empty)
// - empty():   Return true if empty
// - size():    Return number of elements

template <typename T>
class Stack {
public:
    void push(const T& value) {
        // TODO: implement
        (void)value;
    }

    void pop() {
        // TODO: implement (throw runtime_error if empty)
    }

    T& top() {
        // TODO: implement (throw runtime_error if empty)
        if (empty()) throw runtime_error("Stack is empty");
        return data_.back();
    }

    const T& top() const {
        if (empty()) throw runtime_error("Stack is empty");
        return data_.back();
    }

    bool empty() const {
        // TODO: implement
        return data_.empty();
    }

    size_t size() const {
        // TODO: implement
        return data_.size();
    }

private:
    vector<T> data_;
};
