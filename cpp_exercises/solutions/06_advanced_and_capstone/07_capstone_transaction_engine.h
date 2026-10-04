#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <functional>
#include <stdexcept>
#include <iostream>

using namespace std;

// ============================================================================
// CADT DSA CAPSTONE PROJECT (WEEK 05):
// COMPLETE REFERENCE SOLUTION — IN-MEMORY TRANSACTION ENGINE ("CADT-CORE")
// ============================================================================

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
    Record record;
    Record previous;
};

// --- 1. DOUBLY LINKED LIST BUFFER ---
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

    ~DoublyLinkedBuffer() {
        clear();
    }

    DoublyLinkedBuffer(const DoublyLinkedBuffer&) = delete;
    DoublyLinkedBuffer& operator=(const DoublyLinkedBuffer&) = delete;

    void push_back(const T& val) {
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

// --- 2. LIFO TRANSACTION STACK ---
class TransactionStack {
public:
    void push(const Transaction& tx) {
        undo_stack_.push_back(tx);
    }

    Transaction pop() {
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

// --- 3. FIFO TASK SCHEDULER QUEUE ---
struct JobTask {
    int taskId{0};
    string taskName;
    Record payload;
};

class TaskQueue {
public:
    void enqueue(const JobTask& task) {
        tasks_.push_back(task);
    }

    JobTask dequeue() {
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

// --- 4. SORTING & <CHRONO> BENCHMARK ENGINE ---
class AnalyticsSortEngine {
public:
    static void quickSort(vector<Record>& arr, int low, int high,
                          function<bool(const Record&, const Record&)> comp) {
        if (low < high) {
            int p = partition(arr, low, high, comp);
            quickSort(arr, low, p - 1, comp);
            quickSort(arr, p + 1, high, comp);
        }
    }

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

// --- 5. UNIFIED CADT-CORE FACADE ---
class CapstoneEngine {
public:
    bool insertRecord(const Record& rec) {
        if (buffer_.find_by_id(rec.id) != nullptr) {
            return false;
        }
        buffer_.push_back(rec);
        undo_stack_.push({ActionType::INSERT, rec, {}});
        redo_stack_.clear();
        return true;
    }

    bool deleteRecord(int id) {
        Record* existing = buffer_.find_by_id(id);
        if (!existing) return false;

        Record deletedRecord = *existing;
        buffer_.remove_by_id(id);
        undo_stack_.push({ActionType::DELETE, deletedRecord, {}});
        redo_stack_.clear();
        return true;
    }

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

    bool undo() {
        if (undo_stack_.empty()) return false;
        Transaction tx = undo_stack_.pop();

        if (tx.action == ActionType::INSERT) {
            buffer_.remove_by_id(tx.record.id);
        } else if (tx.action == ActionType::DELETE) {
            buffer_.push_back(tx.record);
        } else if (tx.action == ActionType::UPDATE) {
            Record* curr = buffer_.find_by_id(tx.record.id);
            if (curr) {
                curr->score = tx.previous.score;
                curr->priority = tx.previous.priority;
            }
        }

        redo_stack_.push(tx);
        return true;
    }

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

    vector<Record> getTopPerformers() {
        vector<Record> recs = buffer_.to_vector();
        AnalyticsSortEngine::quickSort(recs, 0, static_cast<int>(recs.size() - 1),
            [](const Record& a, const Record& b) {
                return a.score > b.score;
            });
        return recs;
    }

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
