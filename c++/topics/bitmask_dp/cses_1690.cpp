// problem url: https://cses.fi/problemset/task/1690
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vii;

const int mod = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    vii g(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[b].push_back(a);
    }
    int FULL = 1 << n;
    /*
        dp[S][x] = number of routes with subset S ending at x
    */
    vii dp(FULL, vi(n, 0)); dp[1][0] = 1;
    for (int mask = 0; mask < FULL; mask++) {
        if ((mask & (1<<0)) == 0) continue;
        if ((mask & (1<<(n-1))) && (mask != FULL-1)) continue;
        for (int u = 0; u < n; u++) {
            if ((mask&(1<<u)) == 0) continue;
            int prev = mask ^ (1<<u);
            for (int v : g[u]) {
                dp[mask][u] = ((ll)dp[mask][u] + dp[prev][v]) % mod;
            }
        }
    }
    cout << dp[FULL-1][n-1];
}

int main() {
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}