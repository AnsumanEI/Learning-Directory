#include <bits/stdc++.h>

using namespace std;
// tail recursion can be easily converted to loops
// loops are more efficient int case of tail recursion
// if the values are added in return time then it cannot be a tail recursion
void func(int n)
{
    if (n > 0)
    {
        cout << "number " << n << endl;
        func(n - 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    func(5);
    return 0;
}