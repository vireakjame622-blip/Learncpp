#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <functional>
#include <stdexcept>
#include <iostream>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 07_capstone_transaction_engine
//    OR:
//    .\run_tests.bat 07_capstone_transaction_engine
// ============================================================================

// ============================================================================
// CADT DSA CAPSTONE PROJECT (WEEK 05):
// HIGH-PERFORMANCE IN-MEMORY TRANSACTION & DATA ENGINE ("CADT-CORE")
// ============================================================================
//
// This capstone project integrates all concepts learned across Weeks 1-4:
//   * WEEK 1: Dynamic Memory, RAII, Pointer Safety & Robust Exception Guards
//   * WEEK 2: Sorting Algorithms (QuickSort/MergeSort) & <chrono> Benchmarking
//   * WEEK 3: Custom Doubly Linked List with O(1) Endpoint Operations
//   * WEEK 4: LIFO Undo/Redo Transaction Stack & FIFO Task Processing Queue
//
// ============================================================================

// --- 1. CORE DATA MODELS ---
struct Record {
    int id{0};
    string name;
    double score{0.0};
    int priority{0};

    bool operator==(const Record& other) const {
        return id == other.id && name == other.name && score == other.score && priority == other.priority;
    }
};

enum class ActionType {
    INSERT,
    DELETE,
    UPDATE
};

struct Transaction {
    ActionType action;
    Record record;       // For INSERT: the inserted record. For DELETE: the deleted record.
    Record previous;     // For UPDATE: previous record state
};

// --- 2. WEEK 3 COMPONENT: CUSTOM DOUBLY LINKED LIST BUFFER ---
template <typename T>
class DoublyLinkedBuffer {
public:
    struct Node {
        T data;
        Node* prev{nullptr};
        Node* next{nullptr};
        explicit Node(const T& val) : data(val), prev(nullptr), next(nullptr) {}
    };

    DoublyLinkedBuffer() : head_(nullptr), tail_(nullptr), size_(0) {}

    // Destructor: Must safely free all dynamically allocated heap nodes (Week 1 RAII)
    ~DoublyLinkedBuffer() {
        clear();
    }

    // Disable copy for memory safety unless implemented
    DoublyLinkedBuffer(const DoublyLinkedBuffer&) = delete;
    DoublyLinkedBuffer& operator=(const DoublyLinkedBuffer&) = delete;

    void push_back(const T& val) {
        // TODO: Allocate a new Node on heap
        // If empty, set head_ and tail_ to the new node
        // Otherwise, link tail_->next to new node, new node->prev to tail_, update tail_
        // Increment size_
        Node* n = new Node(val);
        if (!tail_) {
            head_ = tail_ = n;
        } else {
            tail_->next = n;
            n->prev = tail_;
            tail_ = n;
        }
        ++size_;
    }

    void push_front(const T& val) {
        // TODO: Allocate new node on heap
        // If empty, set head_ and tail_ to new node
        // Otherwise, link new node->next to head_, head_->prev to new node, update head_
        // Increment size_
        Node* n = new Node(val);
        if (!head_) {
            head_ = tail_ = n;
        } else {
            n->next = head_;
            head_->prev = n;
            head_ = n;
        }
        ++size_;
    }

    bool remove_by_id(int id) {
        // TODO: Traverse nodes from head to tail.
        // If node->data.id == id, unlink it properly:
        //   - Update prev->next (or head_ if removing head)
        //   - Update next->prev (or tail_ if removing tail)
        //   - Safely delete the node and decrement size_
        // Return true if found and removed, false otherwise.
        Node* curr = head_;
        while (curr) {
            if (curr->data.id == id) {
                if (curr->prev) curr->prev->next = curr->next;
                else head_ = curr->next;

                if (curr->next) curr->next->prev = curr->prev;
                else tail_ = curr->prev;

                delete curr;
                --size_;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    T* find_by_id(int id) {
        // TODO: Find record with matching id, return pointer to data or nullptr if not found
        Node* curr = head_;
        while (curr) {
            if (curr->data.id == id) return &(curr->data);
            curr = curr->next;
        }
        return nullptr;
    }

    const T* find_by_id(int id) const {
        Node* curr = head_;
        while (curr) {
            if (curr->data.id == id) return &(curr->data);
            curr = curr->next;
        }
        return nullptr;
    }

    void clear() {
        // TODO: Traverse and delete all nodes to prevent memory leaks
        Node* curr = head_;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        head_ = tail_ = nullptr;
        size_ = 0;
    }

    size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }
    Node* head() const { return head_; }
    Node* tail() const { return tail_; }

    vector<T> to_vector() const {
        vector<T> res;
        res.reserve(size_);
        Node* curr = head_;
        while (curr) {
            res.push_back(curr->data);
            curr = curr->next;
        }
        return res;
    }

private:
    Node* head_{nullptr};
    Node* tail_{nullptr};
    size_t size_{0};
};

// --- 3. WEEK 4 COMPONENT: LIFO UNDO/REDO TRANSACTION STACK ---
class TransactionStack {
public:
    void push(const Transaction& tx) {
        // TODO: Push transaction onto stack
        undo_stack_.push_back(tx);
    }

    Transaction pop() {
        // TODO: Check if empty, throw runtime_error if empty.
        // Otherwise pop and return top transaction
        if (empty()) throw runtime_error("TransactionStack is empty");
        Transaction top = undo_stack_.back();
        undo_stack_.pop_back();
        return top;
    }

    const Transaction& top() const {
        if (empty()) throw runtime_error("TransactionStack is empty");
        return undo_stack_.back();
    }

    bool empty() const { return undo_stack_.empty(); }
    size_t size() const { return undo_stack_.size(); }
    void clear() { undo_stack_.clear(); }

private:
    vector<Transaction> undo_stack_;
};

// --- 4. WEEK 4 COMPONENT: FIFO TASK SCHEDULER QUEUE ---
struct JobTask {
    int taskId{0};
    string taskName;
    Record payload;
};

class TaskQueue {
public:
    void enqueue(const JobTask& task) {
        // TODO: Enqueue task at rear (FIFO)
        tasks_.push_back(task);
    }

    JobTask dequeue() {
        // TODO: Throw runtime_error if empty.
        // Dequeue from front and return
        if (empty()) throw runtime_error("TaskQueue is empty");
        JobTask front = tasks_.front();
        tasks_.erase(tasks_.begin());
        return front;
    }

    const JobTask& peek() const {
        if (empty()) throw runtime_error("TaskQueue is empty");
        return tasks_.front();
    }

    bool empty() const { return tasks_.empty(); }
    size_t size() const { return tasks_.size(); }
    void clear() { tasks_.clear(); }

private:
    vector<JobTask> tasks_;
};

// --- 5. WEEK 2 COMPONENT: SORTING & <CHRONO> BENCHMARK ENGINE ---
class AnalyticsSortEngine {
public:
    // In-place QuickSort on vector<Record> using Lomuto partition
    static void quickSort(vector<Record>& arr, int low, int high,
                          function<bool(const Record&, const Record&)> comp) {
        // TODO: Implement recursive QuickSort with comparator
        if (low < high) {
            int p = partition(arr, low, high, comp);
            quickSort(arr, low, p - 1, comp);
            quickSort(arr, p + 1, high, comp);
        }
    }

    // Benchmark execution time in microseconds using chrono (Week 2 Lab)
    static double benchmarkSort(vector<Record>& arr,
                                function<bool(const Record&, const Record&)> comp) {
        auto start = chrono::high_resolution_clock::now();
        if (!arr.empty()) {
            quickSort(arr, 0, static_cast<int>(arr.size() - 1), comp);
        }
        auto end = chrono::high_resolution_clock::now();
        return chrono::duration<double, micro>(end - start).count();
    }

private:
    static int partition(vector<Record>& arr, int low, int high,
                         function<bool(const Record&, const Record&)> comp) {
        Record pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (comp(arr[j], pivot)) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
};

// --- 6. UNIFIED CAPSTONE ENGINE FACADE ("CADT-CORE") ---
class CapstoneEngine {
public:
    // INSERT Operation (with Transaction logging for Undo)
    bool insertRecord(const Record& rec) {
        if (buffer_.find_by_id(rec.id) != nullptr) {
            return false;
        }
        buffer_.push_back(rec);
        undo_stack_.push({ActionType::INSERT, rec, {}});
        redo_stack_.clear(); // New operation clears redo history
        return true;
    }

    // DELETE Operation (with Transaction logging for Undo)
    bool deleteRecord(int id) {
        Record* existing = buffer_.find_by_id(id);
        if (!existing) return false;

        Record deletedRecord = *existing;
        buffer_.remove_by_id(id);
        undo_stack_.push({ActionType::DELETE, deletedRecord, {}});
        redo_stack_.clear();
        return true;
    }

    // UPDATE Operation (with Transaction logging for Undo)
    bool updateRecord(int id, double newScore, int newPriority) {
        Record* existing = buffer_.find_by_id(id);
        if (!existing) return false;

        Record prev = *existing;
        existing->score = newScore;
        existing->priority = newPriority;

        undo_stack_.push({ActionType::UPDATE, *existing, prev});
        redo_stack_.clear();
        return true;
    }

    // UNDO: Rolls back the most recent transaction (LIFO)
    bool undo() {
        if (undo_stack_.empty()) return false;
        Transaction tx = undo_stack_.pop();

        if (tx.action == ActionType::INSERT) {
            // Revert insert by removing
            buffer_.remove_by_id(tx.record.id);
        } else if (tx.action == ActionType::DELETE) {
            // Revert delete by re-inserting
            buffer_.push_back(tx.record);
        } else if (tx.action == ActionType::UPDATE) {
            // Revert update by restoring previous state
            Record* curr = buffer_.find_by_id(tx.record.id);
            if (curr) {
                curr->score = tx.previous.score;
                curr->priority = tx.previous.priority;
            }
        }

        redo_stack_.push(tx);
        return true;
    }

    // REDO: Re-applies the most recent undone transaction
    bool redo() {
        if (redo_stack_.empty()) return false;
        Transaction tx = redo_stack_.pop();

        if (tx.action == ActionType::INSERT) {
            buffer_.push_back(tx.record);
        } else if (tx.action == ActionType::DELETE) {
            buffer_.remove_by_id(tx.record.id);
        } else if (tx.action == ActionType::UPDATE) {
            Record* curr = buffer_.find_by_id(tx.record.id);
            if (curr) {
                curr->score = tx.record.score;
                curr->priority = tx.record.priority;
            }
        }

        undo_stack_.push(tx);
        return true;
    }

    // Task Scheduling (FIFO)
    void scheduleTask(const JobTask& task) {
        task_queue_.enqueue(task);
    }

    size_t processPendingTasks() {
        size_t count = 0;
        while (!task_queue_.empty()) {
            JobTask task = task_queue_.dequeue();
            insertRecord(task.payload);
            ++count;
        }
        return count;
    }

    // Analytics: Returns records sorted by score descending (Top Performers)
    vector<Record> getTopPerformers() {
        vector<Record> recs = buffer_.to_vector();
        AnalyticsSortEngine::quickSort(recs, 0, static_cast<int>(recs.size() - 1),
            [](const Record& a, const Record& b) {
                return a.score > b.score;
            });
        return recs;
    }

    // Accessors
    size_t recordCount() const { return buffer_.size(); }
    size_t undoCount() const { return undo_stack_.size(); }
    size_t redoCount() const { return redo_stack_.size(); }
    size_t pendingTaskCount() const { return task_queue_.size(); }

    const Record* getRecord(int id) const {
        return buffer_.find_by_id(id);
    }

private:
    DoublyLinkedBuffer<Record> buffer_;
    TransactionStack undo_stack_;
    TransactionStack redo_stack_;
    TaskQueue task_queue_;
};
