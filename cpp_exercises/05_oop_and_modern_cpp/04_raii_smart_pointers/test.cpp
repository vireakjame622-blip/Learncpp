#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <string>

using namespace std;

// Test tracker struct for RAII lifecycle verification
struct Tracker {
    static int live_instances;
    int id;
    string text;

    Tracker(int i, string s) : id(i), text(s) { live_instances++; }
    ~Tracker() { live_instances--; }
};
int Tracker::live_instances = 0;

int main() {
    TEST_SUITE("04_raii_smart_pointers (Move Semantics & Ownership Invariants)");

    // Condition 1: Basic lifecycle and destructor RAII
    {
        TEST_EQUAL(Tracker::live_instances, 0, "Initial live instances is 0", "Static counter check");
        {
            UniquePointer<Tracker> ptr(new Tracker(1, "Alpha"));
            TEST_EQUAL(Tracker::live_instances, 1, "Instance count is 1 inside scope", "Constructor increment");
            TEST_EQUAL(ptr->id, 1, "Arrow operator access ptr->id is 1", "operator->");
            TEST_EQUAL((*ptr).text, "Alpha", "Dereference (*ptr).text is Alpha", "operator*");
            TEST_CONDITION(static_cast<bool>(ptr) == true, "bool conversion is true for non-null", "operator bool");
        }
        // Scope exited: destructor should run automatically
        TEST_EQUAL(Tracker::live_instances, 0, "Destructor called upon scope exit (no leaks!)", "RAII verification");
    }

    // Condition 2: Move semantics (transfer of ownership)
    {
        UniquePointer<Tracker> p1(new Tracker(2, "Beta"));
        TEST_EQUAL(Tracker::live_instances, 1, "Instance created", "Count is 1");

        // Move constructor
        UniquePointer<Tracker> p2(move(p1));
        TEST_CONDITION(p1.get() == nullptr, "p1 is now nullptr after move", "Move source reset");
        TEST_CONDITION(static_cast<bool>(p1) == false, "p1 evaluates to false", "bool check on moved-from");
        TEST_CONDITION(p2.get() != nullptr, "p2 holds the resource", "Move destination acquired");
        TEST_EQUAL(p2->id, 2, "p2->id is 2", "Resource intact");
        TEST_EQUAL(Tracker::live_instances, 1, "Still exactly 1 instance alive during move", "No extra allocations");

        // Move assignment
        UniquePointer<Tracker> p3;
        p3 = move(p2);
        TEST_CONDITION(p2.get() == nullptr, "p2 is nullptr after move assignment", "Move assignment reset");
        TEST_EQUAL(p3->id, 2, "p3 holds resource", "Move assignment value");
    }
    TEST_EQUAL(Tracker::live_instances, 0, "All moved instances destroyed upon scope exit", "Final cleanup check");

    // Condition 3: release() and reset()
    {
        UniquePointer<Tracker> ptr(new Tracker(3, "Gamma"));
        Tracker* raw = ptr.release();
        TEST_CONDITION(ptr.get() == nullptr, "ptr.get() is null after release", "release() relinquishes ownership");
        TEST_EQUAL(Tracker::live_instances, 1, "Object still alive after release", "Must not delete on release");

        ptr.reset(raw); // re-adopt ownership
        TEST_CONDITION(ptr.get() == raw, "ptr re-adopted raw pointer", "reset() takes new pointer");

        ptr.reset(new Tracker(4, "Delta")); // deletes Gamma (id:3) and owns Delta (id:4)
        TEST_EQUAL(Tracker::live_instances, 1, "Old object deleted on reset, new one retained", "reset replacement");
        TEST_EQUAL(ptr->id, 4, "Current object is id 4", "Reset value check");

        ptr.reset(); // deletes Delta
        TEST_EQUAL(Tracker::live_instances, 0, "ptr.reset() deletes owned object", "Null reset deletes");
    }

    TEST_REPORT();
}
