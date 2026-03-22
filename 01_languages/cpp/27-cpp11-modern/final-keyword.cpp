#include <bits/stdc++.h>

using namespace std;
int count = 1;
class parent final
{
public:
    parent()
    {
        cout << "final keyword means that no inheritance from that class and also the the function cannot be overloaded " << endl;
    }
    void delete1(parent &obj)
    {
        delete &obj;
    }
    ~parent()
    {

        cout << "destroyed " << ::count << endl;
        ::count++;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    parent b1;
    b1.delete1(b1);

    return 0;
}