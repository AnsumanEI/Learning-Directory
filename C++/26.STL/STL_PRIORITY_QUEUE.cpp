#include <bits/stdc++.h>

using namespace std;
// this data structure has only two possibility
// min heap
// max heap
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int> maxi;
    maxi.push(10);
    maxi.push(5);
    maxi.push(1);
    maxi.push(11);
    maxi.push(6);
    // the top value is always the maximum of the entire queue
    cout << "top element = " << maxi.top() << endl;
    int size = maxi.size();
    cout << "printing maximum heap " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;
    // now for minimum heap
    priority_queue<int, vector<int>, greater<int>> mini;
    cout << "printing minimum heap " << endl;
    mini.push(10);
    mini.push(5);
    mini.push(1);
    mini.push(11);
    mini.push(6);
    size = mini.size();
    for (int i = 0; i < size; i++)
    {
        cout << mini.top() << " ";
        mini.pop();
    }

    return 0;
}