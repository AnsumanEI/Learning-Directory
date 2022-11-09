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
    array1()
    {
        size = 10;
        length = 0;
    }
    array1(int size, int length = 0)
    {
        this->size = size;
        this->length = length;
        a = new int[size];
    }
    void arrinput();
    void arrdisplay();
    void swap(int *x, int *y);
    void lstransposition(int key);
    void lsmovetofront();
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
void array1::lstransposition(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (a[i] == key)
        {
            if (i != 0)
            {
                swap(&a[i], &a[i - 1]);
            }

            cout << "the address is :" << i + 1 << endl;
        }
    }
}

int main()
{
    //*two types
    //*move to front type
    //*transposition type

    int size, length;
    size = 10;
    length = 5;
    array1 arr1(size, length);

    arr1.arrinput();
    cout << endl;
    arr1.arrdisplay();
    cout << endl;
start:
    cout << "enter the key to find :";
    int key;
    cin >> key;
    arr1.lstransposition(key);
    arr1.arrdisplay();
    goto start;

    //! in move to front same happens just the diffrence is that the searched element is move to the first place every time it is seacrhed

    return 0;
}