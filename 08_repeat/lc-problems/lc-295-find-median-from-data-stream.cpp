#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
public:
    MedianFinder()
    {
    }
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    void rebalance()
    {
        int mxsize = maxheap.size();
        int misize = minheap.size();

        if (mxsize > misize + 1)
        {
            int temp = maxheap.top();
            maxheap.pop();
            minheap.push(temp);
        }
        else if (misize > mxsize)
        {
            int temp = minheap.top();
            minheap.pop();
            maxheap.push(temp);
        }
    }
    void addNum(int num)
    {

        if (!minheap.empty() && num > minheap.top())
        {
            minheap.push(num);
        }
        else
        {
            maxheap.push(num);
        }
        // rebalance
        if (maxheap.size() > minheap.size() + 1 || minheap.size() > maxheap.size())
        {
            rebalance();
        }
    }

    double findMedian()
    {
        if ((maxheap.size() + minheap.size()) % 2 == 0)
        {
            return (maxheap.top() + minheap.top()) / 2.0;
        }
        else
        {
            return maxheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main()
{

    return 0;
}