#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
class stackoverflow : exception
{
};
class stackunderflow : exception
{
};

class stack
{

    int size;
    int *ptr;
    int top = 0;

public:
    int size1(int sz)
    {
        size = sz;
        ptr = new int{size};
    }
    int getsize()
    {
        return size;
    }
    void push(int x)
    {
        if (top == size + 1)
        {
            throw stackoverflow();
        }
        top++;
        ptr[top] = x;
    }
    int pop()
    {
        if (top == 0)
        {
            throw stackunderflow();
        }
        else
        {
            return ptr[top--];
        }
    }
    int *call(int x)
    {
        return ptr;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack obj;
    obj.size1(5);
    obj.push(2);
    obj.push(2);
    obj.push(2);
    obj.push(2);
    obj.push(2);
    obj.push(2); // CANNOT THROW MORE THANT THIS AND RUNS AN ERROR OF STACK OVERFLOW

    obj.push(2);

    int *arr;
    arr = obj.call(10);
    int length = obj.getsize();
    for (int i = 0; i < length + 3; i++)
    {
        cout << *(arr + i) << endl;
    }

    return 0;
}