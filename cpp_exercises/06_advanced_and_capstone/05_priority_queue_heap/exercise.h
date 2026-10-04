#pragma once
#include <vector>
#include <stdexcept>
#include <utility>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 05_priority_queue_heap
//    OR:
//    .\run_tests.bat 05_priority_queue_heap
// ============================================================================

// EXERCISE 6.5: Priority Queue (Binary Min-Heap)
// CADT Advanced Algorithm & C++ • Week 5 Heaps
//
// TASKS:
// Build an array-backed Binary Min-Heap Priority Queue:
// 1. push(int val): Appends val to array and bubbles up (heapifyUp) in O(log n).
// 2. pop(): Replaces root with last element, removes last, and bubbles down (heapifyDown) in O(log n).
//    - Throws underflow_error if empty.
// 3. top() const: Returns minimum element at root in O(1).
//    - Throws underflow_error if empty.
// 4. size() and empty() helpers.

class MinHeapPriorityQueue {
public:
    MinHeapPriorityQueue() = default;

    size_t size() const { return heap_.size(); }
    bool empty() const { return heap_.empty(); }

    void push(int val) {
        // TODO: Append val to heap_, then call heapifyUp(heap_.size() - 1)
        (void)val;
    }

    void pop() {
        // TODO: If empty, throw underflow_error("Priority queue is empty").
        // Replace root heap_[0] with heap_.back(), pop_back(), call heapifyDown(0)
    }

    int top() const {
        // TODO: If empty, throw underflow_error. Otherwise return root heap_[0].
        throw underflow_error("Priority queue is empty");
    }

    const vector<int>& getRawBuffer() const { return heap_; }

private:
    vector<int> heap_;

    void heapifyUp(size_t index) {
        // TODO: Bubble up until heap property (heap_[index] >= heap_[parent]) is satisfied
        // Parent index is (index - 1) / 2
        (void)index;
    }

    void heapifyDown(size_t index) {
        // TODO: Bubble down with smallest child among left (2*i+1) and right (2*i+2)
        (void)index;
    }
};
