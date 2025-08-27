// problem url: https://leetcode.com/problems/rotated-digits/description/?envType=problem-list-v2&envId=r6yc959s
// difficulty: medium
// difficulty: hard for large n
#include <bits/stdc++.h>
using namespace std;

int dp[20][1500][2][2];

int valid_mask(int mask) {
    int nmir[3] = {3, 4, 7};    // no mirror
    int rmir[4] = {2, 5, 6, 9}; // reverse
    int nm = 0; for (int x : nmir) nm |= (mask & (1 << x));    
    int rm = 0; for (int x : rmir) rm |= (mask & (1 << x));
    return (nm == 0 & rm > 0);
}

int solve_dp(string num, int n, int mask, bool tight, bool started) {
    if (n == 0) return valid_mask(mask);
    int answer = 0;
    int ub = tight ? (num[num.size()-n]-'0') : 9;
    for (int d = 0; d <= ub; d++) {
        if (d == 3 || d == 4 || d == 7) continue; // cannot use
        if (started|(d!=0)) {
            answer += solve_dp(num, n-1, mask|(1<<d), tight&(d==ub), 1);
        }
        else {
            // leading zeros
            answer += solve_dp(num, n-1, mask, tight&(d==ub), 0);
        }
    }
    return answer;
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