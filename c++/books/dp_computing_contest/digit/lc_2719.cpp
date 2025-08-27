// problem url: https://leetcode.com/problems/count-of-integers/
// difficulty: hard
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9+7;

/*
dp[pos][sum][2]
*/
ll dp[30][405][2];

ll solve_dp(string& num, int n, int x, bool tight) {
    if (x < 0) return 0;
    if (n == 0) return (x == 0);
    if (dp[n][x][tight] != -1) return dp[n][x][tight];
    ll answer = 0;
    int ub = tight ? (num[(num.size() - n)] - '0') : 9;
    for (int d = 0; d <= ub; d++) {
        answer += solve_dp(num, n-1, x-d, tight&(d == ub));
        if (answer >= mod) answer %= mod;
    }
    return dp[n][x][tight] = answer;
}

string subtract_one(string s) {
    if (s == "0") return "0";
    int i = (int)s.size() - 1;
    while (i >= 0 && s[i] == '0') { s[i] = '9'; --i; }
    if (i >= 0) --s[i];
    size_t p = s.find_first_not_of('0');
    return p == string::npos ? "0" : s.substr(p);
}

int count_up_to(string num, int min_sum, int max_sum) {
    memset(dp, -1, sizeof dp);
    ll answer = 0;
    for (int s = min_sum; s <= max_sum; s++) {
        answer += solve_dp(num, num.size(), s, 1);
        answer %= mod;
    }
    if (answer < 0) answer += mod;
    return (int) answer;
}

void solve() {
    string L, R; cin >> L >> R;
    int min_sum, max_sum; cin >> min_sum >> max_sum;
    string Lm1 = subtract_one(L);
    ll answer = 0;
    answer += count_up_to(R, min_sum, max_sum);
    answer -= count_up_to(Lm1, min_sum, max_sum);
    if (answer < 0) answer += mod;
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