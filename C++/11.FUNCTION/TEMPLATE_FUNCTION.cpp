#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
template <class a>
// to get multiple data types we can also add to template class like one for integer and one for float
// template <class a, class b>
// void add(a z, b p)
// {
//     cout << z + p;
//     // so here z will be intger and p will be float
// }
a printf1(a number1)
{
    switch (number1)
    {
    case 21:
        cout << "integer" << endl;
        break;
    case 'a':
        cout << "character" << endl;
    case 2:
        cout << "float" << endl;
    default:
        cout << "something else" << endl;
        break;
    }
    return number1;
}
int main()
{
    printf1(21);
    printf1('a');
    printf1(2);
}
