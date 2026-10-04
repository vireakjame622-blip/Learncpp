#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main() {
    TEST_SUITE("04_merge_sort (Divide, Conquer & Merge)");

    // Condition 1: Empty and single
    vector<int> emptyVec;
    mergeSort(emptyVec);
    TEST_CONDITION(emptyVec.empty(), "Empty array remains empty", "Base case size <= 1");

    vector<int> single = {15};
    mergeSort(single);
    TEST_CONDITION(single.size() == 1 && single[0] == 15, "Single element remains [15]", "Base case size <= 1");

    // Condition 2: Even and odd sizes
    vector<int> evenArr = {38, 27, 43, 3, 9, 82};
    vector<int> expectedEven = {3, 9, 27, 38, 43, 82};
    mergeSort(evenArr);
    TEST_CONDITION(evenArr == expectedEven, "Sorts even-length array {38, 27, 43, 3, 9, 82}", "Check mergeHelper merging");

    vector<int> oddArr = {12, 11, 13, 5, 6, 7, 1};
    vector<int> expectedOdd = {1, 5, 6, 7, 11, 12, 13};
    mergeSort(oddArr);
    TEST_CONDITION(oddArr == expectedOdd, "Sorts odd-length array {12, 11, 13, 5, 6, 7, 1}", "Check mid index calculation");

    // Condition 3: Large randomized array
    vector<int> large(500);
    mt19937 rng(42);
    uniform_int_distribution<int> dist(-1000, 1000);
    for (int& x : large) x = dist(rng);

    vector<int> stdSorted = large;
    sort(stdSorted.begin(), stdSorted.end());

    mergeSort(large);
    TEST_CONDITION(large == stdSorted, "Sorts large array (500 random elements) accurately", "Matches sort result");

    TEST_REPORT();
}
