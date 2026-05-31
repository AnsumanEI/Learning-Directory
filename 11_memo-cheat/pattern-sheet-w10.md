# DSA Problems by Pattern

> One problem can appear in multiple patterns. Use this to think in patterns, not problem names.

---

## 1. Hash Map / Frequency Count

| Problem                              | Notes                  |
| ------------------------------------ | ---------------------- |
| LC #1 Two Sum                        | classic hashmap lookup |
| LC #217 Contains Duplicate           | set lookup             |
| LC #242 Valid Anagram                | frequency count        |
| LC #49 Group Anagrams                | sorted key → hashmap   |
| LC #347 Top K Frequent Elements      | freq map + heap        |
| LC #451 Sort Characters by Frequency | freq map + heap        |
| LC #692 Top K Frequent Words         | freq map + heap        |
| LC #249 Group Shifted Strings        | diff pattern key       |

---

## 2. Two Pointers / Sliding Window

| Problem                                   | Notes                 |
| ----------------------------------------- | --------------------- |
| LC #3 Longest Substring Without Repeating | sliding window + set  |
| LC #239 Sliding Window Maximum            | monotonic deque       |
| LC #480 Sliding Window Median             | two heaps + window    |
| LC #33 Search in Rotated Sorted Array     | binary search variant |
| LC #704 Binary Search                     | pure binary search    |

---

## 3. Prefix / Suffix

| Problem                              | Notes                  |
| ------------------------------------ | ---------------------- |
| LC #238 Product of Array Except Self | prefix + suffix arrays |
| LC #560 Subarray Sum Equals K        | prefix sum + hashmap   |

---

## 4. Stack

| Problem                          | Notes                           |
| -------------------------------- | ------------------------------- |
| LC #20 Valid Parentheses         | classic stack                   |
| LC #155 Min Stack                | stack with min tracking         |
| LC #32 Longest Valid Parentheses | stack + indices                 |
| LC #239 Sliding Window Maximum   | monotonic deque (stack variant) |

---

## 5. Binary Search

| Problem                               | Notes                                    |
| ------------------------------------- | ---------------------------------------- |
| LC #704 Binary Search                 | pure                                     |
| LC #33 Search in Rotated Sorted Array | modified binary search                   |
| LC #230 Kth Smallest in BST           | inorder — not binary search but BST      |
| LC #354 Russian Doll Envelopes        | LIS + binary search                      |
| LC #300 LIS                           | binary search version (patience sorting) |

---

## 6. Trees — DFS / BFS

| Problem                                     | Notes                 |
| ------------------------------------------- | --------------------- |
| LC #104 Max Depth of BT                     | DFS recursion         |
| LC #111 Minimum Depth of BT                 | BFS or DFS            |
| LC #226 Invert BT                           | DFS                   |
| LC #100 Same Tree                           | DFS                   |
| LC #572 Subtree of Another Tree             | DFS + same tree check |
| LC #98 Validate BST                         | DFS with bounds       |
| LC #230 Kth Smallest in BST                 | inorder DFS           |
| LC #236 LCA of Binary Tree                  | DFS post-order        |
| LC #235 LCA of BST                          | DFS with BST property |
| LC #105 Construct BT from Preorder+Inorder  | DFS + index math      |
| LC #106 Construct BT from Inorder+Postorder | DFS + index math      |
| LC #199 BT Right Side View                  | BFS level order       |
| LC #297 Serialize/Deserialize BT            | BFS + queue           |
| LC #114 Flatten BT to Linked List           | DFS post-order        |
| LC #538 Convert BST to Greater Tree         | reverse inorder DFS   |

---

## 7. Graphs — BFS / DFS

| Problem                    | Notes                       |
| -------------------------- | --------------------------- |
| LC #200 Number of Islands  | DFS/BFS flood fill          |
| LC #695 Max Area of Island | DFS flood fill              |
| LC #133 Clone Graph        | BFS + hashmap               |
| LC #130 Surrounded Regions | BFS from boundary           |
| LC #417 Pacific Atlantic   | BFS from boundary (reverse) |
| LC #207 Course Schedule    | DFS cycle detection (topo)  |
| LC #210 Course Schedule II | DFS topo sort               |
| LC #269 Alien Dictionary   | BFS topo sort               |

---

## 8. Union Find

| Problem                                      | Notes                      |
| -------------------------------------------- | -------------------------- |
| LC #684 Redundant Connection                 | union find cycle detection |
| LC #1319 Make Network Connected              | union find components      |
| LC #990 Satisfiability of Equality Equations | union find grouping        |

---

## 9. Shortest Path (Dijkstra / Bellman-Ford / Floyd-Warshall)

| Problem                                 | Notes                          |
| --------------------------------------- | ------------------------------ |
| LC #743 Network Delay Time              | Dijkstra + Bellman-Ford        |
| LC #1334 Find the City                  | Floyd-Warshall                 |
| LC #787 Cheapest Flights Within K Stops | Bellman-Ford with K constraint |

---

## 10. Heap / Priority Queue

| Problem                              | Notes                   |
| ------------------------------------ | ----------------------- |
| LC #347 Top K Frequent Elements      | min heap size K         |
| LC #973 K Closest Points to Origin   | min heap                |
| LC #215 Kth Largest Element          | max heap or quickselect |
| LC #295 Find Median from Data Stream | two heaps               |
| LC #23 Merge K Sorted Lists          | min heap                |
| LC #621 Task Scheduler               | max heap + greedy       |
| LC #767 Reorganize String            | max heap + greedy       |
| LC #451 Sort Characters by Frequency | max heap                |
| LC #480 Sliding Window Median        | two heaps               |

---

## 11. Backtracking

| Problem                            | Notes                        |
| ---------------------------------- | ---------------------------- |
| LC #46 Permutations                | swap or visited array        |
| LC #47 Permutations II             | sort + skip duplicates       |
| LC #78 Subsets                     | include/exclude              |
| LC #90 Subsets II                  | sort + skip duplicates       |
| LC #39 Combination Sum             | reuse allowed                |
| LC #17 Letter Combinations         | cartesian product backtrack  |
| LC #131 Palindrome Partitioning    | backtrack + palindrome check |
| LC #132 Palindrome Partitioning II | DP version                   |
| LC #37 Sudoku Solver               | constraint backtracking      |
| LC #51 N-Queens                    | constraint backtracking      |
| LC #79 Word Search                 | DFS + visited                |
| LC #212 Word Search II             | Trie + DFS                   |

---

## 12. Dynamic Programming — 1D

| Problem                | Notes                  |
| ---------------------- | ---------------------- |
| LC #70 Climbing Stairs | classic 1D DP          |
| LC #198 House Robber   | 1D DP skip adjacent    |
| LC #139 Word Break     | 1D DP + set lookup     |
| LC #300 LIS            | 1D DP or binary search |
| LC #322 Coin Change    | unbounded knapsack 1D  |

---

## 13. Dynamic Programming — 2D / Interval

| Problem                                 | Notes                        |
| --------------------------------------- | ---------------------------- |
| LC #1143 LCS                            | 2D DP                        |
| LC #516 Longest Palindromic Subsequence | interval DP                  |
| LC #72 Edit Distance                    | 2D DP                        |
| LC #354 Russian Doll Envelopes          | LIS variant 2D sort          |
| LC #123 Buy Sell Stock III              | state machine DP             |
| LC #188 Buy Sell Stock IV               | generalised state machine DP |

---

## 14. Knapsack (0/1 and Unbounded)

| Problem             | Notes                               |
| ------------------- | ----------------------------------- |
| LC #322 Coin Change | unbounded knapsack                  |
| LC #494 Target Sum  | 0/1 knapsack (subset sum reduction) |
| LC #139 Word Break  | unbounded knapsack variant          |

---

## 15. Greedy

| Problem                          | Notes               |
| -------------------------------- | ------------------- |
| LC #621 Task Scheduler           | greedy + heap       |
| LC #767 Reorganize String        | greedy + heap       |
| LC #121 Best Time to Buy Stock I | greedy min tracking |

---

## 16. Linked List

| Problem                           | Notes              |
| --------------------------------- | ------------------ |
| LC #23 Merge K Sorted Lists       | heap + linked list |
| LC #114 Flatten BT to Linked List | tree → linked list |

---

## Pattern Summary (quick reference)

| Pattern        | When to reach for it                                    |
| -------------- | ------------------------------------------------------- |
| Hash Map       | frequency, lookup, grouping                             |
| Sliding Window | subarray, substring, window of size k                   |
| Prefix Sum     | subarray sums, range queries                            |
| Stack          | matching brackets, monotonic problems                   |
| Binary Search  | sorted array, search space reduction                    |
| Tree DFS       | path problems, subtree checks, recursion                |
| Tree BFS       | level order, shortest path in tree                      |
| Graph BFS/DFS  | connected components, flood fill                        |
| Topo Sort      | dependency ordering, cycle detection                    |
| Union Find     | dynamic connectivity, cycle detection                   |
| Dijkstra       | weighted shortest path, no negative edges               |
| Bellman-Ford   | weighted shortest path, negative edges ok, K constraint |
| Floyd-Warshall | all pairs shortest path                                 |
| Heap           | top K, median, merge sorted                             |
| Backtracking   | all combinations, permutations, constraint satisfaction |
| 1D DP          | optimal substructure, one variable state                |
| 2D DP          | two sequences, grid problems                            |
| Knapsack       | pick/skip decisions, subset sum                         |
| Greedy         | locally optimal = globally optimal                      |
