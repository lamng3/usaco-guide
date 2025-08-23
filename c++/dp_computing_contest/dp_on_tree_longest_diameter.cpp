/*
Find the diameter (longest path) in a tree in O(n) time.
*/
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vii;
int diam;

int dfs(int u, int p, vii g) {
    // find longest height of a node
    int best1 = -1, best2 = -1;
    for (int v : g[u]) {
        if (v != p) {
            int h = dfs(v, u, g);
            if (h > best1) { 
                best2 = best1; 
                best1 = h; 
            }
            else if (h > best2) best2 = h;
        }
    }
    diam = max(diam, best1 + best2 + 2);
    return best1 + 1;
}

void solve() {
    // n nodes; m edges
    int n, m; cin >> n >> m;
    // initialize graph
    vii g(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    diam = 0;
    dfs(0, -1, g);
    cout << diam << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}