#include <bits/stdc++.h>
#include <climits>
using namespace std;
char *func(char str1[])
{
    static int i = 0;
    static char rev[100];
    if (*str1)
    {
        func(str1 + 1);

        cout << *str1 << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char str[100];
    cin >> str;
    func(str);
    return 0;
}