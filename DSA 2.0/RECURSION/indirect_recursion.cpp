#include <bits/stdc++.h>

using namespace std;
class functions
{
public:
    void func(int n)
    {
        if (n > 0)
        {
            func1(n);
        }
    }

    void func1(int n)
    {
        if (n % 2 == 0)
        {
            cout << n << " ";
            func(n - 1);
        }
        else
        {
            func(n - 1);
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    functions b;
    int callvalue;
    cin >> callvalue;
    b.func(callvalue);
    cout << "0" << endl;
    return 0;
}