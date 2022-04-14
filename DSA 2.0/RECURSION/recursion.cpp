#include <bits/stdc++.h>

using namespace std;
// 1st.function
// 2nd.stopping condition
// calling fun
void fun(int x)
{
    if (x > 0)
    {
        cout << x << " ";
        fun(x - 1);
    }
}
void fun1(int y)
{
    if (y > 0)
    {

        fun1(y - 1); // calling
        cout << y << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fun(10);
    cout << endl;
    fun1(10);
    return 0;
}