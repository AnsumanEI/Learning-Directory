#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
class salary
{

public:
    int num;
    salary(int num = 0)
    {
        this->num = num;
    }
    float basic();
    float hra();
    float da();
    float gross();
};
float salary::gross()
{
    return basic() + hra() + da();
}
float salary::basic()
{
    return num;
}
float salary::hra()
{
    return num >= 1500 ? 500 : 0.1 * num;
}
float salary::da()
{

    return num >= 1500 ? (0.98 * num) : 0.9 * num;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int slry;
        cin >> slry;
        salary t(slry);
        cout << fixed << setprecision(6) << t.gross() << endl;
    }
    return 0;
}