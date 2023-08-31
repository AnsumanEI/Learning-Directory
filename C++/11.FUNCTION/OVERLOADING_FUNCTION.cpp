#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
int add(int x, int y, int p)
{

    cout << "without float" << endl;
    return 0;
}
int add(int x, int y, float z)
{

    cout << "with float" << endl;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a = 1, b = 2, c = 3, d = 4;

    add(a, b, c);
    add(a, b, 5.6f);
    return 0;
}