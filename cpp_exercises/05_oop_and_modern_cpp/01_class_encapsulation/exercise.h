#pragma once
#include <string>
#include <stdexcept>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 01_class_encapsulation
//    OR:
//    .\run_tests.bat 01_class_encapsulation
// ============================================================================

// EXERCISE 5.1: Class Encapsulation & Const Correctness
// CADT Advanced Algorithm & C++ • Object-Oriented Programming
//
// TASK:
// Build a robust StudentRecord class adhering to strict OOP principles:
// 1. Private fields: id_ (int), name_ (string), gpa_ (double), credits_ (int).
// 2. Parameterized constructor: StudentRecord(int id, const string& name, double gpa, int credits)
//    - Validate: id > 0 (throw invalid_argument if id <= 0)
//    - Validate: 0.0 <= gpa <= 4.0 (throw invalid_argument if outside)
//    - Validate: credits >= 0 (throw invalid_argument if negative)
// 3. Const Getters: getId(), getName(), getGpa(), getCredits().
// 4. Setters with validation:
//    - setGpa(double newGpa): validates range [0.0, 4.0].
//    - addCredits(int additional): must be >= 0, adds to credits_.
// 5. Query method: isHonorRoll() const: returns true if gpa >= 3.5 and credits >= 12.

class StudentRecord {
public:
    StudentRecord(int id, const string& name, double gpa, int credits)
        : id_(id), name_(name), gpa_(gpa), credits_(credits) {
        // TODO: Validate id, gpa, and credits. Throw invalid_argument if invalid.
    }

    // TODO: Implement const getters:
    int getId() const { return id_; }
    const string& getName() const { return name_; }
    double getGpa() const { return gpa_; }
    int getCredits() const { return credits_; }

    void setGpa(double newGpa) {
        // TODO: Validate newGpa in [0.0, 4.0], throw invalid_argument if invalid.
        // Update gpa_.
        (void)newGpa;
    }

    void addCredits(int additional) {
        // TODO: Validate additional >= 0, throw invalid_argument if negative.
        // Add to credits_.
        (void)additional;
    }

    bool isHonorRoll() const {
        // TODO: Return true if gpa_ >= 3.5 and credits_ >= 12.
        return false;
    }

private:
    int id_{0};
    string name_;
    double gpa_{0.0};
    int credits_{0};
};
