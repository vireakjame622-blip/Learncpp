#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <stdexcept>

using namespace std;

int main() {
    TEST_SUITE("01_class_encapsulation (Constructors, Validation & Invariants)");

    // Condition 1: Valid construction & const getters
    {
        const StudentRecord s(101, "Sokha", 3.8, 15);
        TEST_EQUAL(s.getId(), 101, "getId() returns 101", "Check constructor initialization");
        TEST_EQUAL(s.getName(), "Sokha", "getName() returns Sokha", "Check name initialization");
        TEST_EQUAL(s.getGpa(), 3.8, "getGpa() returns 3.8", "Check gpa initialization");
        TEST_EQUAL(s.getCredits(), 15, "getCredits() returns 15", "Check credits initialization");
        TEST_CONDITION(s.isHonorRoll() == true, "3.8 GPA and 15 credits is Honor Roll", "GPA >= 3.5 && credits >= 12");
    }

    // Condition 2: Constructor validation exceptions
    {
        TEST_THROWS(StudentRecord(0, "Invalid", 3.0, 10), invalid_argument, "ID <= 0 throws invalid_argument", "id > 0 guard");
        TEST_THROWS(StudentRecord(-5, "Invalid", 3.0, 10), invalid_argument, "Negative ID throws invalid_argument", "id > 0 guard");
        TEST_THROWS(StudentRecord(1, "Invalid", -0.1, 10), invalid_argument, "GPA < 0.0 throws invalid_argument", "GPA range check");
        TEST_THROWS(StudentRecord(1, "Invalid", 4.01, 10), invalid_argument, "GPA > 4.0 throws invalid_argument", "GPA range check");
        TEST_THROWS(StudentRecord(1, "Invalid", 3.0, -1), invalid_argument, "Negative credits throws invalid_argument", "Credits >= 0 guard");
    }

    // Condition 3: Setters and boundary updates
    {
        StudentRecord s(102, "Dara", 3.2, 8);
        TEST_CONDITION(s.isHonorRoll() == false, "Initial state (3.2 GPA, 8 credits) not honor roll", "Check honor roll thresholds");

        s.setGpa(3.9);
        TEST_EQUAL(s.getGpa(), 3.9, "GPA updated to 3.9", "Setter check");
        TEST_CONDITION(s.isHonorRoll() == false, "3.9 GPA with only 8 credits is still not honor roll", "Credits must be >= 12");

        s.addCredits(6);
        TEST_EQUAL(s.getCredits(), 14, "Credits updated to 14 (8 + 6)", "addCredits accumulator");
        TEST_CONDITION(s.isHonorRoll() == true, "3.9 GPA with 14 credits is now Honor Roll", "Both conditions met");

        TEST_THROWS(s.setGpa(4.5), invalid_argument, "Setting GPA to 4.5 throws", "Validate in setter");
        TEST_THROWS(s.addCredits(-2), invalid_argument, "Adding negative credits throws", "Validate in addCredits");
    }

    TEST_REPORT();
}
