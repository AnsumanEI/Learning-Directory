#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
namespace first
{

    void func()
    {
        std::cout << "function from the first namespace " << std::endl;
    }
}
namespace second
{
    void func()
    {
        std::cout << "same function name but from the second namespace " << std::endl;
    }
}

int main()
{
    first::func();

    second::func();

    return 0;
}