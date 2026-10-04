#pragma once
#include <string>
#include <cctype>

using namespace std;

// SOLUTION: String Manipulation & Palindrome Verification
inline bool isPalindrome(const string& s) {
    if (s.empty()) return true;
    int left = 0;
    int right = static_cast<int>(s.length()) - 1;

    while (left < right) {
        // Skip non-alphanumeric from left
        while (left < right && !isalnum(static_cast<unsigned char>(s[left]))) {
            left++;
        }
        // Skip non-alphanumeric from right
        while (left < right && !isalnum(static_cast<unsigned char>(s[right]))) {
            right--;
        }

        if (tolower(static_cast<unsigned char>(s[left])) != 
            tolower(static_cast<unsigned char>(s[right]))) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

inline int countVowels(const string& s) {
    int count = 0;
    for (char c : s) {
        char lower = tolower(static_cast<unsigned char>(c));
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
            count++;
        }
    }
    return count;
}

inline string removeSpaces(const string& s) {
    string result;
    for (char c : s) {
        if (c != ' ') {
            result.push_back(c);
        }
    }
    return result;
}
