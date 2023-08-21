#include <iostream >
using namespace std;
const int abc = 5;
int max = 1;
int main()
{

    int arr[::abc];
    for (auto &x : arr)
    {
        cout << "enter the element " << endl;
        cin >> x;
        if (x > ::max)
        {

            ::max = x;
        }
    }
    cout << " ____________" << endl;
    cout << "max -> " << ::max << endl;
}
