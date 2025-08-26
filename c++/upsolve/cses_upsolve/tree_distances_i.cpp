// problem url: https://cses.fi/problemset/task/1132
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vii;

/*
    dp1[u] = max distance going down from u
        dp1[u] = max(dp1[v]+1) with v = child of u
    dp2[u] = max distance going to u
        going to v from root u: dp2[v] = max(dp2[u]+1)
        going to v from another child: dp2[v] = max(dp2[c]+2)
*/
vi dp1, dp2;

// graph
vii g;

void dfs1(int u, int p) {
    /*
        post-order dfs (downward)
            dp1[u] needs every child dp1[v] first
        mental model: dfs1 flows from leaves up
            compute after visiting children
    */
    for (int v : g[u]) {
        if (v == p) continue;
        dfs1(v, u); // update downward first
        dp1[u] = max(dp1[u], dp1[v] + 1);
    }
}

void dfs2(int u, int p) {
    /*
        pre-order dfs (upward/sideway)
            dp2[v] combines info from dp2[u] and dp2[c]
                so we make sure v is ready for future dp(v,u)
        mental model: dfs2 flows from parents and siblings down
            compute child before visiting that child
    */
    // find top 2 children
    int mx1 = -1, mx2 = -1;
    for (int v : g[u]) {
        if (v == p) continue;
        int cx = dp1[v];
        if (cx > mx1) { mx2 = mx1; mx1 = cx; }
        else if (cx > mx2) { mx2 = cx; }
    }
    // update going to v
    for (int v : g[u]) {
        if (v == p) continue;
        int from_other = dp1[v] == mx1 ? mx2 : mx1;
        int from_root = dp2[u];
        // connect 2 edges from other to v (passing through u)
        // connect 1 edge from root u to v
        dp2[v] = max(from_other + 2, from_root + 1);
        dfs2(v, u); // update upward
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