#include <bits/stdc++.h>

using namespace std;
// cannot be converted to loops easily

void func(int n)
{
    if (n > 0)
    {
        func(n - 1);
        cout << n << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    func(5);
    return 0;
}