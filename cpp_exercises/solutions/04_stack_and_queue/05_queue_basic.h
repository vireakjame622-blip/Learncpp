#pragma once
#include <deque>
#include <stdexcept>
#include <cstddef>

using namespace std;

// SOLUTION: Generic Queue (Deque-backed)
template <typename T>
class Queue {
public:
    void enqueue(const T& value) {
        data_.push_back(value);
    }

    void dequeue() {
        if (empty()) {
            throw runtime_error("Queue is empty");
        }
        data_.pop_front();
    }

    T& front() {
        if (empty()) {
            throw runtime_error("Queue is empty");
        }
        return data_.front();
    }

    const T& front() const {
        if (empty()) {
            throw runtime_error("Queue is empty");
        }
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
