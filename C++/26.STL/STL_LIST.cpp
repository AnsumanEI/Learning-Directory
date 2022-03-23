#include <bits/stdc++.h>
#include <list>
using namespace std;
// list cannot be accesse directly bu [ ] or using at operator
// we have to traverse till a particular number and then we can access it
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    list<int> l;
    l.push_back(1);
    l.push_front(2);
    for (auto i : l)
    {
        cout << i << " ";
    }
    cout << " " << endl;
    cout << "size -> " << l.size() << endl;

    list<int> l2(l);
    l.push_back(3);
    l.swap(l2);
    for (auto i : l2)
    {
        cout << i << " ";
    }
    return 0;
}