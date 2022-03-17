#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 1;
    while (n > 10)
    {
        n = n / 10;
        count++;
    }

    if (count <= 3)
    {
        cout << count << endl;
    }
    else
    {
        cout << "More than 3 digits" << endl;
    }
    return 0;
}