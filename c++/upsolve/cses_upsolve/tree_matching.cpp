// problem url: https://cses.fi/problemset/task/1130
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector< vector<int> > vii;

/*
dp1[u] = include node u
dp2[u] = not include node u

if not include u: dp2[u] += max(dp1[v], dp2[v])
if include u:
    dp1[u] = max(dp2[v] + 1 + dp2[u] - max(dp1[v], dp2[v]))
        * can only choose 1 child to take
        * each v contributes max(dp1[v], dp2[v])
        * dp2[v] + 1 adds an edge u -> v to count
        * dp2[u] - max(dp1[v], dp2[v]) removes contribution of v out
*/
vl dp1, dp2;

// graph
vii g;

void dfs(int u, int p) {
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
    g.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dp1.assign(n, 0); dp2.assign(n, 0);
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