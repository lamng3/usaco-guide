// problem url: https://atcoder.jp/contests/abc187/tasks/abc187_f
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int oo = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    vi adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        // adj representation with bitmask
        adj[a] |= (1 << b);
        adj[b] |= (1 << a);
    }

    int FULL = 1 << n;
    /*
    dp[S] = minimum cliques a set of selected node form
    */
    vi dp(FULL, oo);
    for (int mask = 0; mask < FULL; mask++) {
        bool connected = true;
        for (int u = 0; u < n; u++) {
            if ((mask & (1 << u)) == 0) continue;
            // check u connected with the rest
            /*
            if node v is not included in mask, but included in adj[u]
                & mask removes v from adj[u]
            if node v included in mask, but not included in adj[u]
                this would be an invalid case
            */
            if (((adj[u]|(1<<u)) & mask) != mask) {
                connected = false;
            }
        }
        if (connected) dp[mask] = 1;
    }

    for (int mask = 0; mask < FULL; mask++) {
        for (int submask = mask; submask != 0; submask = (submask-1) & mask) {
            int subset = submask ^ mask;
            if (dp[submask] != oo && dp[subset] != oo) {
                dp[mask] = min(dp[mask], dp[submask] + dp[subset]);
            }
        }
    }
    cout << dp[FULL-1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}