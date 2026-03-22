#include <bits/stdc++.h>
#include <set>
using namespace std;
// set only stores the unique elements
// it return the values  in a sorted way
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<string> s;
    set<string> s1;

    s.insert("hello");
    s.insert("hello");

    int size = s.size();
    set<string>::iterator it;
    cout << "the string array = >" << endl;
    for (it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    // it only returns one value hello as it is repeated many times
    cout << "check wether hello is present in the set or not - > " << s.count("hello") << endl; // returns one so it is present
    // find returns the iterator if the value is present
    set<string>::iterator itr = s.find("hello");
    // can only be traverse by iterators an random access is not allowed
    s.lower_bound("hello"); // returns element to the frst element greater than or equalto the input
    // to verify we print the value at that address
    // s.erase(it); // erases the element in which the iterator is present
    cout << "value at iterator returned by find - > " << *itr << endl;

    return 0;
}