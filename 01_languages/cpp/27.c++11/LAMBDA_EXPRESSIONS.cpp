#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // lambda expressions ot unnamed funtions
    //[capture list](parameter){body}(this parenthis to call the function)
    // simple printing hello with unnamed functions
    []()
    { cout << "hello"; }(); // directly calling
    cout << endl;
    auto function = []()
    { cout << "hello by call"; };
    function();
    // taking parameters
    // to use local variables use capture list[]
    cout << endl;
    int a, b;
    a = 10;
    b = 20;
    [a, b](int x, int y)
    { cout << a + x << " " << b + y << endl; }(11, 22);
    // still we cannot modify a or b so to modify we use reference variable
    [&]()
    { cout << ++a << " " << ++b << endl; }();
    return 0;
}