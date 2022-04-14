#include <bits/stdc++.h>

using namespace std;
int count = 1;
class rectangle
{
public:
    int length;
    int breadth;
    rectangle(int x = 0, int y = 0)
    {
        length = x;
        breadth = y;
        cout << "object " << ::count << " is created" << endl;
        ::count++;
    }
    int area()
    {
        cout << endl;
        cout << "area " << length * breadth << endl;
    }
    int perimeter()
    {
        cout << endl;
        cout << "peri " << 2 * (length + breadth) << endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // three types of smart poiinters
    // unique pointers

    // if we use normal pointer we have to delete the object after completion , if we are using heap memory
    // eg
    // rectangle *ptr = new rectangle(2, 2);
    // delete ptr;
    // this needs to be written
    // or instead we can use unique pointers which automatically deallocates the memory after the object is pulled out os scope

    unique_ptr<rectangle> ptr2(new rectangle(3, 3));
    ptr2->area();
    ptr2->perimeter();
    // shared pointers
    // shared pointers means unique pointers but diffrent pointers can assign to same value
    unique_ptr<rectangle> ptr3;
    ptr3 = move(ptr2);
    // now the pointer is using ptr3 so it cannot use ptr2 now
    // eg
    ptr3->area();
    ptr2->area();
    // weak pointers
    // it is between both unique and shared pointers it does not cares how many ptrs are pointing
    return 0;
}