#include <bits/stdc++.h>

using namespace std;
int func(int pnum, int num, int end)
{
    int next;
    static int i = 1;
    if (i == end + 1)
    {
        return (0);
    }
    else
    {
        next = pnum + num;
        cout << num << " ";
        i++;
        pnum = num;
        num = next;
        func(pnum, num, end);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << func(0, 1, 10);
    return 0;
}