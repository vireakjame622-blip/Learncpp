#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <vector>

using namespace std;

int main() {
    TEST_SUITE("03_insertion_sort (Shifting & Key Insertion)");

    // Condition 1: Empty and single
    vector<int> emptyVec;
    insertionSort(emptyVec);
    TEST_CONDITION(emptyVec.empty(), "Empty array remains empty", "Guard n <= 1");

    vector<int> single = {77};
    insertionSort(single);
    TEST_CONDITION(single.size() == 1 && single[0] == 77, "Single element stays [77]", "Guard n <= 1");

    // Condition 2: General unsorted array
    vector<int> arr1 = {12, 11, 13, 5, 6};
    vector<int> expected1 = {5, 6, 11, 12, 13};
    insertionSort(arr1);
    TEST_CONDITION(arr1 == expected1, "Sorts unsorted array {12, 11, 13, 5, 6}", "Check key placement and shifting");

    // Condition 3: Already sorted array (O(n) best-case test)
    vector<int> arr2 = {1, 2, 3, 4, 5, 6};
    vector<int> expected2 = {1, 2, 3, 4, 5, 6};
    insertionSort(arr2);
    TEST_CONDITION(arr2 == expected2, "Already sorted array remains sorted", "While loop terminates immediately");

    // Condition 4: Reverse array (O(n^2) worst-case)
    vector<int> arr3 = {6, 5, 4, 3, 2, 1};
    vector<int> expected3 = {1, 2, 3, 4, 5, 6};
    insertionSort(arr3);
    TEST_CONDITION(arr3 == expected3, "Reverse array sorted properly", "Full shifts to position 0");

    // Condition 5: Array with duplicates and negative values
    vector<int> arr4 = {0, -5, 10, -5, 2, 0};
    vector<int> expected4 = {-5, -5, 0, 0, 2, 10};
    insertionSort(arr4);
    TEST_CONDITION(arr4 == expected4, "Handles duplicates and negative numbers correctly", "Stable shifting");

    TEST_REPORT();
}
