#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 01_grade_classifier
//    OR:
//    .\run_tests.bat 01_grade_classifier
// ============================================================================
//
// EXERCISE 1.1: Progressive Decision Logic (Easy to Deep Thinking)
// CADT Lab Session 01 • Step-by-Step Mastery

// ----------------------------------------------------------------------------
// 🟢 LEVEL 1: SUPER EASY WARMUP (Basic Comparisons)
// ----------------------------------------------------------------------------

// Task 1.1: Return true if score is an even number, false if odd
inline bool isEven(int score) {
    // TODO (Warmup): Use the modulo operator (%)
    // If score % 2 == 0, it is even.
    (void)score;
    return (score % 2 == 0);
}   

// Task 1.2: Return the larger of two scores
inline int getMaxScore(int scoreA, int scoreB) {
    // TODO (Warmup): Compare scoreA and scoreB using if / else
    (void)scoreA; (void)scoreB;
    if (scoreA > scoreB) {
        return scoreA;
    } else {
        return scoreB;
    }
    return 0;
}

// ----------------------------------------------------------------------------
// 🟡 LEVEL 2: FOUNDATION (If-Else Ladder & Error Guards) - [YOU COMPLETED THIS!]
// ----------------------------------------------------------------------------

// Task 2.1: Map score 0-100 to letter grade
inline char classifyGrade(int score) {
    if (score < 0 || score > 100) {
        throw invalid_argument("Score out of range");
    }

    if (score >= 90) {
        return 'A';
    } else if (score >= 80) {
        return 'B';
    } else if (score >= 70) {
        return 'C';
    } else if (score >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

// Task 2.2: Check if score is passing (>= 60)
inline bool isPassing(int score) {
    if (score < 0 || score > 100) {
        throw invalid_argument("Score out of range");
    }
    return score >= 60;
}

// ----------------------------------------------------------------------------
// 🟠 LEVEL 3: INTERMEDIATE (Multi-Value Branching & Switch/If)
// ----------------------------------------------------------------------------

// Task 3.1: Convert letter grade ('A'-'F' or 'a'-'f') to GPA points (4.0 - 0.0)
//   'A' or 'a' -> 4.0
//   'B' or 'b' -> 3.0
//   'C' or 'c' -> 2.0
//   'D' or 'd' -> 1.0
//   'F' or 'f' -> 0.0
//   Any other character -> throw invalid_argument("Invalid letter grade")
inline double getGradePoints(char letterGrade) {
    // TODO (Intermediate): Support both uppercase and lowercase letters.
    // If letter is invalid (e.g. 'Z', 'X', '?'), throw invalid_argument.
    (void)letterGrade;
    switch (letterGrade) {
        case 'A':
        case 'a':
            return 4.0;
        case 'B':
        case 'b':
            return 3.0;
        case 'C':
        case 'c':
            return 2.0;
        case 'D':
        case 'd':
            return 1.0;
        case 'F':
        case 'f':
            return 0.0;
        default:
            throw invalid_argument("Invalid letter grade");
    }
}

// ----------------------------------------------------------------------------
// 🔴 LEVEL 4: DEEP THINKING (Compound Boolean Operators &&, ||, !)
// ----------------------------------------------------------------------------

// Task 4.1: Multi-criteria scholarship eligibility
// Rules:
// 1. Validation: if score not in [0, 100] or attendancePercent not in [0.0, 100.0],
//    throw invalid_argument("Input out of range")
// 2. Disciplinary: if hasDisciplinaryWarning is true -> return "No Scholarship"
// 3. Honors:
//    - score >= 90 AND attendancePercent >= 90.0 -> return "Full Scholarship"
//    - score >= 80 AND attendancePercent >= 80.0 -> return "Half Scholarship"
//    - score < 60 OR attendancePercent < 70.0   -> return "Academic Probation"
//    - Otherwise                                -> return "Standard"
inline string evaluateScholarship(int score, double attendancePercent, bool hasDisciplinaryWarning) {
    // TODO (Deep Thinking): Follow the 4 rules in order!
    (void)score; (void)attendancePercent; (void)hasDisciplinaryWarning;
    if (score < 0 || score > 100 || attendancePercent < 0.0 || attendancePercent > 100.0) {
        throw invalid_argument("Input out of range");
    }
    if (hasDisciplinaryWarning) {
        return "No Scholarship";
    }
    if (score >= 90 && attendancePercent >= 90.0) {
        return "Full Scholarship";
    }
    if (score >= 80 && attendancePercent >= 80.0) {
        return "Half Scholarship";
    }           
    if (score < 60 || attendancePercent < 70.0) {
        return "Academic Probation";
    }
    return "Standard";  
}
