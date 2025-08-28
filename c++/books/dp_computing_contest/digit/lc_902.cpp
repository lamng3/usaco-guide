// problem url: https://leetcode.com/problems/numbers-at-most-n-given-digit-set/description/
// difficulty: hard
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
dp[pos][tight][started]
*/
ll dp[11][2][2];
bool allowed[10];

ll solve_dp(string num, int n, bool tight, bool started) {
    if (n == 0) return started;
    if (dp[n][tight][started] != -1) return dp[n][tight][started];
    ll answer = 0;
    ll ub = tight ? (num[num.size()-n] - '0') : 9;
    for (int d = 0; d <= ub; d++) {
        bool ok = allowed[d] || (!started && (d==0));
        if (!ok) continue;
        answer += solve_dp(num, n-1, tight&(d==ub), started|(d!=0));
    }
    return dp[n][tight][started] = answer;
}

int count_up_to(string num) {
    memset(dp, -1, sizeof dp);
    ll answer = solve_dp(num, num.size(), 1, 0);
    return (int) answer;
}

void solve() {
    ll n, m; cin >> n >> m;
    vector<string> digits(m);
    for (int i = 0; i < m; i++) cin >> digits[i];

    memset(allowed, 0, sizeof allowed);
    for (auto &s : digits) allowed[s[0]-'0'] = 1;

    string num = to_string(n);
    int answer = count_up_to(num);
    cout << answer << '\n';
}

int main() {
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}