#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class array1
{
private:
    int *a;
    int size;
    int length;

public:
    array1(int size = 10, int length = 0)
    {
        this->size = size
        this->length = length;
        a = new int[size];
    }
    void arrinput();
    void arrdisplay();
    void swap(int *x, int *y);
    array1 reverse();
};
void array1::arrinput()
{
    if (size >= length)
    {
        cout << "starting input \n";
        for (int i = 0; i < length; i++)
        {
            cout << "enter the " << i + 1 << " number :";
            cin >> a[i];
            cout << endl;
        }
    }
    else
    {
        cout << " ";
    }
}
void array1::arrdisplay()
{
    cout << "elements are \n";
    for (int i = 0; i < length; i++)
    {
        cout << a[i] << " ";
    }
}
void array1::swap(int *x, int *y)
{
    int temp;
    temp = *y;
    *y = *x;
    *x = temp;
}
array1 array1::reverse()
{
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        //*cout << "I " << i << " j " << j << endl;
        swap(&a[i], &a[j]);
    }
}
int main()
{
    int size, length;
    size = 10;
    length = 10;
    array1 arr1(size, length);
    arr1.arrinput();
    arr1.reverse();
    arr1.arrdisplay();

    return 0;
}