#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 01_binary_search_tree
//    OR:
//    .\run_tests.bat 01_binary_search_tree
// ============================================================================

// EXERCISE 6.1: Binary Search Tree (BST) & Invariants
// CADT Advanced Algorithm & C++ • Week 5 Trees
//
// TASKS:
// Build an integer Binary Search Tree maintaining the BST invariant (left < root < right):
// 1. insert(int val): Inserts val. Returns true on success, false if duplicate.
// 2. search(int val) const: Returns true if val is found, false otherwise.
// 3. inOrderTraversal() const: Returns vector<int> of values in ascending order.
// 4. height() const: Returns height of tree (0 for empty tree, 1 for root only).
// 5. findMin() const and findMax() const: Return extremes; throw runtime_error on empty.
// 6. Destructor: Recursively free all nodes.

struct BSTNode {
    int val;
    BSTNode* left{nullptr};
    BSTNode* right{nullptr};
    explicit BSTNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root_(nullptr), size_(0) {}

    ~BinarySearchTree() {
        destroy(root_);
    }

    BinarySearchTree(const BinarySearchTree&) = delete;
    BinarySearchTree& operator=(const BinarySearchTree&) = delete;

    size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }

    bool insert(int val) {
        // TODO: Insert val maintaining BST property. Reject duplicates (return false).
        (void)val;
        return false;
    }

    bool search(int val) const {
        // TODO: Search for val iteratively or recursively. Return true if found.
        (void)val;
        return false;
    }

    vector<int> inOrderTraversal() const {
        // TODO: Perform in-order traversal (Left, Root, Right) to produce sorted vector
        return {};
    }

    int findMin() const {
        // TODO: Find leftmost node. Throw runtime_error if tree is empty.
        throw runtime_error("Tree is empty");
    }

    int findMax() const {
        // TODO: Find rightmost node. Throw runtime_error if tree is empty.
        throw runtime_error("Tree is empty");
    }

    int height() const {
        // TODO: Return tree height recursively
        return 0;
    }

private:
    BSTNode* root_{nullptr};
    size_t size_{0};

    void destroy(BSTNode* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
};
