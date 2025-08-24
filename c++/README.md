# Pattern Notebook

## DP on Tree
Passing graph into DFS can cause stack overflow of memory blowup
```
void dfs(int u, int p, vii g) {...} <-- avoid
void dfs(int u, int p) {...}        <-- use this
```