#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Verified Solution for Exercise 1.1: Levels 1 - 4

// LEVEL 1: WARMUP
inline bool isEven(int score) {
    return score % 2 == 0;
}

inline int getMaxScore(int scoreA, int scoreB) {
    return (scoreA > scoreB) ? scoreA : scoreB;
}

// LEVEL 2: FOUNDATION
inline char classifyGrade(int score) {
    if (score < 0 || score > 100) {
        throw invalid_argument("Score out of range");
    }
    if (score >= 90) return 'A';
    if (score >= 80) return 'B';
    if (score >= 70) return 'C';
    if (score >= 60) return 'D';
    return 'F';
}

inline bool isPassing(int score) {
    if (score < 0 || score > 100) {
        throw invalid_argument("Score out of range");
    }
    return score >= 60;
}

// LEVEL 3: INTERMEDIATE
inline double getGradePoints(char letterGrade) {
    if (letterGrade == 'A' || letterGrade == 'a') return 4.0;
    if (letterGrade == 'B' || letterGrade == 'b') return 3.0;
    if (letterGrade == 'C' || letterGrade == 'c') return 2.0;
    if (letterGrade == 'D' || letterGrade == 'd') return 1.0;
    if (letterGrade == 'F' || letterGrade == 'f') return 0.0;
    throw invalid_argument("Invalid letter grade");
}

// LEVEL 4: DEEP THINKING
inline string evaluateScholarship(int score, double attendancePercent, bool hasDisciplinaryWarning) {
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
