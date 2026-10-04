#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <string>

using namespace std;

int main() {
    TEST_SUITE("04_string_palindrome (Strings, Vowels & Two-Pointer Palindromes)");

    // Condition 1: Basic palindromes
    TEST_CONDITION(isPalindrome("") == true, "Empty string is a palindrome", "Trivially reads the same");
    TEST_CONDITION(isPalindrome("a") == true, "Single character 'a' is a palindrome", "Single character");
    TEST_CONDITION(isPalindrome("radar") == true, "'radar' is a palindrome", "Simple all-lowercase");
    TEST_CONDITION(isPalindrome("noon") == true, "'noon' is a palindrome (even length)", "Even length");

    // Condition 2: Case insensitivity
    TEST_CONDITION(isPalindrome("RaceCar") == true, "'RaceCar' is a palindrome (case-insensitive)", "Use tolower() when comparing characters");
    TEST_CONDITION(isPalindrome("Madam") == true, "'Madam' is a palindrome", "Case insensitive check");

    // Condition 3: Sentence with spaces and punctuation
    TEST_CONDITION(isPalindrome("A man, a plan, a canal: Panama!") == true, "Classic Panama palindrome with spaces/punctuation", "Skip isalnum() false characters");
    TEST_CONDITION(isPalindrome("Was it a car or a cat I saw?") == true, "Question mark palindrome", "Ignore spaces and '?'");

    // Condition 4: Non-palindromes
    TEST_CONDITION(isPalindrome("hello") == false, "'hello' is NOT a palindrome", "Should return false");
    TEST_CONDITION(isPalindrome("0P") == false, "'0P' is NOT a palindrome", "Should return false");

    // Condition 5: countVowels
    TEST_EQUAL(countVowels(""), 0, "countVowels empty string", "0 vowels");
    TEST_EQUAL(countVowels("rhythm"), 0, "countVowels with no vowels", "rhythm has 0 vowels");
    TEST_EQUAL(countVowels("AEIOUaeiou"), 10, "countVowels all vowels upper and lower", "10 vowels");
    TEST_EQUAL(countVowels("C++ Programming at CADT!"), 5, "countVowels mixed sentence", "o, a, i, a, A = 5 vowels");

    // Condition 6: removeSpaces
    TEST_EQUAL(removeSpaces("C + +  is  fun"), string("C++isfun"), "removeSpaces removes all spaces", "Check space filtering");

    TEST_REPORT();
}
