#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <string>

using namespace std;

int main() {
    TEST_SUITE("05_templates_generic_vector (Generic Buffer & Dynamic Amortization)");

    // Condition 1: Initial state
    {
        CustomVector<int> vec;
        TEST_CONDITION(vec.empty() == true, "New vector is empty", "empty() check");
        TEST_EQUAL(vec.size(), static_cast<size_t>(0), "Initial size is 0", "size() check");
        TEST_THROWS(vec.pop_back(), underflow_error, "pop_back on empty throws underflow_error", "Empty guard");
        TEST_THROWS(vec.at(0), out_of_range, "at(0) on empty vector throws out_of_range", "Bounds guard");
    }

    // Condition 2: push_back & capacity doubling
    {
        CustomVector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);

        TEST_EQUAL(vec.size(), static_cast<size_t>(3), "Size is 3 after 3 pushes", "size() after push");
        TEST_CONDITION(vec.capacity() >= 3, "Capacity automatically grew", "Amortized growth");
        TEST_EQUAL(vec[0], 10, "vec[0] is 10", "operator[] read");
        TEST_EQUAL(vec[1], 20, "vec[1] is 20", "operator[] read");
        TEST_EQUAL(vec[2], 30, "vec[2] is 30", "operator[] read");
        TEST_EQUAL(vec.front(), 10, "front() is 10", "front() read");
        TEST_EQUAL(vec.back(), 30, "back() is 30", "back() read");
    }

    // Condition 3: pop_back & at() bounds check
    {
        CustomVector<int> vec;
        vec.push_back(100);
        vec.push_back(200);
        vec.pop_back();

        TEST_EQUAL(vec.size(), static_cast<size_t>(1), "Size is 1 after pop_back", "pop decrement");
        TEST_EQUAL(vec.back(), 100, "back() is now 100", "Updated back()");
        TEST_THROWS(vec.at(1), out_of_range, "at(1) after pop throws out_of_range", "Bounds verification");
    }

    // Condition 4: Generic type compatibility (CustomVector<string>)
    {
        CustomVector<string> svec;
        svec.push_back("CADT");
        svec.push_back("C++");
        svec.push_back("DSA");

        TEST_EQUAL(svec.size(), static_cast<size_t>(3), "String vector size is 3", "Template instantiation");
        TEST_EQUAL(svec[0], "CADT", "String element 0 matches", "Object storage");
        TEST_EQUAL(svec[1], "C++", "String element 1 matches", "Object storage");
        TEST_EQUAL(svec[2], "DSA", "String element 2 matches", "Object storage");
    }

    // Condition 5: Copy and Move semantics
    {
        CustomVector<int> v1;
        v1.push_back(1);
        v1.push_back(2);

        // Copy constructor
        CustomVector<int> v2 = v1;
        TEST_EQUAL(v2.size(), static_cast<size_t>(2), "v2 copied size is 2", "Deep copy");
        v2[0] = 999;
        TEST_EQUAL(v1[0], 1, "v1 unchanged when v2 is modified (deep copy confirmed)", "Deep copy independence");

        // Move constructor
        CustomVector<int> v3 = move(v2);
        TEST_EQUAL(v3.size(), static_cast<size_t>(2), "v3 size is 2 after move", "Move destination");
        TEST_EQUAL(v3[0], 999, "v3[0] holds moved value 999", "Resource transfer");
        TEST_EQUAL(v2.size(), static_cast<size_t>(0), "v2 size is 0 after move", "Move source reset");
    }

    TEST_REPORT();
}
