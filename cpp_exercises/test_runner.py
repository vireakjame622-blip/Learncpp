#!/usr/bin/env python3
"""
C++ Exercise Test Runner & Compiler Harness
Designed for CADT PREPARE-Y2 C++ & DSA Course

Features:
- Compiles with g++ -std=c++17 -Wall -Wextra
- Protects against infinite loops with execution timeouts (5s)
- Analyzes compiler errors with beginner-friendly hints
- Evaluates every test condition and prints color-coded feedback
- Cleans up generated binaries automatically
- Supports running individual exercises, modules, or all tests
"""

import sys
import os
import subprocess
from pathlib import Path

# Fix Windows console UTF-8 output encoding safely
if hasattr(sys.stdout, 'reconfigure'):
    sys.stdout.reconfigure(encoding='utf-8', errors='replace')
if hasattr(sys.stderr, 'reconfigure'):
    sys.stderr.reconfigure(encoding='utf-8', errors='replace')

# Enable ANSI colors on Windows console
os.system('')

COLOR_RESET = "\033[0m"
COLOR_CYAN = "\033[1;36m"
COLOR_GREEN = "\033[1;32m"
COLOR_RED = "\033[1;31m"
COLOR_YELLOW = "\033[1;33m"
COLOR_WHITE = "\033[1;37m"
COLOR_GRAY = "\033[0;90m"

SCRIPT_DIR = Path(__file__).resolve().parent
INCLUDE_DIR = SCRIPT_DIR / "include"

def print_banner():
    print(f"{COLOR_CYAN}================================================================={COLOR_RESET}")
    print(f"{COLOR_WHITE}   CADT C++ & DSA Learning Suite — Test Runner & Compiler        {COLOR_RESET}")
    print(f"{COLOR_CYAN}================================================================={COLOR_RESET}")

def find_exercises():
    exercises = []
    for p in sorted(SCRIPT_DIR.rglob("test.cpp")):
        rel = p.parent.relative_to(SCRIPT_DIR)
        parts = rel.parts
        if "include" in parts or "temp" in parts or "solutions" in parts:
            continue
        exercises.append(p.parent)
    return exercises

def analyze_compile_error(stderr_text):
    hints = []
    if "was not declared in this scope" in stderr_text:
        hints.append("Check spelling of variable/function names or make sure required headers are included.")
    if "expected ';' before" in stderr_text:
        hints.append("Missing semicolon ';' at the end of a previous statement.")
    if "control reaches end of non-void function" in stderr_text:
        hints.append("Function is missing a 'return' statement in one or more code branches.")
    if "cannot convert" in stderr_text:
        hints.append("Type mismatch: you might be assigning incompatible data types (e.g. pointer to int or double to pointer).")
    if "no matching function for call" in stderr_text:
        hints.append("Function call arguments don't match the parameters defined in the function.")
    if "undefined reference to" in stderr_text:
        hints.append("Linker error: function was declared but not defined, or file was not included.")
    return hints

def run_single_exercise(ex_dir, use_solution=False):
    ex_path = Path(ex_dir)
    rel_name = ex_path.relative_to(SCRIPT_DIR)
    test_src = ex_path / "test.cpp"
    bin_name = ex_path / ("test_bin.exe" if os.name == "nt" else "test_bin")
    temp_sol_dir = None

    print(f"\n{COLOR_CYAN}-----------------------------------------------------------------{COLOR_RESET}")
    sol_tag = f" {COLOR_GREEN}[TESTING REFERENCE SOLUTION]{COLOR_RESET}" if use_solution else ""
    print(f"{COLOR_WHITE}Running: {COLOR_YELLOW}{rel_name}{COLOR_RESET}{sol_tag}")
    print(f"{COLOR_CYAN}-----------------------------------------------------------------{COLOR_RESET}")

    if not test_src.exists():
        print(f"{COLOR_RED}[ERROR]{COLOR_RESET} test.cpp not found in {rel_name}")
        return False

    backup_file = None
    if use_solution:
        parts = rel_name.parts
        if len(parts) >= 2:
            sol_file = SCRIPT_DIR / "solutions" / parts[0] / f"{parts[1]}.h"
            orig_ex = ex_path / "exercise.h"
            if sol_file.exists() and orig_ex.exists():
                backup_file = ex_path / "exercise.h.runner_bak"
                try:
                    orig_ex.rename(backup_file)
                    orig_ex.write_text(sol_file.read_text(encoding="utf-8"), encoding="utf-8")
                except Exception as e:
                    print(f"{COLOR_YELLOW}[WARNING]{COLOR_RESET} Failed to swap solution: {e}")
                    backup_file = None
            else:
                print(f"{COLOR_YELLOW}[WARNING]{COLOR_RESET} Solution {sol_file.name} not found.")

    # 1. Compile with g++
    compile_cmd = [
        "g++",
        "-std=c++17",
        "-Wall",
        "-Wextra",
        f"-I{INCLUDE_DIR}",
        f"-I{ex_path}",
        str(test_src),
        "-o",
        str(bin_name)
    ]

    print(f"{COLOR_GRAY}[1/2] Compiling with g++ (C++17)...{COLOR_RESET}")
    try:
        c_res = subprocess.run(compile_cmd, capture_output=True, text=True, timeout=30)
    except FileNotFoundError:
        print(f"{COLOR_RED}[ERROR]{COLOR_RESET} 'g++' compiler not found on PATH! Please install MinGW/MSYS2 or add g++ to PATH.")
        return False
    except subprocess.TimeoutExpired:
        print(f"{COLOR_RED}[ERROR]{COLOR_RESET} Compilation timed out after 30 seconds.")
        return False
    finally:
        if backup_file and backup_file.exists():
            orig_ex = ex_path / "exercise.h"
            try:
                if orig_ex.exists():
                    orig_ex.unlink()
                backup_file.rename(orig_ex)
            except Exception as e:
                print(f"{COLOR_RED}[WARNING]{COLOR_RESET} Could not restore exercise.h: {e}")

    if c_res.returncode != 0:
        print(f"{COLOR_RED}[COMPILATION FAILED]{COLOR_RESET}")
        print(f"{COLOR_RED}{c_res.stderr}{COLOR_RESET}")
        hints = analyze_compile_error(c_res.stderr)
        if hints:
            print(f"\n{COLOR_YELLOW}Friendly Hints:{COLOR_RESET}")
            for h in hints:
                print(f"  • {h}")
        return False

    if c_res.stderr.strip():
        print(f"{COLOR_YELLOW}[Compiler Warnings]:{COLOR_RESET}")
        print(c_res.stderr.strip())

    # 2. Run the test binary with timeout
    print(f"{COLOR_GRAY}[2/2] Running automated test conditions (Timeout: 5s)...{COLOR_RESET}")
    success = False
    try:
        r_res = subprocess.run([str(bin_name)], capture_output=True, text=True, timeout=5)
        print(r_res.stdout)
        if r_res.stderr:
            print(r_res.stderr)
        if r_res.returncode == 0:
            success = True
        else:
            success = False
    except subprocess.TimeoutExpired:
        print(f"{COLOR_RED}[FAIL] Time Limit Exceeded (5s)!{COLOR_RESET}")
        print(f"{COLOR_YELLOW}Hint: Your code likely has an infinite loop (e.g. in a while or for loop condition).{COLOR_RESET}")
        success = False
    except Exception as e:
        print(f"{COLOR_RED}[FAIL] Runtime Crash: {e}{COLOR_RESET}")
        success = False
    finally:
        # Clean up binary
        if bin_name.exists():
            try:
                bin_name.unlink()
            except Exception:
                pass

    return success

def print_help(all_exercises):
    print_banner()
    print("USAGE:")
    print("  python test_runner.py [options] [target]")
    print("\nOPTIONS:")
    print("  --solution, -s               Test against verified reference solutions")
    print("  --list, -l                   List all available exercises")
    print("  --help, -h                   Show this help message")
    print("\nEXAMPLES:")
    print("  python test_runner.py                       Run all exercises (starter code)")
    print("  python test_runner.py --solution            Verify all reference solutions (100% pass)")
    print("  python test_runner.py foundation            Run all Foundation exercises")
    print("  python test_runner.py sorting               Run all Sorting exercises")
    print("  python test_runner.py linked_lists          Run all Linked List exercises")
    print("  python test_runner.py stack                 Run all Stack & Queue exercises")
    print("  python test_runner.py capstone              Run Week 5 Capstone Project")
    print("  python test_runner.py 01_grade_classifier   Run a specific exercise")
    print(f"\nTOTAL EXERCISES AVAILABLE: {len(all_exercises)}")

def list_exercises(all_exercises):
    print_banner()
    print(f"\n{COLOR_WHITE}Available Exercises ({len(all_exercises)} total):{COLOR_RESET}\n")
    current_mod = ""
    for ex in all_exercises:
        rel = ex.relative_to(SCRIPT_DIR)
        parts = rel.parts
        mod = parts[0]
        if mod != current_mod:
            current_mod = mod
            mod_title = mod.replace("_", " ").title()
            print(f"\n{COLOR_CYAN}[MODULE] {mod_title}{COLOR_RESET}")
        name = parts[1] if len(parts) > 1 else parts[0]
        print(f"   * {name}")
    print(f"\nRun any exercise with: {COLOR_YELLOW}python test_runner.py <name>{COLOR_RESET}\n")

def main():
    all_exercises = find_exercises()
    if not all_exercises:
        print(f"{COLOR_RED}No exercises found under {SCRIPT_DIR}{COLOR_RESET}")
        return 1

    args = [a for a in sys.argv[1:]]
    use_solution = False
    filtered_args = []

    for a in args:
        al = a.lower()
        if al in ["--solution", "-s", "solution", "solutions"]:
            use_solution = True
        elif al in ["--help", "-h", "help"]:
            print_help(all_exercises)
            return 0
        elif al in ["--list", "-l", "list"]:
            list_exercises(all_exercises)
            return 0
        else:
            filtered_args.append(a)

    print_banner()

    target = filtered_args[0] if filtered_args else None

    targets_to_run = []
    if target in [None, "--all", "-a", "all"]:
        targets_to_run = all_exercises
    else:
        norm_target = target.replace("\\", "/").strip("/").lower()
        for ex in all_exercises:
            rel = str(ex.relative_to(SCRIPT_DIR)).replace("\\", "/").lower()
            if norm_target in rel:
                targets_to_run.append(ex)

        if not targets_to_run:
            print(f"{COLOR_RED}No exercises matching '{target}' found.{COLOR_RESET}")
            print("\nAvailable exercises:")
            for ex in all_exercises:
                print(f"  - {ex.relative_to(SCRIPT_DIR)}")
            return 1

    passed_count = 0
    failed_count = 0
    results = []

    for ex in targets_to_run:
        rel = ex.relative_to(SCRIPT_DIR)
        ok = run_single_exercise(ex, use_solution=use_solution)
        if ok:
            passed_count += 1
            results.append((str(rel), "PASS", COLOR_GREEN))
        else:
            failed_count += 1
            results.append((str(rel), "FAIL", COLOR_RED))

    # Summary table
    print(f"\n{COLOR_CYAN}================================================================={COLOR_RESET}")
    print(f"{COLOR_WHITE}                     EXERCISE SUITE SUMMARY                      {COLOR_RESET}")
    print(f"{COLOR_CYAN}================================================================={COLOR_RESET}")
    for name, status, color in results:
        dots = "." * max(2, (50 - len(name)))
        print(f"  {name} {COLOR_GRAY}{dots}{COLOR_RESET} [{color}{status}{COLOR_RESET}]")

    print(f"{COLOR_CYAN}-----------------------------------------------------------------{COLOR_RESET}")
    total = len(results)
    percentage = (passed_count / total * 100) if total > 0 else 0
    print(f"  Passed: {COLOR_GREEN}{passed_count}{COLOR_RESET} / {total} ({percentage:.1f}%) | Failed: {COLOR_RED}{failed_count}{COLOR_RESET}")
    print(f"{COLOR_CYAN}================================================================={COLOR_RESET}\n")

    return 0 if failed_count == 0 else 1

if __name__ == "__main__":
    sys.exit(main())
