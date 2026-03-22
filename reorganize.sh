#!/bin/bash
# ============================================================
#  REPO REORGANIZER — Interview-Ready Cleanup
#  Run from the ROOT of your git repo in Git Bash / Terminal
#  Usage:  bash reorganize.sh
# ============================================================

set -e
echo ""
echo "=========================================="
echo "  Starting Repository Reorganization..."
echo "=========================================="
echo ""

# ----------------------------------------------------------
# STEP 1: DELETE JUNK FILES (binaries, temp, scratch, media)
# ----------------------------------------------------------
echo "==> [1/7] Removing junk files..."

# Compiled binaries
find . -name "*.exe" ! -path "./.git/*" -exec git rm -f --ignore-unmatch {} \; 2>/dev/null || true

# Temp and scratch
find . -name "tempCodeRunnerFile*" ! -path "./.git/*" -exec git rm -f --ignore-unmatch {} \; 2>/dev/null || true
git rm -f "02_dsa/complete-course/RECURSION/rough.cpp"  2>/dev/null || true
git rm -f "02_dsa/complete-course/RECURSION/rough2.cpp" 2>/dev/null || true
git rm -f "02_dsa/complete-course/RECURSION/rough3.cpp" 2>/dev/null || true
git rm -f "02_dsa/complete-course/rough.cpp"            2>/dev/null || true
git rm -f "cleanup.sh"                                  2>/dev/null || true
git rm -f "final_rename.sh"                             2>/dev/null || true
git rm -f "current_state2.txt"                          2>/dev/null || true
git rm -f "project_preview.txt"                         2>/dev/null || true

# Media files
git rm -f "05_web/full-stack/HTML5/Lutt Le Gaya (From Dhurandhar).mp3" 2>/dev/null || true
git rm -f "05_web/html-basics/Beautiful Rain Wallpapers For Your Desktop.jpg" 2>/dev/null || true

# Grocery test file (not a source file)
git rm -f "01_languages/cpp/26.STL/grocery.txt" 2>/dev/null || true

echo "   Done."

# ----------------------------------------------------------
# STEP 2: FIX C NUMBERING CONFLICTS
# (08-even-odd and 08-area-of-rectangle both existed)
# ----------------------------------------------------------
echo ""
echo "==> [2/7] Fixing C file number conflicts..."

git mv "01_languages/c/13-area-of-rectangle.c"         "01_languages/c/13-area-of-rectangle.c"         2>/dev/null || true
git mv "01_languages/c/14-area-of-circle.c"            "01_languages/c/14-area-of-circle.c"            2>/dev/null || true
# (These were already renamed by cleanup.sh; this is a safety pass — no-ops are fine)

echo "   Done."

# ----------------------------------------------------------
# STEP 3: FLATTEN + RENAME C CHAPTER FOLDERS
# Spaced folder names ("chapter 4") are messy. Rename them.
# ----------------------------------------------------------
echo ""
echo "==> [3/7] Renaming C chapter folders..."

# chapter 4 → ch04-loops
if [ -d "01_languages/c/chapter 4" ]; then
  git mv "01_languages/c/chapter 4/print-multiplication-table.c" \
         "01_languages/c/ch04-loops/print-multiplication-table.c" 2>/dev/null || \
  (mkdir -p "01_languages/c/ch04-loops" && \
   git mv "01_languages/c/chapter 4/print-multiplication-table.c" \
          "01_languages/c/ch04-loops/print-multiplication-table.c")
  git mv "01_languages/c/chapter 4/print-table-in-reverse-order.c" \
         "01_languages/c/ch04-loops/print-table-in-reverse-order.c" 2>/dev/null || true
  git rm -rf "01_languages/c/chapter 4" 2>/dev/null || true
fi

# chapter-4-loops → merge into ch04-loops if present
if [ -d "01_languages/c/chapter-4-loops" ]; then
  for f in "01_languages/c/chapter-4-loops"/*.c; do
    [ -f "$f" ] && git mv "$f" "01_languages/c/ch04-loops/$(basename $f)" 2>/dev/null || true
  done
  git rm -rf "01_languages/c/chapter-4-loops" 2>/dev/null || true
fi

# chapter 5 → ch05-functions
if [ -d "01_languages/c/chapter 5" ]; then
  mkdir -p "01_languages/c/ch05-functions"
  for f in "01_languages/c/chapter 5"/*.c; do
    [ -f "$f" ] && git mv "$f" "01_languages/c/ch05-functions/$(basename $f)" 2>/dev/null || true
  done
  git rm -rf "01_languages/c/chapter 5" 2>/dev/null || true
fi

# chapter 6 → ch06-pointers
if [ -d "01_languages/c/chapter 6" ]; then
  mkdir -p "01_languages/c/ch06-pointers"
  for f in "01_languages/c/chapter 6"/*.c; do
    [ -f "$f" ] && git mv "$f" "01_languages/c/ch06-pointers/$(basename $f)" 2>/dev/null || true
  done
  git rm -rf "01_languages/c/chapter 6" 2>/dev/null || true
fi

# chapter 7 → ch07-arrays
if [ -d "01_languages/c/chapter 7" ]; then
  mkdir -p "01_languages/c/ch07-arrays"
  for f in "01_languages/c/chapter 7"/*.c; do
    [ -f "$f" ] && git mv "$f" "01_languages/c/ch07-arrays/$(basename $f)" 2>/dev/null || true
  done
  git rm -rf "01_languages/c/chapter 7" 2>/dev/null || true
fi

# misc-practice stays, rename folder only if space exists
if [ -d "01_languages/c/misc-practice" ]; then
  echo "   misc-practice folder already clean."
fi

# projects of c programme → c-projects
if [ -d "01_languages/c/projects of c programme" ]; then
  mkdir -p "01_languages/c/c-projects"
  for f in "01_languages/c/projects of c programme"/*; do
    [ -f "$f" ] && git mv "$f" "01_languages/c/c-projects/$(basename $f)" 2>/dev/null || true
  done
  git rm -rf "01_languages/c/projects of c programme" 2>/dev/null || true
fi

echo "   Done."

# ----------------------------------------------------------
# STEP 4: RENAME C++ FOLDERS (ALLCAPS with spaces → clean names)
# ----------------------------------------------------------
echo ""
echo "==> [4/7] Renaming C++ chapter folders..."

rename_cpp_folder() {
  local OLD="01_languages/cpp/$1"
  local NEW="01_languages/cpp/$2"
  if [ -d "$OLD" ] && [ "$OLD" != "$NEW" ]; then
    mkdir -p "$NEW"
    for f in "$OLD"/*; do
      [ -f "$f" ] && git mv "$f" "$NEW/$(basename $f)" 2>/dev/null || true
    done
    git rm -rf "$OLD" 2>/dev/null || true
    echo "   Renamed: $1 → $2"
  fi
}

rename_cpp_folder "1.BASICS"                                          "01-basics"
rename_cpp_folder "2.DATA TYPES, VARIABLES, SCOPE RESOLUTION"        "02-data-types-variables"
rename_cpp_folder "3.ENUM,TYPEDEF"                                    "03-enum-typedef"
rename_cpp_folder "4.CONDITIONAL STATEMENTS"                          "04-conditional-statements"
rename_cpp_folder "5.SHORT CIRCUIT,SWITCH"                            "05-short-circuit-switch"
rename_cpp_folder "7.ARRAYS"                                          "07-arrays"
rename_cpp_folder "8.POINTERS BASIC ONLY"                             "08-pointers"
rename_cpp_folder "9.STRINGS"                                         "09-strings-cstyle"
rename_cpp_folder "10.CLASS STRINGS AND FUNCTIONS"                    "10-strings-class"
rename_cpp_folder "11.FUNCTION"                                       "11-functions"
rename_cpp_folder "12.PARAMETRE PASSING & RETURNING & POINTING FUCNTIONS" "12-parameter-passing"
rename_cpp_folder "13.RECURSIONS"                                     "13-recursion"
rename_cpp_folder "14.OOPS"                                           "14-oops"
rename_cpp_folder "15.DATA HANDLING"                                  "15-data-handling"
rename_cpp_folder "16.OVERLOADING"                                    "16-operator-overloading"
rename_cpp_folder "17.INHERITANCE"                                    "17-inheritance"
rename_cpp_folder "18.VIRTUAL FUNCTIONS"                              "18-virtual-functions"
rename_cpp_folder "19.EXCEPTION HANDLING"                             "19-exception-handling"
rename_cpp_folder "20.FILE HANDLING"                                  "20-file-handling"
rename_cpp_folder "21.TEMPLATES"                                      "21-templates"
rename_cpp_folder "22.STD"                                            "22-std"
rename_cpp_folder "23.ITERATORS"                                      "23-iterators"
rename_cpp_folder "24.SORTING"                                        "24-sorting"
rename_cpp_folder "25.SEARCHING"                                      "25-searching"
rename_cpp_folder "26.STL"                                            "26-stl"
rename_cpp_folder "27.c++11"                                          "27-cpp11-modern"

echo "   Done."

# ----------------------------------------------------------
# STEP 5: RENAME MISNAMED C++ FILES
# Files whose name doesn't match their content
# ----------------------------------------------------------
echo ""
echo "==> [5/7] Renaming misnamed C++ files..."

# STL folder: misnamed files
git mv "01_languages/cpp/26-stl/STLs.cpp"            "01_languages/cpp/26-stl/stl-vector-iterator.cpp"         2>/dev/null || true
git mv "01_languages/cpp/26-stl/STRIVER.cpp"          "01_languages/cpp/26-stl/stl-array-demo.cpp"              2>/dev/null || true
git mv "01_languages/cpp/26-stl/STUDENT_EXCERCISE.cpp" "01_languages/cpp/26-stl/stl-fileio-item-class.cpp"      2>/dev/null || true

# Functions folder
git mv "01_languages/cpp/11-functions/OVERFLOW.cpp"   "01_languages/cpp/11-functions/integer-overflow-demo.cpp" 2>/dev/null || true
git mv "01_languages/cpp/11-functions/POINTER_TO_FUNCTION.cpp" \
       "01_languages/cpp/11-functions/pointer-to-function.cpp" 2>/dev/null || true

# Recursion
git mv "01_languages/cpp/13-recursion/RECURSION_MINM_WAYS.cpp" \
       "01_languages/cpp/13-recursion/recursion-minimum-ways.cpp"              2>/dev/null || true
git mv "01_languages/cpp/13-recursion/RECURSION_POINTER_TO_FUNCTION.cpp" \
       "01_languages/cpp/13-recursion/recursion-print-ascending-descending.cpp" 2>/dev/null || true
git mv "01_languages/cpp/13-recursion/RECURSION_SUM_TO_N.cpp" \
       "01_languages/cpp/13-recursion/recursion-sum-to-n.cpp"                  2>/dev/null || true

# Parameter passing folder
git mv "01_languages/cpp/12-parameter-passing/CALL_BY_ADDRESS.cpp" \
       "01_languages/cpp/12-parameter-passing/call-by-address-swap.cpp"        2>/dev/null || true
git mv "01_languages/cpp/12-parameter-passing/RETURN_BY_ADDRESS.cpp" \
       "01_languages/cpp/12-parameter-passing/return-by-address.cpp"           2>/dev/null || true
git mv "01_languages/cpp/12-parameter-passing/RETURN_BY_REFERENCE.cpp" \
       "01_languages/cpp/12-parameter-passing/return-by-reference.cpp"         2>/dev/null || true

# Modern C++11 folder
git mv "01_languages/cpp/27-cpp11-modern/AUTO.cpp"            "01_languages/cpp/27-cpp11-modern/auto-decltype.cpp"     2>/dev/null || true
git mv "01_languages/cpp/27-cpp11-modern/FINAL_KEYWORD.cpp"   "01_languages/cpp/27-cpp11-modern/final-keyword.cpp"     2>/dev/null || true
git mv "01_languages/cpp/27-cpp11-modern/LAMBDA_EXPRESSIONS.cpp" "01_languages/cpp/27-cpp11-modern/lambda-expressions.cpp" 2>/dev/null || true
git mv "01_languages/cpp/27-cpp11-modern/SMART_POINTER.cpp"   "01_languages/cpp/27-cpp11-modern/smart-pointer.cpp"    2>/dev/null || true

# Basics folder ALLCAPS → lowercase-hyphen
git mv "01_languages/cpp/01-basics/DYNAMIC_DECLARATION.cpp"   "01_languages/cpp/01-basics/dynamic-variable-declaration.cpp" 2>/dev/null || true
git mv "01_languages/cpp/01-basics/HEAP_DECLARATION.cpp"      "01_languages/cpp/01-basics/heap-memory-allocation.cpp"       2>/dev/null || true
git mv "01_languages/cpp/01-basics/HELLO_WORLD.cpp"           "01_languages/cpp/01-basics/hello-world.cpp"                  2>/dev/null || true
git mv "01_languages/cpp/01-basics/STANDARD_NAMESPACE.cpp"    "01_languages/cpp/01-basics/standard-namespace.cpp"           2>/dev/null || true
git mv "01_languages/cpp/01-basics/SUM.cpp"                   "01_languages/cpp/01-basics/sum-with-comments.cpp"            2>/dev/null || true
git mv "01_languages/cpp/01-basics/TAKING_INPUT_SUM.cpp"      "01_languages/cpp/01-basics/taking-input-sum.cpp"             2>/dev/null || true

# Internshala Trees — misnamed files
git mv "03_courses/internshala/Trees/Prac/singly-ll-in-tree-practice.cpp" \
       "03_courses/internshala/Trees/Prac/linked-list-practice.cpp" 2>/dev/null || true

# DSA PRAC — freq.cpp is username-frequency problem (Codeforces 4C style)
git mv "02_dsa/complete-course/PRAC/freq.cpp" \
       "02_dsa/complete-course/PRAC/username-frequency-map.cpp" 2>/dev/null || true

# College folder — generic names → descriptive
git mv "06_college/dynamic-array-input.cpp"      "06_college/dynamic-array-heap-input.cpp" 2>/dev/null || true
git mv "06_college/increment-and-print.cpp"      "06_college/pre-increment-demo.cpp"       2>/dev/null || true

# Phase-1 folder — move into DSA leetcode section
mkdir -p "02_dsa/leetcode/arrays"
git mv "Phase-1/lc1-two-sum-brute.cpp" \
       "02_dsa/leetcode/arrays/lc1-two-sum-brute.cpp" 2>/dev/null || true
git rm -rf "Phase-1" 2>/dev/null || true

# striver-a2z: map-of-pairs.cpp is a scratch/practice file
git mv "03_courses/striver-a2z/map-of-pairs.cpp" \
       "03_courses/striver-a2z/map-of-pairs-practice.cpp" 2>/dev/null || true

echo "   Done."

# ----------------------------------------------------------
# STEP 6: RENAME PROJECT FILES (interview showpieces)
# ----------------------------------------------------------
echo ""
echo "==> [6/7] Cleaning up project filenames..."

# sorting-visualizer is clear already — leave name
# employee-management: keep final, remove v1 duplicate if identical
echo "   Note: employee-management-system-v1.cpp and -final.cpp both exist."
echo "   Review manually — keep whichever is more complete, delete the other."

echo "   Done."

# ----------------------------------------------------------
# STEP 7: COMMIT EVERYTHING
# ----------------------------------------------------------
echo ""
echo "==> [7/7] Staging and committing..."

git add -A
git commit -m "refactor: interview-ready repo reorganization

- Removed all .exe binaries, temp files, media files, scratch files
- Renamed C chapter folders: 'chapter 4' -> ch04-loops, etc.
- Renamed C++ folders from ALLCAPS-with-spaces to kebab-case
- Renamed misnamed C++ files to match their actual content
- Moved Phase-1/lc1-two-sum-brute.cpp into 02_dsa/leetcode/arrays/
- Renamed college utility files to descriptive names
- Removed grocery.txt (test data, not source)
- Cleaned up striver-a2z map-of-pairs scratch file name"

echo ""
echo "=========================================="
echo "  Reorganization Complete!"
echo "=========================================="
echo ""
echo "  ACTION REQUIRED:"
echo "  1. Review 07_projects/ — decide which employee-management version to keep"
echo "  2. Run: git log --oneline -5   to verify the commit"
echo "  3. Run: git push               to push to GitHub"
echo ""
