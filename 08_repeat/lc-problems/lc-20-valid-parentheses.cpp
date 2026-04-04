/*
 * #20 Valid Parentheses
 *
 * APPROACH : Stack + HashMap matching
 *   - map closing bracket → expected opening bracket
 *   - If closing bracket: check stack top matches expected
 *   - If opening bracket: push onto stack
 *   - End: stack must be empty (no unclosed brackets)
 *
 * COMPLEXITY :
 *   Time  : O(n)
 *   Space : O(n)  worst case all opening brackets
 *
 * READABLE VARIABLES :
 *   s      → input string
 *   seen   → stack of opening brackets
 *   match  → closing→opening bracket map
 *   p      → current character
 *
 * EDGE CASES :
 *   - First char is closing bracket → stack empty → false ✓
 *   - Only opening brackets → stack not empty at end → false ✓
 *   - Empty string → stack empty → true ✓
 *
 * MISTAKES MADE :
 *   - seen.count() on stack → compile error, stacks have no .count()
 *   - match[')']= ')' → value must be opposite bracket
 *   - Pushed s[0] before loop → double processed first char
 */


#include<iostream>
#include <bits/stdc++.h>
#include<math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> seen;
        unordered_map<char, char> match;
        match['}'] = '{';
        match[')'] = '(';
        match[']'] = '[';

        for (auto& p : s) {
            if (match.count(p)) {
                if (seen.empty()) return false;
                if (seen.top() != match[p]) return false;
                seen.pop();
            } else {
                seen.push(p);
            }
        }
        return seen.empty();
    }
};
int main()
{

return 0;
}