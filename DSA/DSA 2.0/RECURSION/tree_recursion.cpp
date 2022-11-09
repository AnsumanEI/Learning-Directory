#include <bits/stdc++.h>

using namespace std;
void func(int n)
{
    if (n > 0)
    {

        cout << n << endl;
        func(n - 1);
        func(n - 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    func(4);
    return 0;
}