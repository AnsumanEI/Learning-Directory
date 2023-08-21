#include <iostream>
using namespace std;
int main()
{

    int *p = new int[5];
    *(p + 1) = 2;

    cout << "&p ->" << &p << "\n"
         << "p ->" << &*p << "\n" // address of the heap
         << "&* ->" << &*(p + 1) << "\n"
         << "&p[] ->" << &p[1] << endl; // 2nd and third are the same way of diffrent things

    for (int i = 0; i < 5; i++)
    {
        cout << *(p + i) << endl;
    }
    delete[] p;

    return 0;
}