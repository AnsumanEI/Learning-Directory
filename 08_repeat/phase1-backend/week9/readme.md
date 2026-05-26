# C++ Graph Pathfinder

A CLI tool that finds paths between two nodes in a weighted undirected graph using three algorithms: BFS, DFS, and Dijkstra.

## What it does

- Accepts a graph as an adjacency list from stdin
- Runs BFS (shortest by hop count), DFS (first valid path), and Dijkstra (shortest by weight)
- Prints the path and total distance for each algorithm

## Compile & Run

```bash
g++ -std=c++17 main.cpp -o main && ./main
```

## Input Format

```
<number of nodes>
<number of edges>
<u> <v> <weight>   ← one edge per line
...
<source> <destination>
```

## Example

**Input:**

```
5
6
0 1 4
0 2 1
2 1 2
1 3 1
2 4 5
3 4 3
0 4
```

Node layout: 0, 1, 2, 3, 4  
Edge `0 2 1` means node 0 and node 2 are connected with weight 1.  
Find path from node **0** to node **4**.

**Output:**

```
<--------------------BFS--------------------->
0 -> 2 -> 4
Bfs Distance : 6

<--------------------DFS--------------------->
0 -> 1 -> 2 -> 4
DFS Distance : 11

<--------------------DIJSKTRA--------------------->
0 -> 2 -> 4
Dijkstra Distance : 6
```

## Algorithm Notes

| Algorithm | Finds                  | Use when                           |
| --------- | ---------------------- | ---------------------------------- |
| BFS       | Fewest hops            | Equal weights or hop count matters |
| DFS       | Any valid path         | Exploring all paths                |
| Dijkstra  | Shortest weighted path | Different edge weights             |
