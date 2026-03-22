#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
void fun1()
{
    static int count = 0;
    if (count == 3)
    {
        return;
    }
    cout << count << endl;
    count++;
    fun1(); // before base case this function is executed till the base case then it starts getting completed from the last and secound cout is executed
    count--;
    cout << count << " after ";
}
int main()
{
    fun1();
    return 0;
}
