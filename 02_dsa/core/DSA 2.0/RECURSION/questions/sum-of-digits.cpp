#include <bits/stdc++.h>

using namespace std;

int func(int num)
{
    static int sum = 0;
    if (num > 0)
    {
        sum += num % 10;
        num /= 10;
        func(num);
    }
    else
    {
        return sum;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << func(20);

    return 0;
}