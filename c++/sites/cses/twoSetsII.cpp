// problem url: https://cses.fi/problemset/task/1093
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

const int mod = 1e9+7;

void solve() {
    int n; cin >> n;
    int sum = (n+1) * n / 2;
    if (sum % 2 != 0) {
        cout << 0 << '\n';
        return;
    }
    int k = sum / 2;
    vi dp(k+1);
    dp[0] = 1;
    for (int c = 1; c <= n; c++) {
        for (int i = k; i >= 0; i--) {
            if (i < c) continue;
            dp[i] = ((ll) dp[i] + dp[i-c]) % mod;
        }
    }
    // double counting because we are choosing both A and ~A twice
    // divide by 2 using modular multiplicative inverse 
    int ans = ((ll) dp[k] * (mod + 1) / 2) % mod;
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