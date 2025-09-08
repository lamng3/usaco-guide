// problem url: https://usaco.org/index.php?page=viewproblem2&cpid=647
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vii;

void solve() {
    /*
        dp[i][j] = value [i..j] can be merged into; 0 otherwise.
    */
    int n; cin >> n;
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
    vii dp(n, vi(n, 0));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dp[i][j] = a[i];
            else dp[i][j] = 0;
            ans = max(ans, dp[i][j]);
        }
        if (i != n-1) {
            dp[i][i+1] = a[i] == a[i+1] ? a[i]+1 : 0;
            ans = max(ans, dp[i][i+1]);
        }
    }
    for (int gap = 2; gap < n; gap++) {
        for (int pos = 0; pos+gap < n; pos++) {
            /*
                point may split to dp[pos][pos] and dp[pos+1][pos+gap]
            */
            for (int point = pos; point < pos+gap; point++) {
                int L = dp[pos][point], R = dp[point+1][pos+gap];
                if (L && L == R) {
                    dp[pos][pos+gap] = max(dp[pos][pos+gap], L+1);
                }
            }
            ans = max(ans, dp[pos][pos+gap]);
        }
    }
    cout << ans << '\n';
}

int main() {
    // freopen("248.in", "r", stdin);
    // freopen("248.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}