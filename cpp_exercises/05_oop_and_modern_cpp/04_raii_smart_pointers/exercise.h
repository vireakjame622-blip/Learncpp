#pragma once
#include <utility>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 04_raii_smart_pointers
//    OR:
//    .\run_tests.bat 04_raii_smart_pointers
// ============================================================================

// EXERCISE 5.4: RAII & Smart Pointers (UniquePointer<T>)
// CADT Advanced Algorithm & C++ • Modern C++
//
// TASKS:
// Build a lightweight exclusive-ownership smart pointer UniquePointer<T>:
// 1. Destructor: Safely delete heap-allocated resource (prevent leaks).
// 2. Disable Copy: Delete copy constructor and copy assignment operator.
// 3. Move Semantics: Implement move constructor and move assignment operator.
//    - Transfer resource pointer from source and set source to nullptr.
// 4. Pointer Operators: operator*, operator->, operator bool().
// 5. Lifecycle Management:
//    - T* release(): Relinquishes ownership and returns raw pointer.
//    - void reset(T* newPtr): Deletes owned object and re-assigns to newPtr.

template <typename T>
class UniquePointer {
public:
    explicit UniquePointer(T* ptr = nullptr) : ptr_(ptr) {}

    ~UniquePointer() {
        // TODO: Delete managed resource ptr_ to enforce RAII
    }

    // TODO: Disable copy constructor and copy assignment operator
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

    // TODO: Implement move constructor (UniquePointer&& other)
    UniquePointer(UniquePointer&& other) noexcept : ptr_(other.ptr_) {
        // other.ptr_ = nullptr;
    }

    // TODO: Implement move assignment operator (UniquePointer&& other)
    UniquePointer& operator=(UniquePointer&& other) noexcept {
        (void)other;
        return *this;
    }

    T& operator*() const { return *ptr_; }
    T* operator->() const { return ptr_; }

    T* get() const { return ptr_; }

    T* release() {
        // TODO: Relinquish ownership, set ptr_ to nullptr, return former pointer
        return nullptr;
    }

    void reset(T* newPtr = nullptr) {
        // TODO: Delete current resource and replace with newPtr
        (void)newPtr;
    }

    explicit operator bool() const {
        return ptr_ != nullptr;
    }

private:
    T* ptr_{nullptr};
};
