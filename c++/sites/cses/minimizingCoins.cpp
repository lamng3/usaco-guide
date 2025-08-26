// problem url: https://cses.fi/problemset/task/1634
#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9+7;

void solve() {
    int n, x; cin >> n >> x;
    int c[n];
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<int> dp(x+1, oo); 
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= c[j]) {
                dp[i] = min(dp[i], dp[i-c[j]]+1);
            }
        }
    }
    cout << (dp[x] == oo ? -1 : dp[x]) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    while (tt--) solve();
    return 0;
}