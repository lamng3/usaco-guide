// problem url: https://leetcode.com/problems/count-stepping-numbers-in-range/description/
// difficulty: hard
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

/*
dp[pos][last][tight]
*/
int dp[205][11][2];

int solve_dp(string num, int n, int last, bool tight) {
    if (n == 0) return 1;
    if (dp[n][last][tight] != -1) return dp[n][last][tight];
    int answer = 0;
    int ub = tight ? (num[num.size()-n]-'0') : 9;
    for (int d = 0; d <= ub; d++) {
        if (last == 10) {
            answer += solve_dp(num, n-1, (d == 0 ? 10 : d), tight&(d==ub));
            answer %= mod;
        }
        else {
            if (abs(d - last) != 1) continue;
            answer += solve_dp(num, n-1, d, tight&(d==ub));
            answer %= mod;
        }
    }
    if (answer < 0) answer += mod;
    return dp[n][last][tight] = answer;
}

string subtract_one(string s) {
    if (s == "0") return "0";
    int i = (int)s.size() - 1;
    while (i >= 0 && s[i] == '0') { s[i] = '9'; --i; }
    if (i >= 0) --s[i];
    size_t p = s.find_first_not_of('0');
    return p == string::npos ? "0" : s.substr(p);
}

int count_up_to(string num) {
    memset(dp, -1, sizeof dp);
    int answer = solve_dp(num, num.size(), 10, 1);
    answer %= mod;
    if (answer < 0) answer += mod;
    return answer;
}

void solve() {
    string low; cin >> low;
    string high; cin >> high;
    string lowm1 = subtract_one(low);
    int answer = count_up_to(high) - count_up_to(lowm1);
    answer %= mod;
    if (answer < 0) answer += mod;
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