// problem url: https://leetcode.com/problems/count-numbers-with-unique-digits/description/?envType=problem-list-v2&envId=r6yc959s
// difficulty: medium
// difficulty: hard if solve with Digit DP
#include <bits/stdc++.h>
using namespace std;

/*
dp[pos][mask][tight][started]
*/
int dp[10][1500][2][2];

int solve_dp(string num, int n, int k, bool tight, bool started) {
    if (k < 0) return 0;
    if (n == 0) return 1;
    if (dp[n][k][tight][started] != -1) return dp[n][k][tight][started];
    int answer = 0;
    int ub = tight ? (num[num.size()-n] - '0') : 9;
    for (int d = 0; d <= ub; d++) {
        if (started|(d!=0)) { // already started
            if (k & (1 << d)) continue; // digit used
            answer += solve_dp(num, n-1, k|(1 << d), tight&(d==ub), 1);
        }
        else {
            // leading zeros: do not consume digit
            answer += solve_dp(num, n-1, k, tight&(d==ub), 0);
        }
    }
    return dp[n][k][tight][started] = answer;
}

int count_up_to(string num) {
    memset(dp, -1, sizeof dp);
    int answer = solve_dp(num, num.size(), 0, 1, 0);
    return answer;
}

void solve() {
    int n; cin >> n;
    string num = string(n, '9');
    int answer = count_up_to(num);
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}