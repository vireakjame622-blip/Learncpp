#pragma once
#include <vector>
#include <stdexcept>
#include <cstddef>

using namespace std;

// SOLUTION: Generic Stack (Vector-backed)
template <typename T>
class Stack {
public:
    void push(const T& value) {
        data_.push_back(value);
    }

    void pop() {
        if (empty()) {
            throw runtime_error("Stack is empty");
        }
        data_.pop_back();
    }

    T& top() {
        if (empty()) {
            throw runtime_error("Stack is empty");
        }
        return data_.back();
    }

    const T& top() const {
        if (empty()) {
            throw runtime_error("Stack is empty");
        }
        return data_.back();
    }

    bool empty() const {
        return data_.empty();
    }

    size_t size() const {
        return data_.size();
    }

private:
    vector<T> data_;
};
