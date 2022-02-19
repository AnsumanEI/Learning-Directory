#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <climits>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int temp = INT_MAX;
        int skill[N];
        for (int i = 0; i < N; i++)
        {
            cin >> *(skill + i);
            if (i != 0)
            {
                for (int j = 1; j <= i; j++)
                {
                    if (skill[i] <= skill[j - 1])
                    {
                        if ((skill[j - 1] - skill[i]) < temp)
                        {
                            temp = skill[j - 1] - skill[i];
                        }
                    }
                    else
                    {
                        if ((skill[i] - skill[j - 1]) < temp)
                        {
                            temp = skill[i] - skill[j - 1];
                        }
                    }
                }
            }
        }
        cout << temp << endl;
    }
    return 0;
}