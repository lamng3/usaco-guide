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

### Merging Subsets
For some problems, it is not sufficient to just take `S \ {i}`. Instead, we need to look at all strict subsets of S. Therefore, we need to consider all possible ordered pairs `T \subset S`. For each element x, there are 3 possibilities:
- x in S not in T
- x in neither S or T
- x in both S and T
If x in T not in S, T is not a valid subset of S.
Therefore, we reduced from `O(2^N * 2^N)` to just `O(3^N)`.

**Hint:** Readers can use Newton's Expansion (Binomial Theorem) to proof the above. 
```
for (int mask = 0; mask < (1 << n); mask++) {
	for (int submask = mask; submask != 0; submask = (submask - 1) & mask) {
		int subset = mask ^ submask;
		// do whatever you need to do here
	}
}
```
When we subtract 1 from `submask`, we flip the rightmost bits of `submask` to 0, and setting the rest of the bits on the right to 1. This ensures that we eliminate the bit at the desired location by taking `mask ^ submask`.

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

### Helpers
Subtract one from a string.
```
string subtract_one(string s) {
    if (s == "0") return "0";
    int i = (int)s.size() - 1;
    while (i >= 0 && s[i] == '0') { s[i] = '9'; --i; }
    if (i >= 0) --s[i];
    size_t p = s.find_first_not_of('0');
    return p == string::npos ? "0" : s.substr(p);
}
```

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