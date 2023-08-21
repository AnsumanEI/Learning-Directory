#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str = "holimay";
    cout << str.at(4) << endl;
    str[4] = 'd';
    cout << str << endl;
    string::iterator bt;
    for (bt = str.begin(); bt != str.end(); bt++)
    {
        cout << *bt << endl;
    }
    cout << str << endl;
    return 0;
}