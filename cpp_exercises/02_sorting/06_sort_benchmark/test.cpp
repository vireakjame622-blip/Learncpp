#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <vector>
#include <algorithm>
#include <thread>

using namespace std;

void dummyFastSort(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

void dummySleepSort(vector<int>&) {
    this_thread::sleep_for(chrono::milliseconds(5));
}

int main() {
    TEST_SUITE("06_sort_benchmark (<chrono> Performance Measurement)");

    vector<int> sample = {5, 3, 8, 1, 2, 7, 4, 6};
    vector<int> originalCopy = sample;

    // Condition 1: Verify execution time is non-negative and works
    long long duration = measureSortTimeMicroseconds(dummyFastSort, sample);
    TEST_CONDITION(duration >= 0, "measureSortTime returns non-negative microseconds", "Timer must record positive interval");

    // Condition 2: Sleep benchmark to verify accuracy (>= 4000 microseconds)
    long long sleepDuration = measureSortTimeMicroseconds(dummySleepSort, sample);
    TEST_CONDITION(sleepDuration >= 4000, "Measured sleep duration accurately (~5000 microseconds)", "Timer accurately tracked execution time");

    // Condition 3: Verify caller's array was NOT modified because it was passed by value
    TEST_CONDITION(sample == originalCopy, "Caller array remains unchanged (passed by value)", "Ensure arr is passed by value to keep fresh copies");

    TEST_REPORT();
}
