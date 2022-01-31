#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
class car
{
public:
    virtual int start() = 0; // purely virtual as function=0 done to achieve polymorphism,it has to be overriden by the derived class
    virtual int stop() = 0;
};
class ferrari : public car
{
public:
    int start()
    {
        cout << "ferrari started " << endl;
    }
    int stop()
    {
        cout << "ferrari stopped" << endl;
    }
};
class innova : public car
{
public:
    int start()
    {
        cout << "innova started " << endl;
    }
    int stop()
    {
        cout << "innova stopped " << endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    car *ptr = new ferrari();
    ptr->start();
    ptr->stop();
    ptr = new innova();
    ptr->start();
    ptr->stop();

    return 0;
}