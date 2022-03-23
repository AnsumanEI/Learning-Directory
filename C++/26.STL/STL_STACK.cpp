#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<string> s;
    // this follows the concept last in first out
    // exactly like stacking books
    s.push("hello");
    s.push("my");
    s.push("name");
    s.push("is");
    s.push("ansuman");
    // lets check the top element
    cout << "top element - >" << s.top() << endl; // as the string ansuman is pushed last so it is at the top
    s.pop();
    cout << "top element - >" << s.top() << endl;

    return 0;
}