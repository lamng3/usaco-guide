/*
How many X such that L <= X <= R which have a sum of digits = X.
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
dp[pos][sum][tight]
    * pos = current position
    * sum = current sum
    * tight = whether the number can be > R in the future
*/
ll dp[20][185][2];

ll solve_dp(string& num, int n, int x, bool tight) {
    if (x < 0) return 0;
    if (n == 0) return (x == 0);
    if (dp[n][x][tight] != -1) return dp[n][x][tight];
    ll answer = 0;
    int ub = tight ? (num[(num.length() - n)] - '0') : 9; // upperbound
    for (int d = 0; d <= ub; d++) {
        answer += solve_dp(num, n-1, x-d, tight&(d == ub));
    }
    return dp[n][x][tight] = answer;
}

ll count_up_to(ll a, ll x) {
    memset(dp, -1, sizeof dp);
    string num = to_string(a);
    return solve_dp(num, num.length(), x, 1);
}

void solve() {
    memset(dp, -1, sizeof dp);
    ll L, R, x; cin >> L >> R >> x;
    ll ans = count_up_to(R, x) - count_up_to(L-1, x);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}