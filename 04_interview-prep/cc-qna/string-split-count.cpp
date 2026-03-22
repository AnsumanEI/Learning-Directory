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
        string s;
        string str1, str2;
        cin >> s;
        int length;
        int count = 0;

        length = s.length();

        if (length % 2 == 0)
        {
            str1 = s.substr(length / 2, length / 2);
            str2 = s.substr(0, length / 2);
            for (int i = 0; i < length / 2; i++)
            {
                for (int j = length / 2; j < length; j++)
                {
                    if (str2[i] == str1[j])
                    {
                        count++;
                        i++;
                    }
                }
            }
        }
        else
        {
            int mid;
            mid = (length / 2) + 1;
            str1 = s.substr(mid, length / 2);
            str2 = s.substr(0, length / 2);

            for (int i = 0; i < str1.length(); i++)
            {
                for (int j = 0; j < str2.length(); j++)
                {
                    if (str2[i] == str1[j])
                    {
                        count++;
                    }
                }
            }
        }

        if (count >= length / 2)
        {
            cout << "YES" << endl;
            cout << count << endl;
        }
        else
        {
            cout << "NO" << endl;
            cout << count << endl;
        }
    }
    return 0;
}