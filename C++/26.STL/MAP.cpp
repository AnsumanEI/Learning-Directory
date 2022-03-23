#include <bits/stdc++.h>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int, string> m;
    m.insert(pair<int, string>(1, "ravi"));
    m.insert(pair<int, string>(2, "john"));
    m.insert(pair<int, string>(3, "ansuman"));

    map<int, string>::iterator itr;
    for (itr = m.begin(); itr != m.end(); itr++)
    {
        cout << itr->first << " " << itr->second << endl;
    }
    map<int, string>::iterator itr1;
    itr1 = m.find(3);
    cout << itr1->first << " " << itr1->second << endl;

    return 0;
}