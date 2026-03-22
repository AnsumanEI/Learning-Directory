#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
vector<int> bubblesort(vector<int> &arr)
{
    int size = arr.size();
    for (int i = 0; i < size - 1; ++i) // no. of passes
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
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
    // same as bubble sort but the the number which is compared is not switched

    vector<int> arr;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {

        arr.push_back(rand() % 100 + 0);
    }
    vector<int> ans = bubblesort(arr);
    display(ans);
    return 0;
}