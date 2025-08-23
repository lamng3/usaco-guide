// problem url: https://usaco.org/index.php?page=viewproblem2&cpid=574
// rank: gold
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

void solve() {
    int t, a, b; cin >> t >> a >> b;
    vi dp(t+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= t; i++) {
        if (i >= a) dp[i] |= dp[i-a];
        if (i >= b) dp[i] |= dp[i-b];
    }
    for (int i = 1; i <= t; i++) if (i * 2 <= t) dp[i] = dp[i*2]; // drink water
    for (int i = 1; i <= t; i++) {
        if (dp[i]) continue;
        if (i >= a) dp[i] |= dp[i-a];
        if (i >= b) dp[i] |= dp[i-b];
    }
    int best = 0;
    for (int i = 0; i <= t; i++) if (dp[i]) best = i;
    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}