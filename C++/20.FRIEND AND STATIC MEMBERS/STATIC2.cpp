#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
class admission
{

public:
    static int admnumber;
    int rollno;
    admission()
    {
        admnumber++;
        rollno = admnumber;
    }
    int getRoll()
    {
        return rollno;
    }
    static int getadm()
    {
        return admnumber;
    }
};
int admission::admnumber = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    admission a1, a2, a3;
    cout << a1.getRoll() << endl;
    cout << a2.getRoll() << endl;
    cout << admission::getadm() << endl; // can be used with scope resolution as it is a static function
    cout << admission::getadm() << endl; // can be used with scope resolution as it is a static function

    return 0;
}