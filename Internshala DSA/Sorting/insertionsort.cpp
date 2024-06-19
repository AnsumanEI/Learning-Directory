#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
vector<int> selecsort(vector<int> &arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
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
    vector<int> arr;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(rand() % 100 + 0);
    }
    display(arr);
    vector<int> ans = selecsort(arr);
    cout << endl;
    display(ans);
    return 0;
}