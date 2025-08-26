/*
Author: Patrick Zhang, TJ SCT
There are N flowers. 
Each flower can either be red flower or a white flower. 
How many ways are there to arrange them in a line of length N such that 
    there are never more than M flowers of the same color in a row?
Constraints: 
    - 1 <= N, M <= 5000
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9+7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n+1, vector<ll>(2));
    dp[0][0] = dp[0][1] = 1;
    for (int i = 0; i <= n; i++) {
        // for each flower of type x placed at position i
        // we can calculate based on previous M states
        // we are not missing any states, because if we go beyond M (i - j where j > M)
        //      we already have calculated it inside the state dp[i-j] within dp[i-1] and dp[i-M]
        for (int j = 1; j <= m; j++) {
            if (i - j < 0) break;
            for (int c = 0; c < 2; c++) dp[i][c] += dp[i-j][1-c];
        }
    }
    cout << dp[n][0] + dp[n][1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt; // number of test cases
    while (tt--) solve();
    return 0;
}