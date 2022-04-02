#include <bits/stdc++.h>

using namespace std;
int *swap(int *a, int *b)
{
    int *temp;
    *temp = *a;
    *a = *b;
    *b = *temp;
    return temp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a;
    int b;
    cin >> a >> b;
    int *swap1;

    swap1 = swap(&a, &b);
    cout << a << " " << b << endl;

    return 0;
}