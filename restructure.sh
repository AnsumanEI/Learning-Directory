#!/bin/bash
# ============================================================
#  LEARNING-DIRECTORY → PRODUCTION RESTRUCTURE SCRIPT
#  Run from: root of your Learning-Directory repo
#  Effect:   renames, reorganizes, cleans up all files
# ============================================================

set -e  # stop on any error

echo "==> Step 1: Create new folder structure"
mkdir -p 01_languages/cpp
mkdir -p 01_languages/c
mkdir -p 01_languages/java
mkdir -p 02_dsa/binary-search
mkdir -p 02_dsa/core
mkdir -p 02_dsa/stl-cheatsheet
mkdir -p 02_dsa/complete-course
mkdir -p 03_courses/striver-a2z
mkdir -p 03_courses/supreme-batch
mkdir -p 03_courses/internshala
mkdir -p 04_interview-prep/cc-qna
mkdir -p 05_web/html-basics
mkdir -p 05_web/full-stack
mkdir -p 06_college
mkdir -p 07_projects

echo "==> Step 2: Move and rename root check*.cpp binary search files"
git mv check.cpp    02_dsa/binary-search/sqrt-integer.cpp
git mv check1.cpp   02_dsa/binary-search/first-last-position.cpp
git mv check2.cpp   02_dsa/binary-search/first-last-position-v2.cpp
git mv check3.cpp   02_dsa/binary-search/find-right-interval.cpp
git mv check4.cpp   02_dsa/binary-search/arranging-coins.cpp
git mv check5.cpp   02_dsa/binary-search/guess-number.cpp
git mv check6.cpp   02_dsa/binary-search/first-bad-version.cpp
git mv check7.cpp   02_dsa/binary-search/search-rotated-array.cpp
git mv check8.cpp   02_dsa/binary-search/h-index.cpp
git mv check9.cpp   02_dsa/binary-search/single-non-duplicate.cpp
git mv check10.cpp  02_dsa/binary-search/k-weakest-rows.cpp

echo "==> Step 3: Remove all compiled binary artifacts (.exe, .out, .o)"
find . -name "*.exe" -not -path "./.git/*" | xargs git rm -f --ignore-unmatch
find . -name "*.out" -not -path "./.git/*" | xargs git rm -f --ignore-unmatch
find . -name "*.o"   -not -path "./.git/*" | xargs git rm -f --ignore-unmatch

echo "==> Step 4: Reorganize top-level folders"
# Languages
git mv "C++"/*        01_languages/cpp/      2>/dev/null || true
git mv "C"/*          01_languages/c/        2>/dev/null || true
git mv "Java"/*       01_languages/java/     2>/dev/null || true
git mv "Javamain"/*   01_languages/java/     2>/dev/null || true

# DSA
git mv "DSA"/*            02_dsa/core/          2>/dev/null || true
git mv "DSA-FULL"/*       02_dsa/complete-course/ 2>/dev/null || true
git mv "CheatsheetSTL"/*  02_dsa/stl-cheatsheet/ 2>/dev/null || true

# Courses
git mv "DSA_Striver"/*         03_courses/striver-a2z/  2>/dev/null || true
git mv "DSA SUPREME BATCH"/*   03_courses/supreme-batch/ 2>/dev/null || true
git mv "Internshala DSA"/*     03_courses/internshala/   2>/dev/null || true

# Interview prep
git mv "CC QNA"/*   04_interview-prep/cc-qna/ 2>/dev/null || true

# Web
git mv "HTML"/*        05_web/html-basics/ 2>/dev/null || true
git mv "FULL_STACK"/*  05_web/full-stack/  2>/dev/null || true

# College & Projects
git mv "COLLEGE"/*  06_college/  2>/dev/null || true
git mv "Project"/*  07_projects/ 2>/dev/null || true

echo "==> Step 5: Remove now-empty old folders"
for dir in "C++" "C" "Java" "Javamain" "DSA" "DSA-FULL" "CheatsheetSTL" \
           "DSA_Striver" "DSA SUPREME BATCH" "Internshala DSA" \
           "CC QNA" "HTML" "FULL_STACK" "COLLEGE" "Project"; do
  [ -d "$dir" ] && rmdir "$dir" 2>/dev/null || true
done

echo "==> Step 6: Create .gitignore"
cat > .gitignore << 'EOF'
# Compiled binaries
*.exe
*.out
*.o
*.class

# IDE settings
.vscode/
.idea/

# OS files
.DS_Store
Thumbs.db

# Node modules
node_modules/
EOF
git add .gitignore

echo "==> Step 7: Create recruiter-friendly README.md"
cat > README.md << 'EOF'
# DSA & Interview Prep Repository

A structured collection of Data Structures, Algorithms, and full-stack learning materials,
organized for clarity and easy navigation.

## Structure

| Folder | Contents |
|--------|----------|
| `01_languages/` | Language fundamentals — C, C++, Java |
| `02_dsa/` | DSA topics: Binary Search, STL Cheatsheet, complete course |
| `03_courses/` | Course-specific solutions — Striver A2Z, Supreme Batch, Internshala |
| `04_interview-prep/` | Competitive coding Q&A and interview practice |
| `05_web/` | HTML basics and full-stack development |
| `06_college/` | College coursework and assignments |
| `07_projects/` | Personal projects |

## Topics Covered

- **Binary Search** — 11 LeetCode problems (LC 69, 34, 436, 441, 374, 278, 33, 275, 540, 1337)
- **Data Structures** — Arrays, Linked Lists, Trees, Graphs, Stacks, Queues
- **Algorithms** — Sorting, Searching, Dynamic Programming, Recursion
- **Languages** — C, C++, Java
- **Web** — HTML, CSS, JavaScript, Full-Stack

## Language Breakdown

- C++ (primary)
- Java
- C
- HTML / CSS / JavaScript
EOF
git add README.md

echo "==> Step 8: Commit everything"
git add -A
git commit -m "refactor: restructure repo to professional layout

- Reorganized all folders into numbered, purpose-driven directories
- Renamed check*.cpp → descriptive binary-search problem names
- Removed all compiled .exe/.out/.o binaries from version control
- Added comprehensive .gitignore to prevent future binary commits
- Updated README with full topic and structure overview"

echo "==> Step 9: Push to GitHub"
git push origin main

echo ""
echo "✅ Done! Your repo is now production-grade."
echo "   Visit: https://github.com/AnsumanEI/Learning-Directory"
