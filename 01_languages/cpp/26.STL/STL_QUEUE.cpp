#include <bits/stdc++.h>
#include <queue>
using namespace std;
// it is exact oppposite of stack
// this follows first in first out concept
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    queue<string> q;
    q.push("hello");
    q.push("ansuman");
    q.push("here");
    cout << "first elemtent before pop " << q.front() << endl;
    // if we pop first then the 1st one will be removed
    q.pop();
    cout << "first element after pop " << q.front() << endl;

    return 0;
}