#pragma once
#include <vector>
#include <stdexcept>
#include <utility>

using namespace std;

// Verified Solution for Exercise 6.3: MinHeapPriorityQueue
class MinHeapPriorityQueue {
public:
    MinHeapPriorityQueue() = default;

    void push(int val) {
        heap_.push_back(val);
        heapifyUp(heap_.size() - 1);
    }

    void pop() {
        if (heap_.empty()) {
            throw underflow_error("Priority queue is empty");
        }
        heap_[0] = heap_.back();
        heap_.pop_back();
        if (!heap_.empty()) {
            heapifyDown(0);
        }
    }

    int top() const {
        if (heap_.empty()) {
            throw underflow_error("Priority queue is empty");
        }
        return heap_[0];
    }

    size_t size() const { return heap_.size(); }
    bool empty() const { return heap_.empty(); }

    const vector<int>& getRawBuffer() const { return heap_; }

private:
    vector<int> heap_;

    void heapifyUp(size_t index) {
        while (index > 0) {
            size_t parent = (index - 1) / 2;
            if (heap_[index] < heap_[parent]) {
                swap(heap_[index], heap_[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(size_t index) {
        size_t n = heap_.size();
        while (true) {
            size_t smallest = index;
            size_t left = 2 * index + 1;
            size_t right = 2 * index + 2;

            if (left < n && heap_[left] < heap_[smallest]) {
                smallest = left;
            }
            if (right < n && heap_[right] < heap_[smallest]) {
                smallest = right;
            }

            if (smallest != index) {
                swap(heap_[index], heap_[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }
};
