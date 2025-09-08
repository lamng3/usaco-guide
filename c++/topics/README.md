# Notes

## 1. Topics
### 1.1. DP on Strings
#### Exercises
- [[LeetCode] 115. Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/description/) (see 2.1 for big numbers)

### 1.2. Topological Sort
Topological Sort with BFS is also called [Kahn Algorithm](https://en.wikipedia.org/wiki/Topological_sorting#Kahn's_algorithm)
#### Exercises
- [[CSES] Course Schedule](https://cses.fi/problemset/task/1679)

### 1.3. 0/1 BFS
Invariant: The difference between any two distances inside the deque at the same time is at most 1. 
*Proof:* Deque never holds two "layers": by the time we reach `d+2`, the front of the queue has been fully processed for `d`. We add `d+1` to the back of the deque.
The way 0/1 BFS works is that if an edge has weight 0, we add to the front; otherwise, we add to the back of the deque. And we process from front to back.
```
d[v] <= d[u] <= d[v] + 1 for each u in Q
```
**Dial's Algorithm:** This is an extension of `0/1 BFS` where weights are allowed to be <= K. So we can keep `K+1` buckets in the queue.
#### Sources
[[CP Algorithms] 0/1 BFS](https://cp-algorithms.com/graph/01_bfs.html)

## 2. Useful Helpers
### 2.1. Big Numbers
In case the numbers overflow, use this definition
```
typedef unsigned __int128 u128;
```