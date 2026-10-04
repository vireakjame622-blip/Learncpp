#pragma once
#include <string>
#include <cctype>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 04_string_palindrome
//    OR:
//    .\run_tests.bat 04_string_palindrome
// ============================================================================

// EXERCISE 1.4: String Manipulation & Palindrome Verification
// C++ Foundations - Strings
//
// TASKS:
// 1. isPalindrome(const string& s):
//    - Returns true if s reads the same forward and backwards.
//    - MUST BE CASE-INSENSITIVE (e.g. 'A' == 'a').
//    - MUST IGNORE NON-ALPHANUMERIC CHARACTERS (spaces, punctuation: commas, periods, colons).
//    - Example: "RaceCar" -> true
//    - Example: "A man, a plan, a canal: Panama!" -> true
//    - Example: "hello" -> false
//    - Hint: Filter alphanumeric chars (isalnum) and convert to lowercase (tolower),
//      or use two pointers skipping non-alphanumeric chars.
//
// 2. countVowels(const string& s):
//    - Returns count of vowels ('a', 'e', 'i', 'o', 'u' / 'A', 'E', 'I', 'O', 'U').
//
// 3. removeSpaces(const string& s):
//    - Returns a new string with all space characters ' ' removed.

inline bool isPalindrome(const string& s) {
    // TODO: implement
    (void)s;
    return false;
}

inline int countVowels(const string& s) {
    // TODO: implement
    (void)s;
    return 0;
}

inline string removeSpaces(const string& s) {
    // TODO: implement
    (void)s;
    return "";
}
