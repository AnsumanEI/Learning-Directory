#!/bin/bash
# ================================================================
#  FINAL COMPLETE RESTRUCTURE — Learning-Directory (Windows-safe)
#  Run from: root of your repo in Git Bash
# ================================================================
set -e

echo ""
echo "==> Creating new folder structure..."

mkdir -p lang-c/basics
mkdir -p lang-c/control-flow
mkdir -p lang-c/loops
mkdir -p lang-c/practice

mkdir -p lang-cpp/basics
mkdir -p lang-cpp/arrays
mkdir -p lang-cpp/strings
mkdir -p lang-cpp/functions
mkdir -p lang-cpp/pointers
mkdir -p lang-cpp/oops
mkdir -p lang-cpp/operator-overloading
mkdir -p lang-cpp/inheritance
mkdir -p lang-cpp/practice

mkdir -p lang-java/basics
mkdir -p lang-java/oops

mkdir -p dsa/arrays
mkdir -p dsa/linked-list
mkdir -p dsa/stacks-and-queues
mkdir -p dsa/sorting
mkdir -p dsa/searching/binary-search
mkdir -p dsa/recursion
mkdir -p dsa/graphs
mkdir -p dsa/stl-reference
mkdir -p dsa/full-course

mkdir -p web/html
mkdir -p web/css
mkdir -p web/projects/ultimatix-dashboard
mkdir -p web/projects/empower-young-minds
mkdir -p web/projects/css-box-model-demo

mkdir -p competitive-coding
mkdir -p college

mkdir -p projects/employee-management-system
mkdir -p projects/sorting-visualizer
mkdir -p projects/tetris

echo "==> Folders created."

echo ""
echo "==> C — basics"
git mv "C/1.first.c"               "lang-c/basics/01-hello-world.c"                   2>/dev/null || true
git mv "C/2.variables.c"           "lang-c/basics/02-variables-and-datatypes.c"        2>/dev/null || true
git mv "C/3.question1.c"           "lang-c/basics/03-addition-of-two-numbers.c"        2>/dev/null || true
git mv "C/4.input.c"               "lang-c/basics/04-user-input-and-sum.c"             2>/dev/null || true
git mv "C/5.Practice.c"            "lang-c/basics/05-arithmetic-operators-practice.c"  2>/dev/null || true
git mv "C/6.Instructions.c"        "lang-c/basics/06-arithmetic-operators.c"           2>/dev/null || true
git mv "C/7.Operator_precedence.c" "lang-c/basics/07-operator-precedence.c"            2>/dev/null || true
git mv "C/C1P1.c"                  "lang-c/basics/08-area-of-rectangle.c"              2>/dev/null || true
git mv "C/C1P2.c"                  "lang-c/basics/09-area-of-circle.c"                 2>/dev/null || true
git mv "C/C1P3.c"                  "lang-c/basics/10-celsius-to-fahrenheit.c"          2>/dev/null || true
git mv "C/C2P1.c"                  "lang-c/basics/11-bitwise-xor-and-divisibility.c"   2>/dev/null || true

echo "==> C — control flow"
git mv "C/8.Conditonal_operators.c"  "lang-c/control-flow/01-even-odd-check.c"            2>/dev/null || true
git mv "C/9.logical_operators.c"     "lang-c/control-flow/02-logical-operators-driving.c"  2>/dev/null || true
git mv "C/10.conditonal_operators.c" "lang-c/control-flow/03-ternary-operator.c"           2>/dev/null || true
git mv "C/11.switchcase.c"           "lang-c/control-flow/04-switch-case-rating.c"         2>/dev/null || true
git mv "C/C2P3.c"                    "lang-c/control-flow/05-basic-calculator.c"            2>/dev/null || true
git mv "C/C3P4.c"                    "lang-c/control-flow/06-grade-calculator.c"            2>/dev/null || true
git mv "C/C3P5.c"                    "lang-c/control-flow/07-age-check-if-else.c"           2>/dev/null || true
git mv "C/C3P6.c"                    "lang-c/control-flow/08-marks-percentage.c"            2>/dev/null || true
git mv "C/C3P7.c"                    "lang-c/control-flow/09-income-tax-calculator.c"       2>/dev/null || true
git mv "C/C3P8.c"                    "lang-c/control-flow/10-leap-year-check.c"             2>/dev/null || true
git mv "C/C3P9.c"                    "lang-c/control-flow/11-find-greatest-of-four.c"       2>/dev/null || true
git mv "C/C3P10.c"                   "lang-c/control-flow/12-uppercase-lowercase-check.c"   2>/dev/null || true

echo "==> C — loops"
git mv "C/12.Loop_control_instruction.c"   "lang-c/loops/01-while-loop-range.c"         2>/dev/null || true
git mv "C/123/for_loop.c"                  "lang-c/loops/02-for-loop-basic.c"            2>/dev/null || true
git mv "C/123/dowhile.c"                   "lang-c/loops/03-do-while-natural-numbers.c"  2>/dev/null || true
git mv "C/chapter 4/break_statement.c"     "lang-c/loops/04-break-statement.c"           2>/dev/null || true
git mv "C/chapter 4/continue_loop.c"       "lang-c/loops/05-continue-statement.c"        2>/dev/null || true
git mv "C/chapter 4/decrmenting_forloop.c" "lang-c/loops/06-decrementing-for-loop.c"     2>/dev/null || true
git mv "C/chapter 4/question_3.c"          "lang-c/loops/07-sum-of-n-natural-numbers.c"  2>/dev/null || true
git mv "C/chapter 4/question_4.c"          "lang-c/loops/08-factorial-using-loop.c"      2>/dev/null || true
git mv "C/chapter 4/question_5.c"          "lang-c/loops/09-infinite-while-loop-demo.c"  2>/dev/null || true
git mv "C/chapter 4/question_6.c"          "lang-c/loops/10-prime-number-check.c"        2>/dev/null || true
git mv "C/chapter 4/asxsax.c"              "lang-c/loops/11-for-loop-rewrite.c"          2>/dev/null || true

echo "==> C — practice"
git mv "C/123/armstrong.c"                              "lang-c/practice/armstrong-number.c"           2>/dev/null || true
git mv "C/123/calculator.c"                             "lang-c/practice/calculator-with-operators.c"  2>/dev/null || true
git mv "C/123/convert second to min.c"                  "lang-c/practice/seconds-to-hours-minutes.c"   2>/dev/null || true
git mv "C/123/detetminin _the_largest_integer.c"        "lang-c/practice/find-largest-integer.c"       2>/dev/null || true
git mv "C/123/first.c"                                  "lang-c/practice/square-root.c"                2>/dev/null || true
git mv "C/123/how_to check the_aunthenticity _of_an_equation.c" "lang-c/practice/relational-operators-demo.c" 2>/dev/null || true
git mv "C/123/infinity.c"                               "lang-c/practice/memory-addresses.c"           2>/dev/null || true
git mv "C/123/perfect_num.c"                            "lang-c/practice/perfect-number-check.c"       2>/dev/null || true
git mv "C/123/practiceset1.c"                           "lang-c/practice/logical-not-operator.c"       2>/dev/null || true
git mv "C/123/reverse_the_character.c"                  "lang-c/practice/toggle-character-case.c"      2>/dev/null || true
git mv "C/chapter 4/check.c"                            "lang-c/practice/modulo-scratch.c"             2>/dev/null || true

echo "==> C++ — numbered chapters to basics"
for d in "C++/1.INTRODUCTION AND DATATYPES" "C++/2.OPERATORS" "C++/3.CONDITIONAL STATEMENTS" \
         "C++/4.LOOPS" "C++/5.PATTERNS" "C++/6.FUNCTIONS"; do
  [ -d "$d" ] || continue
  for f in "$d"/*; do
    fname=$(basename "$f")
    [[ "$fname" == "tempCodeRunnerFile.cpp" ]] && continue
    lname=$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')
    git mv "$f" "lang-cpp/basics/$lname" 2>/dev/null || true
  done
done

echo "==> C++ — arrays"
for f in "C++/7.ARRAYS AND STRINGS"/*; do
  fname=$(basename "$f"); lname=$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')
  git mv "$f" "lang-cpp/arrays/$lname" 2>/dev/null || true
done

echo "==> C++ — strings"
for f in "C++/10.CLASS STRINGS AND FUNCTIONS"/*; do
  fname=$(basename "$f"); lname=$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')
  git mv "$f" "lang-cpp/strings/$lname" 2>/dev/null || true
done

echo "==> C++ — functions and recursion"
for f in "C++/11.FUNCTION"/*; do
  fname=$(basename "$f"); [[ "$fname" == "tempCodeRunnerFile.cpp" ]] && continue
  lname=$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')
  git mv "$f" "lang-cpp/functions/$lname" 2>/dev/null || true
done
for f in "C++/12.PARAMETRE PASSING & RETURNING & POINTING FUCNTIONS"/*; do
  fname=$(basename "$f"); lname=$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')
  git mv "$f" "lang-cpp/functions/$lname" 2>/dev/null || true
done
for f in "C++/13.RECURSIONS"/*; do
  fname=$(basename "$f"); lname=$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')
  git mv "$f" "lang-cpp/functions/recursion-$lname" 2>/dev/null || true
done

echo "==> C++ — pointers"
for f in "C++/8.POINTERS"/*; do
  fname=$(basename "$f"); lname=$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')
  git mv "$f" "lang-cpp/pointers/$lname" 2>/dev/null || true
done
for f in "C++/9.DYNAMIC MEMORY"/*; do
  fname=$(basename "$f"); lname=$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')
  git mv "$f" "lang-cpp/pointers/dynamic-$lname" 2>/dev/null || true
done

echo "==> C++ — OOPs"
for f in "C++/14.OOPS"/*; do
  fname=$(basename "$f"); [[ "$fname" == "tempCodeRunnerFile.cpp" ]] && continue
  lname=$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')
  git mv "$f" "lang-cpp/oops/$lname" 2>/dev/null || true
done
for f in "C++/15.DATA HANDLING"/*; do
  fname=$(basename "$f"); lname=$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')
  git mv "$f" "lang-cpp/oops/$lname" 2>/dev/null || true
done

echo "==> C++ — operator overloading"
for f in "C++/16.OVERLOADING"/*; do
  fname=$(basename "$f"); lname=$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')
  git mv "$f" "lang-cpp/operator-overloading/$lname" 2>/dev/null || true
done

echo "==> C++ — inheritance"
for f in "C++/17.INHERITANCE"/*; do
  fname=$(basename "$f"); lname=$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')
  git mv "$f" "lang-cpp/inheritance/$lname" 2>/dev/null || true
done

echo "==> C++ — practice"
git mv "C++/QUESTIONS/areaofcircle.cpp"           "lang-cpp/practice/area-of-circle.cpp"                2>/dev/null || true
git mv "C++/QUESTIONS/armstrong_number.cpp"        "lang-cpp/practice/armstrong-number.cpp"              2>/dev/null || true
git mv "C++/QUESTIONS/capital_to_small.cpp"        "lang-cpp/practice/toggle-char-case.cpp"              2>/dev/null || true
git mv "C++/QUESTIONS/check_pallindrome.cpp"       "lang-cpp/practice/check-palindrome-string.cpp"       2>/dev/null || true
git mv "C++/QUESTIONS/defining_roots.cpp"          "lang-cpp/practice/define-nature-of-roots.cpp"        2>/dev/null || true
git mv "C++/QUESTIONS/display_grades.cpp"          "lang-cpp/practice/display-grades.cpp"                2>/dev/null || true
git mv "C++/QUESTIONS/factorial.cpp"               "lang-cpp/practice/factorial.cpp"                     2>/dev/null || true
git mv "C++/QUESTIONS/factors.cpp"                 "lang-cpp/practice/find-factors.cpp"                  2>/dev/null || true
git mv "C++/QUESTIONS/multiplication_table.cpp"    "lang-cpp/practice/multiplication-table.cpp"          2>/dev/null || true
git mv "C++/QUESTIONS/pallindrome.cpp"             "lang-cpp/practice/palindrome-reverse-string.cpp"     2>/dev/null || true
git mv "C++/QUESTIONS/perfect_numbers.cpp"         "lang-cpp/practice/perfect-number-check.cpp"          2>/dev/null || true
git mv "C++/QUESTIONS/prime_numbers.cpp"           "lang-cpp/practice/count-divisible-by-k.cpp"          2>/dev/null || true
git mv "C++/QUESTIONS/reverse_numbers.cpp"         "lang-cpp/practice/reverse-a-number.cpp"              2>/dev/null || true
git mv "C++/QUESTIONS/sum_n_number.cpp"            "lang-cpp/practice/sum-of-n-numbers.cpp"              2>/dev/null || true
git mv "C++/QUESTIONS/username_ingmail.cpp"        "lang-cpp/practice/extract-username-from-email.cpp"   2>/dev/null || true
git mv "C++/QUESTIONS/words_consonants_vowels.cpp" "lang-cpp/practice/count-words-vowels-consonants.cpp" 2>/dev/null || true
git mv "C++/QUESTIONS/tut6.cpp"                    "lang-cpp/practice/quadratic-equation-roots.cpp"      2>/dev/null || true
git mv "C++/QUESTIONS/check.cpp"                   "lang-cpp/practice/matrix-2d-array-input.cpp"         2>/dev/null || true
git mv "C++/QUESTIONS/p6.cpp"                      "lang-cpp/practice/sum-of-digits.cpp"                 2>/dev/null || true
git mv "C++/QUESTIONS/p7.cpp"                      "lang-cpp/practice/find-max-of-three.cpp"             2>/dev/null || true
git mv "C++/QUESTIONS/p8.cpp"                      "lang-cpp/practice/running-score-tracker.cpp"         2>/dev/null || true
git mv "C++/QUESTIONS/p9.cpp"                      "lang-cpp/practice/binary-steps-counter.cpp"          2>/dev/null || true
git mv "C++/QUESTIONS/p12.cpp"                     "lang-cpp/practice/array-index-assignment.cpp"        2>/dev/null || true
git mv "C++/QUESTIONS/p13.cpp"                     "lang-cpp/practice/string-length-check.cpp"           2>/dev/null || true
git mv "C++/QUESTIONS/p14.cpp"                     "lang-cpp/practice/range-and-power-of-two-check.cpp"  2>/dev/null || true
git mv "C++/QUESTIONS/p16.cpp"                     "lang-cpp/practice/rectangle-class-oops.cpp"          2>/dev/null || true
git mv "C++/QUESTIONS/p17.cpp"                     "lang-cpp/practice/dynamic-array-on-heap.cpp"         2>/dev/null || true
git rm -f "C++/QUESTIONS/p10.cpp" "C++/QUESTIONS/p15.cpp" "C++/QUESTIONS/P5.cpp" \
          "C++/QUESTIONS/tempCodeRunnerFile.cpp" "C++/gg.cpp" 2>/dev/null || true

echo "==> Java"
git mv "Java/basic.java"              "lang-java/basics/BasicInputOutput.java"     2>/dev/null || true
git mv "Java/Strings.java"            "lang-java/basics/StringBasics.java"         2>/dev/null || true
git mv "Java/Main.java"               "lang-java/basics/StringMethods.java"        2>/dev/null || true
git mv "Java/arrays.java"             "lang-java/basics/ArraysDemo.java"           2>/dev/null || true
git mv "Java/arraylist.java"          "lang-java/basics/ArrayListDemo.java"        2>/dev/null || true
git mv "Java/functions.java"          "lang-java/basics/StaticMethodsAndSwap.java" 2>/dev/null || true
git mv "Java/defaultvalues.java"      "lang-java/basics/DefaultValuesDemo.java"    2>/dev/null || true
git mv "Java/Car.java"                "lang-java/oops/Car.java"                    2>/dev/null || true
git mv "Java/circle.java"             "lang-java/oops/Circle.java"                 2>/dev/null || true
git mv "Java/Java Dev Yt/Class1.java" "lang-java/basics/EmptySkeleton.java"       2>/dev/null || true
for f in Javamain/*; do
  fname=$(basename "$f"); [[ "$fname" == "tempCodeRunnerFile.cpp" ]] && continue
  git mv "$f" "lang-java/basics/$fname" 2>/dev/null || true
done
git rm -f "Java/classmethods.java" 2>/dev/null || true

echo "==> DSA — arrays"
git mv "DSA/array_addding.cpp"                    "dsa/arrays/insert-element-at-position.cpp" 2>/dev/null || true
git mv "DSA/array_adding2.cpp"                    "dsa/arrays/delete-element-at-index.cpp"    2>/dev/null || true
git mv "DSA/pointer1darray.cpp"                   "dsa/arrays/pointer-to-1d-array.cpp"        2>/dev/null || true
git mv "DSA/pointer_2darray.cpp"                  "dsa/arrays/pointer-to-2d-array.cpp"        2>/dev/null || true
git mv "Internshala DSA/Array/maximum_in_arr.cpp" "dsa/arrays/find-maximum-in-array.cpp"      2>/dev/null || true
git mv "Internshala DSA/Array/sum_of_all.cpp"     "dsa/arrays/sum-of-all-elements.cpp"        2>/dev/null || true
git mv "Internshala DSA/Array/transpose.cpp"      "dsa/arrays/matrix-transpose.cpp"           2>/dev/null || true
git mv "DSA/DSA 2.0/space_array.cpp"              "dsa/arrays/space-complexity-array.cpp"     2>/dev/null || true
git mv "DSA/DSA 2.0/array_basic.cpp"              "dsa/arrays/switch-case-movie-demo.cpp"     2>/dev/null || true
git rm -f "Internshala DSA/Array/tempCodeRunnerFile.cpp" 2>/dev/null || true

echo "==> DSA — linked list"
git mv "DSA/imlementation_ll.cpp"                        "dsa/linked-list/singly-ll-implementation.cpp" 2>/dev/null || true
git mv "DSA/lniked_list.cpp"                             "dsa/linked-list/singly-ll-node-struct.cpp"    2>/dev/null || true
git mv "Internshala DSA/Linkedlist/SinglyLL.cpp"         "dsa/linked-list/singly-ll-with-class.cpp"     2>/dev/null || true
git mv "Internshala DSA/Linkedlist/DoublyLL.cpp"         "dsa/linked-list/doubly-ll.cpp"                2>/dev/null || true
git mv "Internshala DSA/Linkedlist/DoublyLLwithMenu.cpp" "dsa/linked-list/doubly-ll-with-menu.cpp"      2>/dev/null || true
git mv "Internshala DSA/Linkedlist/singleCircularLL.cpp" "dsa/linked-list/circular-singly-ll.cpp"       2>/dev/null || true

echo "==> DSA — stacks and queues"
git mv "Internshala DSA/Queue/queue.cpp" "dsa/stacks-and-queues/circular-queue.cpp" 2>/dev/null || true
for f in "Internshala DSA/Stack"/*; do
  fname=$(basename "$f")
  git mv "$f" "dsa/stacks-and-queues/$fname" 2>/dev/null || true
done

echo "==> DSA — sorting"
git mv "Internshala DSA/Sorting/bubblsort.cpp"     "dsa/sorting/bubble-sort.cpp"    2>/dev/null || true
git mv "Internshala DSA/Sorting/insertionsort.cpp" "dsa/sorting/insertion-sort.cpp" 2>/dev/null || true
git mv "Internshala DSA/Sorting/selectionsort.cpp" "dsa/sorting/selection-sort.cpp" 2>/dev/null || true
git mv "Internshala DSA/Sorting/mergesort.cpp"     "dsa/sorting/merge-sort.cpp"     2>/dev/null || true
git mv "Internshala DSA/Sorting/quicksort.cpp"     "dsa/sorting/quick-sort.cpp"     2>/dev/null || true

echo "==> DSA — binary search"
git mv "check.cpp"    "dsa/searching/binary-search/lc69-sqrt-integer.cpp"                   2>/dev/null || true
git mv "check1.cpp"   "dsa/searching/binary-search/lc34-first-last-position.cpp"            2>/dev/null || true
git mv "check2.cpp"   "dsa/searching/binary-search/lc34-first-last-position-v2.cpp"         2>/dev/null || true
git mv "check3.cpp"   "dsa/searching/binary-search/lc436-find-right-interval.cpp"           2>/dev/null || true
git mv "check4.cpp"   "dsa/searching/binary-search/lc441-arranging-coins.cpp"               2>/dev/null || true
git mv "check5.cpp"   "dsa/searching/binary-search/lc374-guess-number-higher-or-lower.cpp"  2>/dev/null || true
git mv "check6.cpp"   "dsa/searching/binary-search/lc278-first-bad-version.cpp"             2>/dev/null || true
git mv "check7.cpp"   "dsa/searching/binary-search/lc33-search-in-rotated-sorted-array.cpp" 2>/dev/null || true
git mv "check8.cpp"   "dsa/searching/binary-search/lc275-h-index-ii.cpp"                    2>/dev/null || true
git mv "check9.cpp"   "dsa/searching/binary-search/lc540-single-element-in-sorted-array.cpp" 2>/dev/null || true
git mv "check10.cpp"  "dsa/searching/binary-search/lc1337-k-weakest-rows-in-matrix.cpp"    2>/dev/null || true
git mv "DSA SUPREME BATCH/Begin.cpp"         "dsa/searching/binary-search/bs-template.cpp"                     2>/dev/null || true
git mv "DSA SUPREME BATCH/letters.cpp"       "dsa/searching/binary-search/lc744-smallest-letter-gt-target.cpp" 2>/dev/null || true
git mv "DSA SUPREME BATCH/Rightinterval.cpp" "dsa/searching/binary-search/lc436-right-interval-v2.cpp"         2>/dev/null || true
git mv "DSA/DSA 2.0/binary_search.cpp"       "dsa/searching/binary-search/binary-search-basics.cpp"            2>/dev/null || true
git mv "DSA/DSA 2.0/excercise.cpp"           "dsa/searching/binary-search/binary-search-exercise.cpp"          2>/dev/null || true
git mv "DSA_Striver/twosum.cpp"              "dsa/searching/lc1-two-sum-hashmap.cpp"                           2>/dev/null || true
git mv "DSA_Striver/mappair.cpp"             "dsa/searching/map-of-pairs-stl.cpp"                              2>/dev/null || true

echo "==> DSA — recursion"
git mv "DSA/DSA 2.0/RECURSION/factorial.cpp"          "dsa/recursion/factorial.cpp"               2>/dev/null || true
git mv "DSA/DSA 2.0/RECURSION/fibonacci.cpp"          "dsa/recursion/fibonacci.cpp"               2>/dev/null || true
git mv "DSA/DSA 2.0/RECURSION/sum_n_numbers.cpp"      "dsa/recursion/sum-of-n-numbers.cpp"        2>/dev/null || true
git mv "DSA/DSA 2.0/RECURSION/tail_recursion.cpp"     "dsa/recursion/tail-recursion.cpp"          2>/dev/null || true
git mv "DSA/DSA 2.0/RECURSION/tree_recursion.cpp"     "dsa/recursion/tree-recursion.cpp"          2>/dev/null || true
git mv "DSA/DSA 2.0/RECURSION/taylor_series.cpp"      "dsa/recursion/taylor-series-expansion.cpp" 2>/dev/null || true
git mv "DSA/DSA 2.0/RECURSION/time_complexity.cpp"    "dsa/recursion/time-complexity-notes.cpp"   2>/dev/null || true
git mv "DSA/DSA 2.0/RECURSION/indirect_recursion.cpp" "dsa/recursion/indirect-recursion.cpp"      2>/dev/null || true
git mv "DSA/DSA 2.0/indirect_recursion.cpp"           "dsa/recursion/indirect-recursion-v2.cpp"   2>/dev/null || true
git mv "DSA/DSA 2.0/arr.java"                         "dsa/recursion/PalindromeRecursion.java"    2>/dev/null || true

echo "==> DSA — graphs"
git mv "Internshala DSA/Graphs/creation.cpp" "dsa/graphs/graph-creation-adjacency-list.cpp" 2>/dev/null || true
git mv "Internshala DSA/Graphs/bfs.cpp"      "dsa/graphs/bfs-breadth-first-search.cpp"      2>/dev/null || true
git mv "Internshala DSA/Graphs/dfs.cpp"      "dsa/graphs/dfs-depth-first-search.cpp"        2>/dev/null || true

echo "==> Internshala functions + pointers -> lang-cpp"
git mv "Internshala DSA/Pointers/pointers.cpp"        "lang-cpp/pointers/pointers-basics.cpp"               2>/dev/null || true
git mv "Internshala DSA/Pointers/Dynamicmemalloc.cpp" "lang-cpp/pointers/dynamic-memory-allocation.cpp"     2>/dev/null || true
git mv "Internshala DSA/Function/func.cpp"            "lang-cpp/functions/function-basics-and-recursion.cpp" 2>/dev/null || true
git mv "Internshala DSA/Function/callbyadd.cpp"       "lang-cpp/functions/call-by-address-swap.cpp"         2>/dev/null || true
git mv "Internshala DSA/Function/callbyref.cpp"       "lang-cpp/functions/call-by-reference.cpp"            2>/dev/null || true
git mv "Internshala DSA/Function/passingarray.cpp"    "lang-cpp/functions/passing-array-to-function.cpp"    2>/dev/null || true
git mv "Internshala DSA/Function/pointertofunc.cpp"   "lang-cpp/functions/pointer-to-function.cpp"          2>/dev/null || true
git mv "Internshala DSA/Function/prc.cpp"             "lang-cpp/functions/global-scope-resolution.cpp"      2>/dev/null || true
git mv "Internshala DSA/Function/scope.cpp"           "lang-cpp/functions/scope-resolution-operator.cpp"    2>/dev/null || true

echo "==> DSA — STL reference"
for f in CheatsheetSTL/*; do
  fname=$(basename "$f"); lname=$(echo "$fname" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')
  git mv "$f" "dsa/stl-reference/$lname" 2>/dev/null || true
done

echo "==> DSA — full course"
for item in DSA-FULL/*; do
  iname=$(basename "$item")
  if [ -d "$item" ]; then
    mkdir -p "dsa/full-course/$iname"
    for f in "$item"/*; do git mv "$f" "dsa/full-course/$iname/$(basename "$f")" 2>/dev/null || true; done
  else
    git mv "$item" "dsa/full-course/$iname" 2>/dev/null || true
  fi
done

echo "==> Competitive coding"
git mv "CC QNA/sievesnippet.cpp" "competitive-coding/sieve-of-eratosthenes.cpp"          2>/dev/null || true
git mv "CC QNA/CHECK.cpp"        "competitive-coding/sort-class-implementation.cpp"       2>/dev/null || true
git mv "CC QNA/PP2.cpp"          "competitive-coding/count-interior-lattice-points.cpp"   2>/dev/null || true
git mv "CC QNA/PP3.cpp"          "competitive-coding/array-processing-with-testcases.cpp" 2>/dev/null || true
git mv "CC QNA/PP4.cpp"          "competitive-coding/string-split-and-count.cpp"          2>/dev/null || true
git mv "CC QNA/PP5.cpp"          "competitive-coding/nearest-multiple-of-five.cpp"        2>/dev/null || true
git mv "CC QNA/PP6.cpp"          "competitive-coding/digit-count-of-difference.cpp"       2>/dev/null || true
git mv "CC QNA/PP7.cpp"          "competitive-coding/find-minimum-skill.cpp"              2>/dev/null || true
git mv "CC QNA/PP8.cpp"          "competitive-coding/print-one-to-ten.cpp"                2>/dev/null || true
git mv "CC QNA/PP10.cpp"         "competitive-coding/target-search-in-array.cpp"          2>/dev/null || true
git mv "CC QNA/PP11.cpp"         "competitive-coding/song-key-matching.cpp"               2>/dev/null || true
git mv "CC QNA/ccc.cpp"          "competitive-coding/vector-input-processing.cpp"         2>/dev/null || true
git mv "CC QNA/gg1.cpp"          "competitive-coding/count-digits-in-number.cpp"          2>/dev/null || true
git mv "CC QNA/ppp1.cpp"         "competitive-coding/matrix-multiplication.cpp"           2>/dev/null || true

echo "==> College"
git mv "COLLEGE/p1.cpp" "college/increment-and-print.cpp"       2>/dev/null || true
git mv "COLLEGE/p2.cpp" "college/find-max-of-three-numbers.cpp" 2>/dev/null || true
git mv "COLLEGE/p3.cpp" "college/dynamic-array-input.cpp"       2>/dev/null || true
git rm -f "COLLEGE/cc.cpp"                                       2>/dev/null || true

echo "==> Web — HTML"
for f in HTML/*; do fname=$(basename "$f"); git mv "$f" "web/html/$fname" 2>/dev/null || true; done
git mv "FULL_STACK/HTML5/textformatting.html" "web/html/text-formatting.html"   2>/dev/null || true
git mv "FULL_STACK/HTML5/thankyou.html"       "web/html/form-thankyou-page.html" 2>/dev/null || true
git mv "FULL_STACK/HTML5/forms.html"          "web/html/html-forms.html"        2>/dev/null || true
git mv "FULL_STACK/HTML5/tables.html"         "web/html/html-tables.html"       2>/dev/null || true
git mv "web/html/fff.html"                    "web/html/transparent-button-demo.html"     2>/dev/null || true
git mv "web/html/CSS.html"                    "web/html/internal-external-css-demo.html"  2>/dev/null || true
git mv "web/html/BiodataPracticeproject.html" "web/html/biodata-svg-practice.html"        2>/dev/null || true

echo "==> Web — CSS"
for f in FULL_STACK/CSS/*; do fname=$(basename "$f"); git mv "$f" "web/css/$fname" 2>/dev/null || true; done

echo "==> Web — Projects"
git mv "FULL_STACK/Project_prac/proj1/index.html" "web/projects/ultimatix-dashboard/index.html"  2>/dev/null || true
git mv "FULL_STACK/Project_prac/proj1/style.css"  "web/projects/ultimatix-dashboard/style.css"   2>/dev/null || true
git mv "FULL_STACK/Project_prac/proj2/index.html" "web/projects/empower-young-minds/index.html"  2>/dev/null || true
git mv "FULL_STACK/Project_prac/proj2/style.css"  "web/projects/empower-young-minds/style.css"   2>/dev/null || true
git mv "FULL_STACK/Project_prac/proj3/index.html" "web/projects/css-box-model-demo/index.html"   2>/dev/null || true
git mv "FULL_STACK/Project_prac/proj3/styles.css" "web/projects/css-box-model-demo/styles.css"   2>/dev/null || true

echo "==> Projects"
git mv "Project/Front.cpp"      "projects/employee-management-system/employee-management-v1.cpp"    2>/dev/null || true
git mv "Project/frontfinal.cpp" "projects/employee-management-system/employee-management-final.cpp" 2>/dev/null || true
git mv "Project/main.cpp"       "projects/sorting-visualizer/sorting-visualizer-sfml.cpp"           2>/dev/null || true
git mv "Project/tetris.cpp"     "projects/tetris/tetris-game.cpp"                                   2>/dev/null || true
git rm -f "Project/tempCodeRunnerFile.cpp" 2>/dev/null || true

echo "==> Removing binaries and junk"
find . -name "*.exe"               -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true
find . -name "*.out"               -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true
find . -name "*.o"                 -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true
find . -name "tempCodeRunnerFile*" -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true

echo "==> Removing old folders"
for dir in "C++" "C" "CC QNA" "COLLEGE" "CheatsheetSTL" "DSA" "DSA SUPREME BATCH" \
           "DSA-FULL" "DSA_Striver" "FULL_STACK" "HTML" "Internshala DSA" \
           "Java" "Javamain" "Project" ".vscode"; do
  git rm -rf "$dir" 2>/dev/null || true
done

echo "==> Writing .gitignore"
cat > .gitignore << 'EOF'
*.exe
*.out
*.o
*.class
.vscode/
.idea/
.DS_Store
Thumbs.db
tempCodeRunnerFile*
EOF
git add .gitignore

echo "==> Writing README.md"
cat > README.md << 'EOF'
# DSA & Programming Learning Repository

A structured collection of programs, data structures, algorithms, and web development
exercises organized by topic.

## Structure

| Folder | Contents |
|--------|----------|
| `lang-c/` | C — basics, control flow, loops, practice |
| `lang-cpp/` | C++ — arrays, strings, functions, pointers, OOPs, inheritance, practice |
| `lang-java/` | Java — basics, OOPs |
| `dsa/` | Arrays, Linked Lists, Sorting, Binary Search, Recursion, Graphs, STL |
| `web/` | HTML, CSS, mini projects |
| `competitive-coding/` | Competitive programming problems |
| `college/` | College assignments |
| `projects/` | Employee Management System, Sorting Visualizer (SFML), Tetris |

## Binary Search — LeetCode Problems

| File | Problem |
|------|---------|
| `lc69-sqrt-integer.cpp` | LC 69 — Sqrt(x) |
| `lc34-first-last-position.cpp` | LC 34 — First and Last Position |
| `lc33-search-in-rotated-sorted-array.cpp` | LC 33 — Search Rotated Array |
| `lc278-first-bad-version.cpp` | LC 278 — First Bad Version |
| `lc374-guess-number-higher-or-lower.cpp` | LC 374 — Guess Number |
| `lc275-h-index-ii.cpp` | LC 275 — H-Index II |
| `lc436-find-right-interval.cpp` | LC 436 — Find Right Interval |
| `lc441-arranging-coins.cpp` | LC 441 — Arranging Coins |
| `lc540-single-element-in-sorted-array.cpp` | LC 540 — Single Element |
| `lc1337-k-weakest-rows-in-matrix.cpp` | LC 1337 — K Weakest Rows |
| `lc744-smallest-letter-gt-target.cpp` | LC 744 — Smallest Letter |
EOF
git add README.md

echo "==> Committing and pushing..."
git add -A
git commit -m "refactor: complete repository restructure and rename

- lang-c/     : basics, control-flow, loops, practice
- lang-cpp/   : arrays, strings, functions, pointers, oops, overloading, inheritance, practice
- lang-java/  : basics, oops
- dsa/        : arrays, linked-list, stacks-and-queues, sorting,
                searching/binary-search (11 LC problems), recursion, graphs,
                stl-reference, full-course
- web/        : html, css, 3 mini projects
- competitive-coding/, college/, projects/
- All check*.cpp renamed with LC number prefix
- All vague p*.cpp and C*P*.c files renamed descriptively
- Removed all .exe binaries and tempCodeRunnerFile.cpp"

git push origin main

echo ""
echo "=================================================="
echo "  Done! https://github.com/AnsumanEI/Learning-Directory"
echo "=================================================="
