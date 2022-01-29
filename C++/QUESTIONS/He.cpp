#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int num, rot;
        cin >> num >> rot;
        int arr[num];
        rot %= num;
        for (int i = 0; i < num; i++)
        {
            cin >> arr[i];
        }
        while (rot--)
        {
            int temp = 0;
            temp = arr[0];
            arr[0] = arr[num - 1];

            for (int j = num - 1; j > 1; j--)
            {

                arr[j] = arr[j - 1];
            }
            arr[1] = temp;
        }

        for (int k = 0; k < num; k++)
        {
            cout << arr[k] << " ";
        }
    }

    return 0;
}