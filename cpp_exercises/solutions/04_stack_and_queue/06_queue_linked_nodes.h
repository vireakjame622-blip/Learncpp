#pragma once
#include <stdexcept>
#include <cstddef>

using namespace std;

// SOLUTION: Node-Based Queue (With Rear Bug Fix)
struct QueueNode {
    int data;
    QueueNode* next;
    QueueNode(int val) : data(val), next(nullptr) {}
};

class NodeQueue {
public:
    NodeQueue() : front_(nullptr), rear_(nullptr), size_(0) {}

    ~NodeQueue() {
        clear();
    }

    void clear() {
        while (front_ != nullptr) {
            QueueNode* temp = front_;
            front_ = front_->next;
            delete temp;
        }
        rear_ = nullptr;
        size_ = 0;
    }

    void enqueue(int val) {
        QueueNode* newNode = new QueueNode(val);
        if (empty()) {
            front_ = rear_ = newNode;
        } else {
            rear_->next = newNode;
            rear_ = newNode;
        }
        size_++;
    }

    void dequeue() {
        if (empty()) {
            throw runtime_error("Queue is empty");
        }
        QueueNode* temp = front_;
        front_ = front_->next;
        delete temp;
        size_--;

        // ⚠️ THE REAR BUG FIX (CADT Slide 14):
        // If the queue is now empty, rear_ MUST also be set to nullptr!
        // Otherwise rear_ points to deleted memory, corrupting future enqueues.
        if (front_ == nullptr) {
            rear_ = nullptr;
        }
    }

    int front() const {
        if (empty()) {
            throw runtime_error("Queue is empty");
        }
        return front_->data;
    }

    bool empty() const {
        return front_ == nullptr;
    }

    size_t size() const {
        return size_;
    }

    const QueueNode* getRear() const {
        return rear_;
    }

private:
    QueueNode* front_;
    QueueNode* rear_;
    size_t size_;
};
