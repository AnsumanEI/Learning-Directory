#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    char callfunc(vector<char> &letters, char target)
    {
        int s = 0, e = letters.size() - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (letters[mid] <= target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        // Since the array is circular, if s is out of bounds, wrap around to the start.
        if (letters[s] > target)
        {
            return letters[s];
        }
        else
        {
            return letters[0];
        }
    }
};

int main()
{
    Solution obj;
    vector<char> letters = {'a', 'b', 'e', 'f'};
    char target = 'g';
    char a = obj.callfunc(letters, target);
    cout << a;
    return 0;
}
