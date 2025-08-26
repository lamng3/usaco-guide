# Pattern Notebook

## Segmentation Fault
SIGSEGV error in C++, aka Segmentation Fault: 
    - Attempting to access a memory location not permitted.
```
typedef vector<int> vi;
vi dp;
// dp.assign(n, 0)  <-- set this to avoid SIGSEV for vector access
```

## DP on Tree
Passing graph into DFS can cause stack overflow of memory blowup
```
void dfs(int u, int p, vii g) {...} <-- avoid
void dfs(int u, int p) {...}        <-- use this
```
### Exercises
- [CSES/Tree Matching](https://cses.fi/problemset/task/1130)