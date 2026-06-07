#include <bits/stdc++.h>
using namespace std;
class NumArray
{
    vector<int> tree;
    int globalsize = 0;

public:
    void buildtree(int node, int start, int end, vector<int> &nums, vector<int> &tree)
    {
        if (start == end)
        {
            tree[node] = nums[start];
            return;
        }
        int mid = (start + end) / 2;
        buildtree(2 * node, start, mid, nums, tree);
        buildtree(2 * node + 1, mid + 1, end, nums, tree);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    int sumhelper(int node, int start, int end, int l, int r, vector<int> &tree)
    {
        if (l <= start && r >= end)
        {
            return tree[node];
        }
        else if (r < start || l > end)
        {
            return 0;
        }
        else
        {
            int mid = (start + end) / 2;
            int left = sumhelper(2 * node, start, mid, l, r, tree);
            int right = sumhelper(2 * node + 1, mid + 1, end, l, r, tree);
            return left + right;
        }
    }
    NumArray(vector<int> &nums)
    {
        tree.resize(4 * nums.size(), 0);
        globalsize = nums.size();
        buildtree(1, 0, nums.size() - 1, nums, tree);
    }
    void updatehelper(int node, int start, int end, int index, int val, vector<int> &tree)
    {
        if (start == end)
        {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid)
        {
            updatehelper(2 * node, start, mid, index, val, tree);
        }
        else
        {
            updatehelper(2 * node + 1, mid + 1, end, index, val, tree);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    void update(int index, int val)
    {
        updatehelper(1, 0, globalsize - 1, index, val, tree);
    }
    int sumRange(int left, int right)
    {
        return sumhelper(1, 0, globalsize - 1, left, right, tree);
    }
};
int main()
{

    return 0;
}