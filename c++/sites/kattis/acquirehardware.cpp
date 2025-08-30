#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w; cin >> h >> w;
    vector<string> field(h);
    for (int i = 0; i < h; i++) cin >> field[i];
    vector< vector<int> > dp(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int iron = (field[i][j] == 'I');
            if (i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j] + iron);
            if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1] + iron);
        }
    }
    cout << dp[h-1][w-1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}