#pragma once
#include <cstddef>
#include <stdexcept>
#include <utility>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 05_templates_generic_vector
//    OR:
//    .\run_tests.bat 05_templates_generic_vector
// ============================================================================

// EXERCISE 5.5: Templates & Dynamic Amortization (CustomVector<T>)
// CADT Advanced Algorithm & C++ • Rule of 5 & Generic Data Types
//
// TASKS:
// Build a generic dynamic array template CustomVector<T>:
// 1. Dynamic buffer management with size_ and capacity_.
// 2. Destructor: delete[] data_.
// 3. Rule of 5: Deep Copy constructor/assignment, Move constructor/assignment.
// 4. push_back(const T& val): Amortized doubling when size_ == capacity_.
// 5. pop_back(): Decrements size_; throws underflow_error if empty.
// 6. at(size_t index): Bounds-checked access, throws out_of_range.
// 7. front() and back(): Access endpoints, throw underflow_error if empty.

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
        // TODO: Free dynamic buffer
        delete[] data_;
    }

    // TODO: Implement Rule of 5 (Copy Constructor & Assignment)
    CustomVector(const CustomVector& other) : data_(nullptr), size_(0), capacity_(0) {
        (void)other;
    }

    CustomVector& operator=(const CustomVector& other) {
        (void)other;
        return *this;
    }

    // TODO: Implement Move Constructor & Assignment
    CustomVector(CustomVector&& other) noexcept : data_(nullptr), size_(0), capacity_(0) {
        (void)other;
    }

    CustomVector& operator=(CustomVector&& other) noexcept {
        (void)other;
        return *this;
    }

    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }

    void reserve(size_t newCap) {
        // TODO: If newCap > capacity_, allocate new buffer, copy elements, free old buffer
        (void)newCap;
    }

    void push_back(const T& val) {
        // TODO: If size_ == capacity_, reserve(capacity_ == 0 ? 1 : capacity_ * 2)
        // Store val at data_[size_++]
        (void)val;
    }

    void pop_back() {
        // TODO: If empty, throw underflow_error. Otherwise decrement size_.
    }

    T& operator[](size_t index) { return data_[index]; }
    const T& operator[](size_t index) const { return data_[index]; }

    T& at(size_t index) {
        // TODO: If index >= size_, throw out_of_range.
        (void)index;
        throw out_of_range("Index out of bounds");
    }

    const T& at(size_t index) const {
        (void)index;
        throw out_of_range("Index out of bounds");
    }

    T& front() {
        if (empty()) throw underflow_error("Vector is empty");
        return data_[0];
    }

    T& back() {
        if (empty()) throw underflow_error("Vector is empty");
        return data_[size_ - 1];
    }

private:
    T* data_{nullptr};
    size_t size_{0};
    size_t capacity_{0};
};
