/*
Find the size of the subtrees for all n nodes in a tree in O(n) time.
*/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;

const int MAXN = 1e6+5;

vi subsz(MAXN);
int t = 0;

void dfs(int u, int p, vii g) {
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u, g);
            subsz[u] += subsz[v];
        }
    }
}

void solve_dfs() {
    // n nodes; m edges
    int n, m; cin >> n >> m;
    
    // initialize graph
    vii g(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    subsz.assign(n, 1);
    int root = 0; // dp on dfs rooted
    dfs(0, -1, g);
}

void dfs_timestamp(int u, int p, vii g) {
    int entry_t = t; // entry time
    t += 1;
    for (int v : g[u]) {
        if (v != p) {
            dfs_timestamp(v, u, g);
        }
    }
    subsz[u] = t - entry_t;
}

void solve_dfs_timestamp() {
    // n nodes; m edges
    int n, m; cin >> n >> m;
    
    // initialize graph
    vii g(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    subsz.assign(n, 1);
    int root = 0; // dp on dfs rooted
    dfs_timestamp(0, -1, g);
}

void solve() {
    solve_dfs();
    solve_dfs_timestamp();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
    return 0;
}