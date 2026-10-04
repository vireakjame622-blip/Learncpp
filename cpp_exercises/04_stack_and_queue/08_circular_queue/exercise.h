#pragma once
#include <vector>
#include <stdexcept>
#include <cstddef>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 08_circular_queue
//    OR:
//    .\run_tests.bat 08_circular_queue
// ============================================================================

// EXERCISE 4.8: Fixed-Capacity Circular Queue (Ring Buffer)
// CADT DSA Week 4 & LeetCode 622
//
// TASK:
// Implement a fixed-capacity circular queue using an array/vector.
// Avoid the O(n) element shifting penalty of a standard linear array queue
// by using modulo arithmetic: `(index + 1) % capacity_`!
//
// Methods:
// - enqueue(val): Add val at rear. If full, throw runtime_error("Queue is full")
// - dequeue(): Remove front element. If empty, throw runtime_error("Queue is empty")
// - front(): Return front element (throw if empty)
// - rear(): Return rear element (throw if empty)
// - empty(): True if size_ == 0
// - full(): True if size_ == capacity_
// - size(): Current count of elements
// - capacity(): Maximum capacity

class CircularQueue {
public:
    explicit CircularQueue(size_t capacity)
        : buffer_(capacity), capacity_(capacity), head_(0), tail_(0), size_(0) {}

    void enqueue(int value) {
        // TODO:
        // If full(), throw runtime_error("Queue is full").
        // Otherwise, place value at buffer_[tail_],
        // advance tail_ = (tail_ + 1) % capacity_,
        // increment size_.
        if (full()) throw runtime_error("Queue is full");
        (void)value;
    }

    void dequeue() {
        // TODO:
        // If empty(), throw runtime_error("Queue is empty").
        // Otherwise, advance head_ = (head_ + 1) % capacity_,
        // decrement size_.
        if (empty()) throw runtime_error("Queue is empty");
    }

    int front() const {
        if (empty()) throw runtime_error("Queue is empty");
        return buffer_[head_];
    }

    int rear() const {
        if (empty()) throw runtime_error("Queue is empty");
        size_t lastIdx = (tail_ == 0) ? (capacity_ - 1) : (tail_ - 1);
        return buffer_[lastIdx];
    }

    bool empty() const {
        return size_ == 0;
    }

    bool full() const {
        return size_ == capacity_;
    }

    size_t size() const {
        return size_;
    }

    size_t capacity() const {
        return capacity_;
    }

private:
    vector<int> buffer_;
    size_t capacity_;
    size_t head_;
    size_t tail_;
    size_t size_;
};
