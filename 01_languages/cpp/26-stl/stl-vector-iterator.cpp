#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // iterator for vector
    vector<int> v(10);
    vector<int>::iterator itr;
    for (itr = v.begin(); itr != v.end(); itr++)
    {
        cout << *itr << endl;
    }

    // exact same for list forwarlist and deque

    return 0;
}