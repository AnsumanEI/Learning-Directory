/*
 * #155 Min Stack
 *
 * APPROACH : Stack of pairs {element, current_minimum}
 *   - Each push stores element + minimum at that moment
 *   - Stack empty → min is val itself
 *   - New val < current min → new min is val
 *   - New val >= current min → min stays same (prevmin)
 *   - getMin() → always O(1) via top().second
 *
 * COMPLEXITY :
 *   Time  : O(1) for all operations
 *   Space : O(n)
 *
 * READABLE VARIABLES :
 *   pval    → stack of {element, min_at_that_moment}
 *   val     → value being pushed
 *   prevmin → minimum before this push
 *
 * EDGE CASES :
 *   - Pop on empty stack → guard with empty check ✓
 *   - Min after pop → still correct via pair ✓
 *
 * MISTAKES MADE :
 *   - pval.push.first(val) → wrong. Use pval.push({val, min})
 *   - pval.top().second() → second is field not function
 *   - pval.top.first() → top() needs brackets, first does not
 */

#include<iostream>
#include <bits/stdc++.h>
#include<math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;

class MinStack {
    stack<pair<int, int>> pval;

public:
    MinStack() {}

    void push(int val) {
        if (pval.empty()) {
            pval.push({val, val});
        } else if (val < pval.top().second) {
            pval.push({val, val});
        } else {
            int prevmin = pval.top().second;
            pval.push({val, prevmin});
        }
    }

    void pop() {
        if (pval.empty()) return;
        pval.pop();
    }

    int top() { return pval.top().first; }
    int getMin() { return pval.top().second; }
};
int main()
{


return 0;
}