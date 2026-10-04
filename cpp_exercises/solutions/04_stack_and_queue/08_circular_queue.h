#pragma once
#include <vector>
#include <stdexcept>
#include <cstddef>

using namespace std;

// SOLUTION: Fixed-Capacity Circular Queue (Ring Buffer)
class CircularQueue {
public:
    explicit CircularQueue(size_t capacity)
        : buffer_(capacity), capacity_(capacity), head_(0), tail_(0), size_(0) {}

    void enqueue(int value) {
        if (full()) {
            throw runtime_error("Queue is full");
        }
        buffer_[tail_] = value;
        tail_ = (tail_ + 1) % capacity_;
        size_++;
    }

    void dequeue() {
        if (empty()) {
            throw runtime_error("Queue is empty");
        }
        head_ = (head_ + 1) % capacity_;
        size_--;
    }

    int front() const {
        if (empty()) {
            throw runtime_error("Queue is empty");
        }
        return buffer_[head_];
    }

    int rear() const {
        if (empty()) {
            throw runtime_error("Queue is empty");
        }
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
