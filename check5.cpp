#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guess(int a); // this was given in the code database
    int guessNumber(int n)
    {
        int l = 1;
        int r = n;
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            int g = guess(mid);
            if (g == 0)
                return mid;
            else if (g == -1)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return 0;
    }
};
int main()
{

    return 0;
}