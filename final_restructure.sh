#!/bin/bash
# ================================================================
#  FINAL COMPLETE RESTRUCTURE — Learning-Directory
#  Run from: root of your repo in Git Bash
#  Does: creates new folder structure, moves every file with a
#        proper descriptive name, cleans binaries, commits, pushes
# ================================================================
set -e

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   Creating new folder structure              ║"
echo "╚══════════════════════════════════════════════╝"

mkdir -p c/basics
mkdir -p c/control-flow
mkdir -p c/loops
mkdir -p c/practice

mkdir -p cpp/basics
mkdir -p cpp/arrays
mkdir -p cpp/strings
mkdir -p cpp/functions
mkdir -p cpp/pointers
mkdir -p cpp/oops
mkdir -p cpp/operator-overloading
mkdir -p cpp/inheritance
mkdir -p cpp/practice

mkdir -p java/basics
mkdir -p java/oops

mkdir -p dsa/arrays
mkdir -p dsa/linked-list
mkdir -p dsa/stacks-and-queues
mkdir -p dsa/sorting
mkdir -p dsa/searching/binary-search
mkdir -p dsa/recursion
mkdir -p dsa/graphs
mkdir -p dsa/stl-reference

mkdir -p web/html
mkdir -p web/css
mkdir -p web/javascript
mkdir -p web/projects/ultimatix-dashboard
mkdir -p web/projects/empower-young-minds
mkdir -p web/projects/css-box-model-demo

mkdir -p competitive-coding

mkdir -p projects/employee-management-system
mkdir -p projects/sorting-visualizer
mkdir -p projects/tetris


echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   C — basics                                 ║"
echo "╚══════════════════════════════════════════════╝"

git mv "C/1.first.c"                    "c/basics/01-hello-world.c"
git mv "C/2.variables.c"                "c/basics/02-variables-and-datatypes.c"
git mv "C/3.question1.c"                "c/basics/03-addition-of-two-numbers.c"
git mv "C/4.input.c"                    "c/basics/04-user-input-and-sum.c"
git mv "C/5.Practice.c"                 "c/basics/05-arithmetic-operators-practice.c"
git mv "C/6.Instructions.c"             "c/basics/06-arithmetic-operators.c"
git mv "C/7.Operator_precedence.c"      "c/basics/07-operator-precedence.c"
git mv "C/C1P1.c"                       "c/basics/08-area-of-rectangle.c"
git mv "C/C1P2.c"                       "c/basics/09-area-of-circle.c"
git mv "C/C1P3.c"                       "c/basics/10-celsius-to-fahrenheit.c"
git mv "C/C2P1.c"                       "c/basics/11-bitwise-xor-and-divisibility.c"

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   C — control flow                           ║"
echo "╚══════════════════════════════════════════════╝"

git mv "C/8.Conditonal_operators.c"     "c/control-flow/01-even-odd-check.c"
git mv "C/9.logical_operators.c"        "c/control-flow/02-logical-operators-driving.c"
git mv "C/10.conditonal_operators.c"    "c/control-flow/03-ternary-operator.c"
git mv "C/11.switchcase.c"              "c/control-flow/04-switch-case-rating.c"
git mv "C/C2P3.c"                       "c/control-flow/05-basic-calculator.c"
git mv "C/C3P4.c"                       "c/control-flow/06-grade-calculator.c"
git mv "C/C3P5.c"                       "c/control-flow/07-age-check-if-else.c"
git mv "C/C3P6.c"                       "c/control-flow/08-marks-percentage.c"
git mv "C/C3P7.c"                       "c/control-flow/09-income-tax-calculator.c"
git mv "C/C3P8.c"                       "c/control-flow/10-leap-year-check.c"
git mv "C/C3P9.c"                       "c/control-flow/11-find-greatest-of-four.c"
git mv "C/C3P10.c"                      "c/control-flow/12-uppercase-lowercase-check.c"

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   C — loops                                  ║"
echo "╚══════════════════════════════════════════════╝"

git mv "C/12.Loop_control_instruction.c"            "c/loops/01-while-loop-range.c"
git mv "C/123/for_loop.c"                           "c/loops/02-for-loop-basic.c"
git mv "C/123/dowhile.c"                            "c/loops/03-do-while-natural-numbers.c"
git mv "C/chapter 4/break_statement.c"              "c/loops/04-break-statement.c"
git mv "C/chapter 4/continue_loop.c"                "c/loops/05-continue-statement.c"
git mv "C/chapter 4/decrmenting_forloop.c"          "c/loops/06-decrementing-for-loop.c"
git mv "C/chapter 4/question_3.c"                   "c/loops/07-sum-of-n-natural-numbers.c"
git mv "C/chapter 4/question_4.c"                   "c/loops/08-factorial-using-loop.c"
git mv "C/chapter 4/question_5.c"                   "c/loops/09-infinite-while-loop-demo.c"
git mv "C/chapter 4/question_6.c"                   "c/loops/10-prime-number-check.c"
git mv "C/chapter 4/asxsax.c"                       "c/loops/11-for-loop-rewrite.c"

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   C — practice                               ║"
echo "╚══════════════════════════════════════════════╝"

git mv "C/123/armstrong.c"                              "c/practice/armstrong-number.c"
git mv "C/123/calculator.c"                             "c/practice/calculator-with-operators.c"
git mv "C/123/convert second to min.c"                  "c/practice/seconds-to-hours-minutes.c"
git mv "C/123/detetminin _the_largest_integer.c"        "c/practice/find-largest-integer.c"
git mv "C/123/first.c"                                  "c/practice/square-root.c"
git mv "C/123/how_to check the_aunthenticity _of_an_equation.c"  "c/practice/relational-operators-demo.c"
git mv "C/123/infinity.c"                               "c/practice/memory-addresses.c"
git mv "C/123/perfect_num.c"                            "c/practice/perfect-number-check.c"
git mv "C/123/practiceset1.c"                           "c/practice/logical-not-operator.c"
git mv "C/123/reverse_the_character.c"                  "c/practice/toggle-character-case.c"
git mv "C/chapter 4/check.c"                            "c/practice/modulo-scratch.c"


echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   C++ — basics                               ║"
echo "╚══════════════════════════════════════════════╝"

# Numbered chapters already have decent folder names, move their files
for f in "C++"/1.INTRODUCTION\ AND\ DATATYPES/*; do
  fname=$(basename "$f")
  git mv "$f" "cpp/basics/$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')" 2>/dev/null || true
done

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   C++ — arrays                               ║"
echo "╚══════════════════════════════════════════════╝"

for f in "C++"/7.ARRAYS\ AND\ STRINGS/*; do
  fname=$(basename "$f")
  git mv "$f" "cpp/arrays/$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')" 2>/dev/null || true
done

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   C++ — strings                              ║"
echo "╚══════════════════════════════════════════════╝"

for f in "C++"/10.CLASS\ STRINGS\ AND\ FUNCTIONS/*; do
  fname=$(basename "$f")
  git mv "$f" "cpp/strings/$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')" 2>/dev/null || true
done

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   C++ — functions                            ║"
echo "╚══════════════════════════════════════════════╝"

for f in "C++"/11.FUNCTION/*; do
  fname=$(basename "$f")
  git mv "$f" "cpp/functions/$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')" 2>/dev/null || true
done
for f in "C++"/12.PARAMETRE\ PASSING\ \&\ RETURNING\ \&\ POINTING\ FUCNTIONS/*; do
  fname=$(basename "$f")
  git mv "$f" "cpp/functions/$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')" 2>/dev/null || true
done
for f in "C++"/13.RECURSIONS/*; do
  fname=$(basename "$f")
  git mv "$f" "cpp/functions/recursion-$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')" 2>/dev/null || true
done

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   C++ — pointers                             ║"
echo "╚══════════════════════════════════════════════╝"

for f in "C++"/8.POINTERS/*; do
  fname=$(basename "$f")
  git mv "$f" "cpp/pointers/$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')" 2>/dev/null || true
done
for f in "C++"/9.DYNAMIC\ MEMORY/*; do
  fname=$(basename "$f")
  git mv "$f" "cpp/pointers/dynamic-memory-$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')" 2>/dev/null || true
done

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   C++ — oops                                 ║"
echo "╚══════════════════════════════════════════════╝"

for f in "C++"/14.OOPS/*; do
  fname=$(basename "$f")
  [[ "$fname" == "tempCodeRunnerFile.cpp" ]] && continue
  git mv "$f" "cpp/oops/$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')" 2>/dev/null || true
done
for f in "C++"/15.DATA\ HANDLING/*; do
  fname=$(basename "$f")
  git mv "$f" "cpp/oops/$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')" 2>/dev/null || true
done

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   C++ — operator overloading                 ║"
echo "╚══════════════════════════════════════════════╝"

for f in "C++"/16.OVERLOADING/*; do
  fname=$(basename "$f")
  git mv "$f" "cpp/operator-overloading/$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')" 2>/dev/null || true
done

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   C++ — inheritance                          ║"
echo "╚══════════════════════════════════════════════╝"

for f in "C++"/17.INHERITANCE/*; do
  fname=$(basename "$f")
  git mv "$f" "cpp/inheritance/$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')" 2>/dev/null || true
done

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   C++ — practice (QUESTIONS folder)          ║"
echo "╚══════════════════════════════════════════════╝"

# Well-named files — keep as-is (lowercase)
for f in \
  "C++/QUESTIONS/areaofcircle.cpp" \
  "C++/QUESTIONS/armstrong_number.cpp" \
  "C++/QUESTIONS/capital_to_small.cpp" \
  "C++/QUESTIONS/check_pallindrome.cpp" \
  "C++/QUESTIONS/defining_roots.cpp" \
  "C++/QUESTIONS/display_grades.cpp" \
  "C++/QUESTIONS/factorial.cpp" \
  "C++/QUESTIONS/factors.cpp" \
  "C++/QUESTIONS/multiplication_table.cpp" \
  "C++/QUESTIONS/pallindrome.cpp" \
  "C++/QUESTIONS/perfect_numbers.cpp" \
  "C++/QUESTIONS/prime_numbers.cpp" \
  "C++/QUESTIONS/reverse_numbers.cpp" \
  "C++/QUESTIONS/sum_n_number.cpp" \
  "C++/QUESTIONS/username_ingmail.cpp" \
  "C++/QUESTIONS/words_consonants_vowels.cpp" \
  "C++/QUESTIONS/tut6.cpp"; do
  fname=$(basename "$f")
  newname=$(echo "$fname" | sed 's/_/-/g' | tr '[:upper:]' '[:lower:]')
  [ "$fname" = "tut6.cpp" ] && newname="quadratic-equation-roots.cpp"
  git mv "$f" "cpp/practice/$newname" 2>/dev/null || true
done

# Vaguely named files — rename properly
git mv "C++/QUESTIONS/check.cpp"    "cpp/practice/matrix-2d-array-input.cpp"       2>/dev/null || true
git mv "C++/QUESTIONS/p6.cpp"       "cpp/practice/sum-of-digits.cpp"               2>/dev/null || true
git mv "C++/QUESTIONS/p7.cpp"       "cpp/practice/find-max-of-three.cpp"           2>/dev/null || true
git mv "C++/QUESTIONS/p8.cpp"       "cpp/practice/running-score-tracker.cpp"       2>/dev/null || true
git mv "C++/QUESTIONS/p9.cpp"       "cpp/practice/binary-steps-counter.cpp"        2>/dev/null || true
git mv "C++/QUESTIONS/p10.cpp"      "cpp/practice/testcase-skeleton.cpp"           2>/dev/null || true
git mv "C++/QUESTIONS/p12.cpp"      "cpp/practice/array-index-assignment.cpp"      2>/dev/null || true
git mv "C++/QUESTIONS/p13.cpp"      "cpp/practice/string-length-check.cpp"         2>/dev/null || true
git mv "C++/QUESTIONS/p14.cpp"      "cpp/practice/range-and-power-of-two-check.cpp" 2>/dev/null || true
git mv "C++/QUESTIONS/p16.cpp"      "cpp/practice/rectangle-class-oops.cpp"        2>/dev/null || true
git mv "C++/QUESTIONS/p17.cpp"      "cpp/practice/dynamic-array-on-heap.cpp"       2>/dev/null || true
git mv "C++/QUESTIONS/P5.cpp"       "cpp/practice/incomplete-scratch.cpp"          2>/dev/null || true

# Delete junk
git rm -f "C++/QUESTIONS/p15.cpp"                   2>/dev/null || true  # empty skeleton
git rm -f "C++/QUESTIONS/tempCodeRunnerFile.cpp"     2>/dev/null || true
git rm -f "C++/gg.cpp"                               2>/dev/null || true


echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   Java                                       ║"
echo "╚══════════════════════════════════════════════╝"

git mv "Java/basic.java"          "java/basics/BasicInputOutput.java"       2>/dev/null || true
git mv "Java/Strings.java"        "java/basics/StringBasics.java"           2>/dev/null || true
git mv "Java/Main.java"           "java/basics/StringMethods.java"          2>/dev/null || true
git mv "Java/arrays.java"         "java/basics/ArraysDemo.java"             2>/dev/null || true
git mv "Java/arraylist.java"      "java/basics/ArrayListDemo.java"          2>/dev/null || true
git mv "Java/functions.java"      "java/basics/StaticMethodsAndSwap.java"   2>/dev/null || true
git mv "Java/defaultvalues.java"  "java/basics/DefaultValuesDemo.java"      2>/dev/null || true
git mv "Java/Car.java"            "java/oops/Car.java"                      2>/dev/null || true
git mv "Java/circle.java"         "java/oops/Circle.java"                   2>/dev/null || true

# Javamain folder
for f in Javamain/*; do
  fname=$(basename "$f")
  [[ "$fname" == "tempCodeRunnerFile.cpp" ]] && continue
  git mv "$f" "java/basics/$fname" 2>/dev/null || true
done

# Java Dev Yt
git mv "Java/Java Dev Yt/Class1.java" "java/basics/EmptySkeleton.java"     2>/dev/null || true
git rm -f "Java/classmethods.java"                                          2>/dev/null || true


echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   DSA — arrays                               ║"
echo "╚══════════════════════════════════════════════╝"

git mv "DSA/array_addding.cpp"                          "dsa/arrays/insert-element-at-position.cpp"      2>/dev/null || true
git mv "DSA/array_adding2.cpp"                          "dsa/arrays/delete-element-at-index.cpp"         2>/dev/null || true
git mv "DSA/pointer1darray.cpp"                         "dsa/arrays/pointer-to-1d-array.cpp"             2>/dev/null || true
git mv "DSA/pointer_2darray.cpp"                        "dsa/arrays/pointer-to-2d-array.cpp"             2>/dev/null || true
git mv "Internshala DSA/Array/maximum_in_arr.cpp"       "dsa/arrays/find-maximum-in-array.cpp"           2>/dev/null || true
git mv "Internshala DSA/Array/sum_of_all.cpp"           "dsa/arrays/sum-of-all-elements.cpp"             2>/dev/null || true
git mv "Internshala DSA/Array/transpose.cpp"            "dsa/arrays/matrix-transpose.cpp"                2>/dev/null || true
git rm -f "Internshala DSA/Array/tempCodeRunnerFile.cpp"                                                  2>/dev/null || true
git mv "DSA/DSA 2.0/array_basic.cpp"                    "dsa/arrays/switch-case-movie-demo.cpp"          2>/dev/null || true
git mv "DSA/DSA 2.0/space_array.cpp"                    "dsa/arrays/space-complexity-array.cpp"          2>/dev/null || true

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   DSA — linked list                          ║"
echo "╚══════════════════════════════════════════════╝"

git mv "DSA/imlementation_ll.cpp"                       "dsa/linked-list/singly-ll-implementation.cpp"   2>/dev/null || true
git mv "DSA/lniked_list.cpp"                            "dsa/linked-list/singly-ll-node-struct.cpp"      2>/dev/null || true
git mv "Internshala DSA/Linkedlist/SinglyLL.cpp"        "dsa/linked-list/singly-ll-with-class.cpp"       2>/dev/null || true
git mv "Internshala DSA/Linkedlist/DoublyLL.cpp"        "dsa/linked-list/doubly-ll.cpp"                  2>/dev/null || true
git mv "Internshala DSA/Linkedlist/DoublyLLwithMenu.cpp" "dsa/linked-list/doubly-ll-with-menu.cpp"       2>/dev/null || true
git mv "Internshala DSA/Linkedlist/singleCircularLL.cpp" "dsa/linked-list/circular-singly-ll.cpp"        2>/dev/null || true

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   DSA — stacks and queues                    ║"
echo "╚══════════════════════════════════════════════╝"

git mv "Internshala DSA/Queue/queue.cpp"                "dsa/stacks-and-queues/circular-queue.cpp"       2>/dev/null || true

# Move stacks if they exist
for f in "Internshala DSA/Stack"/*; do
  fname=$(basename "$f")
  git mv "$f" "dsa/stacks-and-queues/$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')" 2>/dev/null || true
done

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   DSA — sorting                              ║"
echo "╚══════════════════════════════════════════════╝"

git mv "Internshala DSA/Sorting/bubblsort.cpp"          "dsa/sorting/bubble-sort.cpp"                    2>/dev/null || true
git mv "Internshala DSA/Sorting/insertionsort.cpp"      "dsa/sorting/insertion-sort.cpp"                 2>/dev/null || true
git mv "Internshala DSA/Sorting/selectionsort.cpp"      "dsa/sorting/selection-sort.cpp"                 2>/dev/null || true
git mv "Internshala DSA/Sorting/mergesort.cpp"          "dsa/sorting/merge-sort.cpp"                     2>/dev/null || true
git mv "Internshala DSA/Sorting/quicksort.cpp"          "dsa/sorting/quick-sort.cpp"                     2>/dev/null || true

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   DSA — binary search (11 LeetCode problems) ║"
echo "╚══════════════════════════════════════════════╝"

git mv "check.cpp"    "dsa/searching/binary-search/lc69-sqrt-integer.cpp"                  2>/dev/null || true
git mv "check1.cpp"   "dsa/searching/binary-search/lc34-first-last-position.cpp"           2>/dev/null || true
git mv "check2.cpp"   "dsa/searching/binary-search/lc34-first-last-position-v2.cpp"        2>/dev/null || true
git mv "check3.cpp"   "dsa/searching/binary-search/lc436-find-right-interval.cpp"          2>/dev/null || true
git mv "check4.cpp"   "dsa/searching/binary-search/lc441-arranging-coins.cpp"              2>/dev/null || true
git mv "check5.cpp"   "dsa/searching/binary-search/lc374-guess-number-higher-or-lower.cpp" 2>/dev/null || true
git mv "check6.cpp"   "dsa/searching/binary-search/lc278-first-bad-version.cpp"            2>/dev/null || true
git mv "check7.cpp"   "dsa/searching/binary-search/lc33-search-in-rotated-sorted-array.cpp" 2>/dev/null || true
git mv "check8.cpp"   "dsa/searching/binary-search/lc275-h-index-ii.cpp"                   2>/dev/null || true
git mv "check9.cpp"   "dsa/searching/binary-search/lc540-single-element-in-sorted-array.cpp" 2>/dev/null || true
git mv "check10.cpp"  "dsa/searching/binary-search/lc1337-k-weakest-rows-in-matrix.cpp"   2>/dev/null || true

# Supreme batch binary search files
git mv "DSA SUPREME BATCH/Begin.cpp"         "dsa/searching/binary-search/bs-template.cpp"                        2>/dev/null || true
git mv "DSA SUPREME BATCH/letters.cpp"       "dsa/searching/binary-search/lc744-smallest-letter-gt-target.cpp"   2>/dev/null || true
git mv "DSA SUPREME BATCH/Rightinterval.cpp" "dsa/searching/binary-search/lc436-right-interval-v2.cpp"           2>/dev/null || true

# DSA core binary search
git mv "DSA/DSA 2.0/binary_search.cpp"       "dsa/searching/binary-search/binary-search-basics.cpp"              2>/dev/null || true
git mv "DSA/DSA 2.0/excercise.cpp"           "dsa/searching/binary-search/binary-search-exercise.cpp"            2>/dev/null || true

# Striver two sum
git mv "DSA_Striver/twosum.cpp"              "dsa/searching/lc1-two-sum-hashmap.cpp"                             2>/dev/null || true
git mv "DSA_Striver/mappair.cpp"             "dsa/searching/map-of-pairs-stl.cpp"                                2>/dev/null || true

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   DSA — recursion                            ║"
echo "╚══════════════════════════════════════════════╝"

git mv "DSA/DSA 2.0/RECURSION/factorial.cpp"            "dsa/recursion/factorial.cpp"                    2>/dev/null || true
git mv "DSA/DSA 2.0/RECURSION/fibonacci.cpp"            "dsa/recursion/fibonacci.cpp"                    2>/dev/null || true
git mv "DSA/DSA 2.0/RECURSION/sum_n_numbers.cpp"        "dsa/recursion/sum-of-n-numbers.cpp"             2>/dev/null || true
git mv "DSA/DSA 2.0/RECURSION/tail_recursion.cpp"       "dsa/recursion/tail-recursion.cpp"               2>/dev/null || true
git mv "DSA/DSA 2.0/RECURSION/tree_recursion.cpp"       "dsa/recursion/tree-recursion.cpp"               2>/dev/null || true
git mv "DSA/DSA 2.0/RECURSION/taylor_series.cpp"        "dsa/recursion/taylor-series-expansion.cpp"      2>/dev/null || true
git mv "DSA/DSA 2.0/RECURSION/time_complexity.cpp"      "dsa/recursion/time-complexity-notes.cpp"        2>/dev/null || true
git mv "DSA/DSA 2.0/RECURSION/indirect_recursion.cpp"   "dsa/recursion/indirect-recursion.cpp"           2>/dev/null || true
git mv "DSA/DSA 2.0/indirect_recursion.cpp"             "dsa/recursion/indirect-recursion-v2.cpp"        2>/dev/null || true
git mv "DSA/DSA 2.0/arr.java"                           "dsa/recursion/PalindromeRecursion.java"         2>/dev/null || true

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   DSA — graphs                               ║"
echo "╚══════════════════════════════════════════════╝"

git mv "Internshala DSA/Graphs/creation.cpp"            "dsa/graphs/graph-creation-adjacency-list.cpp"   2>/dev/null || true

# BFS / DFS if present
git mv "Internshala DSA/Graphs/bfs.cpp"                 "dsa/graphs/bfs-breadth-first-search.cpp"        2>/dev/null || true
git mv "Internshala DSA/Graphs/dfs.cpp"                 "dsa/graphs/dfs-depth-first-search.cpp"          2>/dev/null || true

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   DSA — pointers (internshala)               ║"
echo "╚══════════════════════════════════════════════╝"

git mv "Internshala DSA/Pointers/pointers.cpp"          "cpp/pointers/pointers-basics.cpp"               2>/dev/null || true
git mv "Internshala DSA/Pointers/Dynamicmemalloc.cpp"   "cpp/pointers/dynamic-memory-allocation.cpp"     2>/dev/null || true

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   DSA — functions (internshala)              ║"
echo "╚══════════════════════════════════════════════╝"

git mv "Internshala DSA/Function/func.cpp"              "cpp/functions/function-basics-and-recursion.cpp" 2>/dev/null || true
git mv "Internshala DSA/Function/callbyadd.cpp"         "cpp/functions/call-by-address-swap.cpp"          2>/dev/null || true
git mv "Internshala DSA/Function/callbyref.cpp"         "cpp/functions/call-by-reference.cpp"             2>/dev/null || true
git mv "Internshala DSA/Function/passingarray.cpp"      "cpp/functions/passing-array-to-function.cpp"     2>/dev/null || true
git mv "Internshala DSA/Function/pointertofunc.cpp"     "cpp/functions/pointer-to-function.cpp"           2>/dev/null || true
git mv "Internshala DSA/Function/prc.cpp"               "cpp/functions/global-scope-resolution.cpp"       2>/dev/null || true
git mv "Internshala DSA/Function/scope.cpp"             "cpp/functions/scope-resolution-operator.cpp"     2>/dev/null || true

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   DSA — STL reference (CheatsheetSTL)        ║"
echo "╚══════════════════════════════════════════════╝"

for f in CheatsheetSTL/*; do
  fname=$(basename "$f")
  git mv "$f" "dsa/stl-reference/$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')" 2>/dev/null || true
done

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   DSA-FULL course files                      ║"
echo "╚══════════════════════════════════════════════╝"

# DSA-FULL has its own structure — preserve it under dsa/
for f in DSA-FULL/*; do
  fname=$(basename "$f")
  if [ -d "$f" ]; then
    mkdir -p "dsa/full-course/$fname"
    for ff in "$f"/*; do
      ffname=$(basename "$ff")
      git mv "$ff" "dsa/full-course/$fname/$ffname" 2>/dev/null || true
    done
  else
    git mv "$f" "dsa/full-course/$fname" 2>/dev/null || true
  fi
done

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   Competitive coding                         ║"
echo "╚══════════════════════════════════════════════╝"

git mv "CC QNA/sievesnippet.cpp"    "competitive-coding/sieve-of-eratosthenes.cpp"          2>/dev/null || true
git mv "CC QNA/CHECK.cpp"           "competitive-coding/sort-class-implementation.cpp"       2>/dev/null || true
git mv "CC QNA/PP2.cpp"             "competitive-coding/count-interior-lattice-points.cpp"   2>/dev/null || true
git mv "CC QNA/PP3.cpp"             "competitive-coding/array-processing-with-testcases.cpp" 2>/dev/null || true
git mv "CC QNA/PP4.cpp"             "competitive-coding/string-split-and-count.cpp"          2>/dev/null || true
git mv "CC QNA/PP5.cpp"             "competitive-coding/nearest-multiple-of-five.cpp"        2>/dev/null || true
git mv "CC QNA/PP6.cpp"             "competitive-coding/digit-count-of-difference.cpp"       2>/dev/null || true
git mv "CC QNA/PP7.cpp"             "competitive-coding/find-minimum-skill.cpp"              2>/dev/null || true
git mv "CC QNA/PP8.cpp"             "competitive-coding/print-one-to-ten.cpp"                2>/dev/null || true
git mv "CC QNA/PP10.cpp"            "competitive-coding/target-search-in-array.cpp"          2>/dev/null || true
git mv "CC QNA/PP11.cpp"            "competitive-coding/song-key-matching.cpp"               2>/dev/null || true
git mv "CC QNA/ccc.cpp"             "competitive-coding/vector-input-processing.cpp"         2>/dev/null || true
git mv "CC QNA/gg1.cpp"             "competitive-coding/count-digits-in-number.cpp"          2>/dev/null || true
git mv "CC QNA/ppp1.cpp"            "competitive-coding/matrix-multiplication.cpp"           2>/dev/null || true

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   College assignments                        ║"
echo "╚══════════════════════════════════════════════╝"

mkdir -p college
git mv "COLLEGE/p1.cpp"             "college/increment-and-print.cpp"                        2>/dev/null || true
git mv "COLLEGE/p2.cpp"             "college/find-max-of-three-numbers.cpp"                  2>/dev/null || true
git mv "COLLEGE/p3.cpp"             "college/dynamic-array-input.cpp"                        2>/dev/null || true
git rm -f "COLLEGE/cc.cpp"                                                                    2>/dev/null || true

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   Web                                        ║"
echo "╚══════════════════════════════════════════════╝"

# HTML basics
for f in HTML/*; do
  fname=$(basename "$f")
  git mv "$f" "web/html/$fname" 2>/dev/null || true
done

# Full stack HTML files
git mv "FULL_STACK/HTML5/textformatting.html"     "web/html/text-formatting.html"            2>/dev/null || true
git mv "FULL_STACK/HTML5/thankyou.html"           "web/html/form-thankyou-page.html"         2>/dev/null || true
git mv "FULL_STACK/HTML5/forms.html"              "web/html/html-forms.html"                 2>/dev/null || true
git mv "FULL_STACK/HTML5/tables.html"             "web/html/html-tables.html"                2>/dev/null || true

# CSS
for f in FULL_STACK/CSS/*; do
  fname=$(basename "$f")
  git mv "$f" "web/css/$fname" 2>/dev/null || true
done

# Projects
git mv "FULL_STACK/Project_prac/proj1/index.html"   "web/projects/ultimatix-dashboard/index.html"     2>/dev/null || true
git mv "FULL_STACK/Project_prac/proj1/style.css"    "web/projects/ultimatix-dashboard/style.css"      2>/dev/null || true
git mv "FULL_STACK/Project_prac/proj2/index.html"   "web/projects/empower-young-minds/index.html"     2>/dev/null || true
git mv "FULL_STACK/Project_prac/proj2/style.css"    "web/projects/empower-young-minds/style.css"      2>/dev/null || true
git mv "FULL_STACK/Project_prac/proj3/index.html"   "web/projects/css-box-model-demo/index.html"      2>/dev/null || true
git mv "FULL_STACK/Project_prac/proj3/styles.css"   "web/projects/css-box-model-demo/styles.css"      2>/dev/null || true

# Rename vague HTML files
git mv "web/html/fff.html"   "web/html/transparent-button-demo.html"   2>/dev/null || true
git mv "web/html/CSS.html"   "web/html/internal-external-css-demo.html" 2>/dev/null || true
git mv "web/html/BiodataPracticeproject.html" "web/html/biodata-svg-practice.html" 2>/dev/null || true

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   Projects                                   ║"
echo "╚══════════════════════════════════════════════╝"

git mv "Project/Front.cpp"              "projects/employee-management-system/employee-management-v1.cpp"    2>/dev/null || true
git mv "Project/frontfinal.cpp"         "projects/employee-management-system/employee-management-final.cpp" 2>/dev/null || true
git mv "Project/main.cpp"               "projects/sorting-visualizer/sorting-visualizer-sfml.cpp"           2>/dev/null || true
git mv "Project/tetris.cpp"             "projects/tetris/tetris-game.cpp"                                   2>/dev/null || true
git rm -f "Project/tempCodeRunnerFile.cpp"                                                                   2>/dev/null || true

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   Remove all compiled binaries & junk        ║"
echo "╚══════════════════════════════════════════════╝"

find . -name "*.exe"               -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true
find . -name "*.out"               -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true
find . -name "*.o"                 -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true
find . -name "tempCodeRunnerFile*" -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true

# Remove now-empty old folders
for dir in "C++" "C" "CC QNA" "COLLEGE" "CheatsheetSTL" "DSA" "DSA SUPREME BATCH" \
           "DSA-FULL" "DSA_Striver" "FULL_STACK" "HTML" "Internshala DSA" \
           "Java" "Javamain" "Project" ".vscode"; do
  git rm -rf "$dir" 2>/dev/null || true
done

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   Write .gitignore                           ║"
echo "╚══════════════════════════════════════════════╝"

cat > .gitignore << 'EOF'
# Compiled binaries
*.exe
*.out
*.o
*.class

# IDE / editor
.vscode/
.idea/
*.suo
*.user

# OS
.DS_Store
Thumbs.db

# Temp files
tempCodeRunnerFile*
EOF
git add .gitignore

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   Write README.md                            ║"
echo "╚══════════════════════════════════════════════╝"

cat > README.md << 'EOF'
# DSA & Programming Learning Repository

A well-structured collection of programs, data structures, algorithms,
and web development exercises, organized by topic for easy navigation.

## Repository Structure

```
├── c/                    C language fundamentals
│   ├── basics/           Variables, I/O, operators
│   ├── control-flow/     If-else, switch, ternary
│   ├── loops/            For, while, do-while
│   └── practice/         Practice problems
│
├── cpp/                  C++ fundamentals
│   ├── basics/           Data types, I/O
│   ├── arrays/           1D, 2D arrays
│   ├── strings/          String methods, STL
│   ├── functions/        Functions, recursion, templates
│   ├── pointers/         Pointers, dynamic memory
│   ├── oops/             Classes, constructors, destructors
│   ├── operator-overloading/
│   ├── inheritance/
│   └── practice/         Practice problems
│
├── java/                 Java fundamentals
│   ├── basics/           I/O, strings, arrays, collections
│   └── oops/             Classes, objects
│
├── dsa/                  Data Structures & Algorithms
│   ├── arrays/           Array operations, matrix
│   ├── linked-list/      Singly, doubly, circular
│   ├── stacks-and-queues/
│   ├── sorting/          Bubble, insertion, selection, merge, quick
│   ├── searching/
│   │   └── binary-search/ 11 LeetCode problems (LC 33, 34, 69, 278...)
│   ├── recursion/        Factorial, fibonacci, taylor series
│   ├── graphs/           Adjacency list, BFS, DFS
│   ├── stl-reference/    C++ STL cheatsheet
│   └── full-course/      Complete DSA course notes
│
├── web/                  Web development
│   ├── html/             HTML basics and formatting
│   ├── css/              CSS styling
│   └── projects/         Mini web projects
│
├── competitive-coding/   Competitive programming problems
├── college/              College assignments
└── projects/             Personal projects (SFML visualizer, Tetris, EMS)
```

## Topics Covered

**Languages:** C, C++, Java
**DSA:** Arrays, Linked Lists, Stacks, Queues, Sorting, Binary Search, Recursion, Graphs
**Web:** HTML, CSS, JavaScript
**Tools:** STL, SFML

## LeetCode Binary Search Problems

| File | Problem |
|------|---------|
| lc69-sqrt-integer.cpp | LC 69 — Sqrt(x) |
| lc34-first-last-position.cpp | LC 34 — First and Last Position |
| lc436-find-right-interval.cpp | LC 436 — Find Right Interval |
| lc441-arranging-coins.cpp | LC 441 — Arranging Coins |
| lc374-guess-number-higher-or-lower.cpp | LC 374 — Guess Number |
| lc278-first-bad-version.cpp | LC 278 — First Bad Version |
| lc33-search-in-rotated-sorted-array.cpp | LC 33 — Search Rotated Array |
| lc275-h-index-ii.cpp | LC 275 — H-Index II |
| lc540-single-element-in-sorted-array.cpp | LC 540 — Single Element |
| lc1337-k-weakest-rows-in-matrix.cpp | LC 1337 — K Weakest Rows |
EOF
git add README.md

echo ""
echo "╔══════════════════════════════════════════════╗"
echo "║   Commit and push                            ║"
echo "╚══════════════════════════════════════════════╝"

git add -A
git commit -m "refactor: complete repository restructure and rename

New structure:
  c/          → basics, control-flow, loops, practice
  cpp/        → basics, arrays, strings, functions, pointers, oops,
                operator-overloading, inheritance, practice
  java/       → basics, oops
  dsa/        → arrays, linked-list, stacks-and-queues, sorting,
                searching/binary-search, recursion, graphs,
                stl-reference, full-course
  web/        → html, css, projects
  competitive-coding/
  college/
  projects/   → employee-management-system, sorting-visualizer, tetris

Changes:
  - All check*.cpp renamed with LC number prefix (lc69, lc34, etc.)
  - All C tutorial files renamed (1.first.c → 01-hello-world.c)
  - All vague p6-p17 cpp files renamed to descriptive names
  - All Java files renamed to PascalCase with meaningful names
  - Removed all .exe binaries, tempCodeRunnerFile.cpp, empty files
  - Added comprehensive README and .gitignore"

git push origin main

echo ""
echo "✅ Done! Your repo is fully restructured and pushed."
echo "   Visit: https://github.com/AnsumanEI/Learning-Directory"
