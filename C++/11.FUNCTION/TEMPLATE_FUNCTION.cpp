#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
// template <class t>
// to get multiple data types we can also add to template class like one for integer and one for float
template <class a, class b>
void add(a z, b p)
{
    cout << z + p;
    // so here z will be intger and p will be float
}
// t call(t x , t y )
// {
//     return x+y;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    float a, b;
    ;
    float res;
    cout << "enter two numbers" << endl;
    cin >> a >> b;
    // res=call(a,b);
    add(a, b);

    return 0;
}