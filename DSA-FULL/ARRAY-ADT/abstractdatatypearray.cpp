#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
class array1
{
private:
    int *a;
    vector<int> *restore;
    int size;
    int length;

public:
    array1()
    {
        size = 10;
        length = 0;
        a = new int[size];
        restore = new vector<int>(size, 0);
    }
    array1(int size, int length)
    {
        if (size >= length)
        {
            this->size = size;
            this->length = length;
            a = new int[size];
            restore = new vector<int>;
        }
        else
        {
            cout << "invalid input ";
            return;
        }
    }
    void arrinput();
    void arrdisplay();
    void arradd(array1 &arr);
    void arrinsert();
    void arrdelete();
    void arrrestore();
    void arrsearch();
    int arrassortedinsert(int x);
    void arrarraymerge(array1 &arr);
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
        for (int i = length; i < size; i++)
        {
            a[i] = 0;
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
void array1::arradd(array1 &arr1)
{
    if (length < size)
    {
        cout << "enter the element to add in the last :";
        cin >> a[length];
        length++;
    }
    else
    {
        // ?cout << "size ++\n"; to check the working of the loop
        size++;
        arr1.arradd(arr1);
    }
}
void array1::arrinsert()
{
insert:
    cout << "enter the index and element :";
    int index, num;
    cin >> index >> num;

    if (index < size && index >= 0)
    {
        length++;
        for (int i = length; i > index; i--)
        {
            a[i] = a[i - 1];
            a[i - 1] = 0;
        }
        a[index] = num;
        size++;
    }
    else
    {
        cout << "invalid index " << endl;
        goto insert;
    }
}
void array1::arrdelete()
{
delete1:
    int index;
    cout << "enter the index you want to delete :";
    cin >> index;
    index -= 1;
    if (index >= 0 && index < length)
    {

        restore->push_back(a[index]);
        for (int i = index; i < length; i++)
        {
            a[i] = a[i + 1];
        }
        length--;
    }
    else
    {
        cout << "invalid index" << endl;
        goto delete1;
    }
}
void array1::arrrestore()
{
    cout << "the deleted element is ::";
    cout << restore->at(0);
}
int array1::arrassortedinsert(int x)
{
    int j = 0;
    while (x > a[j])
    {
        j++;
    }

    length++;
    size++;
    for (int i = length; i > j; i--)
    {
        a[i] = a[i - 1];
        a[i - 1] = 0;
    }
    a[j] = x;
}
void array1::arrarraymerge(array1 &arr){
    // first call arr2 object the inside it call arr1 object again by repeating this same function
    // then store the elements in algorithm for merging
};

int main()
{
    int size;
    int length;
    cout << "enter the size and length of the array :";
    cin >> size >> length;
    array1 arr(size, length);
    arr.arrinput();
    cout << endl;
    array1 arr2(10, 5);
    arr.arrinput();
    cout << endl;
    arr.arrdisplay();
    arr2.arrdisplay();

    return 0;
}