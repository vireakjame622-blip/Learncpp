#pragma once
#include <stdexcept>
#include <cstddef>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 06_queue_linked_nodes
//    OR:
//    .\run_tests.bat 06_queue_linked_nodes
// ============================================================================

// EXERCISE 4.6: Node-Based Queue (With Rear Pointer & "Rear Bug" Fix)
// CADT DSA Week 4 - Slide 10, 11 & Slide 14 ("Find the rear bug")
//
// TASK:
// Build a FIFO Queue class from scratch using singly linked nodes with
// two pointers: `front_` (where we remove) and `rear_` (where we insert).
//
// Required Methods:
// - enqueue(val): Add val at rear_ in O(1)
// - dequeue(): Remove element from front_ in O(1) (throw if empty)
// - front(): Return value at front_ in O(1) (throw if empty)
// - empty(): Return true if queue is empty
// - size(): Return count of elements
//
// ⚠️ THE FAMOUS CADT "REAR BUG" (Slide 14):
// When dequeuing the VERY LAST remaining element in the queue:
// `front_` becomes nullptr.
// BUT WHAT HAPPENS TO `rear_`?
// If you don't update `rear_ = nullptr;`, `rear_` becomes a DANGLING POINTER
// pointing to memory you just deleted! When you next call enqueue(), it crashes!
// Always check: `if (front_ == nullptr) rear_ = nullptr;`!

struct QueueNode {
    int data;
    QueueNode* next;
    QueueNode(int val) : data(val), next(nullptr) {}
};

class NodeQueue {
public:
    NodeQueue() : front_(nullptr), rear_(nullptr), size_(0) {}

    ~NodeQueue() {
        clear();
    }

    void clear() {
        while (front_ != nullptr) {
            QueueNode* temp = front_;
            front_ = front_->next;
            delete temp;
        }
        rear_ = nullptr;
        size_ = 0;
    }

    void enqueue(int val) {
        // TODO:
        // 1. Create new QueueNode(val).
        // 2. If empty(), front_ = rear_ = new node.
        // 3. Otherwise, rear_->next = new node, rear_ = new node.
        // 4. Increment size_.
        (void)val;
    }

    void dequeue() {
        // TODO:
        // 1. Guard empty! Throw runtime_error("Queue is empty") if empty.
        // 2. Save old front: QueueNode* temp = front_;
        // 3. Advance front_: front_ = front_->next;
        // 4. Delete temp, decrement size_.
        // 5. ⚠️ FIX THE REAR BUG:
        //    if (front_ == nullptr) { rear_ = nullptr; }
        if (empty()) throw runtime_error("Queue is empty");
    }

    int front() const {
        if (empty()) throw runtime_error("Queue is empty");
        return front_->data;
    }

    bool empty() const {
        return front_ == nullptr;
    }

    size_t size() const {
        return size_;
    }

    // Helper to check for the dangling rear bug in tests
    const QueueNode* getRear() const { return rear_; }

private:
    QueueNode* front_;
    QueueNode* rear_;
    size_t size_;
};
