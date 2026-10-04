#pragma once
#include <cstddef>
#include <stdexcept>
#include <utility>
#include <algorithm>

using namespace std;

// Verified Solution for Exercise 5.5: CustomVector<T>
template <typename T>
class CustomVector {
public:
    CustomVector() : data_(nullptr), size_(0), capacity_(0) {}

    explicit CustomVector(size_t initialCapacity) 
        : data_(nullptr), size_(0), capacity_(initialCapacity) {
        if (capacity_ > 0) {
            data_ = new T[capacity_];
        }
    }

    ~CustomVector() {
        delete[] data_;
    }

    CustomVector(const CustomVector& other) 
        : data_(nullptr), size_(other.size_), capacity_(other.capacity_) {
        if (capacity_ > 0) {
            data_ = new T[capacity_];
            for (size_t i = 0; i < size_; ++i) data_[i] = other.data_[i];
        }
    }

    CustomVector& operator=(const CustomVector& other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = capacity_ > 0 ? new T[capacity_] : nullptr;
            for (size_t i = 0; i < size_; ++i) data_[i] = other.data_[i];
        }
        return *this;
    }

    CustomVector(CustomVector&& other) noexcept 
        : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    CustomVector& operator=(CustomVector&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }

    void push_back(const T& val) {
        if (size_ == capacity_) {
            size_t newCap = (capacity_ == 0) ? 2 : capacity_ * 2;
            reserve(newCap);
        }
        data_[size_++] = val;
    }

    void pop_back() {
        if (size_ == 0) {
            throw underflow_error("Vector is empty");
        }
        size_--;
    }

    void reserve(size_t newCap) {
        if (newCap <= capacity_) return;
        T* newData = new T[newCap];
        for (size_t i = 0; i < size_; ++i) {
            newData[i] = move(data_[i]);
        }
        delete[] data_;
        data_ = newData;
        capacity_ = newCap;
    }

    T& operator[](size_t index) { return data_[index]; }
    const T& operator[](size_t index) const { return data_[index]; }

    T& at(size_t index) {
        if (index >= size_) throw out_of_range("Index out of bounds");
        return data_[index];
    }
    const T& at(size_t index) const {
        if (index >= size_) throw out_of_range("Index out of bounds");
        return data_[index];
    }

    T& front() {
        if (size_ == 0) throw out_of_range("Vector empty");
        return data_[0];
    }
    T& back() {
        if (size_ == 0) throw out_of_range("Vector empty");
        return data_[size_ - 1];
    }

    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }

    void clear() {
        size_ = 0;
    }

private:
    T* data_;
    size_t size_;
    size_t capacity_;
};
