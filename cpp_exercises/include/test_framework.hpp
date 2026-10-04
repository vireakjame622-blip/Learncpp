#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <exception>
#include <typeinfo>

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define byte win_byte_override
#include <windows.h>
#undef byte
#endif

namespace test_runner {

// Enable Windows console virtual terminal processing for ANSI colors
inline void enableAnsiColors() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode)) {
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
        }
    }
#endif
}

class TestSuite {
public:
    TestSuite(const std::string& suiteName) 
        : suite_name_(suiteName), passed_(0), failed_(0), total_(0) {
        enableAnsiColors();
        std::cout << "\n\033[1;36m=================================================================\033[0m\n";
        std::cout << "\033[1;37m[TEST SUITE] \033[1;33m" << suite_name_ << "\033[0m\n";
        std::cout << "\033[1;36m=================================================================\033[0m\n";
    }

    void checkCondition(bool condition, const std::string& conditionName, const std::string& hint = "") {
        total_++;
        if (condition) {
            passed_++;
            std::cout << "  \033[1;32m[PASS]\033[0m Condition " << total_ << ": " << conditionName << "\n";
        } else {
            failed_++;
            std::cout << "  \033[1;31m[FAIL]\033[0m Condition " << total_ << ": " << conditionName << "\n";
            if (!hint.empty()) {
                std::cout << "         \033[0;33mHint:\033[0m " << hint << "\n";
            }
        }
    }

    template <typename T, typename U>
    void checkEqual(const T& actual, const U& expected, const std::string& conditionName, const std::string& hint = "") {
        total_++;
        if (actual == expected) {
            passed_++;
            std::cout << "  \033[1;32m[PASS]\033[0m Condition " << total_ << ": " << conditionName << "\n";
        } else {
            failed_++;
            std::cout << "  \033[1;31m[FAIL]\033[0m Condition " << total_ << ": " << conditionName << "\n";
            std::cout << "         \033[0;31mExpected:\033[0m " << expected << "  |  \033[0;31mActual:\033[0m " << actual << "\n";
            if (!hint.empty()) {
                std::cout << "         \033[0;33mHint:\033[0m " << hint << "\n";
            }
        }
    }

    template <typename ExceptionType, typename Fn>
    void checkThrows(Fn&& fn, const std::string& conditionName, const std::string& hint = "") {
        total_++;
        bool threw_expected = false;
        bool threw_other = false;
        try {
            fn();
        } catch (const ExceptionType&) {
            threw_expected = true;
        } catch (...) {
            threw_other = true;
        }

        if (threw_expected) {
            passed_++;
            std::cout << "  \033[1;32m[PASS]\033[0m Condition " << total_ << ": " << conditionName << " (threw expected exception)\n";
        } else if (threw_other) {
            failed_++;
            std::cout << "  \033[1;31m[FAIL]\033[0m Condition " << total_ << ": " << conditionName << "\n";
            std::cout << "         \033[0;31mError:\033[0m Threw an unexpected exception type!\n";
            if (!hint.empty()) {
                std::cout << "         \033[0;33mHint:\033[0m " << hint << "\n";
            }
        } else {
            failed_++;
            std::cout << "  \033[1;31m[FAIL]\033[0m Condition " << total_ << ": " << conditionName << "\n";
            std::cout << "         \033[0;31mError:\033[0m Expected an exception to be thrown, but none occurred!\n";
            if (!hint.empty()) {
                std::cout << "         \033[0;33mHint:\033[0m " << hint << "\n";
            }
        }
    }

    template <typename Fn>
    void checkNoThrow(Fn&& fn, const std::string& conditionName, const std::string& hint = "") {
        total_++;
        bool threw = false;
        try {
            fn();
        } catch (...) {
            threw = true;
        }

        if (!threw) {
            passed_++;
            std::cout << "  \033[1;32m[PASS]\033[0m Condition " << total_ << ": " << conditionName << "\n";
        } else {
            failed_++;
            std::cout << "  \033[1;31m[FAIL]\033[0m Condition " << total_ << ": " << conditionName << "\n";
            std::cout << "         \033[0;31mError:\033[0m An unexpected exception was thrown!\n";
            if (!hint.empty()) {
                std::cout << "         \033[0;33mHint:\033[0m " << hint << "\n";
            }
        }
    }

    int report() const {
        std::cout << "\033[1;36m-----------------------------------------------------------------\033[0m\n";
        if (failed_ == 0 && total_ > 0) {
            std::cout << "\033[1;32m[RESULT] " << suite_name_ << ": ALL " << total_ << " CONDITIONS PASSED! \033[0m(100%)\n";
            std::cout << "\033[1;36m=================================================================\033[0m\n\n";
            return 0;
        } else {
            std::cout << "\033[1;31m[RESULT] " << suite_name_ << ": " << passed_ << " / " << total_ 
                      << " passed (" << failed_ << " failed)\033[0m\n";
            std::cout << "\033[1;33mDon't worry! Read the hints above, update your exercise.h, and re-run.\033[0m\n";
            std::cout << "\033[1;36m=================================================================\033[0m\n\n";
            return 1;
        }
    }

private:
    std::string suite_name_;
    int passed_;
    int failed_;
    int total_;
};

} // namespace test_runner

#define TEST_SUITE(name) test_runner::TestSuite suite(name)
#define TEST_CONDITION(cond, name, hint) suite.checkCondition((cond), (name), (hint))
#define TEST_EQUAL(act, exp, name, hint) suite.checkEqual((act), (exp), (name), (hint))
#define TEST_THROWS(expr, ExType, name, hint) suite.checkThrows<ExType>([&](){ expr; }, (name), (hint))
#define TEST_NO_THROW(expr, name, hint) suite.checkNoThrow([&](){ expr; }, (name), (hint))
#define TEST_REPORT() return suite.report()
