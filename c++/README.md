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
It is common to keep 2 DP arrays for DP on tree problems:
- 1 DP for include node i in subtree
- 1 DP for not include node i in subtree 
### Rerooting
Rerooting usually have 2 DFS. So the **Mental Model** is:
- DFS1 as *post-order DFS*, flowing upward from leaves, computing children first.
    - Information flows up from children to parent.
    - This can also be called *forward*.
- DFS2 as *pre-order DFS*, flowing downward from parent and siblings, computing child before visiting the child. 
    - Pushing information down from parent and siblings.
    - This can also be called *backward*.
### Exercises
- [CSES/Tree Matching](https://cses.fi/problemset/task/1130)