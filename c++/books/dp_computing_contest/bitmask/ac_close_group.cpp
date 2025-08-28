// problem url: https://atcoder.jp/contests/abc187/tasks/abc187_f
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vii;

const int oo = 1e9+7;

vi adj;

void solve() {
    int n, m; cin >> n >> m;
    int FULL = 1 << n;

    // adj represented as bitmask
    adj.reserve(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a] |= (1 << b);
        adj[b] |= (1 << a);
    } 

    vi dp(FULL, oo);
    for (int mask = 0; mask < FULL; mask++) {
        bool connected = true;
        for (int u = 0; u < n; u++) {
            if ((mask & (1 << u)) == 0) continue;
            // turn on bit u of adj[u], check if u part of a clique
            if (((adj[u]|(1<<u))&mask) != mask) {
                connected = false;
                break;
            }
        }
        if (connected) dp[mask] = 1;
    }

    for (int mask = 0; mask < FULL; mask++) {
        for (int submask = mask; submask != 0; submask = (submask - 1) & mask) {
            int subset = mask ^ submask;
            if (dp[subset] != oo && dp[submask] != oo) {
                dp[mask] = min(dp[mask], dp[subset] + dp[submask]);
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