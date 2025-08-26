// problem url: https://cses.fi/problemset/task/1636
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

const int mod = 1e9+7;

void solve() {
    int n, x; cin >> n >> x;
    vi c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(c.begin(), c.end());
    vi dp(x+1, 0);
    dp[0] = 1;
    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= x; i++) {
            if (i >= c[j]) {
                dp[i] = ((ll) dp[i] + dp[i-c[j]]) % mod;
            }
        }
    }
    cout << dp[x] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}