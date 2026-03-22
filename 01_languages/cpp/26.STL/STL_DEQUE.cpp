#include <bits/stdc++.h>
#include <deque>
using namespace std;
// deque is also called doubly ended  as elements can be pushed or popped from both the ends
// also called deck

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    deque<int> q;
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    q.push_front(0); // adding element in the front
    q.pop_back();
    q.pop_front();
    for (auto i : q)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << q.size() << " size " << endl;
    cout << "erase 1st two elements" << endl;
    q.erase(q.begin(), q.begin() + 2);
    // to clear entire deque q.clear();
    for (auto i : q)
    {
        cout << i << " ";
    }
    cout << "copy two deques" << endl;

    deque<int> q2(q);

    cout << " q = ";
    for (auto i : q)
    {
        cout << i << " ";
    }
    cout << " q 2 = ";
    for (auto i : q2)
    {
        cout << i << " ";
    }
    q2.push_back(1);
    q2.push_back(2);
    // swapping
    q2.swap(q);
    cout << endl;
    cout << " q = ";
    for (auto i : q)
    {
        cout << i << " ";
    }
    cout << "\n " << q.size() << endl;
    cout << q.at(2) << endl;
    return 0;
}