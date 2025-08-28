# Dynamic Programming for Computing Contests

## Segmentation Fault
SIGSEGV error in C++, aka Segmentation Fault: 
    - Attempting to access a memory location not permitted.
```
typedef vector<int> vi;
vi dp;
// dp.assign(n, 0)  <-- set this to avoid SIGSEV for vector access
```

## Bitmask DP
When N is sufficiently small enough that an exponential solution is better than a factorial one. Bitmask DP is also called Subset DP.

**Bitwise XOR:** `1 ^ 1 = 1`, otherwise 0.

## Digit DP
Digit DP asks to find the number of integers in a range that have a property. An example is provided below.
```
There are two integers n, m where 0 <= n <= m <= 1e18. Find the number of integers between n and m inclusive containing exactly k d digits. n, m, k, d are given in input.
```
Normally, when the number is large, we can think of Digit DP.
Typicall there are 2 types of problem:
- P1: How many X such that 0 <= X <= R satisfies `f(X)`.
- P2: How many X such that L <= X <= R satisfies `f(X)`.
But solving P1 only suffices to solve P2.

Use `const string& num` to avoid repeated string copies.
- Doing so allows [2376. Count Special Integers](https://leetcode.com/problems/count-special-integers/description/) to AC.

### Resources
- [Introduction to Digit Dynamic Programming](https://www.youtube.com/watch?v=heUFId6Qd1A)

### Exercises
- [LeetCode Digit DP](https://leetcode.com/problem-list/r6yc959s/)

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
### Resources
- [DP on Trees Tutorial](https://codeforces.com/blog/entry/20935)
### Exercises
- [CSES/Tree Matching](https://cses.fi/problemset/task/1130)