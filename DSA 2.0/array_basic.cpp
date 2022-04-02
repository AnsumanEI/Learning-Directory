#include <bits/stdc++.h>

using namespace std;
struct rectangle
{
    int length;
    int breadth;
    int getlength();
    int getbreadth();
};
int rectangle::getlength()
{
    return length;
}
int rectangle::getbreadth()
{
    return breadth;
}
int main()
{

    struct rectangle obj;
    struct rectangle *ptr;
    ptr->length = 100;
    ptr->breadth = 20; // for pointer variable arrow is used
    struct rectangle *ptr1 = new rectangle();
    ptr1->getlength();
    ptr1->getbreadth();

    return 0;
}