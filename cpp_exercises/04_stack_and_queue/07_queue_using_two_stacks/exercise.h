#pragma once
#include <stack>
#include <stdexcept>
#include <cstddef>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 07_queue_using_two_stacks
//    OR:
//    .\run_tests.bat 07_queue_using_two_stacks
// ============================================================================

// EXERCISE 4.7: Queue Using Two Stacks
// CADT DSA Week 4 & LeetCode 232
//
// TASK:
// Implement a FIFO queue using ONLY two standard stacks:
// - `in_stack_`: where we push incoming elements during enqueue()
// - `out_stack_`: where we pop/peek elements during dequeue() and front()
//
// When out_stack_ is empty and someone calls front() or dequeue():
// Pop all elements from in_stack_ one by one and push them to out_stack_!
// This reverses the order so LIFO + LIFO = FIFO!
//
// Amortized Time Complexity: O(1) for enqueue and dequeue!

class QueueTwoStacks {
public:
    void enqueue(int value) {
        // TODO: push to in_stack_
        (void)value;
    }

    void dequeue() {
        // TODO: guard empty! If empty(), throw runtime_error("Queue is empty").
        // Otherwise shift elements from in_stack_ to out_stack_ if out_stack_ is empty,
        // then pop from out_stack_.
        if (empty()) throw runtime_error("Queue is empty");
    }

    int front() {
        // TODO: guard empty! If empty(), throw runtime_error("Queue is empty").
        // Otherwise shift elements if needed, then return out_stack_.top().
        if (empty()) throw runtime_error("Queue is empty");
        return 0;
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
