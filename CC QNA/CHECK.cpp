#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

class sort
{
public:
    int size;
    int *ptr;
    sort(int size = 0)
    {
        this->size = size;
        ptr = new int[size];
    }
    void input()
    {
        cout << "start entering the  elements" << endl;
        for (int i = 0; i < size; i++)
        {

            cin >> *(ptr + i);
        }
    }
    void output()
    {
        cout << "the sorted elements are " << endl;
        for (int j = 0; j < size; j++)
        {

            cout << *(ptr + j) << endl;
        }
    }
    void sorting()
    {
        int check = 0;
        while (check < size + 1)
        {
            for (int k = 0; k < size; k++)
            {
                for (int l = k + 1; l < size; l++)
                {
                    if (*(ptr + k) > *(ptr + l))
                    {
                        int temp;
                        temp = *(ptr + k);
                        *(ptr + k) = *(ptr + l);
                        *(ptr + l) = temp;
                    }
                    else
                    {
                        check++;
                    }
                }
            }
        }
    }
};

int main()
{
    int n;
    cout << "enter the size of the array " << endl;
    cin >> n;
    sort obj(n);
    obj.input();
    obj.sorting();
    obj.output();
    return 0;
}