#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str = "ansuman panigrahi";

    // functions
    // 1.length or size
    cout << str.length() << endl;
    cout << str.size() << endl;
    // 2.capacity
    cout << str.capacity() << endl;
    // resize capacity
    str.resize(100);
    cout << str.capacity() << endl;
    // max size
    cout << str.max_size() << endl;
    // clear and empty checker

    if (str.empty())
    {
        cout << "empty" << endl;
    }
    str.clear();

    if (str.empty())
    {
        cout << "empty" << endl;
    }
    return 0;
}