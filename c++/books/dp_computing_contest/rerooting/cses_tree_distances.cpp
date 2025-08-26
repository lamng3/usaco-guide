// problem url: https://cses.fi/problemset/task/1132
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vii;

/*
    dp1[u]: max distance subtree going down from u
        dp1[u] = max(dp1[v]) + 1 with v = child of u
    dp2[u]: max distance reaching u from outside subtree
        dp2[v] = max(dp[v], dp2[c]+2) with c and v = children of u
        dp2[v] = max(dp[v], dp1[u]+1) with v = child of u
        dp1[u] + 1 means adding 1 edge from u to a child node != v
        dp2[c] + 2 means adding 2 edges to pass through node u
*/
vi dp1, dp2;

// graph
vii g;

void dfs1(int u, int p) {
    for (int v : g[u]) {
        if (v == p) continue;
        dfs1(v, u);
        dp1[u] = max(dp1[u], dp1[v] + 1);
    }
}

void dfs2(int u, int p) {
    // find top 2 best child v of u
    int mx1 = -1, mx2 = -1;
    for (int v : g[u]) {
        if (v == p) continue;
        int cx = dp1[v];
        if (cx > mx1) { mx2 = mx1; mx1 = cx; }
        else if (cx > mx2) { mx2 = cx; }
    }

    for (int v : g[u]) {
        if (v == p) continue;
        int from_other = dp1[v] == mx1 ? mx2 : mx1;
        int from_root = dp2[u];
        // connects 2 edges from other passing root u
        // connects 1 edge to root
        dp2[v] = max(from_other + 2, from_root + 1);
        dfs2(v, u);
    }
}

void solve() {
    int n; cin >> n;

    g.assign(n, vi());
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dp1.assign(n, 0);
    dp2.assign(n, 0);

    dfs1(0, -1);
    dfs2(0, -1);

    for (int i = 0; i < n; i++) {
        cout << max(dp1[i], dp2[i]) << (i + 1 == n ? '\n' : ' ');
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}