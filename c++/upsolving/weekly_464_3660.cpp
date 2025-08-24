// problem url: https://leetcode.com/problems/jump-game-ix/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int oo = (int)1e9+7;

struct Fenwick {
    int n; vi ft;
    Fenwick(int n): n(n), ft(n+1, -oo) {};
    void update(int k, int u) {
        for (; k <= n; k += k & -k) ft[k] = max(ft[k], u);
    }
    int query(int k) {
        int s = -oo;
        for (; k > 0; k -= k & -k) s = max(s, ft[k]);
        return s;
    }
};

int bsearch(int x, vi uq) {
    return int(lower_bound(uq.begin(), uq.end(), x) - uq.begin());
};

void solve() {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // no jumping or left-only
    vi base(n);
    for (int i = 0; i < n; i++) base[i] = i > 0 ? max(a[i], base[i-1]) : a[i];
    
    // coordinate compress
    vi uq = a;
    sort(uq.begin(), uq.end());
    uq.erase(unique(uq.begin(), uq.end()), uq.end());
    
    // get ranks
    unordered_map<int,int> rank;
    for (int i = 0; i < uq.size(); i++) rank[uq[i]] = i+1;
    vi r(n);
    for (int i = 0; i < n; i++) r[i] = rank[a[i]];

    Fenwick ft(uq.size());
    vi dp(n, -oo);
    for (int i = n-1; i >= 0; i--) {
        int id = bsearch(a[i], uq);
        int cur = base[i];
        if (id > 0) cur = max(cur, ft.query(id));
        dp[i] = cur;
        ft.update(r[i], dp[i]);
    }

    for (int i = 0; i < n; i++) cout << dp[i] << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}