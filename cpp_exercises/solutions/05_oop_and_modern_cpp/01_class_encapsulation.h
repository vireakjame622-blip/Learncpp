#pragma once
#include <string>
#include <stdexcept>

using namespace std;

// Verified Solution for Exercise 5.1: Class Encapsulation
class StudentRecord {
public:
    StudentRecord(int id, const string& name, double gpa, int credits)
        : id_(id), name_(name), gpa_(gpa), credits_(credits) {
        if (id <= 0) throw invalid_argument("ID must be positive");
        if (gpa < 0.0 || gpa > 4.0) throw invalid_argument("GPA must be between 0.0 and 4.0");
        if (credits < 0) throw invalid_argument("Credits cannot be negative");
    }

    int getId() const { return id_; }
    const string& getName() const { return name_; }
    double getGpa() const { return gpa_; }
    int getCredits() const { return credits_; }

    void setGpa(double newGpa) {
        if (newGpa < 0.0 || newGpa > 4.0) throw invalid_argument("GPA must be between 0.0 and 4.0");
        gpa_ = newGpa;
    }

    void addCredits(int additional) {
        if (additional < 0) throw invalid_argument("Additional credits cannot be negative");
        credits_ += additional;
    }

    bool isHonorRoll() const {
        return gpa_ >= 3.5 && credits_ >= 12;
    }

private:
    int id_;
    string name_;
    double gpa_;
    int credits_;
};
