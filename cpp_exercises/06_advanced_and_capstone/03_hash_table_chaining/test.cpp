#include "../../include/test_framework.hpp"
#include "exercise.h"
#include <string>

using namespace std;

int main() {
    TEST_SUITE("06_advanced_and_capstone • 03_hash_table_chaining");

    // Test 1: Empty Hash Table Invariants
    {
        StringHashTable ht(7);
        TEST_CONDITION(ht.empty(), "New hash table is empty", "Initial empty state");
        TEST_EQUAL(ht.size(), static_cast<size_t>(0), "Initial size is 0", "Empty size");
        TEST_EQUAL(ht.bucketCount(), static_cast<size_t>(7), "Bucket count is 7", "Capacity matches argument");
        TEST_CONDITION(!ht.contains("apple"), "contains() returns false on empty table", "Empty lookup");
        TEST_THROWS(ht.get("apple"), out_of_range, "get() on empty table throws out_of_range", "Throw out_of_range on missing key");
    }

    // Test 2: Insertion and Lookup
    {
        StringHashTable ht(5);
        ht.insert("cadt", 100);
        ht.insert("cs", 95);
        ht.insert("telecom", 90);

        TEST_EQUAL(ht.size(), static_cast<size_t>(3), "Size is 3 after 3 insertions", "Check size");
        TEST_CONDITION(!ht.empty(), "Table is no longer empty", "empty check");
        TEST_CONDITION(ht.contains("cadt"), "Contains 'cadt'", "contains check");
        TEST_CONDITION(ht.contains("cs"), "Contains 'cs'", "contains check");
        TEST_CONDITION(!ht.contains("unknown"), "Does not contain 'unknown'", "missing key check");

        TEST_EQUAL(ht.get("cadt"), 100, "Value for 'cadt' is 100", "Value retrieval");
        TEST_EQUAL(ht.get("cs"), 95, "Value for 'cs' is 95", "Value retrieval");
        TEST_EQUAL(ht.get("telecom"), 90, "Value for 'telecom' is 90", "Value retrieval");
    }

    // Test 3: Value Updates for Existing Keys (No Duplicate Nodes)
    {
        StringHashTable ht(5);
        ht.insert("score", 50);
        TEST_EQUAL(ht.get("score"), 50, "Initial score is 50", "Initial value");

        ht.insert("score", 99);
        TEST_EQUAL(ht.get("score"), 99, "Updated score is 99", "Overwritten value");
        TEST_EQUAL(ht.size(), static_cast<size_t>(1), "Size remains 1 after update", "No duplicate key created");
    }

    // Test 4: Removal and Collision Handling
    {
        StringHashTable ht(3); // Small bucket count forces collisions!
        ht.insert("alpha", 1);
        ht.insert("beta", 2);
        ht.insert("gamma", 3);
        ht.insert("delta", 4);

        TEST_EQUAL(ht.size(), static_cast<size_t>(4), "4 items inserted across 3 buckets", "Collision insertion");
        TEST_CONDITION(ht.loadFactor() > 1.0, "Load factor > 1.0 indicates collisions handled", "Load factor calculation");

        // Remove non-existent key
        TEST_CONDITION(!ht.remove("zeta"), "Removing non-existent key returns false", "Missing removal");

        // Remove existing key
        TEST_CONDITION(ht.remove("beta"), "Removing 'beta' returns true", "Successful removal");
        TEST_EQUAL(ht.size(), static_cast<size_t>(3), "Size decreased to 3", "Size after remove");
        TEST_CONDITION(!ht.contains("beta"), "'beta' no longer in table", "Key erased");
        TEST_THROWS(ht.get("beta"), out_of_range, "get('beta') throws out_of_range after removal", "Missing key throws exception");

        // Confirm other collision entries still intact
        TEST_EQUAL(ht.get("alpha"), 1, "'alpha' still intact in bucket", "Chain integrity");
        TEST_EQUAL(ht.get("gamma"), 3, "'gamma' still intact in bucket", "Chain integrity");
        TEST_EQUAL(ht.get("delta"), 4, "'delta' still intact in bucket", "Chain integrity");
    }

    TEST_REPORT();
}
