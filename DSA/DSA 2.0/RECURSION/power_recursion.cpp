#include <bits/stdc++.h>

using namespace std;
int func(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }
    else
    {
        return x * func(x, y - 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << func(2, 4);
    return 0;
}