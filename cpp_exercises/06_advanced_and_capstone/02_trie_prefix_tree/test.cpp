#include "../../include/test_framework.hpp"
#include "exercise.h"
#include <string>

using namespace std;

int main() {
    TEST_SUITE("06_advanced_and_capstone • 02_trie_prefix_tree");

    // Test 1: Empty Trie queries
    {
        Trie trie;
        TEST_CONDITION(!trie.search("apple"), "Empty trie search returns false", "Word 'apple' should not be found");
        TEST_CONDITION(!trie.startsWith("app"), "Empty trie startsWith returns false", "Prefix 'app' should not match");
        TEST_EQUAL(trie.countWordsWithPrefix("a"), 0, "Empty trie prefix count is 0", "No words present");
    }

    // Test 2: Insertion and Exact Search
    {
        Trie trie;
        trie.insert("cadt");
        trie.insert("cpp");
        trie.insert("code");

        TEST_CONDITION(trie.search("cadt"), "Found 'cadt'", "Inserted word should exist");
        TEST_CONDITION(trie.search("cpp"), "Found 'cpp'", "Inserted word should exist");
        TEST_CONDITION(trie.search("code"), "Found 'code'", "Inserted word should exist");
        TEST_CONDITION(!trie.search("ca"), "'ca' is only a prefix, not a full word", "isEndOfWord check");
        TEST_CONDITION(!trie.search("coding"), "'coding' was not inserted", "Search mismatch check");
    }

    // Test 3: StartsWith Prefix Search
    {
        Trie trie;
        trie.insert("banana");
        trie.insert("band");
        trie.insert("bandage");

        TEST_CONDITION(trie.startsWith("ban"), "Prefix 'ban' matches", "Prefix match");
        TEST_CONDITION(trie.startsWith("band"), "Prefix 'band' matches", "Prefix match");
        TEST_CONDITION(trie.startsWith("bandage"), "Prefix 'bandage' matches", "Prefix match");
        TEST_CONDITION(!trie.startsWith("box"), "Prefix 'box' does not match", "Prefix mismatch");
    }

    // Test 4: Count Words With Prefix
    {
        Trie trie;
        trie.insert("app");
        trie.insert("apple");
        trie.insert("application");
        trie.insert("apply");
        trie.insert("ball");

        TEST_EQUAL(trie.countWordsWithPrefix("app"), 4, "Prefix 'app' matches 4 words", "Count words with prefix");
        TEST_EQUAL(trie.countWordsWithPrefix("appl"), 3, "Prefix 'appl' matches 3 words ('apple', 'application', 'apply')", "Count sub-prefix");
        TEST_EQUAL(trie.countWordsWithPrefix("apply"), 1, "Prefix 'apply' matches 1 word", "Count exact leaf prefix");
        TEST_EQUAL(trie.countWordsWithPrefix("b"), 1, "Prefix 'b' matches 1 word ('ball')", "Count prefix 'b'");
        TEST_EQUAL(trie.countWordsWithPrefix("cat"), 0, "Prefix 'cat' matches 0 words", "Non-existent prefix");
    }

    TEST_REPORT();
}
