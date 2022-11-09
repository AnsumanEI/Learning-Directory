#include <bits/stdc++.h>

using namespace std;
int func(int n)
{

    if (n > 0)
    {
        return func(n - 1) + n; // n is added in returning time
        // if n is static it will only have o single copy everytime it is called
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a = 5;
    cout << func(a) << endl;
    return 0;
}