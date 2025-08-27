// problem url: https://codeforces.com/contest/1187/problem/E
// difficulty: 2100
// tags: dfs, dp, trees
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vii;

/*
dp1[u] = max points moving downward from u
dp2[u] = max points moving upward to u
h[u] = size of subtree at u
*/
vi dp1, dp2, h;

// undirected graph
vii g;

void dfs0(int u, int p) {
    for (int v : g[u]) {
        if (v == p) continue;
        dfs0(v, u);
        h[u] += h[v];
    }
}

void dfs1(int u, int p) {
    for (int v : g[u]) {
        if (v == p) continue;
        dfs1(v, u);
        dp1[u] += dp1[v];
    }
    dp1[u] += h[u];
}

void dfs2(int u, int p) {
    for (int v : g[u]) {
        if (v == p) continue;
        // dp2[v] ~ dp2[u]
    }
}

/*
    connected components in a tree
        * subtree of all white nodes 
*/
void solve() {
    int n; cin >> n;

    g.assign(n, vi());
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dp1.assign(n, 0);
    dp2.assign(n, 0);
    h.assign(n, 1);

    dfs0(0, -1);
    dfs1(0, -1);
    dfs2(0, -1);   

    cout << max(dp1[0], dp2[0]) << '\n'; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}