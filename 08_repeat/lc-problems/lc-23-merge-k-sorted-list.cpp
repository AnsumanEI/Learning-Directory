#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct compare
{
    auto operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val; // we can call this compare also , a > b so a goes deeper so smallest first so minheap
    }
};
class Solution
{

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto cmp = [](ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }; // this is called a lambda and replaces the greater <int> , decltype is whatever the type of cmp is , minheap(cmp) because there is no defined constructor for it , or else we can use struct also
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> minheap(cmp);
        ListNode clone(0);
        ListNode *tail = &clone;
        for (auto &p : lists)
        {
            if (p)
            {
                minheap.push(p);
            }
        }
        while (!minheap.empty())
        {
            ListNode *temp = minheap.top();
            minheap.pop();

            tail->next = temp;
            tail = tail->next;
            if (temp->next)
            {
                minheap.push(temp->next);
            }
        }
        return clone.next;
    }
};
int main()
{

    return 0;
}