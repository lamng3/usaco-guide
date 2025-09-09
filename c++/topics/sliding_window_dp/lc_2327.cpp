// problem url: https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/
// tags: sliding window dp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

const int mod = 1e9+7;

void solve1() {
    int n, delay, forget; cin >> n >> delay >> forget;
    /*
        dp[d] = number of people started on day d
    */
    vl dp(n+1, 0); dp[1] = 1;
    for (int d = 1; d <= n; d++) {
        for (int prv = 1; prv < d; prv++) {
            if (prv + delay <= d && d < prv + forget) {
                dp[d] += dp[prv];
                dp[d] %= mod;
                if (dp[d] < 0) dp[d] += mod;
            }
        }
    }
    ll ans = 0;
    for (int d = n-forget+1; d <= n; d++) {
        ans += dp[d];
        ans %= mod;
        if (ans < 0) ans += mod;
    }
    cout << (int) ans << '\n';
}

void solve2() {
    /*
        We can do better than O(N^2)!
    */
    int n, delay, forget; cin >> n >> delay >> forget;
    /*
        dp[d] = number of people started on day d
    */
    vl dp(n+1,0); dp[1] = 1;
    int share = 0;
    for (int d = 2; d <= n; d++) {
        dp[d] = share = (share + dp[max(d-delay,0)] - dp[max(d-forget,0)] + mod) % mod;
    }
    ll ans = 0;
    for (int d = n-forget+1; d <= n; d++) ans = (ans + dp[d] + mod) % mod;
    cout << (int) ans << '\n';
}

void solve() {
    // solve1();
    solve2();
}

int main() {
    // freopen("name.in", "r", stdin);
    // freopen("name.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}