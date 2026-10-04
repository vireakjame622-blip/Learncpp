#include "exercise.h"
#include "../../include/test_framework.hpp"

using namespace std;

int main() {
    TEST_SUITE("02_lru_cache (O(1) Eviction & Hash-Linked Synchronization)");

    // Condition 1: Capacity validation
    {
        TEST_THROWS(LRUCache(0), invalid_argument, "Capacity 0 throws invalid_argument", "Capacity > 0 guard");
        TEST_THROWS(LRUCache(-3), invalid_argument, "Negative capacity throws", "Capacity > 0 guard");
    }

    // Condition 2: Put and Get with Capacity 2
    {
        LRUCache cache(2);
        TEST_EQUAL(cache.size(), static_cast<size_t>(0), "Initial size is 0", "Empty check");
        TEST_EQUAL(cache.get(1), -1, "get(1) on empty returns -1", "Miss check");

        cache.put(1, 10);
        cache.put(2, 20);
        TEST_EQUAL(cache.size(), static_cast<size_t>(2), "Size is 2 after 2 puts", "Capacity tracking");
        TEST_EQUAL(cache.get(1), 10, "get(1) returns 10", "Hit check");
        TEST_EQUAL(cache.get(2), 20, "get(2) returns 20", "Hit check");
    }

    // Condition 3: Eviction of least recently used item
    {
        LRUCache cache(2);
        cache.put(1, 10); // Cache: [1]
        cache.put(2, 20); // Cache: [2, 1]
        
        // Access 1, making 1 MRU and 2 LRU
        TEST_EQUAL(cache.get(1), 10, "get(1) marks 1 as MRU", "MRU promotion"); // Cache: [1, 2]

        // Put 3 -> evicts 2 (LRU)
        cache.put(3, 30); // Cache: [3, 1], evicted 2
        TEST_EQUAL(cache.get(2), -1, "Key 2 was evicted (returns -1)", "LRU eviction check");
        TEST_EQUAL(cache.get(1), 10, "Key 1 is still present (returns 10)", "MRU retention check");
        TEST_EQUAL(cache.get(3), 30, "Key 3 is present (returns 30)", "New item check");
    }

    // Condition 4: Value update without eviction
    {
        LRUCache cache(2);
        cache.put(1, 10);
        cache.put(2, 20);
        cache.put(1, 99); // Update key 1 -> Cache: [1(99), 2]

        TEST_EQUAL(cache.size(), static_cast<size_t>(2), "Size remains 2 on update", "No size increase");
        TEST_EQUAL(cache.get(1), 99, "get(1) returns updated value 99", "Update check");

        // Put 4 -> should evict 2, NOT 1
        cache.put(4, 40);
        TEST_EQUAL(cache.get(2), -1, "Key 2 was evicted", "LRU check after update");
        TEST_EQUAL(cache.get(1), 99, "Key 1 is retained", "MRU check after update");
        TEST_EQUAL(cache.get(4), 40, "Key 4 is retained", "New item check");
    }

    TEST_REPORT();
}
