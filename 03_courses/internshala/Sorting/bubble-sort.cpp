#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
vector<int> bubblesort(vector<int> &arr)
{
    int count = 0;
    int size = arr.size();
    for (int i = 0; i < size - 1; ++i) // no. of passes
    {
        for (int j = 0; j < (size - i) - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                count++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (count == 1) // so that if already sorted then no passes are used
            count--;
        return arr;
    }
    return arr;
}
void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr.at(i) << " ";
    }
}
int main()
{
    // logic
    // passes means the stages of sorting
    // adjacent elements are compared and swapped
    // eg 5 elements are there
    // 1st pass 1 to n-1 = 4 passes the largest will settle on the last
    // 2nd pass 1 to n-2 = 3 passes the 2nd largest will settle on the 2nd last
    // so on and so forth
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {

        arr.push_back(rand() % 100 + 0);
    }
    vector<int> ans = bubblesort(arr);
    display(ans);
    return 0;
}