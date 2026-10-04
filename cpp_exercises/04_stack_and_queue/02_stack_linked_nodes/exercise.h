#pragma once
#include <stdexcept>
#include <cstddef>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 02_stack_linked_nodes
//    OR:
//    .\run_tests.bat 02_stack_linked_nodes
// ============================================================================

// EXERCISE 4.2: Node-Based Stack
// CADT DSA Week 4 - Slide 7 & Slide 13 Lab Exercise
//
// TASK:
// Build a Stack class from scratch using linked nodes with private data.
// Do NOT use vector or deque!
//
// Key Concepts:
// - private Node* top_
// - O(1) push: Allocate new node, node->next = top_, top_ = node
// - O(1) pop: Guard empty case! Save old top, top_ = top_->next, delete old top
// - O(1) top/peek: Guard empty case! Return top_->data
// - Destructor: Deallocate remaining nodes

struct StackNode {
    int data;
    StackNode* next;
    StackNode(int val, StackNode* n = nullptr) : data(val), next(n) {}
};

class NodeStack {
public:
    NodeStack() : top_(nullptr), size_(0) {}

    ~NodeStack() {
        clear();
    }

    void clear() {
        while (top_ != nullptr) {
            StackNode* temp = top_;
            top_ = top_->next;
            delete temp;
        }
        size_ = 0;
    }

    void push(int val) {
        // TODO: allocate new node at front (O(1)), update top_ and size_
        (void)val;
    }

    void pop() {
        // TODO: Guard empty case! Throw runtime_error("Stack is empty") if empty.
        // Otherwise advance top_, delete old node, decrement size_.
        if (empty()) {
            throw runtime_error("Stack is empty");
        }
    }

    int top() const {
        // TODO: Guard empty case! Throw runtime_error("Stack is empty") if empty.
        // Otherwise return top_->data.
        if (empty()) {
            throw runtime_error("Stack is empty");
        }
        return top_->data;
    }

    bool empty() const {
        return top_ == nullptr;
    }

    size_t size() const {
        return size_;
    }

private:
    StackNode* top_;
    size_t size_;
};
