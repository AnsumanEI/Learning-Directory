#!/bin/bash
# ============================================================
#  COMPLETE FILE RENAMING SCRIPT
#  Run from: root of your Learning-Directory repo (Git Bash)
#  Effect:   renames all poorly named files across every folder
# ============================================================
set -e

echo ""
echo "=================================================="
echo "  STEP 1: Root-level check*.cpp files"
echo "=================================================="
# These should already be in 02_dsa/binary-search/ from the previous script.
# If they are still in the root, this moves and renames them.
mkdir -p 02_dsa/binary-search
[ -f "check.cpp" ]   && git mv check.cpp   02_dsa/binary-search/sqrt-integer.cpp
[ -f "check1.cpp" ]  && git mv check1.cpp  02_dsa/binary-search/first-last-position.cpp
[ -f "check2.cpp" ]  && git mv check2.cpp  02_dsa/binary-search/first-last-position-v2.cpp
[ -f "check3.cpp" ]  && git mv check3.cpp  02_dsa/binary-search/find-right-interval.cpp
[ -f "check4.cpp" ]  && git mv check4.cpp  02_dsa/binary-search/arranging-coins.cpp
[ -f "check5.cpp" ]  && git mv check5.cpp  02_dsa/binary-search/guess-number.cpp
[ -f "check6.cpp" ]  && git mv check6.cpp  02_dsa/binary-search/first-bad-version.cpp
[ -f "check7.cpp" ]  && git mv check7.cpp  02_dsa/binary-search/search-rotated-array.cpp
[ -f "check8.cpp" ]  && git mv check8.cpp  02_dsa/binary-search/h-index.cpp
[ -f "check9.cpp" ]  && git mv check9.cpp  02_dsa/binary-search/single-non-duplicate.cpp
[ -f "check10.cpp" ] && git mv check10.cpp 02_dsa/binary-search/k-weakest-rows.cpp

# Remove root-level .exe files
find . -maxdepth 1 -name "*.exe" | xargs git rm -f --ignore-unmatch 2>/dev/null || true

echo ""
echo "=================================================="
echo "  STEP 2: 01_languages/c/"
echo "=================================================="
# Numbered tutorial files - keep numbers but fix names
[ -f "01_languages/c/1.first.c" ]                    && git mv "01_languages/c/1.first.c"                    "01_languages/c/01-hello-world.c"
[ -f "01_languages/c/2.variables.c" ]                && git mv "01_languages/c/2.variables.c"                "01_languages/c/02-variables-and-datatypes.c"
[ -f "01_languages/c/3.question1.c" ]                && git mv "01_languages/c/3.question1.c"                "01_languages/c/03-addition-practice.c"
[ -f "01_languages/c/4.input.c" ]                    && git mv "01_languages/c/4.input.c"                    "01_languages/c/04-user-input.c"
[ -f "01_languages/c/5.Practice.c" ]                 && git mv "01_languages/c/5.Practice.c"                 "01_languages/c/05-arithmetic-practice.c"
[ -f "01_languages/c/6.Instructions.c" ]             && git mv "01_languages/c/6.Instructions.c"             "01_languages/c/06-arithmetic-operators.c"
[ -f "01_languages/c/7.Operator_precedence.c" ]      && git mv "01_languages/c/7.Operator_precedence.c"      "01_languages/c/07-operator-precedence.c"
[ -f "01_languages/c/8.Conditonal_operators.c" ]     && git mv "01_languages/c/8.Conditonal_operators.c"     "01_languages/c/08-even-odd-check.c"
[ -f "01_languages/c/9.logical_operators.c" ]        && git mv "01_languages/c/9.logical_operators.c"        "01_languages/c/09-logical-operators.c"
[ -f "01_languages/c/10.conditonal_operators.c" ]    && git mv "01_languages/c/10.conditonal_operators.c"    "01_languages/c/10-ternary-operator.c"
[ -f "01_languages/c/11.switchcase.c" ]              && git mv "01_languages/c/11.switchcase.c"              "01_languages/c/11-switch-case.c"
[ -f "01_languages/c/12.Loop_control_instruction.c" ] && git mv "01_languages/c/12.Loop_control_instruction.c" "01_languages/c/12-while-loop.c"

# Practice set files
[ -f "01_languages/c/C1P1.c" ] && git mv "01_languages/c/C1P1.c" "01_languages/c/practice-area-of-rectangle.c"
[ -f "01_languages/c/C1P2.c" ] && git mv "01_languages/c/C1P2.c" "01_languages/c/practice-area-of-circle.c"
[ -f "01_languages/c/C1P3.c" ] && git mv "01_languages/c/C1P3.c" "01_languages/c/practice-celsius-to-fahrenheit.c"
[ -f "01_languages/c/C2P1.c" ] && git mv "01_languages/c/C2P1.c" "01_languages/c/practice-bitwise-and-divisibility.c"
[ -f "01_languages/c/C2P3.c" ] && git mv "01_languages/c/C2P3.c" "01_languages/c/practice-basic-calculator.c"
[ -f "01_languages/c/C3P4.c" ] && git mv "01_languages/c/C3P4.c" "01_languages/c/practice-grade-calculator.c"
[ -f "01_languages/c/C3P5.c" ] && git mv "01_languages/c/C3P5.c" "01_languages/c/practice-age-check.c"
[ -f "01_languages/c/C3P6.c" ] && git mv "01_languages/c/C3P6.c" "01_languages/c/practice-marks-percentage.c"
[ -f "01_languages/c/C3P7.c" ] && git mv "01_languages/c/C3P7.c" "01_languages/c/practice-income-tax-calculator.c"
[ -f "01_languages/c/C3P8.c" ] && git mv "01_languages/c/C3P8.c" "01_languages/c/practice-leap-year-check.c"
[ -f "01_languages/c/C3P9.c" ] && git mv "01_languages/c/C3P9.c" "01_languages/c/practice-find-greatest-of-four.c"
[ -f "01_languages/c/C3P10.c" ] && git mv "01_languages/c/C3P10.c" "01_languages/c/practice-uppercase-lowercase-check.c"

# Chapter 4 subfolder - rename the folder itself and its files
if [ -d "01_languages/c/chapter 4" ]; then
  mkdir -p "01_languages/c/chapter-4-loops"
  [ -f "01_languages/c/chapter 4/asxsax.c" ]            && git mv "01_languages/c/chapter 4/asxsax.c"            "01_languages/c/chapter-4-loops/for-loop-basic.c"
  [ -f "01_languages/c/chapter 4/break_statement.c" ]    && git mv "01_languages/c/chapter 4/break_statement.c"   "01_languages/c/chapter-4-loops/break-statement.c"
  [ -f "01_languages/c/chapter 4/check.c" ]              && git mv "01_languages/c/chapter 4/check.c"             "01_languages/c/chapter-4-loops/modulo-scratch.c"
  [ -f "01_languages/c/chapter 4/continue_loop.c" ]      && git mv "01_languages/c/chapter 4/continue_loop.c"     "01_languages/c/chapter-4-loops/continue-statement.c"
  [ -f "01_languages/c/chapter 4/decrmenting_forloop.c" ] && git mv "01_languages/c/chapter 4/decrmenting_forloop.c" "01_languages/c/chapter-4-loops/decrementing-for-loop.c"
  [ -f "01_languages/c/chapter 4/question_3.c" ]         && git mv "01_languages/c/chapter 4/question_3.c"        "01_languages/c/chapter-4-loops/sum-of-n-naturals.c"
  [ -f "01_languages/c/chapter 4/question_4.c" ]         && git mv "01_languages/c/chapter 4/question_4.c"        "01_languages/c/chapter-4-loops/factorial.c"
  [ -f "01_languages/c/chapter 4/question_5.c" ]         && git mv "01_languages/c/chapter 4/question_5.c"        "01_languages/c/chapter-4-loops/infinite-while-loop-demo.c"
  [ -f "01_languages/c/chapter 4/question_6.c" ]         && git mv "01_languages/c/chapter 4/question_6.c"        "01_languages/c/chapter-4-loops/prime-check.c"
  rmdir "01_languages/c/chapter 4" 2>/dev/null || true
fi

# 123 subfolder (random named files) - rename and flatten into c/
if [ -d "01_languages/c/123" ]; then
  mkdir -p "01_languages/c/misc-practice"
  [ -f "01_languages/c/123/armstrong.c" ]                   && git mv "01_languages/c/123/armstrong.c"                "01_languages/c/misc-practice/armstrong-number.c"
  [ -f "01_languages/c/123/calculator.c" ]                  && git mv "01_languages/c/123/calculator.c"               "01_languages/c/misc-practice/basic-calculator.c"
  [ -f "01_languages/c/123/convert second to min.c" ]       && git mv "01_languages/c/123/convert second to min.c"    "01_languages/c/misc-practice/seconds-to-hours-minutes.c"
  [ -f "01_languages/c/123/detetminin _the_largest_integer.c" ] && git mv "01_languages/c/123/detetminin _the_largest_integer.c" "01_languages/c/misc-practice/find-largest-integer.c"
  [ -f "01_languages/c/123/dowhile.c" ]                     && git mv "01_languages/c/123/dowhile.c"                  "01_languages/c/misc-practice/do-while-loop.c"
  [ -f "01_languages/c/123/first.c" ]                       && git mv "01_languages/c/123/first.c"                    "01_languages/c/misc-practice/square-root.c"
  [ -f "01_languages/c/123/for_loop.c" ]                    && git mv "01_languages/c/123/for_loop.c"                 "01_languages/c/misc-practice/for-loop-basic.c"
  [ -f "01_languages/c/123/how_to check the_aunthenticity _of_an_equation.c" ] && git mv "01_languages/c/123/how_to check the_aunthenticity _of_an_equation.c" "01_languages/c/misc-practice/relational-operators.c"
  [ -f "01_languages/c/123/infinity.c" ]                    && git mv "01_languages/c/123/infinity.c"                 "01_languages/c/misc-practice/memory-addresses.c"
  [ -f "01_languages/c/123/perfect_num.c" ]                 && git mv "01_languages/c/123/perfect_num.c"              "01_languages/c/misc-practice/perfect-number.c"
  [ -f "01_languages/c/123/practiceset1.c" ]                && git mv "01_languages/c/123/practiceset1.c"             "01_languages/c/misc-practice/logical-not-operator.c"
  [ -f "01_languages/c/123/reverse_the_character.c" ]       && git mv "01_languages/c/123/reverse_the_character.c"   "01_languages/c/misc-practice/toggle-char-case.c"
  rmdir "01_languages/c/123" 2>/dev/null || true
fi

echo ""
echo "=================================================="
echo "  STEP 3: 01_languages/cpp/"
echo "=================================================="

# QUESTIONS subfolder - these are well-named mostly, just fix the bad ones
[ -f "01_languages/cpp/QUESTIONS/check.cpp" ]               && git mv "01_languages/cpp/QUESTIONS/check.cpp"               "01_languages/cpp/QUESTIONS/matrix-multiplication-2d-array.cpp"
[ -f "01_languages/cpp/QUESTIONS/p6.cpp" ]                  && git mv "01_languages/cpp/QUESTIONS/p6.cpp"                  "01_languages/cpp/QUESTIONS/sum-of-digits.cpp"
[ -f "01_languages/cpp/QUESTIONS/p7.cpp" ]                  && git mv "01_languages/cpp/QUESTIONS/p7.cpp"                  "01_languages/cpp/QUESTIONS/find-max-of-three.cpp"
[ -f "01_languages/cpp/QUESTIONS/p8.cpp" ]                  && git mv "01_languages/cpp/QUESTIONS/p8.cpp"                  "01_languages/cpp/QUESTIONS/running-score-tracker.cpp"
[ -f "01_languages/cpp/QUESTIONS/p9.cpp" ]                  && git mv "01_languages/cpp/QUESTIONS/p9.cpp"                  "01_languages/cpp/QUESTIONS/binary-representation-steps.cpp"
[ -f "01_languages/cpp/QUESTIONS/p10.cpp" ]                 && git mv "01_languages/cpp/QUESTIONS/p10.cpp"                 "01_languages/cpp/QUESTIONS/testcase-skeleton.cpp"
[ -f "01_languages/cpp/QUESTIONS/p12.cpp" ]                 && git mv "01_languages/cpp/QUESTIONS/p12.cpp"                 "01_languages/cpp/QUESTIONS/array-assignment-scratch.cpp"
[ -f "01_languages/cpp/QUESTIONS/p13.cpp" ]                 && git mv "01_languages/cpp/QUESTIONS/p13.cpp"                 "01_languages/cpp/QUESTIONS/string-length-check.cpp"
[ -f "01_languages/cpp/QUESTIONS/p14.cpp" ]                 && git mv "01_languages/cpp/QUESTIONS/p14.cpp"                 "01_languages/cpp/QUESTIONS/range-and-power-of-two-check.cpp"
[ -f "01_languages/cpp/QUESTIONS/p15.cpp" ]                 && git mv "01_languages/cpp/QUESTIONS/p15.cpp"                 "01_languages/cpp/QUESTIONS/empty-skeleton.cpp"
[ -f "01_languages/cpp/QUESTIONS/p16.cpp" ]                 && git mv "01_languages/cpp/QUESTIONS/p16.cpp"                 "01_languages/cpp/QUESTIONS/rectangle-class-oops.cpp"
[ -f "01_languages/cpp/QUESTIONS/p17.cpp" ]                 && git mv "01_languages/cpp/QUESTIONS/p17.cpp"                 "01_languages/cpp/QUESTIONS/dynamic-array-heap.cpp"
[ -f "01_languages/cpp/QUESTIONS/P5.cpp" ]                  && git mv "01_languages/cpp/QUESTIONS/P5.cpp"                  "01_languages/cpp/QUESTIONS/incomplete-scratch.cpp"
[ -f "01_languages/cpp/QUESTIONS/tut6.cpp" ]                && git mv "01_languages/cpp/QUESTIONS/tut6.cpp"                "01_languages/cpp/QUESTIONS/quadratic-roots.cpp"
[ -f "01_languages/cpp/QUESTIONS/tempCodeRunnerFile.cpp" ]  && git rm -f "01_languages/cpp/QUESTIONS/tempCodeRunnerFile.cpp"

# Clean up temp runner files across cpp folders
find 01_languages/cpp -name "tempCodeRunnerFile.cpp" | xargs git rm -f --ignore-unmatch 2>/dev/null || true
[ -f "01_languages/cpp/gg.cpp" ] && git rm -f "01_languages/cpp/gg.cpp"

# Rename OOPS subfolder files
[ -f "01_languages/cpp/14.OOPS/PERFECT_CLASS.cpp" ]     && git mv "01_languages/cpp/14.OOPS/PERFECT_CLASS.cpp"     "01_languages/cpp/14.OOPS/rectangle-class-complete.cpp"
[ -f "01_languages/cpp/14.OOPS/OBJECT_IN_HEAP.cpp" ]    && git mv "01_languages/cpp/14.OOPS/OBJECT_IN_HEAP.cpp"    "01_languages/cpp/14.OOPS/object-on-heap.cpp"
[ -f "01_languages/cpp/14.OOPS/NESTED_INNERCLASS.cpp" ] && git mv "01_languages/cpp/14.OOPS/NESTED_INNERCLASS.cpp" "01_languages/cpp/14.OOPS/nested-inner-class.cpp"

echo ""
echo "=================================================="
echo "  STEP 4: 01_languages/java/"
echo "=================================================="
[ -f "01_languages/java/Main.java" ]          && git mv "01_languages/java/Main.java"          "01_languages/java/StringMethods.java"
[ -f "01_languages/java/basic.java" ]         && git mv "01_languages/java/basic.java"         "01_languages/java/BasicInputOutput.java"
[ -f "01_languages/java/arrays.java" ]        && git mv "01_languages/java/arrays.java"        "01_languages/java/ArraysDemo.java"
[ -f "01_languages/java/arraylist.java" ]     && git mv "01_languages/java/arraylist.java"     "01_languages/java/ArrayListDemo.java"
[ -f "01_languages/java/circle.java" ]        && git mv "01_languages/java/circle.java"        "01_languages/java/CircleClass.java"
[ -f "01_languages/java/defaultvalues.java" ] && git mv "01_languages/java/defaultvalues.java" "01_languages/java/DefaultValuesDemo.java"
[ -f "01_languages/java/functions.java" ]     && git mv "01_languages/java/functions.java"     "01_languages/java/StaticMethodsAndSwap.java"
[ -f "01_languages/java/Strings.java" ]       && git mv "01_languages/java/Strings.java"       "01_languages/java/StringBasics.java"
[ -f "01_languages/java/classmethods.java" ]  && git rm -f "01_languages/java/classmethods.java"

# Java Dev Yt subfolder
[ -f "01_languages/java/Java Dev Yt/Class1.java" ] && git mv "01_languages/java/Java Dev Yt/Class1.java" "01_languages/java/EmptySkeleton.java" 2>/dev/null || true
rmdir "01_languages/java/Java Dev Yt" 2>/dev/null || true

echo ""
echo "=================================================="
echo "  STEP 5: 02_dsa/core/"
echo "=================================================="
[ -f "02_dsa/core/array_addding.cpp" ]       && git mv "02_dsa/core/array_addding.cpp"       "02_dsa/core/array-insert-element.cpp"
[ -f "02_dsa/core/array_adding2.cpp" ]       && git mv "02_dsa/core/array_adding2.cpp"       "02_dsa/core/array-insert-at-index.cpp"
[ -f "02_dsa/core/imlementation_ll.cpp" ]    && git mv "02_dsa/core/imlementation_ll.cpp"    "02_dsa/core/linked-list-implementation.cpp"
[ -f "02_dsa/core/lniked_list.cpp" ]         && git mv "02_dsa/core/lniked_list.cpp"         "02_dsa/core/linked-list-node-struct.cpp"
[ -f "02_dsa/core/pointer1darray.cpp" ]      && git mv "02_dsa/core/pointer1darray.cpp"      "02_dsa/core/pointer-to-1d-array.cpp"
[ -f "02_dsa/core/pointer_2darray.cpp" ]     && git mv "02_dsa/core/pointer_2darray.cpp"     "02_dsa/core/pointer-to-2d-array.cpp"
find "02_dsa/core" -name "tempCodeRunnerFile.cpp" | xargs git rm -f --ignore-unmatch 2>/dev/null || true

# DSA 2.0 subfolder
[ -f "02_dsa/core/DSA 2.0/array_basic.cpp" ]     && git mv "02_dsa/core/DSA 2.0/array_basic.cpp"     "02_dsa/core/DSA 2.0/switch-case-demo.cpp"
[ -f "02_dsa/core/DSA 2.0/binary_search.cpp" ]   && git mv "02_dsa/core/DSA 2.0/binary_search.cpp"   "02_dsa/core/DSA 2.0/binary-search-basic.cpp"
[ -f "02_dsa/core/DSA 2.0/excercise.cpp" ]       && git mv "02_dsa/core/DSA 2.0/excercise.cpp"       "02_dsa/core/DSA 2.0/binary-search-exercise.cpp"
[ -f "02_dsa/core/DSA 2.0/indirect_recursion.cpp" ] && git mv "02_dsa/core/DSA 2.0/indirect_recursion.cpp" "02_dsa/core/DSA 2.0/indirect-recursion.cpp"
[ -f "02_dsa/core/DSA 2.0/space_array.cpp" ]     && git mv "02_dsa/core/DSA 2.0/space_array.cpp"     "02_dsa/core/DSA 2.0/space-complexity-array.cpp"
[ -f "02_dsa/core/DSA 2.0/arr.java" ]            && git mv "02_dsa/core/DSA 2.0/arr.java"            "02_dsa/core/DSA 2.0/PalindromeRecursion.java"
find "02_dsa/core/DSA 2.0" -name "tempCodeRunnerFile.cpp" | xargs git rm -f --ignore-unmatch 2>/dev/null || true

echo ""
echo "=================================================="
echo "  STEP 6: 03_courses/internshala/"
echo "=================================================="
[ -f "03_courses/internshala/Function/func.cpp" ]          && git mv "03_courses/internshala/Function/func.cpp"          "03_courses/internshala/Function/function-basics.cpp"
[ -f "03_courses/internshala/Function/callbyadd.cpp" ]     && git mv "03_courses/internshala/Function/callbyadd.cpp"     "03_courses/internshala/Function/call-by-address-swap.cpp"
[ -f "03_courses/internshala/Function/callbyref.cpp" ]     && git mv "03_courses/internshala/Function/callbyref.cpp"     "03_courses/internshala/Function/call-by-reference.cpp"
[ -f "03_courses/internshala/Function/passingarray.cpp" ]  && git mv "03_courses/internshala/Function/passingarray.cpp"  "03_courses/internshala/Function/passing-array-to-function.cpp"
[ -f "03_courses/internshala/Function/pointertofunc.cpp" ] && git mv "03_courses/internshala/Function/pointertofunc.cpp" "03_courses/internshala/Function/pointer-to-function.cpp"
[ -f "03_courses/internshala/Function/prc.cpp" ]           && git mv "03_courses/internshala/Function/prc.cpp"           "03_courses/internshala/Function/global-scope-resolution.cpp"
[ -f "03_courses/internshala/Function/scope.cpp" ]         && git mv "03_courses/internshala/Function/scope.cpp"         "03_courses/internshala/Function/scope-resolution-operator.cpp"
[ -f "03_courses/internshala/Pointers/Dynamicmemalloc.cpp" ] && git mv "03_courses/internshala/Pointers/Dynamicmemalloc.cpp" "03_courses/internshala/Pointers/dynamic-memory-allocation.cpp"
[ -f "03_courses/internshala/Sorting/bubblsort.cpp" ]      && git mv "03_courses/internshala/Sorting/bubblsort.cpp"      "03_courses/internshala/Sorting/bubble-sort.cpp"
find "03_courses/internshala" -name "tempCodeRunnerFile.cpp" | xargs git rm -f --ignore-unmatch 2>/dev/null || true

echo ""
echo "=================================================="
echo "  STEP 7: 03_courses/supreme-batch/"
echo "=================================================="
[ -f "03_courses/supreme-batch/Begin.cpp" ]        && git mv "03_courses/supreme-batch/Begin.cpp"        "03_courses/supreme-batch/binary-search-template.cpp"
[ -f "03_courses/supreme-batch/Rightinterval.cpp" ] && git mv "03_courses/supreme-batch/Rightinterval.cpp" "03_courses/supreme-batch/find-right-interval.cpp"
[ -f "03_courses/supreme-batch/letters.cpp" ]      && git mv "03_courses/supreme-batch/letters.cpp"      "03_courses/supreme-batch/find-smallest-letter-greater-than-target.cpp"

echo ""
echo "=================================================="
echo "  STEP 8: 03_courses/striver-a2z/"
echo "=================================================="
[ -f "03_courses/striver-a2z/mappair.cpp" ] && git mv "03_courses/striver-a2z/mappair.cpp" "03_courses/striver-a2z/map-of-pairs.cpp"
[ -f "03_courses/striver-a2z/twosum.cpp" ]  && git mv "03_courses/striver-a2z/twosum.cpp"  "03_courses/striver-a2z/lc1-two-sum.cpp"

echo ""
echo "=================================================="
echo "  STEP 9: 04_interview-prep/cc-qna/"
echo "=================================================="
[ -f "04_interview-prep/cc-qna/CHECK.cpp" ]        && git mv "04_interview-prep/cc-qna/CHECK.cpp"        "04_interview-prep/cc-qna/sort-class-implementation.cpp"
[ -f "04_interview-prep/cc-qna/PP2.cpp" ]          && git mv "04_interview-prep/cc-qna/PP2.cpp"          "04_interview-prep/cc-qna/count-interior-points.cpp"
[ -f "04_interview-prep/cc-qna/PP3.cpp" ]          && git mv "04_interview-prep/cc-qna/PP3.cpp"          "04_interview-prep/cc-qna/array-processing-testcases.cpp"
[ -f "04_interview-prep/cc-qna/PP4.cpp" ]          && git mv "04_interview-prep/cc-qna/PP4.cpp"          "04_interview-prep/cc-qna/string-split-count.cpp"
[ -f "04_interview-prep/cc-qna/PP5.cpp" ]          && git mv "04_interview-prep/cc-qna/PP5.cpp"          "04_interview-prep/cc-qna/nearest-multiple-of-five.cpp"
[ -f "04_interview-prep/cc-qna/PP6.cpp" ]          && git mv "04_interview-prep/cc-qna/PP6.cpp"          "04_interview-prep/cc-qna/digit-count-of-difference.cpp"
[ -f "04_interview-prep/cc-qna/PP7.cpp" ]          && git mv "04_interview-prep/cc-qna/PP7.cpp"          "04_interview-prep/cc-qna/min-skill-in-array.cpp"
[ -f "04_interview-prep/cc-qna/PP8.cpp" ]          && git mv "04_interview-prep/cc-qna/PP8.cpp"          "04_interview-prep/cc-qna/print-numbers-1-to-10.cpp"
[ -f "04_interview-prep/cc-qna/PP10.cpp" ]         && git mv "04_interview-prep/cc-qna/PP10.cpp"         "04_interview-prep/cc-qna/target-search-in-array.cpp"
[ -f "04_interview-prep/cc-qna/PP11.cpp" ]         && git mv "04_interview-prep/cc-qna/PP11.cpp"         "04_interview-prep/cc-qna/song-key-matching.cpp"
[ -f "04_interview-prep/cc-qna/ccc.cpp" ]          && git mv "04_interview-prep/cc-qna/ccc.cpp"          "04_interview-prep/cc-qna/vector-input-processing.cpp"
[ -f "04_interview-prep/cc-qna/gg1.cpp" ]          && git mv "04_interview-prep/cc-qna/gg1.cpp"          "04_interview-prep/cc-qna/digit-count.cpp"
[ -f "04_interview-prep/cc-qna/ppp1.cpp" ]         && git mv "04_interview-prep/cc-qna/ppp1.cpp"         "04_interview-prep/cc-qna/matrix-multiplication.cpp"
[ -f "04_interview-prep/cc-qna/sievesnippet.cpp" ] && git mv "04_interview-prep/cc-qna/sievesnippet.cpp" "04_interview-prep/cc-qna/sieve-of-eratosthenes.cpp"

echo ""
echo "=================================================="
echo "  STEP 10: 06_college/"
echo "=================================================="
[ -f "06_college/cc.cpp" ] && git rm -f "06_college/cc.cpp"   # empty file
[ -f "06_college/p1.cpp" ] && git mv "06_college/p1.cpp" "06_college/increment-and-print.cpp"
[ -f "06_college/p2.cpp" ] && git mv "06_college/p2.cpp" "06_college/find-max-of-three.cpp"
[ -f "06_college/p3.cpp" ] && git mv "06_college/p3.cpp" "06_college/dynamic-array-input.cpp"

echo ""
echo "=================================================="
echo "  STEP 11: 07_projects/"
echo "=================================================="
[ -f "07_projects/Front.cpp" ]              && git mv "07_projects/Front.cpp"              "07_projects/employee-management-system-v1.cpp"
[ -f "07_projects/frontfinal.cpp" ]         && git mv "07_projects/frontfinal.cpp"         "07_projects/employee-management-system-final.cpp"
[ -f "07_projects/main.cpp" ]               && git mv "07_projects/main.cpp"               "07_projects/sorting-visualizer-sfml.cpp"
[ -f "07_projects/tetris.cpp" ]             && git mv "07_projects/tetris.cpp"             "07_projects/tetris-game.cpp"
[ -f "07_projects/tempCodeRunnerFile.cpp" ] && git rm -f "07_projects/tempCodeRunnerFile.cpp"

echo ""
echo "=================================================="
echo "  STEP 12: 05_web/ — fix bad HTML filenames"
echo "=================================================="
[ -f "05_web/html-basics/fff.html" ]                  && git mv "05_web/html-basics/fff.html"                  "05_web/html-basics/transparent-button-demo.html"
[ -f "05_web/html-basics/BiodataPracticeproject.html" ] && git mv "05_web/html-basics/BiodataPracticeproject.html" "05_web/html-basics/biodata-practice-project.html"
[ -f "05_web/html-basics/CSS.html" ]                  && git mv "05_web/html-basics/CSS.html"                  "05_web/html-basics/internal-external-css-demo.html"

echo ""
echo "=================================================="
echo "  STEP 13: Remove all .exe/.out/.o binaries"
echo "=================================================="
find . -name "*.exe" -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true
find . -name "*.out" -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true
find . -name "*.o"   -not -path "./.git/*" | xargs git rm -f --ignore-unmatch 2>/dev/null || true

echo ""
echo "=================================================="
echo "  STEP 14: Commit and push"
echo "=================================================="
git add -A
git commit -m "refactor: rename all poorly named files to descriptive names

- Renamed all check*.cpp root files to descriptive binary-search names
- Fixed C tutorial files (1.first.c -> 01-hello-world.c, etc.)
- Renamed C practice files (C1P1.c -> practice-area-of-rectangle.c, etc.)
- Renamed C++ QUESTIONS files (p6-p17 -> descriptive names)
- Renamed Java files to PascalCase with meaningful names
- Renamed DSA core files (array_addding -> array-insert-element, etc.)
- Renamed internshala course files to descriptive names
- Renamed supreme-batch and striver files
- Renamed interview prep PP*.cpp files to descriptive names
- Renamed project files (Front.cpp -> employee-management-system)
- Removed all tempCodeRunnerFile.cpp and empty files
- Removed all .exe compiled binaries"

git push origin main

echo ""
echo "✅ All done! Your repo is now fully renamed and production-grade."
