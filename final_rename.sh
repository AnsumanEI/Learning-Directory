#!/bin/bash
# ================================================================
#  FINAL DEFINITIVE RENAME SCRIPT
#  Based on full content analysis of every file
#  Run from: repo root in Git Bash
#  Safe: only renames/deletes, never loses code
# ================================================================

echo "==> Step 1: Remove junk files (binaries, IDE files, temp files)..."
find . -name "*.exe"               -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true
find . -name "*.class"             -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true
find . -name "tempCodeRunnerFile*" -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true
find . -name "*.vsidx"             -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true
find . -name "*.ipch"              -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true
find . -name "*.wsuo"              -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true
find . -name "*.db"                -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true
find . -name "*.sqlite"            -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true
find . -name "read.lock"           -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true
find . -name "*.jpg" -o -name "*.jpeg" -o -name "*.png" -o -name "*.gif" -o -name "*.mp3" \
  | grep -v ".git" | xargs git rm -f --ignore-unmatch 2>/dev/null || true

git rm -f "file_analysis.txt"       2>/dev/null || true
git rm -f "full_analysis.txt"       2>/dev/null || true
git rm -f "current_state.txt"       2>/dev/null || true
git rm -f "restructure.sh"          2>/dev/null || true
git rm -f "rename_all.sh"           2>/dev/null || true
git rm -f "final_restructure.sh"    2>/dev/null || true
git rm -f "01_languages/c/c notes.txt"     2>/dev/null || true
git rm -f "01_languages/c/new 1.txt"       2>/dev/null || true
git rm -f "01_languages/c/quest"           2>/dev/null || true
git rm -f "01_languages/c/practice_loop.c" 2>/dev/null || true
git rm -rf "01_languages/cpp/.vs"          2>/dev/null || true
git rm -f "01_languages/cpp/CppProperties.json" 2>/dev/null || true
git rm -f "01_languages/cpp/QUESTIONS/aaaaa.cPP"         2>/dev/null || true
git rm -f "01_languages/cpp/QUESTIONS/incomplete-scratch.cpp"  2>/dev/null || true
git rm -f "01_languages/cpp/QUESTIONS/empty-skeleton.cpp"      2>/dev/null || true
git rm -f "01_languages/cpp/QUESTIONS/testcase-skeleton.cpp"   2>/dev/null || true
git rm -f "01_languages/java/EmptySkeleton.java"               2>/dev/null || true
git rm -f "01_languages/c/chapter 4/.vscode/settings.json"     2>/dev/null || true
git rm -f "05_web/html-basics/default.asp"                     2>/dev/null || true

echo "==> Step 2: Remove duplicate/extension-less C files (already renamed)..."
git rm -f "01_languages/c/1.first"                2>/dev/null || true
git rm -f "01_languages/c/2.variables"            2>/dev/null || true
git rm -f "01_languages/c/3.question1"            2>/dev/null || true
git rm -f "01_languages/c/4.input"                2>/dev/null || true
git rm -f "01_languages/c/5.Practice"             2>/dev/null || true
git rm -f "01_languages/c/6.Instructions"         2>/dev/null || true
git rm -f "01_languages/c/7.Operator_precedence"  2>/dev/null || true
git rm -f "01_languages/c/8.Conditonal_operators" 2>/dev/null || true
git rm -f "01_languages/c/9.logical_operators"    2>/dev/null || true
git rm -f "01_languages/c/10.conditonal_operators" 2>/dev/null || true
git rm -f "01_languages/c/11.switchcase"           2>/dev/null || true
git rm -f "01_languages/c/12.Loop_control_instruction" 2>/dev/null || true

echo "==> Step 3: Rename C basics files to clean names..."
git mv "01_languages/c/03-addition-practice.c"    "01_languages/c/03-addition-of-two-numbers.c"      2>/dev/null || true
git mv "01_languages/c/04-user-input.c"           "01_languages/c/04-user-input-and-sum.c"           2>/dev/null || true
git mv "01_languages/c/05-arithmetic-practice.c"  "01_languages/c/05-arithmetic-operators-practice.c" 2>/dev/null || true
git mv "01_languages/c/practice-area-of-rectangle.c"         "01_languages/c/08-area-of-rectangle.c"          2>/dev/null || true
git mv "01_languages/c/practice-area-of-circle.c"            "01_languages/c/09-area-of-circle.c"             2>/dev/null || true
git mv "01_languages/c/practice-celsius-to-fahrenheit.c"     "01_languages/c/10-celsius-to-fahrenheit.c"      2>/dev/null || true
git mv "01_languages/c/practice-bitwise-and-divisibility.c"  "01_languages/c/11-bitwise-and-divisibility.c"   2>/dev/null || true
git mv "01_languages/c/practice-basic-calculator.c"          "01_languages/c/12-basic-calculator.c"           2>/dev/null || true
git mv "01_languages/c/practice-grade-calculator.c"          "01_languages/c/13-grade-calculator.c"           2>/dev/null || true
git mv "01_languages/c/practice-age-check.c"                 "01_languages/c/14-age-check-if-else.c"          2>/dev/null || true
git mv "01_languages/c/practice-marks-percentage.c"          "01_languages/c/15-marks-percentage.c"           2>/dev/null || true
git mv "01_languages/c/practice-income-tax-calculator.c"     "01_languages/c/16-income-tax-calculator.c"      2>/dev/null || true
git mv "01_languages/c/practice-leap-year-check.c"           "01_languages/c/17-leap-year-check.c"            2>/dev/null || true
git mv "01_languages/c/practice-find-greatest-of-four.c"     "01_languages/c/18-find-greatest-of-four.c"      2>/dev/null || true
git mv "01_languages/c/practice-uppercase-lowercase-check.c" "01_languages/c/19-uppercase-lowercase-check.c"  2>/dev/null || true

echo "==> Step 4: Rename C chapter 4 files..."
git mv "01_languages/c/chapter 4/table_of_any_no..c"       "01_languages/c/chapter 4/print-multiplication-table.c"    2>/dev/null || true
git mv "01_languages/c/chapter 4/table_in_reverse_order.c" "01_languages/c/chapter 4/print-table-in-reverse-order.c"  2>/dev/null || true

echo "==> Step 5: Rename C chapter 5 (functions) files..."
git mv "01_languages/c/chapter 5/basic.c"               "01_languages/c/chapter 5/function-prototype-demo.c"       2>/dev/null || true
git mv "01_languages/c/chapter 5/chang_function.c"      "01_languages/c/chapter 5/call-by-value-no-change.c"       2>/dev/null || true
git mv "01_languages/c/chapter 5/cpc.c"                 "01_languages/c/chapter 5/fibonacci-recursive.c"           2>/dev/null || true
git mv "01_languages/c/chapter 5/functions.c"           "01_languages/c/chapter 5/function-definition-and-call.c"  2>/dev/null || true
git mv "01_languages/c/chapter 5/practice1.c"           "01_languages/c/chapter 5/practice-average-of-three.c"    2>/dev/null || true
git mv "01_languages/c/chapter 5/practice2.c"           "01_languages/c/chapter 5/practice-celsius-to-fahr-fn.c"  2>/dev/null || true
git mv "01_languages/c/chapter 5/practice3.c"           "01_languages/c/chapter 5/practice-gravitational-force.c" 2>/dev/null || true
git mv "01_languages/c/chapter 5/quick_quiz1.c"         "01_languages/c/chapter 5/quiz-greetings-function.c"      2>/dev/null || true
git mv "01_languages/c/chapter 5/quickquiz1_alternate.c" "01_languages/c/chapter 5/quiz-greetings-alternate.c"   2>/dev/null || true
git mv "01_languages/c/chapter 5/recursion_factorial.c" "01_languages/c/chapter 5/recursion-factorial.c"         2>/dev/null || true
git mv "01_languages/c/chapter 5/return.c"              "01_languages/c/chapter 5/function-return-value.c"        2>/dev/null || true

echo "==> Step 6: Rename C chapter 6 (pointers) files..."
git mv "01_languages/c/chapter 6/call_by_refrence.c"  "01_languages/c/chapter 6/call-by-reference-swap.c"        2>/dev/null || true
git mv "01_languages/c/chapter 6/call_by_value.c"     "01_languages/c/chapter 6/call-by-value-sum.c"             2>/dev/null || true
git mv "01_languages/c/chapter 6/pointer_basics.c"    "01_languages/c/chapter 6/pointer-basics.c"                2>/dev/null || true
git mv "01_languages/c/chapter 6/practice1.c"         "01_languages/c/chapter 6/practice-random-number-pointer.c" 2>/dev/null || true
git mv "01_languages/c/chapter 6/practice2.c"         "01_languages/c/chapter 6/practice-pointer-in-function.c"  2>/dev/null || true
git mv "01_languages/c/chapter 6/practice3.c"         "01_languages/c/chapter 6/practice-modify-via-pointer.c"   2>/dev/null || true
git mv "01_languages/c/chapter 6/practice4.c"         "01_languages/c/chapter 6/practice-sum-avg-via-pointer.c"  2>/dev/null || true
git mv "01_languages/c/chapter 6/practice5.c"         "01_languages/c/chapter 6/practice-double-pointer.c"       2>/dev/null || true
git mv "01_languages/c/chapter 6/practice6.c"         "01_languages/c/chapter 6/practice-pointer-to-function.c"  2>/dev/null || true

echo "==> Step 7: Rename C chapter 7 (arrays) files..."
git mv "01_languages/c/chapter 7/array_input.c"         "01_languages/c/chapter 7/array-input.c"          2>/dev/null || true
git mv "01_languages/c/chapter 7/array_intialisation.c" "01_languages/c/chapter 7/array-initialisation.c" 2>/dev/null || true
git mv "01_languages/c/chapter 7/array_using_loops.c"   "01_languages/c/chapter 7/array-traversal-loops.c" 2>/dev/null || true
git mv "01_languages/c/chapter 7/pointer_arithmetic.c"  "01_languages/c/chapter 7/pointer-arithmetic.c"   2>/dev/null || true

echo "==> Step 8: Rename C projects files..."
git mv "01_languages/c/projects of c programme/do_while_loop.c"  "01_languages/c/projects of c programme/do-while-loop.c"           2>/dev/null || true
git mv "01_languages/c/projects of c programme/random_no_gen.c"  "01_languages/c/projects of c programme/random-number-generator.c" 2>/dev/null || true
git mv "01_languages/c/projects of c programme/while_loop.c"     "01_languages/c/projects of c programme/while-loop-demo.c"         2>/dev/null || true
git mv "01_languages/c/projects of c programme/project1.c"       "01_languages/c/projects of c programme/mini-project-patterns.c"   2>/dev/null || true

echo "==> Step 9: Rename C++ QUESTIONS files..."
git mv "01_languages/cpp/QUESTIONS/array-assignment-scratch.cpp"     "01_languages/cpp/QUESTIONS/array-index-assignment.cpp"        2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/binary-representation-steps.cpp"  "01_languages/cpp/QUESTIONS/binary-steps-counter.cpp"          2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/dynamic-array-heap.cpp"           "01_languages/cpp/QUESTIONS/dynamic-array-on-heap.cpp"         2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/matrix-multiplication-2d-array.cpp" "01_languages/cpp/QUESTIONS/matrix-2d-array-input.cpp"      2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/quadratic-roots.cpp"              "01_languages/cpp/QUESTIONS/quadratic-equation-roots.cpp"      2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/sum_n_number.cpp"                 "01_languages/cpp/QUESTIONS/sum-of-n-numbers.cpp"              2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/username_ingmail.cpp"             "01_languages/cpp/QUESTIONS/extract-username-from-email.cpp"   2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/words_consonants_vowels.cpp"      "01_languages/cpp/QUESTIONS/count-words-vowels-consonants.cpp" 2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/capital_to_small.cpp"             "01_languages/cpp/QUESTIONS/toggle-char-case.cpp"              2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/check_pallindrome.cpp"            "01_languages/cpp/QUESTIONS/check-palindrome-string.cpp"       2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/defining_roots.cpp"               "01_languages/cpp/QUESTIONS/define-nature-of-roots.cpp"        2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/display_grades.cpp"               "01_languages/cpp/QUESTIONS/display-grades.cpp"                2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/multiplication_table.cpp"         "01_languages/cpp/QUESTIONS/multiplication-table.cpp"          2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/perfect_numbers.cpp"              "01_languages/cpp/QUESTIONS/perfect-number-check.cpp"          2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/prime_numbers.cpp"                "01_languages/cpp/QUESTIONS/count-divisible-by-k.cpp"          2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/reverse_numbers.cpp"              "01_languages/cpp/QUESTIONS/reverse-a-number.cpp"              2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/armstrong_number.cpp"             "01_languages/cpp/QUESTIONS/armstrong-number.cpp"              2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/areaofcircle.cpp"                 "01_languages/cpp/QUESTIONS/area-of-circle.cpp"                2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/pallindrome.cpp"                  "01_languages/cpp/QUESTIONS/palindrome-reverse-string.cpp"     2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/P1.cpp"                           "01_languages/cpp/QUESTIONS/print-n-numbers.cpp"               2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/P2.cpp"                           "01_languages/cpp/QUESTIONS/sum-of-array.cpp"                  2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/P3.cpp"                           "01_languages/cpp/QUESTIONS/string-operations-practice.cpp"   2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/He.cpp"                           "01_languages/cpp/QUESTIONS/pattern-printing.cpp"              2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/AZTEC.cpp"                        "01_languages/cpp/QUESTIONS/aztec-pattern.cpp"                 2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/GCD.cpp"                          "01_languages/cpp/QUESTIONS/gcd-algorithm.cpp"                 2>/dev/null || true
git mv "01_languages/cpp/QUESTIONS/NUMBER_OF_NEGATIVE_INT.cpp"       "01_languages/cpp/QUESTIONS/count-negative-integers.cpp"       2>/dev/null || true

echo "==> Step 10: Rename Java files..."
git mv "01_languages/java/hashmap.java"       "01_languages/java/HashMapDemo.java"           2>/dev/null || true
git mv "01_languages/java/memoryconcept.java" "01_languages/java/StringMemoryConceptDemo.java" 2>/dev/null || true
git mv "01_languages/java/objini.java"        "01_languages/java/ObjectInitialisationDemo.java" 2>/dev/null || true
git mv "01_languages/java/point.java"         "01_languages/java/PointClass.java"            2>/dev/null || true
git mv "01_languages/java/priorityqueue.java" "01_languages/java/PriorityQueueDemo.java"     2>/dev/null || true
git mv "01_languages/java/queue.java"         "01_languages/java/QueueDemo.java"             2>/dev/null || true
git mv "01_languages/java/scanner.java"       "01_languages/java/ScannerInputDemo.java"      2>/dev/null || true
git mv "01_languages/java/stack.java"         "01_languages/java/StackDemo.java"             2>/dev/null || true
git mv "01_languages/java/stringbuilder.java" "01_languages/java/StringBuilderDemo.java"     2>/dev/null || true
git mv "01_languages/java/substring.java"     "01_languages/java/SubstringAndSplitDemo.java" 2>/dev/null || true
git mv "01_languages/java/timediffrence.java" "01_languages/java/StringVsStringBuilderPerf.java" 2>/dev/null || true
git mv "01_languages/java/twodarrays.java"    "01_languages/java/TwoDArraysDemo.java"        2>/dev/null || true
git mv "01_languages/java/ArrayListDemo.java" "01_languages/java/ArrayListDemo.java"         2>/dev/null || true

echo "==> Step 11: Rename binary search files with LeetCode prefix..."
git mv "02_dsa/binary-search/sqrt-integer.cpp"          "02_dsa/binary-search/lc69-sqrt-integer.cpp"                   2>/dev/null || true
git mv "02_dsa/binary-search/first-last-position.cpp"   "02_dsa/binary-search/lc34-first-last-position.cpp"            2>/dev/null || true
git mv "02_dsa/binary-search/first-last-position-v2.cpp" "02_dsa/binary-search/lc34-first-last-position-v2.cpp"        2>/dev/null || true
git mv "02_dsa/binary-search/find-right-interval.cpp"   "02_dsa/binary-search/lc436-find-right-interval.cpp"           2>/dev/null || true
git mv "02_dsa/binary-search/arranging-coins.cpp"       "02_dsa/binary-search/lc441-arranging-coins.cpp"               2>/dev/null || true
git mv "02_dsa/binary-search/guess-number.cpp"          "02_dsa/binary-search/lc374-guess-number-higher-or-lower.cpp"  2>/dev/null || true
git mv "02_dsa/binary-search/first-bad-version.cpp"     "02_dsa/binary-search/lc278-first-bad-version.cpp"             2>/dev/null || true
git mv "02_dsa/binary-search/search-rotated-array.cpp"  "02_dsa/binary-search/lc33-search-rotated-sorted-array.cpp"   2>/dev/null || true
git mv "02_dsa/binary-search/h-index.cpp"               "02_dsa/binary-search/lc275-h-index-ii.cpp"                   2>/dev/null || true
git mv "02_dsa/binary-search/single-non-duplicate.cpp"  "02_dsa/binary-search/lc540-single-element-sorted-array.cpp"  2>/dev/null || true
git mv "02_dsa/binary-search/k-weakest-rows.cpp"        "02_dsa/binary-search/lc1337-k-weakest-rows-in-matrix.cpp"    2>/dev/null || true

echo "==> Step 12: Rename DSA core files..."
git mv "02_dsa/core/DSA 2.0/Array_func.cpp"           "02_dsa/core/DSA 2.0/array-functions-demo.cpp"       2>/dev/null || true
git mv "02_dsa/core/DSA 2.0/BST_using_recurssion.cpp" "02_dsa/core/DSA 2.0/bst-using-recursion.cpp"        2>/dev/null || true
git mv "02_dsa/core/DSA 2.0/2D ARRAY/2d_array.cpp"    "02_dsa/core/DSA 2.0/2D ARRAY/2d-array-basics.cpp"   2>/dev/null || true
git mv "02_dsa/core/DSA 2.0/RECURSION/stack_heap.cpp"    "02_dsa/core/DSA 2.0/RECURSION/stack-and-heap-memory.cpp"  2>/dev/null || true
git mv "02_dsa/core/DSA 2.0/RECURSION/static_variable.cpp" "02_dsa/core/DSA 2.0/RECURSION/static-variable-demo.cpp" 2>/dev/null || true
git mv "02_dsa/core/DSA 2.0/RECURSION/sum_n_numbers.cpp"   "02_dsa/core/DSA 2.0/RECURSION/sum-of-n-numbers.cpp"    2>/dev/null || true
git mv "02_dsa/core/DSA 2.0/RECURSION/tail_recursion.cpp"  "02_dsa/core/DSA 2.0/RECURSION/tail-recursion.cpp"      2>/dev/null || true
git mv "02_dsa/core/DSA 2.0/RECURSION/taylor_series.cpp"   "02_dsa/core/DSA 2.0/RECURSION/taylor-series-expansion.cpp" 2>/dev/null || true
git mv "02_dsa/core/DSA 2.0/RECURSION/time_complexity.cpp" "02_dsa/core/DSA 2.0/RECURSION/time-complexity-demo.cpp" 2>/dev/null || true
git mv "02_dsa/core/DSA 2.0/RECURSION/tree_recursion.cpp"  "02_dsa/core/DSA 2.0/RECURSION/tree-recursion.cpp"      2>/dev/null || true
git mv "02_dsa/core/DSA 2.0/RECURSION/head_recursion.cpp"  "02_dsa/core/DSA 2.0/RECURSION/head-recursion.cpp"      2>/dev/null || true
git mv "02_dsa/core/DSA 2.0/RECURSION/linear_recursion.cpp" "02_dsa/core/DSA 2.0/RECURSION/linear-recursion.cpp"   2>/dev/null || true
git mv "02_dsa/core/DSA 2.0/RECURSION/nested_recursion.cpp" "02_dsa/core/DSA 2.0/RECURSION/nested-recursion.cpp"   2>/dev/null || true
git mv "02_dsa/core/DSA 2.0/RECURSION/power_recursion.cpp"  "02_dsa/core/DSA 2.0/RECURSION/power-recursion.cpp"    2>/dev/null || true
git mv "02_dsa/core/DSA 2.0/RECURSION/questions/decimal_binary.cpp"      "02_dsa/core/DSA 2.0/RECURSION/questions/decimal-to-binary.cpp"       2>/dev/null || true
git mv "02_dsa/core/DSA 2.0/RECURSION/questions/largest_element.cpp"     "02_dsa/core/DSA 2.0/RECURSION/questions/largest-element-array.cpp"   2>/dev/null || true
git mv "02_dsa/core/DSA 2.0/RECURSION/questions/matrix_multiplication.cpp" "02_dsa/core/DSA 2.0/RECURSION/questions/matrix-multiplication.cpp" 2>/dev/null || true
git mv "02_dsa/core/DSA 2.0/RECURSION/questions/reverse_string.cpp"      "02_dsa/core/DSA 2.0/RECURSION/questions/reverse-string.cpp"          2>/dev/null || true
git mv "02_dsa/core/DSA 2.0/RECURSION/questions/sum_of_digits.cpp"       "02_dsa/core/DSA 2.0/RECURSION/questions/sum-of-digits.cpp"           2>/dev/null || true

echo "==> Step 13: Rename Internshala course files..."
git mv "03_courses/internshala/Array/maximum_in_arr.cpp"  "03_courses/internshala/Array/find-maximum-in-array.cpp"  2>/dev/null || true
git mv "03_courses/internshala/Array/sum_of_all.cpp"      "03_courses/internshala/Array/sum-of-all-elements.cpp"    2>/dev/null || true
git mv "03_courses/internshala/Sorting/insertionsort.cpp" "03_courses/internshala/Sorting/insertion-sort.cpp"       2>/dev/null || true
git mv "03_courses/internshala/Sorting/selectionsort.cpp" "03_courses/internshala/Sorting/selection-sort.cpp"       2>/dev/null || true
git mv "03_courses/internshala/Sorting/sort.cpp"          "03_courses/internshala/Sorting/sorting-basics.cpp"       2>/dev/null || true
git mv "03_courses/internshala/Structures/cc.cpp"         "03_courses/internshala/Structures/structure-scratch.cpp" 2>/dev/null || true
git mv "03_courses/internshala/Structures/struct.cpp"     "03_courses/internshala/Structures/structure-basics.cpp"  2>/dev/null || true
git mv "03_courses/internshala/Trees/Height.cpp"          "03_courses/internshala/Trees/tree-height.cpp"            2>/dev/null || true
git mv "03_courses/internshala/Trees/Mytree.cpp"          "03_courses/internshala/Trees/binary-tree-v1.cpp"         2>/dev/null || true
git mv "03_courses/internshala/Trees/Mytree2.cpp"         "03_courses/internshala/Trees/binary-tree-v2.cpp"         2>/dev/null || true
git mv "03_courses/internshala/Trees/Prac/practre.cpp"    "03_courses/internshala/Trees/Prac/tree-practice.cpp"     2>/dev/null || true
git mv "03_courses/internshala/Trees/Prac/singlyll.cpp"   "03_courses/internshala/Trees/Prac/singly-ll-in-tree-practice.cpp" 2>/dev/null || true
git mv "03_courses/internshala/Trees/V2/zigzagtrav.cpp"   "03_courses/internshala/Trees/V2/zigzag-level-traversal.cpp" 2>/dev/null || true
git mv "03_courses/internshala/Trees/binarytree.cpp"      "03_courses/internshala/Trees/binary-tree-basics.cpp"     2>/dev/null || true
git mv "03_courses/internshala/Trees/creationbt.cpp"      "03_courses/internshala/Trees/binary-tree-creation.cpp"   2>/dev/null || true
git mv "03_courses/internshala/Trees/identical.cpp"       "03_courses/internshala/Trees/identical-trees-check.cpp"  2>/dev/null || true
git mv "03_courses/internshala/Trees/pracq.cpp"           "03_courses/internshala/Trees/tree-practice-queue.cpp"    2>/dev/null || true
git mv "03_courses/internshala/Trees/practice.cpp"        "03_courses/internshala/Trees/tree-traversal-practice.cpp" 2>/dev/null || true
git mv "03_courses/internshala/search/binary.cpp"         "03_courses/internshala/search/binary-search.cpp"         2>/dev/null || true
git mv "03_courses/internshala/search/linear.cpp"         "03_courses/internshala/search/linear-search.cpp"         2>/dev/null || true
git mv "03_courses/internshala/Graphs/creation.cpp"       "03_courses/internshala/Graphs/graph-adjacency-list-creation.cpp" 2>/dev/null || true

echo "==> Step 14: Rename Striver and Supreme Batch files..."
git mv "03_courses/striver-a2z/lc1-two-sum.cpp"  "03_courses/striver-a2z/lc1-two-sum-hashmap.cpp"  2>/dev/null || true

echo "==> Step 15: Rename interview prep files..."
git mv "04_interview-prep/cc-qna/PP1.CPP" "04_interview-prep/cc-qna/basic-output-and-loop.cpp" 2>/dev/null || true

echo "==> Step 16: Rename web HTML files..."
git mv "05_web/html-basics/attributes styles .htm"            "05_web/html-basics/html-attributes-and-styles.html"    2>/dev/null || true
git mv "05_web/html-basics/background,fonts,allign.htm"       "05_web/html-basics/background-fonts-alignment.html"    2>/dev/null || true
git mv "05_web/html-basics/backgrund and elnt.htm"            "05_web/html-basics/background-and-elements.html"       2>/dev/null || true
git mv "05_web/html-basics/button.htm"                        "05_web/html-basics/html-buttons.html"                  2>/dev/null || true
git mv "05_web/html-basics/colours.htm"                       "05_web/html-basics/html-colours.html"                  2>/dev/null || true
git mv "05_web/html-basics/headings links and image .htm"     "05_web/html-basics/headings-links-and-images.html"     2>/dev/null || true
git mv "05_web/html-basics/hr br and pre  element.htm"        "05_web/html-basics/hr-br-pre-elements.html"            2>/dev/null || true
git mv "05_web/html-basics/html basic 1 .htm"                 "05_web/html-basics/html-basics-1.html"                 2>/dev/null || true
git mv "05_web/html-basics/html link color.htm"               "05_web/html-basics/html-link-colors.html"              2>/dev/null || true
git mv "05_web/html-basics/htmli lbuttons customisation.htm"  "05_web/html-basics/buttons-customisation.html"         2>/dev/null || true
git mv "05_web/html-basics/image map.htm"                     "05_web/html-basics/html-image-map.html"                2>/dev/null || true
git mv "05_web/html-basics/java script in html.htm"           "05_web/html-basics/javascript-in-html.html"            2>/dev/null || true
git mv "05_web/html-basics/picture.htm"                       "05_web/html-basics/html-picture-element.html"          2>/dev/null || true
git mv "05_web/html-basics/project pratice 1.htm"             "05_web/html-basics/project-practice-1.html"            2>/dev/null || true
git mv "05_web/html-basics/quotation and citation.htm"        "05_web/html-basics/html-quotations-and-citations.html" 2>/dev/null || true
git mv "05_web/html-basics/styling a button.htm"              "05_web/html-basics/button-styling.html"                2>/dev/null || true
git mv "05_web/html-basics/table.htm"                         "05_web/html-basics/html-table.html"                    2>/dev/null || true
git mv "05_web/html-basics/target attribute .htm"             "05_web/html-basics/html-target-attribute.html"         2>/dev/null || true
git mv "05_web/html-basics/text formatting .htm"              "05_web/html-basics/html-text-formatting.html"          2>/dev/null || true

echo "==> Step 17: Rename full-stack HTML files..."
git mv "05_web/full-stack/HTML5/textformmating.html"  "05_web/full-stack/HTML5/text-formatting.html"      2>/dev/null || true
git mv "05_web/full-stack/HTML5/hyperlink.html"       "05_web/full-stack/HTML5/hyperlinks-demo.html"      2>/dev/null || true
git mv "05_web/full-stack/HTML5/indexaudio.html"      "05_web/full-stack/HTML5/audio-element-demo.html"   2>/dev/null || true
git mv "05_web/full-stack/HTML5/indexbuttons.html"    "05_web/full-stack/HTML5/buttons-demo.html"         2>/dev/null || true
git mv "05_web/full-stack/HTML5/indexfavicon.html"    "05_web/full-stack/HTML5/favicon-demo.html"         2>/dev/null || true
git mv "05_web/full-stack/HTML5/indexforms.html"      "05_web/full-stack/HTML5/html-forms.html"           2>/dev/null || true
git mv "05_web/full-stack/HTML5/indeximage.html"      "05_web/full-stack/HTML5/image-element-demo.html"   2>/dev/null || true
git mv "05_web/full-stack/HTML5/indexlist.html"       "05_web/full-stack/HTML5/html-lists.html"           2>/dev/null || true
git mv "05_web/full-stack/HTML5/indextable.html"      "05_web/full-stack/HTML5/html-table.html"           2>/dev/null || true
git mv "05_web/full-stack/HTML5/indexvideo.html"      "05_web/full-stack/HTML5/video-element-demo.html"   2>/dev/null || true
git mv "05_web/full-stack/HTML5/spananddiv.html"      "05_web/full-stack/HTML5/span-and-div.html"         2>/dev/null || true
git mv "05_web/full-stack/HTML5/lyrics.html"          "05_web/full-stack/HTML5/lyrics-page-demo.html"     2>/dev/null || true

echo "==> Step 18: Rename Phase-1..."
git mv "Phase-1/two_sum.cpp" "Phase-1/lc1-two-sum-brute.cpp"  2>/dev/null || true

echo "==> Step 19: Fix remaining college file name..."
git mv "06_college/find-max-of-three.cpp" "06_college/find-max-of-three-numbers.cpp" 2>/dev/null || true

echo "==> Step 20: Update .gitignore..."
cat > .gitignore << 'EOF'
# Compiled binaries
*.exe
*.out
*.o
*.class

# IDE and editor files
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
*.lock

# OS files
.DS_Store
Thumbs.db

# Temp files
tempCodeRunnerFile*

# Media files (only code in this repo)
*.mp3
*.jpg
*.jpeg
*.png
*.gif
*.bmp
*.asp
*.php
EOF
git add .gitignore

echo "==> Step 21: Writing comprehensive README..."
cat > README.md << 'README'
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

README
git add README.md

echo "==> Step 22: Stage all changes and commit..."
git add -A
git commit -m "refactor: comprehensive rename and cleanup of entire repository

Changes made:
- Removed all .exe/.class binaries, IDE files (.vs/, tempCodeRunnerFile*)
- Removed all media files (images, mp3)
- Removed duplicate extension-less C files
- Renamed C basics: practice-*.c -> numbered descriptive names
- Renamed C chapter 5 (functions): basic.c -> function-prototype-demo.c, etc.
- Renamed C chapter 6 (pointers): call_by_refrence.c -> call-by-reference-swap.c, etc.
- Renamed C chapter 7 (arrays): array_input.c -> array-input.c, etc.
- Renamed C++ QUESTIONS: P1/P2/P3, He, AZTEC, GCD, _underscored -> kebab-case
- Renamed Java: hashmap/memoryconcept/objini/etc -> PascalCase descriptive names
- Renamed binary-search files: added LC number prefix (lc69/lc34/lc33/etc.)
- Renamed DSA core recursion files: snake_case -> kebab-case
- Renamed Internshala Trees/Structures/Sorting/search files
- Renamed web HTML .htm -> .html with descriptive names
- Renamed full-stack HTML: indexaudio/indexforms/etc -> descriptive names
- Updated .gitignore: covers all binaries, IDE files, media
- Rewrote README: full directory tree, topic table, LC problem table, chapter index"

echo "==> Step 23: Pushing to GitHub..."
git push origin main

echo ""
echo "=========================================="
echo "  DONE! Repo is clean and fully renamed."
echo "  https://github.com/AnsumanEI/Learning-Directory"
echo "=========================================="
