// problem url: https://atcoder.jp/contests/dp/tasks/dp_e?lang=en
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

const ll oo = 2e18+5;

void solve() {
    int n, W; cin >> n >> W;
    vi w(n+1), v(n+1);
    int sumv = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        sumv += v[i];
    }
    // dp[i][v] = min weights to get value v with first i items
    // reduce dp dimension to dp[v] as we only need previous row
    vector<ll> dp(sumv+1, oo);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = sumv; j >= v[i]; j--) {
            if (dp[j-v[i]] == oo) continue; // cannot reach
            dp[j] = min(dp[j], dp[j-v[i]]+w[i]);
        }
    }
    ll ans = 0;
    for (int i = 0; i <= sumv; i++) if (dp[i] <= W) ans = i;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}