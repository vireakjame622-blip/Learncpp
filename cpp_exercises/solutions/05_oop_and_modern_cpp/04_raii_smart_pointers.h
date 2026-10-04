#pragma once
#include <utility>

using namespace std;

// Verified Solution for Exercise 5.4: RAII UniquePointer<T>
template <typename T>
class UniquePointer {
public:
    explicit UniquePointer(T* ptr = nullptr) : ptr_(ptr) {}

    ~UniquePointer() {
        delete ptr_;
    }

    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

    UniquePointer(UniquePointer&& other) noexcept : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }

    UniquePointer& operator=(UniquePointer&& other) noexcept {
        if (this != &other) {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    T& operator*() const { return *ptr_; }
    T* operator->() const { return ptr_; }

    T* get() const { return ptr_; }

    T* release() {
        T* temp = ptr_;
        ptr_ = nullptr;
        return temp;
    }

    void reset(T* newPtr = nullptr) {
        if (ptr_ != newPtr) {
            delete ptr_;
            ptr_ = newPtr;
        }
    }

    explicit operator bool() const {
        return ptr_ != nullptr;
    }

private:
    T* ptr_;
};
