#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <stdexcept>

using namespace std;

int main() {
    TEST_SUITE("01_grade_classifier (Progressive Decision Logic: Levels 1 - 4)");

    // =========================================================================
    // 🟢 LEVEL 1: SUPER EASY WARMUP
    // =========================================================================
    {
        TEST_CONDITION(isEven(10) == true, "Level 1: isEven(10) is true", "10 is even");
        TEST_CONDITION(isEven(7) == false, "Level 1: isEven(7) is false", "7 is odd");
        TEST_CONDITION(isEven(0) == true, "Level 1: isEven(0) is true", "0 is even");

        TEST_EQUAL(getMaxScore(85, 92), 92, "Level 1: getMaxScore(85, 92) is 92", "92 is larger");
        TEST_EQUAL(getMaxScore(100, 50), 100, "Level 1: getMaxScore(100, 50) is 100", "100 is larger");
        TEST_EQUAL(getMaxScore(70, 70), 70, "Level 1: getMaxScore(70, 70) is 70", "Equal scores");
    }

    // =========================================================================
    // 🟡 LEVEL 2: FOUNDATION (If-Else Ladder & Exceptions)
    // =========================================================================
    {
        TEST_EQUAL(classifyGrade(100), 'A', "Level 2: Score 100 should return 'A'", "Check upper bound of 'A'");
        TEST_EQUAL(classifyGrade(95), 'A', "Level 2: Score 95 should return 'A'", "Check standard 'A'");
        TEST_EQUAL(classifyGrade(90), 'A', "Level 2: Boundary 90 should be 'A'", "90 is lower bound for 'A'");
        TEST_EQUAL(classifyGrade(89), 'B', "Level 2: Boundary 89 should be 'B'", "89 is upper bound for 'B'");
        TEST_EQUAL(classifyGrade(80), 'B', "Level 2: Boundary 80 should be 'B'", "80 is lower bound for 'B'");
        TEST_EQUAL(classifyGrade(79), 'C', "Level 2: Boundary 79 should be 'C'", "79 is upper bound for 'C'");
        TEST_EQUAL(classifyGrade(70), 'C', "Level 2: Boundary 70 should be 'C'", "70 is lower bound for 'C'");
        TEST_EQUAL(classifyGrade(69), 'D', "Level 2: Boundary 69 should be 'D'", "69 is upper bound for 'D'");
        TEST_EQUAL(classifyGrade(60), 'D', "Level 2: Boundary 60 should be 'D'", "60 is lower bound for 'D'");
        TEST_EQUAL(classifyGrade(59), 'F', "Level 2: Boundary 59 should be 'F'", "59 is failing");
        TEST_EQUAL(classifyGrade(0), 'F', "Level 2: Boundary 0 should be 'F'", "0 is failing");
        TEST_THROWS(classifyGrade(-1), invalid_argument, "Level 2: Negative score (-1) throws invalid_argument", "Out of range check");
        TEST_THROWS(classifyGrade(101), invalid_argument, "Level 2: Score 101 throws invalid_argument", "Out of range check");

        TEST_CONDITION(isPassing(100) == true, "Level 2: isPassing(100) is true", "100 is passing");
        TEST_CONDITION(isPassing(60) == true, "Level 2: isPassing(60) is true (boundary)", "60 is passing");
        TEST_CONDITION(isPassing(59) == false, "Level 2: isPassing(59) is false (boundary)", "59 is failing");
        TEST_CONDITION(isPassing(0) == false, "Level 2: isPassing(0) is false", "0 is failing");
        TEST_THROWS(isPassing(-10), invalid_argument, "Level 2: isPassing(-10) throws invalid_argument", "Validate score range");
    }

    // =========================================================================
    // 🟠 LEVEL 3: INTERMEDIATE (Grade to Points Mapping)
    // =========================================================================
    {
        TEST_CONDITION(getGradePoints('A') == 4.0, "Level 3: getGradePoints('A') is 4.0", "A gives 4.0 GPA");
        TEST_CONDITION(getGradePoints('a') == 4.0, "Level 3: getGradePoints('a') is 4.0 (lowercase)", "Support lowercase");
        TEST_CONDITION(getGradePoints('B') == 3.0, "Level 3: getGradePoints('B') is 3.0", "B gives 3.0 GPA");
        TEST_CONDITION(getGradePoints('C') == 2.0, "Level 3: getGradePoints('C') is 2.0", "C gives 2.0 GPA");
        TEST_CONDITION(getGradePoints('D') == 1.0, "Level 3: getGradePoints('D') is 1.0", "D gives 1.0 GPA");
        TEST_CONDITION(getGradePoints('F') == 0.0, "Level 3: getGradePoints('F') is 0.0", "F gives 0.0 GPA");
        TEST_THROWS(getGradePoints('Z'), invalid_argument, "Level 3: Invalid grade 'Z' throws invalid_argument", "Reject unknown letter");
    }

    // =========================================================================
    // 🔴 LEVEL 4: DEEP THINKING (Compound Boolean Decisions)
    // =========================================================================
    {
        TEST_EQUAL(evaluateScholarship(95, 95.0, false), "Full Scholarship", "Level 4: Score 95, Att 95% -> Full Scholarship", "Both criteria met");
        TEST_EQUAL(evaluateScholarship(85, 82.0, false), "Half Scholarship", "Level 4: Score 85, Att 82% -> Half Scholarship", "Both >= 80%");
        TEST_EQUAL(evaluateScholarship(95, 95.0, true), "No Scholarship", "Level 4: Disciplinary warning overrides high grades", "Disciplinary disqualification");
        TEST_EQUAL(evaluateScholarship(50, 95.0, false), "Academic Probation", "Level 4: Low score (<60) -> Academic Probation", "Score below 60");
        TEST_EQUAL(evaluateScholarship(75, 65.0, false), "Academic Probation", "Level 4: Low attendance (<70%) -> Academic Probation", "Attendance below 70%");
        TEST_EQUAL(evaluateScholarship(75, 75.0, false), "Standard", "Level 4: Passing student with normal attendance -> Standard", "Normal standing");
        TEST_THROWS(evaluateScholarship(-1, 80.0, false), invalid_argument, "Level 4: Negative score throws invalid_argument", "Validate range");
        TEST_THROWS(evaluateScholarship(80, 105.0, false), invalid_argument, "Level 4: Attendance > 100% throws invalid_argument", "Validate range");
    }

    TEST_REPORT();
}
