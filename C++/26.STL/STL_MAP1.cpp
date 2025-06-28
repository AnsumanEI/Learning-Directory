#include <bits/stdc++.h>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // map<key_datatype,value_datatype> name;
    // in this keys are unique and sorted
    map<int, string> m;
    m[4] = {"hello"}; // can also be entered like this
    m.insert(pair<int, string>(1, "ravi"));
    m.insert(pair<int, string>(2, "john"));
    m.insert(pair<int, string>(3, "ansuman"));

    map<int, string>::iterator itr;
    for (itr = m.begin(); itr != m.end(); itr++)
    {
        cout << itr->first << " " << itr->second << endl;
    }
    map<int, string>::iterator itr1;
    itr1 = m.find(3); // finding the key and returning the iterator to thaat address
    cout << itr1->first << " " << itr1->second << endl;

    // when we dereference an operator we get  a pair of key and value rather than oonly value
    // eg
    auto itr2 = m.find(2);
    // instead of auto we can also write map<int,string>::iterator itr2;
    pair<int, string> pair1 = *itr2;
    cout << pair1.first << " " << pair1.second << endl;
    // or directly auto pair = *itr2;
    // we can write the values without dereferencing also by arrow
    auto itr3 = m.find(4);
    auto pair2 = itr3;
    cout << pair2->first << " " << pair2->second;
    map<pair<int, int>, pair<int, int>> m;
    return 0;
}