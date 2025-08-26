// problem url: https://cses.fi/problemset/task/1745
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

void solve() {
    int n; cin >> n;

    int maxsum = 0;
    vi x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        maxsum += x[i];
    }
    sort(x.begin(), x.end());

    // each coin is used once
    vi dp(maxsum+1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        // iterate from end to avoid double coin use
        for (int j = maxsum; j >= 0; j--) {
            if (j < x[i]) continue;
            dp[j] = dp[j] | dp[j-x[i]];
        }
    }

    vi ans;
    for (int i = 1; i <= maxsum; i++) if (dp[i]) ans.push_back(i);
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}