// problem url: https://usaco.org/index.php?page=viewproblem2&cpid=1114
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vii;

const int oo = 305;

void solve() {
    int n; cin >> n;
    vi p(n+1); for (int i = 1; i <= n; i++) cin >> p[i];
    vii dp(n+1, vi(n+1, oo));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j) dp[i][j] = 1;
            else dp[i][j] = oo;
        }
        if (i != n) dp[i][i+1] = 1 + (p[i] != p[i+1]);
    }
    for (int gap = 2; gap < n; gap++) {
        for (int pos = 1; pos + gap <= n; pos++) {
            dp[pos][pos+gap] = dp[pos+1][pos+gap-1] + (p[pos] == p[pos+gap] ? 1 : 2);
            // inside gap
            for (int point = pos + 1; point < n; point++) {
                dp[pos][pos+gap] = min(
                    dp[pos][pos+gap],
                    dp[pos][point] + dp[point][pos+gap] - 1
                );
            }
        }
    }
    cout << dp[1][n] << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}