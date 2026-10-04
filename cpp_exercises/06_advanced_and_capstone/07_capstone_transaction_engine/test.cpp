#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

int main() {
    TEST_SUITE("05_capstone_project (CADT-Core In-Memory Transaction Engine)");

    // =========================================================================
    // PART 1: WEEK 3 DOUBLY LINKED BUFFER TESTS
    // =========================================================================
    {
        DoublyLinkedBuffer<Record> buf;
        TEST_CONDITION(buf.empty(), "Buffer starts empty", "Initial size should be 0");
        TEST_EQUAL(buf.size(), static_cast<size_t>(0), "Buffer size is 0", "Initial size is 0");

        buf.push_back({101, "Alice", 92.5, 1});
        buf.push_back({102, "Bob", 78.0, 2});
        buf.push_front({100, "Zack", 88.0, 3}); // Order: Zack(100) -> Alice(101) -> Bob(102)

        TEST_EQUAL(buf.size(), static_cast<size_t>(3), "Buffer size after pushes is 3", "Check size tracking");
        TEST_CONDITION(buf.head() != nullptr && buf.head()->data.id == 100, "Head is Zack (100)", "push_front works");
        TEST_CONDITION(buf.tail() != nullptr && buf.tail()->data.id == 102, "Tail is Bob (102)", "push_back works");

        // Verify bidirectional linking
        TEST_CONDITION(buf.head()->next != nullptr && buf.head()->next->data.id == 101, "Head next is Alice", "Forward pointer");
        TEST_CONDITION(buf.tail()->prev != nullptr && buf.tail()->prev->data.id == 101, "Tail prev is Alice", "Backward pointer");

        // Find by ID
        Record* found = buf.find_by_id(101);
        TEST_CONDITION(found != nullptr && found->name == "Alice", "find_by_id(101) returns Alice", "Find by key");
        TEST_CONDITION(buf.find_by_id(999) == nullptr, "find_by_id(999) returns nullptr", "Missing key returns nullptr");

        // Remove from middle (Alice)
        bool removedAlice = buf.remove_by_id(101);
        TEST_CONDITION(removedAlice, "Removed Alice (101) from middle", "remove middle");
        TEST_EQUAL(buf.size(), static_cast<size_t>(2), "Buffer size is now 2", "Decrement size");
        TEST_CONDITION(buf.head()->next == buf.tail(), "Head next links directly to tail", "Relink middle");
        TEST_CONDITION(buf.tail()->prev == buf.head(), "Tail prev links directly to head", "Relink middle reverse");

        // Remove head and tail
        buf.remove_by_id(100);
        buf.remove_by_id(102);
        TEST_CONDITION(buf.empty(), "Buffer is empty after removing all elements", "Empty state");
        TEST_CONDITION(buf.head() == nullptr && buf.tail() == nullptr, "Head and Tail are nullptr", "Pointers reset");
    }

    // =========================================================================
    // PART 2: WEEK 4 LIFO TRANSACTION STACK TESTS
    // =========================================================================
    {
        TransactionStack st;
        TEST_CONDITION(st.empty(), "TransactionStack starts empty", "Empty check");
        TEST_THROWS(st.pop(), runtime_error, "Pop on empty stack throws runtime_error", "Empty guard");

        Transaction tx1{ActionType::INSERT, {1, "Task1", 80.0, 1}, {}};
        Transaction tx2{ActionType::UPDATE, {1, "Task1", 95.0, 1}, {1, "Task1", 80.0, 1}};
        st.push(tx1);
        st.push(tx2);

        TEST_EQUAL(st.size(), static_cast<size_t>(2), "Stack size is 2", "Size tracking");
        TEST_CONDITION(st.top().action == ActionType::UPDATE, "Top action is UPDATE (LIFO)", "LIFO top");

        Transaction popped = st.pop();
        TEST_CONDITION(popped.action == ActionType::UPDATE, "Popped is UPDATE", "LIFO pop");
        TEST_EQUAL(st.size(), static_cast<size_t>(1), "Stack size is 1", "Size decrement");
    }

    // =========================================================================
    // PART 3: WEEK 4 FIFO TASK QUEUE TESTS
    // =========================================================================
    {
        TaskQueue q;
        TEST_CONDITION(q.empty(), "TaskQueue starts empty", "Queue empty");
        TEST_THROWS(q.dequeue(), runtime_error, "Dequeue on empty queue throws runtime_error", "Empty guard");

        q.enqueue({1, "Register", {201, "Charlie", 85.0, 1}});
        q.enqueue({2, "Register", {202, "Dana", 91.0, 2}});
        q.enqueue({3, "Register", {203, "Eli", 74.0, 3}});

        TEST_EQUAL(q.size(), static_cast<size_t>(3), "Queue size is 3", "Queue count");
        TEST_EQUAL(q.peek().taskId, 1, "Peek returns first enqueued task (FIFO)", "FIFO peek");

        JobTask t1 = q.dequeue();
        TEST_EQUAL(t1.taskId, 1, "First dequeued is task 1", "FIFO order 1");
        JobTask t2 = q.dequeue();
        TEST_EQUAL(t2.taskId, 2, "Second dequeued is task 2", "FIFO order 2");
        JobTask t3 = q.dequeue();
        TEST_EQUAL(t3.taskId, 3, "Third dequeued is task 3", "FIFO order 3");
        TEST_CONDITION(q.empty(), "Queue is empty after 3 dequeues", "Queue empty post drain");
    }

    // =========================================================================
    // PART 4: WEEK 2 SORTING & <CHRONO> TIMING ENGINE TESTS
    // =========================================================================
    {
        vector<Record> records = {
            {5, "Eve", 65.5, 3},
            {1, "Bob", 88.0, 1},
            {4, "Dave", 72.0, 2},
            {2, "Charlie", 95.0, 1},
            {3, "Alice", 81.5, 4}
        };

        // Benchmark sorting execution time
        double durationUs = AnalyticsSortEngine::benchmarkSort(records,
            [](const Record& a, const Record& b) {
                return a.id < b.id; // Sort by ID ascending
            });

        TEST_CONDITION(durationUs >= 0.0, "Benchmark returns valid execution duration (us)", "Chrono timer");
        TEST_EQUAL(records[0].id, 1, "First record sorted by ID is 1", "QuickSort ID order");
        TEST_EQUAL(records[1].id, 2, "Second record sorted by ID is 2", "QuickSort ID order");
        TEST_EQUAL(records[4].id, 5, "Last record sorted by ID is 5", "QuickSort ID order");

        // Sort descending by score
        AnalyticsSortEngine::quickSort(records, 0, static_cast<int>(records.size() - 1),
            [](const Record& a, const Record& b) {
                return a.score > b.score;
            });
        TEST_EQUAL(records[0].name, string("Charlie"), "Highest score is Charlie (95.0)", "Score descending");
        TEST_EQUAL(records[4].name, string("Eve"), "Lowest score is Eve (65.5)", "Score descending tail");
    }

    // =========================================================================
    // PART 5: UNIFIED CADT-CORE FACADE INTEGRATION (TRANSACTION & UNDO/REDO)
    // =========================================================================
    {
        CapstoneEngine engine;

        // 1. Insert records
        TEST_CONDITION(engine.insertRecord({301, "Sopheak", 87.0, 1}), "Insert record 301 succeeds", "Insert unique");
        TEST_CONDITION(engine.insertRecord({302, "Bopha", 94.0, 2}), "Insert record 302 succeeds", "Insert unique");
        TEST_CONDITION(!engine.insertRecord({301, "Duplicate", 50.0, 1}), "Insert duplicate ID 301 is rejected", "Disallow duplicates");
        TEST_EQUAL(engine.recordCount(), static_cast<size_t>(2), "Record count is 2", "Count check");

        // 2. Undo insertion (LIFO rollback)
        TEST_CONDITION(engine.undo(), "Undo insert of 302 succeeds", "Undo LIFO");
        TEST_EQUAL(engine.recordCount(), static_cast<size_t>(1), "Record count is 1 after undo", "Rollback insert");
        TEST_CONDITION(engine.getRecord(302) == nullptr, "Record 302 is no longer in buffer", "Removed via undo");

        // 3. Redo insertion
        TEST_CONDITION(engine.redo(), "Redo insert of 302 succeeds", "Redo transaction");
        TEST_EQUAL(engine.recordCount(), static_cast<size_t>(2), "Record count is restored to 2", "Restored via redo");
        TEST_CONDITION(engine.getRecord(302) != nullptr, "Record 302 is back in buffer", "Present via redo");

        // 4. Update record score & Undo/Redo update
        TEST_CONDITION(engine.updateRecord(301, 99.0, 5), "Update record 301 score to 99.0", "Update record");
        TEST_EQUAL(engine.getRecord(301)->score, 99.0, "Record 301 score is 99.0", "Score updated");

        engine.undo(); // Should revert score back to 87.0
        TEST_EQUAL(engine.getRecord(301)->score, 87.0, "Score restored to 87.0 via undo", "Undo update");

        engine.redo(); // Should re-apply 99.0
        TEST_EQUAL(engine.getRecord(301)->score, 99.0, "Score re-applied to 99.0 via redo", "Redo update");

        // 5. Delete record & Undo/Redo delete
        TEST_CONDITION(engine.deleteRecord(302), "Delete record 302 succeeds", "Delete record");
        TEST_EQUAL(engine.recordCount(), static_cast<size_t>(1), "Record count is 1 after delete", "Delete count");

        engine.undo(); // Should restore 302
        TEST_EQUAL(engine.recordCount(), static_cast<size_t>(2), "Record 302 restored via undo", "Undo delete");
        TEST_CONDITION(engine.getRecord(302) != nullptr, "Record 302 exists again", "Record resurrected");

        // 6. FIFO Task Queue Batch Execution
        engine.scheduleTask({10, "Enroll", {303, "Dara", 82.5, 3}});
        engine.scheduleTask({11, "Enroll", {304, "Chenda", 96.0, 1}});
        TEST_EQUAL(engine.pendingTaskCount(), static_cast<size_t>(2), "2 pending tasks scheduled", "Queue count");

        size_t processed = engine.processPendingTasks();
        TEST_EQUAL(processed, static_cast<size_t>(2), "2 tasks processed from queue", "FIFO batch dispatch");
        TEST_EQUAL(engine.pendingTaskCount(), static_cast<size_t>(0), "0 pending tasks remaining", "Queue drained");
        TEST_EQUAL(engine.recordCount(), static_cast<size_t>(4), "Total 4 records in buffer", "Buffer expanded via queue");

        // 7. Analytics: Top Performers (Sorted by score descending)
        vector<Record> top = engine.getTopPerformers();
        TEST_EQUAL(top.size(), static_cast<size_t>(4), "Top performers contains 4 records", "Analytics vector size");
        TEST_EQUAL(top[0].score, 99.0, "Rank 1 is Sopheak (99.0)", "Analytics ranking 1");
        TEST_EQUAL(top[1].score, 96.0, "Rank 2 is Chenda (96.0)", "Analytics ranking 2");
        TEST_EQUAL(top[2].score, 94.0, "Rank 3 is Bopha (94.0)", "Analytics ranking 3");
        TEST_EQUAL(top[3].score, 82.5, "Rank 4 is Dara (82.5)", "Analytics ranking 4");
    }

    TEST_REPORT();
}
