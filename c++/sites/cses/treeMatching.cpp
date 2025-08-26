// problem url: https://cses.fi/problemset/task/1130
/*
dp1[u] = max edges of subtree of u can be matched with u chosen
dp2[u] = max edges of subtree of u can be matched without u chosen
if include node u, can include only 1 child
if not include node u, can include u children

Case 1: Not taking u: dp2[u] = sum(max(dp1[v], dp2[v]))
Case 2: Taking u is trickier
    We take dp2[v] + 1, meaning max edges not taking the child v, and add u->v
    Consider dp2[u]. We have not taken u yet, so we can take u here.
        However, we cannot take children of u.
        As dp2[u] is the sum over dp1[v] and dp2[v].
            We need to remove contribution of v, which is max(dp1[v], dp2[v])
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector< vector<int> > vii;

vl dp1, dp2;
vii g;

void dfs(int u, int p) {
    /*
        Passing graph into DFS can cause stack overflow of memory blowup
    */
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp2[u] += max(dp1[v], dp2[v]);
    }
    for (int v : g[u]) {
        if (v == p) continue;
        dp1[u] = max(dp1[u], dp2[v] + 1 + dp2[u] - max(dp1[v], dp2[v]));
    }
}

void solve() {
    int n; cin >> n;
    g.resize(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // DP on tree
    dp1.resize(n); dp2.resize(n);
    dfs(0, -1);
    int ans = max(dp1[0], dp2[0]);
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