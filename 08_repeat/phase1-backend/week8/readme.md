# C++ Task Scheduler

## What this project does

Simulates a priority-based task scheduler in C++.
Each task has an id, priority, duration, and cooldown period.
Two scheduling strategies are compared:

- **Priority Scheduler** — uses a max heap (priority_queue) to always run the highest priority task first
- **Naive Scheduler** — uses a regular queue (FIFO), runs tasks in insertion order

## How to compile and run

```bash
g++ -std=c++17 task_scheduler.cpp -o task_scheduler
./task_scheduler
```

## What the output means

Each task prints its start time and completion time.
Time advances by `duration + cooldown` after each task.
At the end, weighted throughput is printed:
`throughput = sum of (priority / finish_time)` across all tasks

## Results

Both schedulers process the same 20 tasks in the same total time (115 units).
However, weighted throughput shows a clear difference:

| Scheduler           | Throughput |
| ------------------- | ---------- |
| Priority (max heap) | 18.14      |
| Naive (queue)       | 2.99       |

Priority scheduling is **6x better** — high priority tasks finish early,
delivering more value per unit of time.
