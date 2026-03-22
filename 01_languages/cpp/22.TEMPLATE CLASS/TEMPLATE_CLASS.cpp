#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
template <class t>

class stack
{
    int size;
    int top = 0;
    int *ptr;

public:
    t array(t sz)
    {
        ptr = new t[sz];
    }

    void push(t a);
    void pop();
};
template <class t>
void stack<t>::push(t a)
{
}
template <class t>
void stack<t>::pop()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> s;
    stack<float> s1;
    return 0;
}