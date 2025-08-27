#include <bits/stdc++.h>
using namespace std;

/*
dp[pos][k][tight][started]
*/
int dp[20][20][2][2];

int solve_dp(string num, int n, int k, bool tight, bool started) {
    if (n == 0) return k;
    if (dp[n][k][tight][started] != -1) return dp[n][k][tight][started];
    int answer = 0;
    int ub = tight ? (num[num.size()-n]-'0') : 9;
    for (int d = 0; d <= ub; d++) {
        if (started|(d!=0)) {
            answer += solve_dp(num, n-1, k+(d==1), tight&(d==ub), 1);
        }
        else {
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
    string num = to_string(n);
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