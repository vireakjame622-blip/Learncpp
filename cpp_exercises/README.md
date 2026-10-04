# CADT C++ & DSA Learning Suite: Exercise & Testing Lab

Welcome to the comprehensive hands-on practice suite for **CADT PREPARE-Y2 Advanced Algorithms & C++**.

This repository contains **23 comprehensive exercises** organized across the 5 core course modules. Each exercise includes starter code with `// TODO` markers, an automated testing suite that validates every condition and edge case, and a compiler harness that gives friendly error diagnostics.

---

## 📚 Curriculum Roadmap

```
├── 01_foundation/               (Week 1: C++ Foundations)
│   ├── 01_grade_classifier      • If/Else condition ladders & score validation
│   ├── 02_loop_accumulate       • Loops, digit counters, factorials, tables
│   ├── 03_array_algorithms      • Min/Max, floating-point avg, in-place reverse
│   ├── 04_string_palindrome     • Strings, vowels, case-insensitive 2-pointer
│   └── 05_pointers_and_references • Pass-by-ref, pointer swaps, nullptr safety
│
├── 02_sorting/                  (Week 2: Sorting & <chrono> Lab)
│   ├── 01_bubble_sort           • Adjacent swaps & early exit optimization
│   ├── 02_selection_sort        • Minimum index search & prefix swapping
│   ├── 03_insertion_sort        • Key insertion & shifting
│   ├── 04_merge_sort            • Divide-and-conquer recursion & merging
│   ├── 05_quick_sort            • Pivot partitioning (Lomuto) & recursion
│   └── 06_sort_benchmark        • <chrono> high_resolution_clock timing
│
├── 03_linked_lists/             (Week 3: Dynamic Data Structures)
│   ├── 01_singly_linked_list    • Node pointer manipulation & heap cleanup
│   ├── 02_doubly_linked_list    • Bidirectional traversal & prev/next invariant
│   └── 03_circular_linked_list  • Cycle traversal & Josephus elimination
│
├── 04_stack_and_queue/          (Week 4: LIFO, FIFO & Lab Exercises)
│   ├── 01_stack_vector          • Generic Stack<T> backed by std::vector
│   ├── 02_stack_linked_nodes    • Custom NodeStack & empty guard (Slide 13 Lab)
│   ├── 03_balanced_parentheses  • Matching (), [], {} and code syntax
│   ├── 04_min_stack             • O(1) getMin auxiliary tracking
│   ├── 05_queue_basic           • Generic Queue<T> backed by std::deque
│   ├── 06_queue_linked_nodes    • NodeQueue & the Slide 14 "Rear Bug" fix
│   ├── 07_queue_using_two_stacks • FIFO queue implemented using two LIFO stacks
│   └── 08_circular_queue        • Fixed-capacity ring buffer with modulo
│
└── 05_capstone_project/         (Week 5: DSA Grand Finale Capstone)
    └── 01_transaction_engine    • CADT-Core In-Memory Transaction Engine
                                   (Doubly Linked Buffer + LIFO Undo/Redo +
                                    FIFO Task Queue + QuickSort Benchmark)
```

---

## 🚀 Quick Start (How to Run Tests)

### Method 1: One-Click Windows Batch Runner (Recommended)
From the root directory or inside `cpp_exercises/`:
```bat
.\run_tests.bat
```
To run a specific module or exercise:
```bat
.\run_tests.bat foundation
.\run_tests.bat sorting
.\run_tests.bat 01_bubble_sort
```

### Method 2: Python Test Runner
```bash
# List all 22 exercises
python test_runner.py --list

# Run all exercises
python test_runner.py

# Run a specific module
python test_runner.py 01_foundation
python test_runner.py 02_sorting
python test_runner.py 03_linked_lists
python test_runner.py 04_stack_and_queue

# Run a specific exercise
python test_runner.py 06_queue_linked_nodes
```

### Method 3: Direct g++ Terminal Command
Navigate to any exercise folder and compile with `g++`:
```bash
cd 01_foundation/01_grade_classifier
g++ -std=c++17 -Wall -Wextra -I../../include test.cpp -o test.exe
.\test.exe
```

---

## 🛠️ How to Work Through an Exercise

1. Open the exercise folder, e.g. `02_sorting/01_bubble_sort/`.
2. Open `exercise.h` and read the comments and tasks.
3. Write your implementation inside the `// TODO` areas.
4. Run the test:
   ```bash
   python test_runner.py 01_bubble_sort
   ```
5. Review the condition checklist:
   - Green `[PASS]`: Condition met!
   - Red `[FAIL]`: Condition failed — read the **Expected vs Actual** values and the **Hint**!
6. If you get completely stuck, check the verified reference implementation in `solutions/`!

---

## 💡 Key Gotchas Tested Across Conditions

1. **Integer Division**:
   - In `03_array_algorithms`, calculating `sum / size` when both are integers truncates decimals (`3 / 2 == 1`). Always cast to `double` before dividing: `static_cast<double>(sum) / size`.
2. **Nullptr Safety**:
   - In `05_pointers_and_references`, always check `if (ptr == nullptr)` before dereferencing `*ptr` to prevent fatal segmentation faults.
3. **The Famous CADT "Rear Bug" (Lab 04 Slide 14)**:
   - In `06_queue_linked_nodes`, when you dequeue the last remaining element, `front_` becomes `nullptr`. If you don't also set `rear_ = nullptr;`, `rear_` becomes a dangling pointer to freed memory, causing future `enqueue()` calls to crash!
4. **Duplicate Values in MinStack & Lomuto Partition**:
   - In `04_min_stack`, remember to push onto `min_stack_` when `value <= min_stack_.top()` (with `<=`), not just `<`. Otherwise duplicate minimums will cause desynchronization when popped!
