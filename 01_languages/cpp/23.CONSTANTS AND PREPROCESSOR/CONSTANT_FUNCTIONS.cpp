#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

class base
{

public:
    int x = 10;
    int y = 20;
    void modifiable()
    {
        x++; // modify the data member
        cout << x << " " << y << endl;
        x--;
    }
    void unmodifiable() const
    {
        // x++; is not possible as the function is constant and cannot modify any member of the class
        cout << x << " " << y << endl;
    }
};

int main()
{
    base b;
    b.modifiable();
    b.unmodifiable();
    return 0;
}