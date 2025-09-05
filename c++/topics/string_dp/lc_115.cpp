// problem url: https://leetcode.com/problems/distinct-subsequences/description/
// difficulty: hard
// tags: dp on strings, subsequences
#include <bits/stdc++.h>
using namespace std;

typedef unsigned __int128 u128;
typedef vector<u128> vi;
typedef vector< vector<u128> > vii;

void solve() {
    string s; cin >> s;
    string t; cin >> t;
    int m = (int) s.size(), n = (int) t.size();
    /*
        dp[i][j] = #subsequences in s[1..i] matches t[1..j]
    */
    vii dp(m+1, vi(n+1, 0));
    // avoid setting dp[0][0] = 0 :)
    for (int j = 0; j <= n; j++) dp[0][j] = 0; // empty s
    for (int i = 0; i <= m; i++) dp[i][0] = 1; // empty t appears in s[0..i]
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i-1][j]; // ignore s[i-1]
            if (s[i-1] == t[j-1]) {
                dp[i][j] += dp[i-1][j-1];
            }
        }
    }
    cout << (int) dp[m][n] << '\n';
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}