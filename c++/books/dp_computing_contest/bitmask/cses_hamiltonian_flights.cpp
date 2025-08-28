// problem url: https://cses.fi/problemset/task/1690
// topic: Bitmask DP
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vii;
typedef long long ll;
typedef vector<ll> vl;

const ll mod = (ll)1e9+7;

vector<vl> dp;
vii g;

void solve() {
    int n, m; cin >> n >> m;
    g.assign(n, vi());
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[b].push_back(a);
    }
    
    /*
        dp[s][i] = number of paths subset s ending at i
    */
    int FULL = 1 << n;
    dp.assign(FULL, vl(n, 0));
    dp[1][0] = 1;
    for (int s = 1; s < FULL; s++) {
        if ((s & (1<<0)) == 0) continue;
        if ((s & (1<<(n-1))) && (s != FULL-1)) continue;
        for (int end = 0; end < n; end++) {
            if ((s & (1<<end)) == 0) continue;
            int prev = s ^ (1<<end);
            for (int j : g[end]) {
                dp[s][end] += dp[prev][j];
                dp[s][end] %= mod;
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