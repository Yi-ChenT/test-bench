# 🔧 Test Bench
## Project Overview
This program is used to demonstrate how to combine a small mathematical library with a data‑driven testing engine and a timestamped logging subsystem

## Core Objectives
1. Showcase clean modular C design
Separate translation units (math_library.c, test_harness.c, logger.c, main.c) keep pure logic, test orchestration, logging, and UI strictly isolated.

2. Provide a reusable micro‑testing scaffold
Tests are declared as plain‑C structs holding a description, a function pointer to the math operation, input operands, and an expected value.
Extending coverage is as simple as adding one line to the testCases[] array.

3. Illustrate lightweight file‑based logging
The logger writes [YYYY‑MM‑DD HH:MM:SS] [LEVEL] message to either program.log (runtime events) or test.log (per‑run test results).
Log routing is swapped on the fly from the menu to avoid stream conflicts.

## Interactive Workflow
| Menu Option | Purpose | Behind the Scenes |
|-------------|---------|-------------------|
| **1 · Run Individual Test** | Execute one selected case | Clears `test.log` → switches logger → runs chosen test → restores `program.log`. |
| **2 · Run All Test Cases** | Execute the full suite | Same log rotation, iterates through `testCases[]`. |
| **3 · View Log Files** | Inspect `program.log` or `test.log` in‑app | Opens chosen file read‑only and streams to stdout. |
| **4 · Exit** | Graceful shutdown | Flushes & closes the active log, frees input buffers. |

## 🛠️ Build & Run
Windows User:

1. Download VS Code and C/C++ Extension in VS Code.
2. Download MinGW. Link: https://sourceforge.net/projects/mingw/
3. In Terminal, type gcc main.c logger.c math_library.c test_harness.c -o test-bench.exe for compile the program and build the executable.
4. In Terminal, type .\test-bench.exe to run the program.

Mac User:

1. Open Terminal, type xcode-select --install to install the Command Line Tools.
2. In Terminal, type gcc main.c logger.c math_library.c test_harness.c -o test-bench for compile the prgram and build the executable.
3. Lastly, type ./test-bench to run the program.

Welcome to clone it, add new mathematical functions or entirely different modules, and expand, the infrastructure is already wired for you.

