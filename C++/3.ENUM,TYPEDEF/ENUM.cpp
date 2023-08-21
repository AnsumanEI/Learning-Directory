#include <iostream>
using namespace std;
enum day
{
    mon,
    tue,
    wed,
    thu = 12,
    fri,
    sat,
    sun
};
int main()
{
    // the easy way for this is the enum
    // they will take the value from 0 to any number
    // now the type word is like int we can define it like
    day d;
    cout << mon << endl;
    cout << tue << endl;
    cout << wed << endl;
    cout << thu << endl;
    cout << fri << endl;
    cout << sat << endl;
    cout << sun << endl;

    return 0;
}