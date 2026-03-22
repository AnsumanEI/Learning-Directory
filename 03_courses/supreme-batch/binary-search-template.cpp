#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int callfunc(vector<int> &nums, int key)
    {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (nums[mid] == key)
            {
                return mid;
            }
            else if (nums[mid] > key)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> bst = {5, 4, 3, 2, 1};
    sort(bst.begin(), bst.end());

    int key;
    cout << "Enter key: ";
    cin >> key;

    Solution obj;
    int result = obj.callfunc(bst, key);

    if (result != -1)
    {
        cout << "Key found at index: " << result << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    }

    return 0;
}
