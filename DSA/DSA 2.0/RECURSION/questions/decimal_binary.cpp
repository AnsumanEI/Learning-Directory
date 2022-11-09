#include <bits/stdc++.h>

using namespace std;

int func(int num)
{

    if (num == 0)
    {
        return 0;
    }
    else
    {
        if (num % 2 == 0)
        {
            func(num / 2);
            cout << " 0 ";
        }
        else
        {
            func(num / 2);
            cout << " 1 ";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    func(12);
    return 0;
}