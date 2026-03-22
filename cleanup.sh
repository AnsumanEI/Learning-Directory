#!/bin/bash
# ================================================================
#  FINAL CLEANUP — fixes only what's still wrong
#  Run from repo root in Git Bash
# ================================================================

echo "==> Removing all remaining .exe binaries..."
find . -name "*.exe" -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true

echo "==> Removing tempCodeRunnerFile..."
find . -name "tempCodeRunnerFile*" -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true

echo "==> Removing media files..."
git rm -f "05_web/full-stack/HTML5/Lutt Le Gaya (From Dhurandhar).mp3" 2>/dev/null || true
git rm -f "05_web/html-basics/Beautiful Rain Wallpapers For Your Desktop.jpg" 2>/dev/null || true

echo "==> Removing rough/scratch files..."
git rm -f "02_dsa/complete-course/RECURSION/rough.cpp"  2>/dev/null || true
git rm -f "02_dsa/complete-course/RECURSION/rough2.cpp" 2>/dev/null || true
git rm -f "02_dsa/complete-course/RECURSION/rough3.cpp" 2>/dev/null || true
git rm -f "02_dsa/complete-course/rough.cpp"            2>/dev/null || true
git rm -f "01_languages/c/chapter 4/table_of_any_no"    2>/dev/null || true
git rm -f "final_rename.sh"                             2>/dev/null || true

echo "==> Fixing duplicate numbered C files..."
# Current clash: 08, 09, 10, 11, 12 each have two files
# The practice-renamed ones (area, circle etc) should be 13 onwards
# The original numbered ones (even-odd, logical etc) keep their numbers
git mv "01_languages/c/08-area-of-rectangle.c"         "01_languages/c/13-area-of-rectangle.c"         2>/dev/null || true
git mv "01_languages/c/09-area-of-circle.c"            "01_languages/c/14-area-of-circle.c"            2>/dev/null || true
git mv "01_languages/c/10-celsius-to-fahrenheit.c"     "01_languages/c/15-celsius-to-fahrenheit.c"     2>/dev/null || true
git mv "01_languages/c/11-bitwise-and-divisibility.c"  "01_languages/c/16-bitwise-and-divisibility.c"  2>/dev/null || true
git mv "01_languages/c/12-basic-calculator.c"          "01_languages/c/17-basic-calculator.c"          2>/dev/null || true
git mv "01_languages/c/13-grade-calculator.c"          "01_languages/c/18-grade-calculator.c"          2>/dev/null || true
git mv "01_languages/c/14-age-check-if-else.c"         "01_languages/c/19-age-check-if-else.c"         2>/dev/null || true
git mv "01_languages/c/15-marks-percentage.c"          "01_languages/c/20-marks-percentage.c"          2>/dev/null || true
git mv "01_languages/c/16-income-tax-calculator.c"     "01_languages/c/21-income-tax-calculator.c"     2>/dev/null || true
git mv "01_languages/c/17-leap-year-check.c"           "01_languages/c/22-leap-year-check.c"           2>/dev/null || true
git mv "01_languages/c/18-find-greatest-of-four.c"     "01_languages/c/23-find-greatest-of-four.c"     2>/dev/null || true
git mv "01_languages/c/19-uppercase-lowercase-check.c" "01_languages/c/24-uppercase-lowercase-check.c" 2>/dev/null || true

echo "==> Renaming complete-course MATHS files to kebab-case..."
git mv "02_dsa/complete-course/MATHS/optimisedprimality.cpp"                    "02_dsa/complete-course/MATHS/optimised-primality-check.cpp"           2>/dev/null || true
git mv "02_dsa/complete-course/MATHS/optimisedprimalitycheckfor_n_numbers.cpp"  "02_dsa/complete-course/MATHS/optimised-primality-check-n-numbers.cpp"  2>/dev/null || true
git mv "02_dsa/complete-course/MATHS/primalitycheck.cpp"                        "02_dsa/complete-course/MATHS/primality-check.cpp"                     2>/dev/null || true
git mv "02_dsa/complete-course/MATHS/primalitycheckfor_n_numbers.cpp"           "02_dsa/complete-course/MATHS/primality-check-n-numbers.cpp"           2>/dev/null || true
git mv "02_dsa/complete-course/MATHS/sieveoferatosthemes.cpp"                   "02_dsa/complete-course/MATHS/sieve-of-eratosthenes.cpp"               2>/dev/null || true
git mv "02_dsa/complete-course/MATHS/MODULO ARITHMETIC/multiplicativeinverse.cpp" "02_dsa/complete-course/MATHS/MODULO ARITHMETIC/multiplicative-inverse.cpp" 2>/dev/null || true
git mv "02_dsa/complete-course/MATHS/MODULO ARITHMETIC/optimisedpower.cpp"      "02_dsa/complete-course/MATHS/MODULO ARITHMETIC/optimised-power.cpp"   2>/dev/null || true

echo "==> Renaming complete-course RECURSION files to kebab-case..."
git mv "02_dsa/complete-course/RECURSION/Nqueen.cpp"             "02_dsa/complete-course/RECURSION/n-queens.cpp"                2>/dev/null || true
git mv "02_dsa/complete-course/RECURSION/Nqueenbrute.cpp"        "02_dsa/complete-course/RECURSION/n-queens-brute.cpp"          2>/dev/null || true
git mv "02_dsa/complete-course/RECURSION/combinationsum.cpp"     "02_dsa/complete-course/RECURSION/combination-sum.cpp"         2>/dev/null || true
git mv "02_dsa/complete-course/RECURSION/combinationsum2.cpp"    "02_dsa/complete-course/RECURSION/combination-sum-2.cpp"       2>/dev/null || true
git mv "02_dsa/complete-course/RECURSION/functionalrec.cpp"      "02_dsa/complete-course/RECURSION/functional-recursion.cpp"   2>/dev/null || true
git mv "02_dsa/complete-course/RECURSION/magic_triplets.cpp"     "02_dsa/complete-course/RECURSION/magic-triplets.cpp"          2>/dev/null || true
git mv "02_dsa/complete-course/RECURSION/permutations2.cpp"      "02_dsa/complete-course/RECURSION/permutations-2.cpp"          2>/dev/null || true
git mv "02_dsa/complete-course/RECURSION/permutationstring.cpp"  "02_dsa/complete-course/RECURSION/permutation-string.cpp"      2>/dev/null || true
git mv "02_dsa/complete-course/RECURSION/backtracking.cpp"       "02_dsa/complete-course/RECURSION/backtracking-intro.cpp"      2>/dev/null || true
git mv "02_dsa/complete-course/RECURSION/subsetsum.cpp"          "02_dsa/complete-course/RECURSION/subset-sum.cpp"              2>/dev/null || true
git mv "02_dsa/complete-course/RECURSION/subsetsum2.cpp"         "02_dsa/complete-course/RECURSION/subset-sum-2.cpp"            2>/dev/null || true
git mv "02_dsa/complete-course/RECURSION/sudokusolver.cpp"       "02_dsa/complete-course/RECURSION/sudoku-solver.cpp"           2>/dev/null || true
git mv "02_dsa/complete-course/RECURSION/subsequence.cpp"        "02_dsa/complete-course/RECURSION/subsequence.cpp"             2>/dev/null || true
git mv "02_dsa/complete-course/RECURSION/working.cpp"            "02_dsa/complete-course/RECURSION/recursion-working.cpp"       2>/dev/null || true
git mv "02_dsa/complete-course/RECURSION/MULTIPLE RECURSION/multiplerecursion.cpp" "02_dsa/complete-course/RECURSION/MULTIPLE RECURSION/multiple-recursion.cpp" 2>/dev/null || true

echo "==> Renaming complete-course ARRAY-ADT and STL files..."
git mv "02_dsa/complete-course/ARRAY-ADT/abstractdatatypearray.cpp" "02_dsa/complete-course/ARRAY-ADT/abstract-data-type-array.cpp" 2>/dev/null || true
git mv "02_dsa/complete-course/ARRAY-ADT/reverseandshift.cpp"       "02_dsa/complete-course/ARRAY-ADT/reverse-and-shift.cpp"        2>/dev/null || true
git mv "02_dsa/complete-course/ARRAY-ADT/shell_sorting.cpp"         "02_dsa/complete-course/ARRAY-ADT/shell-sorting.cpp"            2>/dev/null || true
git mv "02_dsa/complete-course/STL/vector_of_pairs.cpp"             "02_dsa/complete-course/STL/vector-of-pairs.cpp"                2>/dev/null || true
git mv "02_dsa/complete-course/STL/pair_vector.cpp"                 "02_dsa/complete-course/STL/pair-vector.cpp"                    2>/dev/null || true
git mv "02_dsa/complete-course/STL/pairsortingquestion.cpp"         "02_dsa/complete-course/STL/pair-sorting-question.cpp"          2>/dev/null || true
git mv "02_dsa/complete-course/STL/vectorpair.cpp"                  "02_dsa/complete-course/STL/vector-pair.cpp"                    2>/dev/null || true
git mv "02_dsa/complete-course/leetcode/q1.cpp"                     "02_dsa/complete-course/leetcode/lc1-two-sum.cpp"               2>/dev/null || true

echo "==> Renaming CSS files..."
git mv "05_web/full-stack/CSS/extrenalcss.html"   "05_web/full-stack/CSS/external-css-demo.html"    2>/dev/null || true
git mv "05_web/full-stack/CSS/indexfloat.html"    "05_web/full-stack/CSS/css-float-layout.html"     2>/dev/null || true
git mv "05_web/full-stack/CSS/indexoverflow.html" "05_web/full-stack/CSS/css-overflow-demo.html"    2>/dev/null || true
git mv "05_web/full-stack/CSS/inlinecss.html"     "05_web/full-stack/CSS/inline-css-demo.html"      2>/dev/null || true
git mv "05_web/full-stack/CSS/internalcss.html"   "05_web/full-stack/CSS/internal-css-demo.html"    2>/dev/null || true

echo "==> Renaming DSA core remaining file..."
git mv "02_dsa/core/DSA 2.0/RECURSION/indirect_recursion.cpp" "02_dsa/core/DSA 2.0/RECURSION/indirect-recursion.cpp" 2>/dev/null || true
git mv "02_dsa/core/DSA 2.0/RECURSION/questions/gcsd.cpp"     "02_dsa/core/DSA 2.0/RECURSION/questions/gcd-steps.cpp" 2>/dev/null || true

echo "==> Renaming internshala Linkedlist to kebab-case..."
git mv "03_courses/internshala/Linkedlist/DoublyLL.cpp"         "03_courses/internshala/Linkedlist/doubly-linked-list.cpp"          2>/dev/null || true
git mv "03_courses/internshala/Linkedlist/DoublyLLwithMenu.cpp" "03_courses/internshala/Linkedlist/doubly-linked-list-with-menu.cpp" 2>/dev/null || true
git mv "03_courses/internshala/Linkedlist/SinglyLL.cpp"         "03_courses/internshala/Linkedlist/singly-linked-list.cpp"          2>/dev/null || true
git mv "03_courses/internshala/Linkedlist/singleCircularLL.cpp" "03_courses/internshala/Linkedlist/circular-singly-linked-list.cpp" 2>/dev/null || true

echo "==> Writing final .gitignore..."
cat > .gitignore << 'EOF'
# Compiled binaries
*.exe
*.out
*.o
*.class

# IDE
.vscode/
.vs/
.idea/
*.suo
*.user
CppProperties.json
*.vsidx
*.ipch
*.wsuo
*.db
*.sqlite
read.lock

# OS
.DS_Store
Thumbs.db

# Temp
tempCodeRunnerFile*

# Scripts (not part of the learning content)
*.sh

# Media
*.mp3
*.jpg
*.jpeg
*.png
*.gif
EOF
git add .gitignore

echo "==> Writing final README..."
cat > README.md << 'EOF'
# Programming & DSA Learning Repository

A structured collection of programs covering C, C++, Java, Data Structures & Algorithms,
Web Development, and personal projects — built during active learning.

---

## Structure

```
.
├── 01_languages/
│   ├── c/                        C language — 24 numbered files (basics → arrays)
│   │   ├── 01–12                 Variables, operators, conditionals, loops
│   │   ├── 13–24                 Practice — area, calculator, tax, leap year, etc.
│   │   ├── chapter 4/            Loops — for, while, break, tables
│   │   ├── chapter 5/            Functions — prototype, recursion, return, practice
│   │   ├── chapter 6/            Pointers — call by ref/val, pointer practice
│   │   ├── chapter 7/            Arrays — input, traversal, pointer arithmetic
│   │   ├── chapter-4-loops/      Alternate loop exercises
│   │   ├── misc-practice/        Armstrong, calculator, do-while, etc.
│   │   └── projects of c programme/  Mini projects, random number gen
│   │
│   ├── cpp/                      C++ — 27 chapters (full course)
│   │   ├── 1.BASICS/             Hello World, dynamic declaration, namespace
│   │   ├── 2.DATA TYPES.../      Variables, operators, scope resolution, loops
│   │   ├── 3.ENUM,TYPEDEF/       Enums and typedefs
│   │   ├── 4.CONDITIONAL.../     If-else, switch
│   │   ├── 5.SHORT CIRCUIT.../   Short circuit, switch case variations
│   │   ├── 7.ARRAYS/             1D/2D arrays, matrix, linear search
│   │   ├── 8.POINTERS.../        Pointer basics and arithmetic
│   │   ├── 9.STRINGS/            C-style string functions
│   │   ├── 10.CLASS STRINGS.../  String class, iterators
│   │   ├── 11.FUNCTION/          Functions, overloading, templates
│   │   ├── 12.PARAMETRE.../      Call by address, return by reference
│   │   ├── 13.RECURSIONS/        Recursive functions, sorting
│   │   ├── 14.OOPS/              Classes, constructors, deep copy, this pointer
│   │   ├── 15.DATA HANDLING/     Data handling, struct vs class
│   │   ├── 16.OVERLOADING/       Operator overloading, friend functions
│   │   ├── 17.INHERITANCE/       Access specifiers, constructors, is-a/has-a
│   │   ├── 18.BASE CLASS.../     Base class pointers, derived class objects
│   │   ├── 19.POLYMORPHISM/      Virtual functions, abstract class, overriding
│   │   ├── 20.FRIEND AND.../     Friend functions, static members
│   │   ├── 21.EXCEPTION.../      Try/catch/throw, stack overflow/underflow
│   │   ├── 22.TEMPLATE CLASS/    Generic stack with templates
│   │   ├── 23.CONSTANTS.../      const, preprocessors, macros, namespaces
│   │   ├── 24.DESTRUCTOR.../     Destructors and virtual destructors
│   │   ├── 25.IOSTREAMS/         File I/O, streams, serialisation
│   │   ├── 26.STL/               Vector, Map, Set, Stack, Queue, Deque, Algorithms
│   │   ├── 27.c++11/             Auto, lambda expressions, smart pointers
│   │   └── QUESTIONS/            50+ named practice problems
│   │
│   └── java/                     Java — collections, OOPs, strings
│       ├── BasicInputOutput.java
│       ├── StringBasics/Methods/Builder/Memory/Substring — string series
│       ├── ArraysDemo / ArrayListDemo / TwoDArraysDemo
│       ├── HashMapDemo / StackDemo / QueueDemo / PriorityQueueDemo
│       ├── Car / CircleClass / PointClass / ObjectInitialisationDemo — OOPs
│       └── javatcs/              OOPs package (Car + Main)
│
├── 02_dsa/
│   ├── binary-search/            11 LeetCode binary search solutions
│   ├── core/                     DSA fundamentals
│   │   ├── array-insert/delete, linked-list, pointer arrays
│   │   └── DSA 2.0/              Recursion series, BST, 2D array, binary search
│   ├── complete-course/          Full DSA course
│   │   ├── ARRAY-ADT/            Abstract data type, search, sort
│   │   ├── MATHS/                GCD, primality, sieve, modular arithmetic
│   │   ├── RECURSION/            N-Queens, subset sum, permutations, backtracking, Sudoku
│   │   ├── STL/                  Pairs, vectors, sorting
│   │   └── leetcode/             LeetCode solutions from course
│   └── stl-cheatsheet/           C++ STL markdown reference
│
├── 03_courses/
│   ├── internshala/              Internshala DSA course
│   │   ├── Array/                Max, sum, transpose
│   │   ├── Function/             Call by addr/ref, scope, pointer-to-fn
│   │   ├── Graphs/               Adjacency list creation
│   │   ├── Linkedlist/           Singly, Doubly, Circular LL
│   │   ├── Pointers/             Pointer basics, dynamic memory
│   │   ├── Queue/                Circular queue
│   │   ├── Sorting/              Bubble, insertion, selection sort
│   │   ├── Stacks/               Stack implementation
│   │   ├── Structures/           Struct basics
│   │   ├── Trees/                Binary tree, height, traversal, zigzag
│   │   └── search/               Binary and linear search
│   ├── striver-a2z/              Striver A2Z DSA sheet solutions
│   └── supreme-batch/            Love Babbar Supreme Batch — binary search
│
├── 04_interview-prep/
│   └── cc-qna/                   15 competitive coding problems
│
├── 05_web/
│   ├── html-basics/              20+ named HTML fundamentals files + CSS + JS
│   └── full-stack/
│       ├── HTML5/                Forms, tables, audio, video, hyperlinks
│       ├── CSS/                  Inline, internal, external, float, overflow
│       └── Project_prac/
│           ├── proj1/            Ultimatix Dashboard
│           ├── proj2/            Empower Young Minds landing page
│           └── proj3/            CSS Box Model visualiser
│
├── 06_college/                   3 college assignment files
│
├── 07_projects/
│   ├── employee-management-system-v1.cpp    EMS — struct + class (v1)
│   ├── employee-management-system-final.cpp EMS — final version
│   ├── sorting-visualizer-sfml.cpp          Insertion sort visualizer (SFML)
│   └── tetris-game.cpp                      Tetris game logic
│
└── Phase-1/
    └── lc1-two-sum-brute.cpp     Two Sum brute force skeleton
```

---

## LeetCode Binary Search — `02_dsa/binary-search/`

| File | Problem | Difficulty |
|------|---------|-----------|
| `lc33-search-rotated-sorted-array.cpp` | Search in Rotated Sorted Array | Medium |
| `lc34-first-last-position.cpp` | First and Last Position | Medium |
| `lc34-first-last-position-v2.cpp` | First and Last Position (v2) | Medium |
| `lc69-sqrt-integer.cpp` | Sqrt(x) | Easy |
| `lc275-h-index-ii.cpp` | H-Index II | Medium |
| `lc278-first-bad-version.cpp` | First Bad Version | Easy |
| `lc374-guess-number-higher-or-lower.cpp` | Guess Number Higher or Lower | Easy |
| `lc436-find-right-interval.cpp` | Find Right Interval | Medium |
| `lc441-arranging-coins.cpp` | Arranging Coins | Easy |
| `lc540-single-element-sorted-array.cpp` | Single Element in Sorted Array | Medium |
| `lc1337-k-weakest-rows-in-matrix.cpp` | K Weakest Rows in a Matrix | Easy |

---

## Topics Covered

| Area | Topics |
|------|--------|
| **C** | Variables, operators, control flow, loops, functions, pointers, arrays |
| **C++** | All of the above + OOPs, templates, STL, file I/O, exception handling, C++11 |
| **Java** | I/O, strings, arrays, collections, OOPs |
| **DSA** | Arrays, Linked Lists, Stacks, Queues, Sorting, Binary Search, Recursion, Trees, Graphs |
| **Web** | HTML5, CSS3, JavaScript basics |
| **Projects** | Employee Management System, Sorting Visualizer (SFML), Tetris |

---

## How to Compile

```bash
# C
gcc filename.c -o out && ./out

# C++
g++ filename.cpp -o out && ./out

# Java
javac FileName.java && java FileName

# Sorting Visualizer (needs SFML)
g++ sorting-visualizer-sfml.cpp -lsfml-graphics -lsfml-window -lsfml-system -o viz && ./viz
```
EOF
git add README.md

echo "==> Committing and pushing..."
git add -A
git commit -m "cleanup: remove binaries, fix duplicate numbering, rename remaining vague files

- Removed all .exe files, tempCodeRunnerFile, media files, script files
- Fixed duplicate C file numbers: practice files renumbered 13-24
- Renamed complete-course MATHS/RECURSION/STL files to kebab-case
- Renamed Internshala Linkedlist files to kebab-case
- Renamed CSS demo files to descriptive names
- Updated .gitignore and rewrote README with full structure"

git push origin main

echo ""
echo "=========================================="
echo "  Done! Repo is clean and production-ready"
echo "  https://github.com/AnsumanEI/Learning-Directory"
echo "=========================================="
EOF
