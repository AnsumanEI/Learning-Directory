#include <bits/stdc++.h>

using namespace std;
int func(int num, int num2)
{
    int lemma;
    if (num2 > num)
    {
        int temp = num;
        num = num2;
        num2 = temp;
    }
    if (num % num2 == 0)
    {
        return num2;
    }
    else
    {
        lemma = num % num2;
        num = num2;
        num2 = lemma;

        func(num, num2);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << func(19, 7);
    return 0;
}