#pragma once
#include <stack>
#include <stdexcept>
#include <cstddef>

using namespace std;

// SOLUTION: Queue Using Two Stacks
class QueueTwoStacks {
public:
    void enqueue(int value) {
        in_stack_.push(value);
    }

    void dequeue() {
        if (empty()) {
            throw runtime_error("Queue is empty");
        }
        shiftStacks();
        out_stack_.pop();
    }

    int front() {
        if (empty()) {
            throw runtime_error("Queue is empty");
        }
        shiftStacks();
        return out_stack_.top();
    }

    bool empty() const {
        return in_stack_.empty() && out_stack_.empty();
    }

    size_t size() const {
        return in_stack_.size() + out_stack_.size();
    }

private:
    void shiftStacks() {
        if (out_stack_.empty()) {
            while (!in_stack_.empty()) {
                out_stack_.push(in_stack_.top());
                in_stack_.pop();
            }
        }
    }

    stack<int> in_stack_;
    stack<int> out_stack_;
};
