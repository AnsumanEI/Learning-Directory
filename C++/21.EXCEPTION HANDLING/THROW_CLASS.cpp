#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
class myexception
{
public:
    myexception(int x, int y)
    {
        y = 1;
        x = 0;
    }
};
int check(int f, int g)
{
    if (g == 0)
    {
        throw 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num1, num2;
    cin >> num1 >> num2;
    try
    {

        int divide;
        check(num1, num2);
        divide = num1 / num2;
        cout << divide << endl;
    }
    catch (int z)
    {
        cout << "there is an error in the value of denominator " << z << endl;
    }

    return 0;
}