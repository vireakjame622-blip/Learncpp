#pragma once
#include <stack>
#include <stdexcept>
#include <algorithm>

using namespace std;

// SOLUTION: Min Stack in O(1) Time
class MinStack {
public:
    void push(int value) {
        main_stack_.push(value);
        if (min_stack_.empty() || value <= min_stack_.top()) {
            min_stack_.push(value);
        }
    }

    void pop() {
        if (empty()) {
            throw runtime_error("Stack is empty");
        }
        if (main_stack_.top() == min_stack_.top()) {
            min_stack_.pop();
        }
        main_stack_.pop();
    }

    int top() const {
        if (empty()) {
            throw runtime_error("Stack is empty");
        }
        return main_stack_.top();
    }

    int getMin() const {
        if (empty()) {
            throw runtime_error("Stack is empty");
        }
        return min_stack_.top();
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
