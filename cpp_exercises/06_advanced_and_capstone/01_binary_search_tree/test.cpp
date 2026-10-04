#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <vector>

using namespace std;

int main() {
    TEST_SUITE("01_binary_search_tree (BST Ordering & Recursive Invariants)");

    BinarySearchTree bst;

    // Condition 1: Initial empty state
    {
        TEST_CONDITION(bst.empty() == true, "New BST is empty", "empty() check");
        TEST_EQUAL(bst.size(), static_cast<size_t>(0), "Initial size is 0", "size() check");
        TEST_EQUAL(bst.height(), 0, "Initial height is 0", "height() check");
        TEST_THROWS(bst.findMin(), runtime_error, "findMin on empty tree throws", "Empty guard");
        TEST_THROWS(bst.findMax(), runtime_error, "findMax on empty tree throws", "Empty guard");
    }

    // Condition 2: Insertion & In-Order Traversal (Sorting property)
    {
        // Insert keys: 50, 30, 70, 20, 40, 60, 80
        TEST_CONDITION(bst.insert(50) == true, "Insert 50", "Root insertion");
        TEST_CONDITION(bst.insert(30) == true, "Insert 30", "Left child");
        TEST_CONDITION(bst.insert(70) == true, "Insert 70", "Right child");
        TEST_CONDITION(bst.insert(20) == true, "Insert 20", "Subtree left");
        TEST_CONDITION(bst.insert(40) == true, "Insert 40", "Subtree right");
        TEST_CONDITION(bst.insert(60) == true, "Insert 60", "Subtree left");
        TEST_CONDITION(bst.insert(80) == true, "Insert 80", "Subtree right");

        // Duplicate rejection
        TEST_CONDITION(bst.insert(50) == false, "Insert duplicate 50 returns false", "No duplicates allowed");
        TEST_EQUAL(bst.size(), static_cast<size_t>(7), "Size is 7", "Size tracking");

        // Traversal must be strictly sorted: {20, 30, 40, 50, 60, 70, 80}
        vector<int> expected = {20, 30, 40, 50, 60, 70, 80};
        TEST_CONDITION(bst.inOrderTraversal() == expected, "In-Order traversal yields sorted sequence", "BST Invariant");
    }

    // Condition 3: Search
    {
        TEST_CONDITION(bst.search(40) == true, "Search for existing key 40 is true", "BST Search");
        TEST_CONDITION(bst.search(80) == true, "Search for existing key 80 is true", "BST Search");
        TEST_CONDITION(bst.search(999) == false, "Search for missing key 999 is false", "BST Search missing");
        TEST_CONDITION(bst.search(15) == false, "Search for missing key 15 is false", "BST Search missing");
    }

    // Condition 4: Min, Max and Height
    {
        TEST_EQUAL(bst.findMin(), 20, "findMin() returns leftmost key 20", "Leftmost path");
        TEST_EQUAL(bst.findMax(), 80, "findMax() returns rightmost key 80", "Rightmost path");
        TEST_EQUAL(bst.height(), 3, "Height of balanced 7-node tree is 3", "Tree height");
    }

    TEST_REPORT();
}
