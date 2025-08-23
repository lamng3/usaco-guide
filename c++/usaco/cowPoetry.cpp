// problem url: https://usaco.org/index.php?page=viewproblem2&cpid=897
// rank: gold
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vii vector< vector<int> >

const int mod = 1e9+7;

int modpow(int a, int b) {
    if (a == 0) return b == 0;
    int s = 1;
    while (b) {
        if (b & 1) s = ((ll) s * a) % mod;
        a = ((ll) a * a) % mod;
        b >>= 1;
    }
    return s;
}

void solve() {
    // dp[i][j] = ways to create `i` length word that ends at c[j]
    int n, m, k; cin >> n >> m >> k;
    vi s(n+1), c(n+1);
    unordered_set<int> cls;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> c[i];
        cls.insert(c[i]);
    }

    // dynamic programming
    vii dp(k+1, vector<int>(n+1, 0));
    vi prev(k+1, 0); // sum of previous classes count
    prev[0] = 1;
    
    // one word can be used multiple times
    for (int i = 0; i <= k; i++) {
        for (int j = 1; j <= n; j++) { // word by word
            if (i < s[j]) continue;
            // dp[i-s[j]][c[j]]
            dp[i][c[j]] = ((ll) dp[i][c[j]] + prev[i-s[j]]) % mod;
        }
        // sum up previous counts of a class
        for (const auto j : cls) prev[i] = ((ll) prev[i] + dp[i][j]) % mod;
    }
    // different combinations for dp[k][j]

    // group lines of same rhyme class
    unordered_map<char, int> e;
    for (int i = 0; i < m; i++) {
        char x; cin >> x;
        e[x] = e[x] + 1;
    }

    // calculate a1^x + a2^x + ... + an^x
    int ans = 1;
    for (const auto p : e) { // e has at most 26 characters
        int sum = 0;
        for (const auto j : cls) {
            sum = ((ll) sum + modpow(dp[k][j], p.second)) % mod;
        }
        ans = ((ll) ans * sum) % mod;
    }
    cout << (int) ans << '\n';
}

int main() {
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; 
    // cin >> tt;
    while (tt--) solve();
    return 0;
}