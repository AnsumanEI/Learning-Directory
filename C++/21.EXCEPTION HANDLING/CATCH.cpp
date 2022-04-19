#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
class parent
{
public:
    char a = 1.0;
};
class child : public parent
{
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    try
    {

                int a;
        a = 10;
        throw a;
        cout << a << endl;
    }
    catch (parent e)
    {
        cout << "parent" << endl;
    }
    catch (int)
    {
        cout << "integer " << endl;
    }

    catch (float)
    {
        cout << "float" << endl;
    }
    catch (...)
    {
        // it means catch all
        cout << "catch all " << endl;
    }
    return 0;
}