#pragma once
#include <deque>
#include <stdexcept>
#include <cstddef>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 05_queue_basic
//    OR:
//    .\run_tests.bat 05_queue_basic
// ============================================================================

// EXERCISE 4.5: Generic Queue (Deque-backed)
// CADT DSA Week 4 & cpp-stack-queue.html
//
// TASK:
// Implement a generic Queue<T> backed by deque<T>.
// FIFO: First-In, First-Out.
//
// Methods:
// - enqueue(value): Add element to the back/rear of the queue - O(1)
// - dequeue():       Remove front element (throw runtime_error if empty) - O(1)
// - front():         Return reference to front element (throw runtime_error if empty) - O(1)
// - empty():         Return true if empty
// - size():          Return number of elements

template <typename T>
class Queue {
public:
    void enqueue(const T& value) {
        // TODO: implement
        (void)value;
    }

    void dequeue() {
        // TODO: implement (throw runtime_error if empty)
    }

    T& front() {
        // TODO: implement (throw runtime_error if empty)
        if (empty()) throw runtime_error("Queue is empty");
        return data_.front();
    }

    const T& front() const {
        if (empty()) throw runtime_error("Queue is empty");
        return data_.front();
    }

    bool empty() const {
        return data_.empty();
    }

    size_t size() const {
        return data_.size();
    }

private:
    deque<T> data_;
};
