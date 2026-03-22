# Programming & DSA Learning Repository

> A comprehensive, well-organized collection of programs covering C, C++, Java,
> Data Structures & Algorithms, Web Development, and personal projects.
> Built during active learning — structured for easy reference and recruiter review.

---

## Repository Structure

```
.
├── 01_languages/
│   ├── c/                          C language fundamentals
│   │   ├── 01-hello-world.c        ...through...
│   │   ├── 19-uppercase-...c       19 progressively numbered basics files
│   │   ├── chapter 4/              Loops — for, while, break, continue
│   │   ├── chapter 5/              Functions — prototypes, recursion, return
│   │   ├── chapter 6/              Pointers — basics, call by ref, practice
│   │   ├── chapter 7/              Arrays — input, traversal, pointer arithmetic
│   │   ├── chapter-4-loops/        Loop exercises (alternate set)
│   │   ├── misc-practice/          Miscellaneous practice problems
│   │   └── projects of c programme/ Mini C projects
│   │
│   ├── cpp/                        C++ — full course (27 chapters)
│   │   ├── 1.BASICS/               Hello World, I/O, declarations
│   │   ├── 2.DATA TYPES,.../       Variables, operators, scope resolution
│   │   ├── 3.ENUM,TYPEDEF/         Enums and typedefs
│   │   ├── 4.CONDITIONAL STATEMENTS/ If-else, switch
│   │   ├── 5.SHORT CIRCUIT,SWITCH/ Short circuit evaluation
│   │   ├── 7.ARRAYS/               1D, 2D arrays, matrix operations
│   │   ├── 8.POINTERS BASIC ONLY/  Pointer basics and arithmetic
│   │   ├── 9.STRINGS/              C-style string functions
│   │   ├── 10.CLASS STRINGS.../    String class, iterators
│   │   ├── 11.FUNCTION/            Functions — overloading, templates, linear search
│   │   ├── 12.PARAMETRE PASSING/   Call by address, return by reference
│   │   ├── 13.RECURSIONS/          Recursive functions, sorting, min ways
│   │   ├── 14.OOPS/                Classes, constructors, deep copy, this pointer
│   │   ├── 15.DATA HANDLING/       Data handling, structure vs class
│   │   ├── 16.OVERLOADING/         Operator overloading, friend functions
│   │   ├── 17.INHERITANCE/         Access specifiers, constructors, rectangle-cuboid
│   │   ├── 18.BASE CLASS.../       Base class pointers, derived class objects
│   │   ├── 19.POLYMORPHISM/        Virtual functions, abstract class, overriding
│   │   ├── 20.FRIEND AND STATIC/   Friend functions, static members
│   │   ├── 21.EXCEPTION HANDLING/  Try-catch, throw, stack overflow/underflow
│   │   ├── 22.TEMPLATE CLASS/      Generic stack using templates
│   │   ├── 23.CONSTANTS.../        const, preprocessors, namespaces
│   │   ├── 24.DESTRUCTOR.../       Destructors, virtual destructors
│   │   ├── 25.IOSTREAMS/           File I/O, streams, serialisation
│   │   ├── 26.STL/                 Vector, Map, Set, Queue, Stack, Deque, Priority Queue
│   │   ├── 27.c++11/               Auto, lambda, smart pointers, final keyword
│   │   └── QUESTIONS/              50+ practice problems (palindrome, factorial, etc.)
│   │
│   └── java/                       Java fundamentals
│       ├── BasicInputOutput.java   Scanner, input/output
│       ├── StringBasics.java       String methods, charAt, length
│       ├── StringMethods.java      toUpperCase, contains, charAt
│       ├── StringBuilderDemo.java  StringBuilder vs String performance
│       ├── StringVsStringBuilderPerf.java  Benchmark comparison
│       ├── SubstringAndSplitDemo.java      substring, split
│       ├── StringMemoryConceptDemo.java    String interning, hashCode
│       ├── ArraysDemo.java         Arrays.sort, Arrays.fill
│       ├── ArrayListDemo.java      ArrayList operations
│       ├── TwoDArraysDemo.java     2D arrays, jagged arrays
│       ├── HashMapDemo.java        HashMap operations, keySet
│       ├── StackDemo.java          Stack push/pop/peek
│       ├── QueueDemo.java          ArrayDeque as Queue
│       ├── PriorityQueueDemo.java  Min/Max heap
│       ├── ScannerInputDemo.java   Scanner with next/nextInt/nextDouble
│       ├── StaticMethodsAndSwap.java  Static methods, swap
│       ├── DefaultValuesDemo.java  Default values of Java types
│       ├── Car.java                OOP — Car class with constructor
│       ├── CircleClass.java        OOP — Circle with area/perimeter
│       ├── PointClass.java         OOP — Point class
│       ├── ObjectInitialisationDemo.java  Object creation, method calls
│       └── javatcs/                Java OOP practice package (Car + Main)
│
├── 02_dsa/
│   ├── binary-search/              11 LeetCode Binary Search problems
│   │   ├── lc33-...cpp             Search in Rotated Sorted Array
│   │   ├── lc34-...cpp (x2)        First and Last Position (2 approaches)
│   │   ├── lc69-...cpp             Sqrt(x)
│   │   ├── lc275-...cpp            H-Index II
│   │   ├── lc278-...cpp            First Bad Version
│   │   ├── lc374-...cpp            Guess Number Higher or Lower
│   │   ├── lc436-...cpp            Find Right Interval
│   │   ├── lc441-...cpp            Arranging Coins
│   │   ├── lc540-...cpp            Single Element in Sorted Array
│   │   └── lc1337-...cpp           K Weakest Rows in Matrix
│   │
│   ├── core/                       DSA fundamentals
│   │   ├── array-insert-element.cpp        Insert element at position
│   │   ├── array-insert-at-index.cpp       Insert at specific index
│   │   ├── linked-list-implementation.cpp  Singly LL with malloc
│   │   ├── linked-list-node-struct.cpp     LL node struct
│   │   ├── pointer-to-1d-array.cpp         Pointer-array relationship
│   │   ├── pointer-to-2d-array.cpp         2D array with pointer
│   │   └── DSA 2.0/                        DSA 2.0 course files
│   │       ├── binary-search-basics.cpp
│   │       ├── binary-search-exercise.cpp
│   │       ├── bst-using-recursion.cpp
│   │       ├── 2D ARRAY/
│   │       └── RECURSION/                  Full recursion series
│   │           ├── head/tail/tree/...
│   │           └── questions/              Recursion problem set
│   │
│   ├── complete-course/            Complete DSA course
│   │   ├── ARRAY-ADT/              Abstract data type, binary/linear search
│   │   ├── MATHS/                  GCD, primality, sieve, modular arithmetic
│   │   ├── RECURSION/              N-Queens, subsets, permutations, backtracking
│   │   ├── STL/                    STL algorithms, pairs, vectors
│   │   └── PRAC/                   Practice problems
│   │
│   └── stl-cheatsheet/             C++ STL quick reference (Markdown)
│
├── 03_courses/
│   ├── internshala/                Internshala DSA course
│   │   ├── Array/                  Max, sum, transpose
│   │   ├── Function/               Call by address/ref, scope, pointer-to-fn
│   │   ├── Graphs/                 Graph creation (adjacency list)
│   │   ├── Linkedlist/             Singly, Doubly, Circular LL
│   │   ├── Pointers/               Pointer basics, dynamic memory
│   │   ├── Queue/                  Circular queue implementation
│   │   ├── Sorting/                Bubble, insertion, selection sort
│   │   ├── Stacks/                 Stack implementation
│   │   ├── Structures/             Struct basics
│   │   ├── Trees/                  Binary tree, height, traversal, N-Queens
│   │   └── search/                 Binary and linear search
│   │
│   ├── striver-a2z/                Striver A2Z DSA Sheet
│   │   ├── lc1-two-sum-hashmap.cpp LeetCode 1 — Two Sum (HashMap approach)
│   │   └── map-of-pairs.cpp        Map with pair keys
│   │
│   └── supreme-batch/              Love Babbar Supreme Batch
│       ├── binary-search-template.cpp         BS template
│       ├── find-right-interval.cpp            LC 436
│       └── find-smallest-letter-greater-than-target.cpp  LC 744
│
├── 04_interview-prep/
│   └── cc-qna/                     Competitive coding problems
│       ├── basic-output-and-loop.cpp
│       ├── array-processing-testcases.cpp
│       ├── count-interior-lattice-points.cpp
│       ├── digit-count-of-difference.cpp
│       ├── digit-count.cpp
│       ├── find-minimum-skill.cpp
│       ├── matrix-multiplication.cpp
│       ├── nearest-multiple-of-five.cpp
│       ├── print-numbers-1-to-10.cpp
│       ├── sieve-of-eratosthenes.cpp
│       ├── song-key-matching.cpp
│       ├── sort-class-implementation.cpp
│       ├── string-split-count.cpp
│       ├── target-search-in-array.cpp
│       └── vector-input-processing.cpp
│
├── 05_web/
│   ├── html-basics/                HTML fundamentals (older set)
│   │   ├── html-basics-1.html      ...through...
│   │   ├── html-text-formatting.html  19 topic-named HTML files
│   │   ├── biodata-svg-practice.html  SVG + biodata layout
│   │   ├── internal-external-css-demo.html
│   │   ├── transparent-button-demo.html  (with linked CSS + JS)
│   │   ├── script.js               Dark mode toggle
│   │   └── styles.css              Animated fade-in, background image
│   │
│   └── full-stack/                 Full-stack course files
│       ├── HTML5/                  Complete HTML5 — forms, tables, audio, video
│       ├── CSS/                    CSS — inline, internal, external, float, overflow
│       └── Project_prac/
│           ├── proj1/              Ultimatix Dashboard (HTML + CSS)
│           ├── proj2/              Empower Young Minds (HTML + CSS + Font Awesome)
│           └── proj3/              CSS Box Model visualiser
│
├── 06_college/
│   ├── increment-and-print.cpp     Pre-increment demo
│   ├── find-max-of-three-numbers.cpp  Ternary operator max of 3
│   └── dynamic-array-input.cpp     Dynamic array with new[]
│
├── 07_projects/
│   ├── employee-management-system-v1.cpp    EMS with struct, class, Sleep()
│   ├── employee-management-system-final.cpp EMS final version
│   ├── sorting-visualizer-sfml.cpp          Insertion sort visualizer (SFML)
│   └── tetris-game.cpp                      Tetris game logic (wide strings)
│
└── Phase-1/
    └── lc1-two-sum-brute.cpp       Two Sum — brute force skeleton
```

---

## Topics Covered

| Area | Topics |
|------|--------|
| **C** | Variables, operators, conditionals, loops, functions, pointers, arrays |
| **C++** | All of the above + OOPs, inheritance, polymorphism, templates, STL, file I/O, C++11 |
| **Java** | I/O, strings, arrays, collections (ArrayList, HashMap, Stack, Queue, PriorityQueue), OOPs |
| **DSA** | Arrays, Linked Lists (Singly/Doubly/Circular), Stacks, Queues, Sorting, Binary Search, Recursion, Trees, Graphs |
| **Web** | HTML5, CSS3 (inline/internal/external), JavaScript basics |
| **Projects** | Employee Management System (C++), Sorting Visualizer (SFML), Tetris |

---

## LeetCode Binary Search Problems

All solutions are in `02_dsa/binary-search/`

| # | File | Problem | Difficulty |
|---|------|---------|-----------|
| LC 33 | `lc33-search-rotated-sorted-array.cpp` | Search in Rotated Sorted Array | Medium |
| LC 34 | `lc34-first-last-position.cpp` | First and Last Position of Element | Medium |
| LC 34 | `lc34-first-last-position-v2.cpp` | First and Last Position (alternate) | Medium |
| LC 69 | `lc69-sqrt-integer.cpp` | Sqrt(x) | Easy |
| LC 275 | `lc275-h-index-ii.cpp` | H-Index II | Medium |
| LC 278 | `lc278-first-bad-version.cpp` | First Bad Version | Easy |
| LC 374 | `lc374-guess-number-higher-or-lower.cpp` | Guess Number Higher or Lower | Easy |
| LC 436 | `lc436-find-right-interval.cpp` | Find Right Interval | Medium |
| LC 441 | `lc441-arranging-coins.cpp` | Arranging Coins | Easy |
| LC 540 | `lc540-single-element-sorted-array.cpp` | Single Element in a Sorted Array | Medium |
| LC 1337 | `lc1337-k-weakest-rows-in-matrix.cpp` | K Weakest Rows in a Matrix | Easy |

---

## C++ Course — Chapter Index

| Chapter | Topic |
|---------|-------|
| 1 | Basics — Hello World, dynamic declaration, namespaces |
| 2 | Data types, variables, operators, scope resolution |
| 3 | Enums and typedef |
| 4 | Conditional statements |
| 5 | Short circuit, switch-case |
| 7 | Arrays — 1D/2D, matrix operations, linear search |
| 8 | Pointers — basics and arithmetic |
| 9 | Strings — C-style string functions |
| 10 | String class, iterators |
| 11 | Functions — overloading, templates, default args |
| 12 | Parameter passing — call by address, return by reference |
| 13 | Recursion — min ways, pointer-to-function, sum to N |
| 14 | OOPs — class, constructor, deep copy, this pointer, nested class |
| 15 | Data handling, structure vs class |
| 16 | Operator overloading — member, friend, insertion |
| 17 | Inheritance — access specifiers, constructors, rectangle-cuboid |
| 18 | Base class pointers and derived class objects |
| 19 | Polymorphism — virtual functions, abstract class, function overriding |
| 20 | Friend functions and static members |
| 21 | Exception handling — try/catch/throw, stack overflow |
| 22 | Template class (generic stack) |
| 23 | Constants, preprocessors, namespaces |
| 24 | Destructors and virtual destructors |
| 25 | File I/O, streams, serialisation |
| 26 | STL — Vector, Map, Set, Stack, Queue, Deque, Priority Queue, Algorithms |
| 27 | C++11 — auto, lambda, smart pointers, final keyword |

---

## How to Compile & Run

**C:**
```bash
gcc filename.c -o output && ./output
```

**C++:**
```bash
g++ filename.cpp -o output && ./output
```

**Java:**
```bash
javac FileName.java && java FileName
```

**Sorting Visualizer (requires SFML):**
```bash
g++ sorting-visualizer-sfml.cpp -lsfml-graphics -lsfml-window -lsfml-system -o visualizer
./visualizer
```

---

## About

This repository documents my programming learning journey — from C fundamentals to advanced
C++ OOPs, Java collections, DSA problem solving, and web development. Every file represents
a concept practiced and understood.

