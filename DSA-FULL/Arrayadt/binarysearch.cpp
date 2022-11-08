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
        this->size = size;
        this->length = length;
        a = new int[size];
    }
    void arrinput();
    void arrdisplay();
    int binarysearch(int low, int high, int key, array1 &arr);
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
        sort(&a[0], &a[length]);
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
int array1::binarysearch(int low, int high, int key, array1 &arr)
{
    int mid = (low + high) / 2;
    if (low > high)
    {
        cout << "not found " << endl;
        return -1;
    }

    if (key == a[mid])
    {
        cout << "address ::";
        return mid + 1;
    }
    else if (key < a[mid])
    {
        arr.binarysearch(low, mid - 1, key, arr);
    }
    else if (key > a[mid])
    {
        arr.binarysearch(mid + 1, high, key, arr);
    }
}

int main()
{
    //*for binary search the numbers should be sorted
    int size, length;
    size = 10;
    length = 5;
    array1 arr1(size, length);
    arr1.arrinput();
    int key;
    cout << "enter the key :";
    cin >> key;
    arr1.arrdisplay();
    cout << arr1.binarysearch(0, length, key, arr1);

    return 0;
}