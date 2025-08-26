// source: https://codeforces.com/blog/entry/20935
// problem 1
/*
Given a tree T of N nodes, where each node i has Ci coins attached with it. 
You have to choose a subset of nodes such that no two adjacent nodes
    (i.e. nodes connected directly by an edge) 
are chosen and sum of coins attached with nodes in chosen subset is maximum.
*/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;

vi C;
// dp1[u] = max coins subtree of u with u included
// dp2[u] = max coins subtree of u without u included
vi dp1, dp2;

void dfs(int u, int p, vii g) {
    int s1 = 0, s2 = 0;
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u, g);
        s1 += dp2[v]; // dp2[v] = include u and not include v
        s2 += max(dp1[v], dp2[v]); // include child v and not include child v
    }
    dp1[u] = C[u] + s1;
    dp2[u] = s2;
}

void solve() {
    int n; cin >> n;
    C.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> C[i];
    vii g;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dp1.resize(n+1); dp2.resize(n+1);
    dfs(1, 0, g);
    int ans = max(dp1[1], dp2[1]);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}