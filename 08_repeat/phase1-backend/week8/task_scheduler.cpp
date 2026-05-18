#include <bits/stdc++.h>
using namespace std;
struct Task
{
    static int count;
    int id = 0;
    int Priority;
    int duration;
    int cooldown;

    Task()
    {
    }
    Task(int pr, int dr, int cd)
    {
        id = ++count;
        Priority = pr;
        duration = dr;
        cooldown = cd;
    }
};
struct Operator
{
    bool operator()(Task a, Task b)
    {
        return a.Priority < b.Priority;
    }
};
void runScheduler(priority_queue<Task, vector<Task>, Operator> pq, queue<Task> store)
{
    int current_time = 0;
    double throughput;

    while (!pq.empty())
    {
        Task temp = pq.top();
        // cout << "Task :" << temp.id << " Starting , Current Time : " << current_time << "\n";
        pq.pop();
        current_time += temp.cooldown + temp.duration;
        throughput += (double)temp.Priority / current_time;
        //  cout << "Task :" << temp.id << " Completed, Current Time : " << current_time << "\n";
    }
    cout << "Total time taken=" << current_time << " Throughput :" << throughput;

    cout << "\n\n\n"
         << "Now the Naive scheduler \n\n\n";
    current_time = 0;
    throughput = 0.0;

    while (!store.empty())
    {
        Task temp1 = store.front();
        //  cout << "Task :" << temp1.id << " Starting , Current Time : " << current_time << "\n";
        store.pop();
        current_time += temp1.cooldown + temp1.duration;
        throughput += (double)temp1.Priority / current_time;
        // cout << "Task :" << temp1.id << " Completed, Current Time : " << current_time << "\n";
    }
    cout << "Total time taken=" << current_time << " Throughput :" << throughput;
}
int Task::count = 0;

int main()
{
    queue<Task> naive;
    priority_queue<Task, vector<Task>, Operator> pq;

    vector<tuple<int, int, int>> data = {
        {3, 5, 2}, {7, 2, 1}, {1, 8, 3}, {9, 1, 0}, {5, 4, 2}, {2, 6, 1}, {8, 3, 2}, {4, 7, 3}, {6, 2, 1}, {10, 1, 0}, {1, 9, 4}, {7, 3, 2}, {3, 5, 1}, {6, 4, 3}, {9, 2, 0}, {2, 7, 2}, {8, 1, 1}, {4, 6, 3}, {5, 3, 2}, {10, 2, 1}};

    for (auto &[pr, dr, cd] : data)
    {
        Task t(pr, dr, cd);
        naive.push(t);
        pq.push(t);
    }
    runScheduler(pq, naive);
    return 0;
}