#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
static char regno = '000000000';
struct ielts
{
    char reg_no[15];
    float bnd1, bnd2, bnd3;
};
float calc(struct ielts one)
{
    return one.bnd1 + one.bnd2 + one.bnd3;
}
int main()
{
    int size;
    cout << "enter the number of people :";
    cin >> size;
    ielts test[size];
    for (int i = 0; i < size; i++)
    {
        cin >> test[i].reg_no;
        cin >> test[i].bnd1 >> test[i].bnd2 >> test[i].bnd3;
    }
    int number;
    cin >> number;
    int avg = calc(test[number]) / 3;
    cout << avg;
    return 0;
}