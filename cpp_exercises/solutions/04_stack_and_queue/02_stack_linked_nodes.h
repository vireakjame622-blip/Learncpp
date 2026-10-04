#pragma once
#include <stdexcept>
#include <cstddef>

using namespace std;

// SOLUTION: Node-Based Stack
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
        StackNode* newNode = new StackNode(val, top_);
        top_ = newNode;
        size_++;
    }

    void pop() {
        if (empty()) {
            throw runtime_error("Stack is empty");
        }
        StackNode* temp = top_;
        top_ = top_->next;
        delete temp;
        size_--;
    }

    int top() const {
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
