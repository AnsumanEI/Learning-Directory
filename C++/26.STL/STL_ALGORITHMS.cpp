#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v;
    v.push_back(1);
    v.push_back(8);
    v.push_back(28);
    v.push_back(10);

    cout << "binary searching for the number 28 - > " << binary_search(v.begin(), v.end(), 28) << endl;
    sort(v.begin(), v.end());
    // for upper bound lower bound binary search the data structure should be sorted

    cout << "lower bound for 10 ->" << lower_bound(v.begin(), v.end(), 10) - v.begin();
    cout << endl;
    cout << "lower bound for 10 ->" << upper_bound(v.begin(), v.end(), 10) - v.begin();

    int a = 10;
    int b = 20;
    cout << "maximum of a b -> " << max(a, b) << endl; // can be done for 2  data
    cout << "minimum of a b -> " << min(a, b) << endl;
    string str = "hello";
    reverse(str.begin(), str.end());
    cout << "reversed string -> " << str << endl;
    rotate(v.begin(), v.begin() + 3, v.end());
    cout << "rotated the vector -> " << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}