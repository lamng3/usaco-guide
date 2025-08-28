// problem url: https://leetcode.com/problems/count-special-integers/description/
// difficulty: hard
// use const string& num to avoid repeated string copies
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
dp[pos][mask][tight][started]
*/
ll dp[11][1100][2][2];

ll solve_dp(const string& num, int n, int mask, bool tight, bool started) {
    if (n == 0) return started;
    if (dp[n][mask][tight][started] != -1) return dp[n][mask][tight][started];
    ll answer = 0;
    int ub = tight ? (num[num.size()-n]-'0') : 9;
    for (int d = 0; d <= ub; d++) {
        if (mask&(1<<d)) continue;
        if (started|(d!=0)) {
            answer += solve_dp(num, n-1, mask|(1<<d), tight&(d==ub), 1);
        } 
        else {
            answer += solve_dp(num, n-1, mask, tight&(d==ub), 0);
        }
    }
    return dp[n][mask][tight][started] = answer;
}

ll count_up_to(const string& num) {
    memset(dp, -1, sizeof dp);
    ll answer = solve_dp(num, num.size(), 0, 1, 0);
    return answer;
}

void solve() {
    ll n; cin >> n;
    string num = to_string(n);
    ll answer = count_up_to(num);
    cout << (int) answer << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}